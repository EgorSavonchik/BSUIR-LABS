using Microsoft.Data.Sqlite;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WEB_153501_Savonchik.API.Data;
using WEB_153501_Savonchik.API.Services.TelephoneService;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;

namespace WEB_153501_Savonchik.Tests
{
	public class TelephoneServiceGetTests : IDisposable
	{
		private readonly DbConnection _dbConnection;
		private readonly DbContextOptions<AppDbContext> _contextOptions;
		
		public void Dispose() => _dbConnection.Dispose();

		public TelephoneServiceGetTests()
		{
			_dbConnection = new SqliteConnection("Filename=:memory:");
			_dbConnection.Open();

			_contextOptions = new DbContextOptionsBuilder<AppDbContext>()
				.UseSqlite(_dbConnection)
				.Options;

			using var context = new AppDbContext(_contextOptions);
			context.Database.EnsureCreated();
			context.Firms.AddRange(
				new Firm() { Id = 1, Name = "Samsung", NormalizedName = "Samsung" },
				new Firm() { Id = 2, Name = "Iphone", NormalizedName = "Iphone" });
			context.Telephones.AddRange(
				new Telephone() { Id = 1, Price = 1000, Name = "Iphone1", FirmId = 2, Description = "Phone" },
				new Telephone() { Id = 2, Price = 1100, Name = "Iphone2", FirmId = 2, Description = "Phone" },
				new Telephone() { Id = 3, Price = 1010, Name = "Iphone3", FirmId = 2, Description = "Phone" },
				new Telephone() { Id = 4, Price = 1020, Name = "Iphone4", FirmId = 2, Description = "Phone" },
				new Telephone() { Id = 5, Price = 1050, Name = "Samsung1", FirmId = 1, Description = "Phone" },
				new Telephone() { Id = 6, Price = 1070, Name = "Samsung2", FirmId = 1, Description = "Phone" },
				new Telephone() { Id = 7, Price = 1200, Name = "Samsung3", FirmId = 1, Description = "Phone" });
			context.SaveChanges();
		}

		private AppDbContext CreateContext() => new(_contextOptions);

		[Fact]
		public void GetTelephonesListAsync_ReturnsFirstPageWithThreeItems_WhenDefaultParametersPassed()
		{
			// Arrange
			using var context = CreateContext();
			TelephoneService service = new(context, null!, null!);

			// Act
			var result = service.GetTelephoneListAsync(null).Result;

			// Assert
			Assert.IsType<ResponseData<ListModel<Telephone>>>(result);
			Assert.True(result.Success);
			Assert.Equal(1, result.Data!.CurrentPage);
			Assert.Equal(3, result.Data.Items.Count);
			Assert.Equal(3, result.Data.TotalPages);
			Assert.Equal(context.Telephones.First(), result.Data.Items[0]);
		}

		[Fact]
		public void GetTelephonesListAsync_ReturnsSecondPageWithSecondThreeItems_WhenPageParameterEquals2()
		{
			// Arrange
			using var context = CreateContext();
			TelephoneService service = new(context, null!, null!);

			// Act
			var result = service.GetTelephoneListAsync(null, 2).Result;

			// Assert
			Assert.IsType<ResponseData<ListModel<Telephone>>>(result);
			Assert.True(result.Success);
			Assert.Equal(2, result.Data!.CurrentPage);
			Assert.Equal(3, result.Data.Items.Count);
			Assert.Equal(3, result.Data.TotalPages);
			Assert.Equal(context.Telephones.Skip(3).First(), result.Data.Items.First());
		}

		[Fact]
		public void GetTelephonesListAsync_ReturnsValidTelephonesByCategory_WhenCategoryParameterPassed()
		{
			// Arrange
			using var context = CreateContext();
			TelephoneService service = new(context, null!, null!);

			// Act
			var result = service.GetTelephoneListAsync("Iphone").Result;

			// Assert
			Assert.IsType<ResponseData<ListModel<Telephone>>>(result);
			Assert.True(result.Success);
			Assert.Equal(1, result.Data!.CurrentPage);
			Assert.Equal(3, result.Data.Items.Count);
			Assert.Equal(2, result.Data.TotalPages);
			Assert.DoesNotContain(result.Data.Items, x => x.FirmId != 2);
		}

		[Fact]
		public void GetTelephonesListAsync_ReturnsSuccessFalse_WhenPageNumberParameterIsGreaterThanTotalPages()
		{
			// Arrange
			using var context = CreateContext();
			TelephoneService service = new(context, null!, null!);

			// Act
			var result = service.GetTelephoneListAsync(null, 1000).Result;

			// Assert
			Assert.IsType<ResponseData<ListModel<Telephone>>>(result);
			Assert.False(result.Success);
		}

		[Fact]
		public void GetTelephonesListAsync_DoesNotAllowToSetPageSizeGreaterThanMaxPageSize_WhenGreaterPageSizePassed()
		{
			// Arrange
			using var context = CreateContext();
			TelephoneService service = new(context, null!, null!);

			// Act
			var result = service.GetTelephoneListAsync(null!, 1, service._maxPageSize + 1).Result;

			// Assert
			Assert.True(result.Success);
			Assert.True(result.Data!.Items.Count <= service._maxPageSize);
		}
	}
}
