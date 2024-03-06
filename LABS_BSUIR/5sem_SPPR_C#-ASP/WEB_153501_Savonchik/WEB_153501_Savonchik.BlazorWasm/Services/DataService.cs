using System.Net.Http.Headers;
using System.Net.Http.Json;
using System.Text;
using System.Text.Json;
using Microsoft.AspNetCore.Components.WebAssembly.Authentication;
using Microsoft.AspNetCore.Http;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;


namespace WEB_153501_Savonchik.BlazorWasm.Services
{
    public class DataService : IDataService
    {
        public event Action DataChanged;
        private readonly HttpClient _httpClient;
        private readonly IAccessTokenProvider _accessTokenProvider;
        private readonly ILogger<DataService> _logger;
        private readonly int _pageSize = 3;
        private readonly JsonSerializerOptions _jsonSerializerOptions;

        public DataService(HttpClient httpClient, IConfiguration configuration, IAccessTokenProvider accessTokenProvider, ILogger<DataService> logger)
        {
            _httpClient = httpClient;
            _accessTokenProvider = accessTokenProvider;
            _logger = logger;
            _pageSize = configuration.GetSection("PageSize").Get<int>();
            _jsonSerializerOptions = new JsonSerializerOptions()
            {
                PropertyNamingPolicy = JsonNamingPolicy.CamelCase
            };
        }

        public List<Firm>? Categories { get; set; }
        public List<Telephone>? TelephoneList { get; set; }
        public bool Success { get; set; } = true;
        public string? ErrorMessage { get; set; }
        public int TotalPages { get; set; }
        public int CurrentPage { get; set; }

        public async Task GetTelephoneListAsync(string? categoryNormalizedName, int pageNo = 1)
        {
            var tokenRequest = await _accessTokenProvider.RequestAccessToken();
            if (tokenRequest.TryGetToken(out var token))
            {
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", token.Value);
                var urlString = new StringBuilder($"{_httpClient.BaseAddress!.AbsoluteUri}api/Telephone/");
                if (categoryNormalizedName != null)
                {
                    urlString.Append($"{categoryNormalizedName}/");
                };
                if (pageNo > 1)
                {
                    urlString.Append($"page{pageNo}");
                };
                if (!_pageSize.Equals("3"))
                {
                    urlString.Append(QueryString.Create("pageSize", _pageSize.ToString()));
                }

                var response = await _httpClient.GetAsync(new Uri(urlString.ToString()));
                if (response.IsSuccessStatusCode)
                {
                    try
                    {
                        var responseData = await response.Content.ReadFromJsonAsync<ResponseData<ListModel<Telephone>>>(_jsonSerializerOptions);
                        TelephoneList = responseData?.Data?.Items;
                        TotalPages = responseData?.Data?.TotalPages ?? 0;
                        CurrentPage = responseData?.Data?.CurrentPage ?? 0;
                        DataChanged?.Invoke();
                        _logger.LogInformation("<------ Telephone list received successfully ------>");
                    }
                    catch (JsonException ex)
                    {
                        Success = false;
                        ErrorMessage = $"Ошибка: {ex.Message}";
                    }
                }
                else
                {
                    Success = false;
                    ErrorMessage = $"Данные не получены от сервера. Error:{response.StatusCode}";
                }
            }
        }

        public async Task<Telephone?> GetTelephoneByIdAsync(int id)
        {
            var tokenRequest = await _accessTokenProvider.RequestAccessToken();
            if (tokenRequest.TryGetToken(out var token))
            {
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", token.Value);
                var urlString = new StringBuilder($"{_httpClient.BaseAddress!.AbsoluteUri}api/Telephone/{id}");
                var response = await _httpClient.GetAsync(new Uri(urlString.ToString()));
                if (response.IsSuccessStatusCode)
                {
                    try
                    {
                        return (await response.Content.ReadFromJsonAsync<ResponseData<Telephone>>(_jsonSerializerOptions))?.Data;
                    }
                    catch (JsonException ex)
                    {
                        Success = false;
                        ErrorMessage = $"Ошибка: {ex.Message}";
                        return null;
                    }
                }
                Success = false;
                ErrorMessage = $"Данные не получены от сервера. Error:{response.StatusCode}";
            }
            return null;
        }

        public async Task GetFirmListAsync()
        {
            var tokenRequest = await _accessTokenProvider.RequestAccessToken();
            if (tokenRequest.TryGetToken(out var token))
            {
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", token.Value);
                var urlString = new StringBuilder($"{_httpClient.BaseAddress?.AbsoluteUri}api/TelephoneCategories/");
                var response = await _httpClient.GetAsync(new Uri(urlString.ToString()));
                if (response.IsSuccessStatusCode)
                {
                    try
                    {
                        var responseData = await response.Content.ReadFromJsonAsync<ResponseData<List<Firm>>>(_jsonSerializerOptions);
                        Categories = responseData?.Data;
                    }
                    catch (JsonException ex)
                    {
                        Success = false;
                        ErrorMessage = $"Ошибка: {ex.Message}";
                    }
                }
                else
                {
                    Success = false;
                    ErrorMessage = $"Данные не получены от сервера. Error:{response.StatusCode}";
                }
            }
        }
    }
}
