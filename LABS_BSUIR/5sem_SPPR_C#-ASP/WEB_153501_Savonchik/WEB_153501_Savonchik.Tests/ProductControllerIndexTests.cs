using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Primitives;
using Moq;
using WEB_153501_Savonchik.Controllers;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;
using WEB_153501_Savonchik.Services.FirmService;
using WEB_153501_Savonchik.Services.TelephoneService;

namespace WEB_153501_Savonchik.Tests
{
	class FirmComparer : IEqualityComparer<Firm>
	{
		public bool Equals(Firm? x, Firm? y)
		{
			if (ReferenceEquals(x, y))
				return true;

			if (ReferenceEquals(x, null) || ReferenceEquals(y, null))
				return false;

			return x.Id == y.Id && x.Name == y.Name && x.NormalizedName == y.NormalizedName;
		}

		public int GetHashCode(Firm obj)
		{
			int hash = 17;
			hash = hash * 23 + obj.Id.GetHashCode();
			hash = hash * 23 + obj.Name.GetHashCode();
			hash = hash * 23 + obj.NormalizedName.GetHashCode();
			return hash;
		}
	}

	public class ProductControllerIndexTests
	{
		private List<Firm> GetSampleCategories()
		{
			return new List<Firm>() {
				new Firm() { Id = 1, Name="Samsung", NormalizedName="samsung"},
				new Firm() { Id = 2, Name="Iphone", NormalizedName="iphone"}
			};
		}

		private List<Telephone> GetSampleTelephone()
		{
			return new List<Telephone>() {
				new Telephone() { Id = 1, Price=1000, Name="Samsung1", FirmId = 1, Description = "Phone" },
				new Telephone() { Id = 2, Price=1000, Name="Iphone1", FirmId = 2, Description = "Phone" }
			};
		}

		[Fact]
		public void Index_ReturnsViewWithListOfTelephoneModel_WhenNotAjaxQuery()
		{
			//Arrange
			Mock<IFirmService> categories_moq = new();
			categories_moq.Setup(m => m.GetFirmListAsync()).ReturnsAsync(new ResponseData<List<Firm>>()
			{
				Data = GetSampleCategories()
			});

			Mock<ITelephoneService> Telephone_moq = new();
			Telephone_moq.Setup(m => m.GetTelephoneListAsync(null, 1)).ReturnsAsync(new ResponseData<ListModel<Telephone>>()
			{
				Success = true,
				ErrorMessage = null,
				Data = new ListModel<Telephone>()
				{
					Items = GetSampleTelephone()
				}
			});

			var header = new Dictionary<string, StringValues>();
			var controllerContext = new ControllerContext();
			var moqHttpContext = new Mock<HttpContext>();

			moqHttpContext.Setup(c => c.Request.Headers).Returns(new HeaderDictionary(header));
			controllerContext.HttpContext = moqHttpContext.Object;

			//Act
			var controller = new ProductController(Telephone_moq.Object, categories_moq.Object) { ControllerContext = controllerContext };
			var result = controller.Index(null, 1).Result;
			//Assert
			Assert.NotNull(result);
			var viewResult = Assert.IsType<ViewResult>(result);
			Assert.IsType<ListModel<Telephone>>(viewResult.Model);
		}

		[Fact]
		public void Index_ReturnsPartialView_WhenAjaxQuery()
		{
			//Arrange
			Mock<IFirmService> categories_moq = new();
			categories_moq.Setup(m => m.GetFirmListAsync()).ReturnsAsync(new ResponseData<List<Firm>>()
			{
				Data = new List<Firm>() {
					new Firm() { Id = 1, Name="Samsung", NormalizedName="samsung"},
					new Firm() { Id = 2, Name="Iphone", NormalizedName="iphone"}
				}
			});

			Mock<ITelephoneService> Telephone_moq = new();
			Telephone_moq.Setup(m => m.GetTelephoneListAsync(null, 1)).ReturnsAsync(new ResponseData<ListModel<Telephone>>()
			{
				Success = true,
				ErrorMessage = null,
				Data = new ListModel<Telephone>()
				{
					Items = new List<Telephone>()
					{
						new Telephone() { Id = 1, Price=1000, Name="Samsung1", FirmId = 1, Description = "Phone" },
						new Telephone() { Id = 2, Price=1000, Name="Iphone1", FirmId = 2, Description = "Phone" },
					}
				}
			});

			var header = new Dictionary<string, StringValues>()
			{
				["X-Requested-With"] = "XMLHttpRequest"
			};
			var controllerContext = new ControllerContext();
			var moqHttpContext = new Mock<HttpContext>();
			moqHttpContext.Setup(c => c.Request.Headers).Returns(new HeaderDictionary(header));
			controllerContext.HttpContext = moqHttpContext.Object;

			//Act
			var controller = new ProductController(Telephone_moq.Object, categories_moq.Object) { ControllerContext = controllerContext };
			var result = controller.Index(null, 1).Result;
			//Assert
			Assert.NotNull(result);
			var viewResult = Assert.IsType<PartialViewResult>(result);
		}

		[Fact]
		public void Index_ReturnsError404_WhenUnsuccessfullyReceivedCategories()
		{
			//Arrange
			Mock<IFirmService> categories_moq = new();
			categories_moq.Setup(m => m.GetFirmListAsync()).ReturnsAsync(new ResponseData<List<Firm>>()
			{
				Success = false
			});

			Mock<ITelephoneService> Telephone_moq = new();
			Telephone_moq.Setup(m => m.GetTelephoneListAsync(null, 1)).ReturnsAsync(new ResponseData<ListModel<Telephone>>()
			{
				Success = true
			});

			var header = new Dictionary<string, StringValues>();
			var controllerContext = new ControllerContext();
			var moqHttpContext = new Mock<HttpContext>();
			moqHttpContext.Setup(c => c.Request.Headers).Returns(new HeaderDictionary(header));
			controllerContext.HttpContext = moqHttpContext.Object;

			//Act
			var controller = new ProductController(Telephone_moq.Object, categories_moq.Object) { ControllerContext = controllerContext };
			var result = controller.Index(null, 1).Result;
			//Assert
			Assert.NotNull(result);
			var viewResult = Assert.IsType<NotFoundObjectResult>(result);
			Assert.Equal(StatusCodes.Status404NotFound, viewResult.StatusCode);
		}

		[Fact]
		public void Index_ReturnsError404_WhenUnsuccessfullyReceivedTelephone()
		{
			//Arrange
			Mock<IFirmService> categories_moq = new();
			categories_moq.Setup(m => m.GetFirmListAsync()).ReturnsAsync(new ResponseData<List<Firm>>()
			{
				Success = true
			});

			Mock<ITelephoneService> Telephone_moq = new();
			Telephone_moq.Setup(m => m.GetTelephoneListAsync(null, 1)).ReturnsAsync(new ResponseData<ListModel<Telephone>>()
			{
				Success = false
			});

			var header = new Dictionary<string, StringValues>();
			var controllerContext = new ControllerContext();
			var moqHttpContext = new Mock<HttpContext>();
			moqHttpContext.Setup(c => c.Request.Headers).Returns(new HeaderDictionary(header));
			controllerContext.HttpContext = moqHttpContext.Object;

			//Act
			var controller = new ProductController(Telephone_moq.Object, categories_moq.Object) { ControllerContext = controllerContext };
			var result = controller.Index(null, 1).Result;
			//Assert
			Assert.NotNull(result);
			var viewResult = Assert.IsType<NotFoundObjectResult>(result);
			Assert.Equal(StatusCodes.Status404NotFound, viewResult.StatusCode);
		}

		[Fact]
		public void Index_ViewDataContainsCategories_WhenSuccessfullyReceivedData()
		{
			//Arrange
			Mock<IFirmService> categories_moq = new();
			categories_moq.Setup(m => m.GetFirmListAsync()).ReturnsAsync(new ResponseData<List<Firm>>()
			{
				Data = GetSampleCategories()
			});

			Mock<ITelephoneService> Telephone_moq = new();
			Telephone_moq.Setup(m => m.GetTelephoneListAsync(null, 1)).ReturnsAsync(new ResponseData<ListModel<Telephone>>()
			{
				Success = true,
				ErrorMessage = null,
				Data = new ListModel<Telephone>()
				{
					Items = GetSampleTelephone()
				}
			});

			var header = new Dictionary<string, StringValues>();
			var controllerContext = new ControllerContext();
			var moqHttpContext = new Mock<HttpContext>();
			moqHttpContext.Setup(c => c.Request.Headers).Returns(new HeaderDictionary(header));
			controllerContext.HttpContext = moqHttpContext.Object;


			//Act
			var controller = new ProductController(Telephone_moq.Object, categories_moq.Object) { ControllerContext = controllerContext };
			var result = controller.Index(null, 1).Result;
			//Assert
			Assert.NotNull(result);
			var viewResult = Assert.IsType<ViewResult>(result);


			Assert.True(viewResult.ViewData["firms"] != null);
			Assert.Equal(GetSampleCategories(), viewResult.ViewData["firms"] as IEnumerable<Firm>, new FirmComparer());
		}

		[Fact]
		public void Index_ViewDataContainsValidCurrentCategoryValue_WhenCategoryParameterIsNotNull()
		{
			//Arrange
			Mock<IFirmService> categories_moq = new();
			categories_moq.Setup(m => m.GetFirmListAsync()).ReturnsAsync(new ResponseData<List<Firm>>()
			{
				Data = GetSampleCategories()
			});

			Mock<ITelephoneService> Telephone_moq = new();
			Telephone_moq.Setup(m => m.GetTelephoneListAsync("samsung", 1)).ReturnsAsync(new ResponseData<ListModel<Telephone>>()
			{
				Data = new ListModel<Telephone>()
				{
					Items = GetSampleTelephone()
				}
			});

			var header = new Dictionary<string, StringValues>();
			var controllerContext = new ControllerContext();
			var moqHttpContext = new Mock<HttpContext>();
			moqHttpContext.Setup(c => c.Request.Headers).Returns(new HeaderDictionary(header));
			controllerContext.HttpContext = moqHttpContext.Object;

			//Act
			var controller = new ProductController(Telephone_moq.Object, categories_moq.Object) { ControllerContext = controllerContext };
			var result = controller.Index("samsung", 1).Result;
			//Assert
			Assert.NotNull(result);
			var viewResult = Assert.IsType<ViewResult>(result);

			Assert.True(viewResult.ViewData.ContainsKey("normalizedFirmName"));
			Assert.True(viewResult.ViewData.ContainsKey("currentFirm"));
			Assert.Equal("samsung", viewResult.ViewData["normalizedFirmName"] as string);
			Assert.Equal("Samsung", viewResult.ViewData["currentFirm"] as string);
		}

		[Fact]
		public void Index_ViewDataContainsValidCurrentCategoryValue_WhenCategoryParameterIsNull()
		{
			//Arrange
			Mock<IFirmService> categories_moq = new();
			categories_moq.Setup(m => m.GetFirmListAsync()).ReturnsAsync(new ResponseData<List<Firm>>()
			{
				Data = GetSampleCategories()
			});

			Mock<ITelephoneService> Telephone_moq = new();
			Telephone_moq.Setup(m => m.GetTelephoneListAsync(null, 1)).ReturnsAsync(new ResponseData<ListModel<Telephone>>()
			{
				Data = new ListModel<Telephone>()
				{
					Items = GetSampleTelephone()
				}
			});

			var header = new Dictionary<string, StringValues>();
			var controllerContext = new ControllerContext();
			var moqHttpContext = new Mock<HttpContext>();
			moqHttpContext.Setup(c => c.Request.Headers).Returns(new HeaderDictionary(header));
			controllerContext.HttpContext = moqHttpContext.Object;

			//Act
			var controller = new ProductController(Telephone_moq.Object, categories_moq.Object) { ControllerContext = controllerContext };
			var result = controller.Index(null, 1).Result;
			//Assert
			Assert.NotNull(result);
			var viewResult = Assert.IsType<ViewResult>(result);

			Assert.True(viewResult.ViewData.ContainsKey("currentFirm"));
			Assert.True(viewResult.ViewData.ContainsKey("normalizedFirmName"));
			Assert.Equal("Все", viewResult.ViewData["currentFirm"] as string);
			Assert.Null(viewResult.ViewData["normalizedFirmName"]);
		}
	}
}
