using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.StaticFiles;
using WEB_153501_Savonchik.IdentityServer.Models;

namespace WEB_153501_Savonchik.IdentityServer.Controllers
{
    [Authorize]
    [Route("[controller]")]
    [ApiController]
    public class AvatarController : ControllerBase
    {
        private readonly IWebHostEnvironment _environment;
        private readonly FileExtensionContentTypeProvider _contentTypeProvider;
        private readonly UserManager<ApplicationUser> _userManager;


        public AvatarController(IWebHostEnvironment webHostEnvironment, UserManager<ApplicationUser> userManager)
        {
            _environment = webHostEnvironment;
            _contentTypeProvider = new FileExtensionContentTypeProvider();
            _userManager = userManager;
        }

        [HttpGet]
        public IActionResult Index()
        {
            var imageName = _userManager.GetUserId(User);
            var imageDirectory = Path.Combine(_environment.WebRootPath, "Images");

            
            var imagePath = Directory.EnumerateFiles(imageDirectory)
                                .FirstOrDefault(file => Path.GetFileNameWithoutExtension(file) == imageName);

            if (imagePath == null)
            {
                imagePath = Path.Combine(imageDirectory, "profile-icon.png"); // Если изображение не найдено
            }

            var contentType = "image/png"; // MIME-тип по умолчанию

            // Попробуйте получить MIME-тип с помощью FileExtensionContentTypeProvider
            if (_contentTypeProvider.TryGetContentType(imagePath, out var discoveredContentType))
            {
                contentType = discoveredContentType;
            }

            var image = System.IO.File.OpenRead(imagePath);

            return File(image, contentType);
        }
    }
}
