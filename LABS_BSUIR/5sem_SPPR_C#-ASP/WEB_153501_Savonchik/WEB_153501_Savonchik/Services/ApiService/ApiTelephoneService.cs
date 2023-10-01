using Microsoft.AspNetCore.Http;
using System.Net.Http;
using System.Text;
using System.Text.Json;
using WEB_153501_Savonchik.Controllers;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;
using WEB_153501_Savonchik.Services.TelephoneService;

namespace WEB_153501_Savonchik.Services.ApiService
{
    public class ApiTelephoneService : ITelephoneService
    {
        HttpClient _httpClient;
        string _pageSize;
        JsonSerializerOptions _serializerOptions;
        ILogger _logger;

        public ApiTelephoneService(HttpClient httpClient, IConfiguration configuration, ILogger<ApiTelephoneService> logger)
        {
            _httpClient = httpClient;
            _pageSize = configuration.GetSection("ItemsPerPage").Value;
            _serializerOptions = new JsonSerializerOptions()
            {
                PropertyNamingPolicy = JsonNamingPolicy.CamelCase
            };
            _logger = logger;
        }


        public async Task<ResponseData<ListModel<Telephone>>> GetTelephoneListAsync(string? categoryNormalizedName, int pageNo = 1)
        {
            // подготовка URL запроса
            var urlString = new StringBuilder($"{_httpClient.BaseAddress.AbsoluteUri}telephones/");
            // добавить категорию в маршрут
            if (categoryNormalizedName != null)
            {
                urlString.Append($"{categoryNormalizedName}/");
            };
            // добавить номер страницы в маршрут
            if (pageNo > 1)
            {
                urlString.Append($"page{pageNo}");
            };
            // добавить размер страницы в строку запроса
            if (!_pageSize.Equals("3"))
            {
                urlString.Append(QueryString.Create("pageSize", _pageSize));
            }
            // отправить запрос к API
            var response = await _httpClient.GetAsync(new Uri(urlString.ToString()));

            if (response.IsSuccessStatusCode)
            {
                try
                {
                    return await response.Content.ReadFromJsonAsync<ResponseData<ListModel<Telephone>>>(_serializerOptions);
                }
                catch (JsonException ex)
                {
                    _logger.LogError($"-----> Ошибка: {ex.Message}");
                    return new ResponseData<ListModel<Telephone>>
                    {
                        Success = false,
                        ErrorMessage = $"Ошибка: {ex.Message}"
                    };
                }
            }

            _logger.LogError($"-----> Данные не получены от сервера. Error: { response.StatusCode.ToString()}");

            return new ResponseData<ListModel<Telephone>>
            {
                Success = false,
                ErrorMessage = $"Данные не получены от сервера. Error: { response.StatusCode.ToString() }"
            };
        }

        public async Task<ResponseData<Telephone>> CreateTelephoneAsync(Telephone telephone, IFormFile? formFile)
        {
            /*var urlString = new StringBuilder($"{_httpClient.BaseAddress.AbsoluteUri}telephones");
            StringContent stringContent = new StringContent(JsonSerializer.Serialize(telephone), Encoding.UTF8, "application/json");

            var response = await _httpClient.PostAsync(new Uri(urlString.ToString()), stringContent);

            if (formFile != null)
            {
                await this.SaveImageAsync((await response.Content.ReadFromJsonAsync<ResponseData<Telephone>>(_serializerOptions)).Data.Id, formFile);
            }

            return await response.Content.ReadFromJsonAsync<ResponseData<Telephone>>(_serializerOptions);*/
            var uri = new Uri(_httpClient.BaseAddress.AbsoluteUri + "telephones");

            var response = await _httpClient.PostAsJsonAsync(uri, telephone, _serializerOptions);
            
            if (response.IsSuccessStatusCode)
            {
                var data = await response.Content.ReadFromJsonAsync<ResponseData<Telephone>>(_serializerOptions);
                
                if (formFile is not null)
                {
                    await SaveImageAsync(data.Data.Id, formFile);
                }

                return data; // telephone;
            }

            _logger.LogError($"-----> object not created. Error{response.StatusCode.ToString()}");

            return new ResponseData<Telephone>
            {
                Success = false,
                ErrorMessage = $"Объект не добавлен. Error: {response.StatusCode.ToString()}"
            };
        }

        public async Task<ResponseData<Telephone>> GetTelephoneByIdAsync(int id)
        {
            var urlString = new StringBuilder($"{_httpClient.BaseAddress.AbsoluteUri}telephones/{id}");

            var response = await _httpClient.GetAsync(new Uri(urlString.ToString()));

            if (response.IsSuccessStatusCode)
            {
                try
                {
                    return await response.Content.ReadFromJsonAsync<ResponseData<Telephone>>(_serializerOptions);
                }
                catch (JsonException ex)
                {
                    _logger.LogError($"-----> Ошибка: {ex.Message}");

                    return new ResponseData<Telephone>
                    {
                        Success = false,
                        ErrorMessage = $"Ошибка: {ex.Message}"
                    };
                }
            }

            _logger.LogError($"-----> Данные не получены от сервера. Error: {response.StatusCode.ToString()}");

            return new ResponseData<Telephone>
            {
                Success = false,
                ErrorMessage = $"Данные не получены от сервера. Error: {response.StatusCode.ToString()}"
            };
        }

        public async Task UpdateTelephoneAsync(int id, Telephone telephone, IFormFile? formFile)
        {
            var urlString = new StringBuilder($"{_httpClient.BaseAddress.AbsoluteUri}telephones/{id}");

            StringContent stringContent = new StringContent(JsonSerializer.Serialize(telephone), Encoding.UTF8, "application/json");

            var response = await _httpClient.PutAsync(new Uri(urlString.ToString()), stringContent);

            if (formFile != null)
            {
                await this.SaveImageAsync(id, formFile);
            }
            //_logger.LogError($"-----> Данные не получены от сервера. Error: {response.StatusCode.ToString()}");
        }

        public async Task DeleteTelephoneAsync(int id)
        {
            var urlString = new StringBuilder($"{_httpClient.BaseAddress.AbsoluteUri}telephones/{id}");

            await _httpClient.DeleteAsync(new Uri(urlString.ToString()));
        }

        private async Task SaveImageAsync(int id, IFormFile image)
        {
            var request = new HttpRequestMessage
            {
                Method = HttpMethod.Post,
                RequestUri = new Uri($"{_httpClient.BaseAddress.AbsoluteUri}telephones/{id}")
            };

            var content = new MultipartFormDataContent();
            var streamContent = new StreamContent(image.OpenReadStream());

            content.Add(streamContent, "formFile", image.FileName);
            request.Content = content;

            await _httpClient.SendAsync(request);
        }
    }
}
