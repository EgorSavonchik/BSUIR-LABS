using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.AspNetCore.Mvc.TagHelpers;
using Microsoft.AspNetCore.Mvc.ViewFeatures;
using Microsoft.AspNetCore.Razor.TagHelpers;


namespace WEB_153501_Savonchik.TagHelpers
{
	[HtmlTargetElement("pager")]
	public class PagerTagHelper : TagHelper
	{
        private readonly LinkGenerator _linkGenerator;
        private readonly IHttpContextAccessor _httpContextAccessor;
		private readonly HttpContext _httpContext;

        public PagerTagHelper(LinkGenerator linkGenerator, IHttpContextAccessor httpContextAccessor)
        {
            _linkGenerator = linkGenerator;
            _httpContextAccessor = httpContextAccessor;
			_httpContext = httpContextAccessor.HttpContext;
        }

        public int CurrentPage { get; set; }
		public int TotalPages { get; set; }
		public string? FirmName { get; set; }

		public override void Process(TagHelperContext context, TagHelperOutput output)
		{
			output.TagName = "nav";
			output.TagMode = TagMode.StartTagAndEndTag;

			var ul = new TagBuilder("ul");
			ul.AddCssClass("pagination");

			var prevLi = CreatePageItem("«", 1, true);
			ul.InnerHtml.AppendHtml(prevLi);

			if(CurrentPage == TotalPages) // добавление пред пред последней страницы, чтобы их было три
			{
                var pageLi = CreatePageItem((TotalPages - 2).ToString(), TotalPages - 2);
                ul.InnerHtml.AppendHtml(pageLi);
            }

			for (int i = (CurrentPage > 1 ? CurrentPage - 1 : 1); i <= (CurrentPage < TotalPages ? CurrentPage + 1 : TotalPages); i++)
			{
				var pageLi = CreatePageItem(i.ToString(), i);
				ul.InnerHtml.AppendHtml(pageLi);
			}

			if(CurrentPage == 1 && TotalPages >= 3) // добавление третьей страницы(при наличии) чтобы их было три
			{
                var pageLi = CreatePageItem("3", 3);
                ul.InnerHtml.AppendHtml(pageLi);
            }

			var nextLi = CreatePageItem("»", TotalPages, true);
			ul.InnerHtml.AppendHtml(nextLi);

			output.Content.AppendHtml(ul);
		}

		private TagBuilder CreatePageItem(string innerHtml, int pageNo, bool isControlElement = false)
		{
			var li = new TagBuilder("li");
			li.AddCssClass("page-item");

			var a = new TagBuilder("a");
			a.AddCssClass("page-link");
			a.InnerHtml.Append(innerHtml);

            a.Attributes["href"] =  _linkGenerator.GetPathByPage("", null, values: new { pageNo }, _httpContext.Request.Path);

            if (FirmName != null)
            {
                a.MergeAttribute("asp-route-firm", FirmName);
            }

            //a.MergeAttribute("asp-route-pageNo", pageNo.ToString());

            if (pageNo == CurrentPage && !isControlElement)
			{
				li.AddCssClass("active");
			}

			li.InnerHtml.AppendHtml(a);
			return li;
		}
	}
}

