namespace WEB_153501_Savonchik.Extensions
{
	public static class RequestExtensions
	{
		public static bool IsAjaxRequest(this HttpRequest request)
		{
			return request.Headers.ContainsKey("X-Requested-With")
				&& request.Headers["X-Requested-With"] == "XMLHttpRequest";
		}
	}
}
