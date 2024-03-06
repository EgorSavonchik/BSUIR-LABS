using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using WEB_153501_Savonchik.Util;

namespace WEB_153501_Savonchik.Controllers
{
    public class Home : Controller
    {
        // GET: Home
        public IActionResult Index()
        {
            List<ListDemo> listDemo = new List<ListDemo>
            {
                new ListDemo { Id = 1, Name = "Элемент 1" },
                new ListDemo { Id = 2, Name = "Элемент 2" },
                new ListDemo { Id = 3, Name = "Элемент 3" }
            };

            ViewData["labVersionMessage"] = "Лабораторная работа #10";

            return View(listDemo);
        }

        // GET: Home/Details/5
        public ActionResult Details(int id)
        {
            return View();
        }

        // GET: Home/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Home/Create
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create(IFormCollection collection)
        {
            try
            {
                return RedirectToAction(nameof(Index));
            }
            catch
            {
                return View();
            }
        }

        // GET: Home/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Home/Edit/5
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit(int id, IFormCollection collection)
        {
            try
            {
                return RedirectToAction(nameof(Index));
            }
            catch
            {
                return View();
            }
        }

        // GET: Home/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Home/Delete/5
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Delete(int id, IFormCollection collection)
        {
            try
            {
                return RedirectToAction(nameof(Index));
            }
            catch
            {
                return View();
            }
        }
    }
}
