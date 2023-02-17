using lab_1.Entities;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Text.Json;
using Newtonsoft.Json;

namespace lab_1.Services
{
    public class RateService : IRateService
    {
        public HttpClient httpClient { get; set; }
        JsonSerializerOptions serializerOptions ;
        public RateService()
        {
            this.httpClient = new HttpClient();

            this.serializerOptions = new JsonSerializerOptions
            {
                PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
                WriteIndented = true
            };
        }

        public RateService(HttpClient httpClient) 
        {
            this.httpClient = httpClient;

            serializerOptions = new JsonSerializerOptions
            {
                PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
                WriteIndented = true
            };
        }

        public IEnumerable<Rate> GetRates(DateTime date)
        {
            IEnumerable<Rate> result = new List<Rate>();

            Uri uri = new Uri("https://www.nbrb.by/api/exrates/rates" + "?ondate=" + date.ToString("yyyy-MM-dd") + "&periodicity=0");

            HttpResponseMessage response = httpClient.GetAsync(uri).Result;

            if (response.IsSuccessStatusCode)
            {
                string content = response.Content.ReadAsStringAsync().Result;
                result = JsonConvert.DeserializeObject<IEnumerable<Rate>>(content);
            }
            
            return result;
        }
    }
}
