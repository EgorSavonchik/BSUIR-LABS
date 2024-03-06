using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections;
using System.Text;
using System.Text.Json.Nodes;

namespace Lab_2
{
    internal class Program
    {
        static string keyC = "C";
        static string keyCTGS = "CTGS";
        static string ASUrl = "https://localhost:7152/api/AS";
        static string TGSUrl = "https://localhost:7152/api/TGS";
        static string SSUrl = "https://localhost:7106/api/SS";
        static Guid clientId = new Guid("1d1300f6-26e6-4c45-9f68-2f1e4f88f7fb");
        static Guid serverId = new Guid("4d1300f6-26e6-4c45-9f68-2f1e4f88f7fb");

        static async Task Main(string[] args)
        {
            DESEncoder encoderC = new DESEncoder(keyC);
            DESEncoder encoderCTGS = new DESEncoder(keyCTGS);

            Console.WriteLine(encoderC.Decrypt(encoderC.Encrypt("{{\r\n  \"client\": \"1d1300f6-26e6-4c45-9f68-2f1e4f88f7fb\",\r\n  \"tgs\": \"2d1300f6-26e6-4c45-9f68-2f1e4f88f7fb\",\r\n  \"time\": \"2024-02-19T00:30:18.9395433+03:00\",\r\n  \"expiration_time\": \"2024-02-24T00:30:18.9398818+03:00\",\r\n  \"c_tgs\": \"CTGS\"\r\n}}")));
            
            BitArray t =  encoderCTGS.MergeBitArrays(new BitArray(new int[] { 10 }), new BitArray(new int[] { 1 }), 4, 1);
            BitArray t2 = new BitArray(new bool[] {true, true, false,true});
            BitArray t3 = new BitArray(new int[] { 13 });   

            Console.WriteLine(BitArrayToString(t) + " " + BitArrayToString(encoderCTGS.SubBits(t, 2, 2)) + " " + encoderCTGS.BitArrayToInt(t));
            Console.WriteLine(BitArrayToString(t2) + " " + t2[0] + " " + encoderCTGS.BitArrayToInt(t2));
            Console.WriteLine(BitArrayToString(t3) + " " + t3[0] + " " + encoderCTGS.BitArrayToInt(t3));
            

            Console.WriteLine(encoderCTGS.Decrypt(encoderCTGS.Encrypt("2f1e")));
            Console.WriteLine(DES.Decipher(DES.Encrypt("{{\r\n  \"client\": \"1d1300f6-26e6-4c45-9f68-2f1e4f88f7fb\",\r\n  \"tgs\": \"2d1300f6-26e6-4c45-9f68-2f1e4f88f7fb\",\r\n  \"time\": \"2024-02-19T00:30:18.9395433+03:00\",\r\n  \"expiration_time\": \"2024-02-24T00:30:18.9398818+03:00\",\r\n  \"c_tgs\": \"CTGS\"\r\n}}", keyC), keyC));
            Console.WriteLine(clientId.ToString());
            /*using (var httpClient = new HttpClient())
            {
                // Добавление параметра к URL
                string urlWithParameter = $"{ASUrl + "/get-connect"}?clientId={clientId}";

                // Отправка GET-запроса
                HttpResponseMessage response = await httpClient.GetAsync(urlWithParameter);

                var t = encoderC.Decrypt(await response.Content.ReadAsStringAsync());
                dynamic responseSaJson = JsonConvert.DeserializeObject(encoderC.Decrypt(await response.Content.ReadAsStringAsync()));

                Console.WriteLine((string)responseSaJson["tgt"] + "   " + (string) responseSaJson["c_tgs"]);

                DESEncoder encoderCTgs = new DESEncoder((string)responseSaJson["c_tgs"]);

                var jsonTicket = new JObject();
                var autJson = new JObject();

                autJson["client"] = clientId;
                autJson["time"] = DateTime.Now;

                jsonTicket["tgt"] = responseSaJson["tgt"];
                jsonTicket["aut"] = encoderCTgs.Encrypt(JsonConvert.SerializeObject(autJson));
                jsonTicket["SS_id"] = serverId;



                urlWithParameter = $"{TGSUrl + "/verify-ticket"}?ticket={JsonConvert.SerializeObject(jsonTicket)}";
                HttpResponseMessage responseTgs = await httpClient.GetAsync(urlWithParameter);
                Console.WriteLine(responseTgs);
                dynamic responseTgsJson = JsonConvert.DeserializeObject(encoderCTGS.Decrypt(await responseTgs.Content.ReadAsStringAsync()));

                DESEncoder encoderCSs = new DESEncoder((string) responseSaJson["c_ss"]);

                var jsonRequest = new JObject();
                var autJson2 = new JObject();

                autJson2["client"] = clientId;
                autJson2["time"] = DateTime.Now;

                jsonRequest["ticket"] = (string) responseTgsJson["ticket"];
                jsonRequest["aut"] = encoderCSs.Encrypt(JsonConvert.SerializeObject((string) autJson2));

                urlWithParameter = $"{SSUrl + "/get-connect"}?request={JsonConvert.SerializeObject(jsonRequest)}";
                HttpResponseMessage responseSs = await httpClient.GetAsync(urlWithParameter);

                dynamic responseSsJson = JsonConvert.DeserializeObject(encoderCSs.Decrypt(await responseSs.Content.ReadAsStringAsync()));
                Console.WriteLine((string) responseSsJson);
            }*/
        }

        public static string BitArrayToString(BitArray bitArray)
        {
            // Создаем строку для хранения битов
            char[] bits = new char[bitArray.Length];

            // Проходимся по каждому элементу BitArray
            for (int i = 0; i < bitArray.Length; i++)
            {
                // Если бит равен true, ставим '1', иначе '0'
                bits[i] = bitArray[i] ? '1' : '0';
            }

            // Преобразуем массив символов в строку и возвращаем её
            return new string(bits);
        }
    }
}