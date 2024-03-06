using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace Lab_2.SS.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class SSController : Controller
    {
        static Guid SsId = new Guid("4d1300f6-26e6-4c45-9f68-2f1e4f88f7fb");
        string keyTGS_SS = "TGS_SS";

        [HttpGet("get-connect")]
        public async Task<IActionResult> GetConnect([FromQuery] string request)
        {
            DESEncoder encoderTGS_SS = new DESEncoder(keyTGS_SS);

            dynamic requestJson = JsonConvert.DeserializeObject(request);

            dynamic ticket = JsonConvert.DeserializeObject(encoderTGS_SS.Decrypt((string)requestJson["ticket"]));
            DESEncoder encoderC_Ss = new DESEncoder((string) ticket["c_ss"]);

            var aut = JsonConvert.DeserializeObject(encoderC_Ss.Decrypt(requestJson["aut"]));


            if ((string) aut["client"] == ticket["client"] && DateTime.Parse(ticket["expiration_time"]) > DateTime.Parse((string) aut["time"]))
            {
                var responseJson = new JObject();
                responseJson["time"] = DateTime.Parse((string) aut["time"]).AddDays(1);

                return Ok(encoderC_Ss.Encrypt(JsonConvert.SerializeObject(responseJson)));
            }
            else
            {
                return BadRequest();
            }
        }
    }
}
