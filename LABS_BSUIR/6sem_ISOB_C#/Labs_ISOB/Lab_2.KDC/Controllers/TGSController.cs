using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Text;

namespace Lab_2.KDC.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class TGSController : Controller
    {
        string keyASTGS = "ASTGS";
        Guid TGSID = new Guid("3d1300f6-26e6-4c45-9f68-2f1e4f88f7fb");
        int expirationTimeDays = 5;
        string keyTGS_SS = "TGS_SS";
        string keyC_SS = "C_SS";

        [HttpGet("verify-ticket")]
        public async Task<IActionResult> VerifyTicket([FromQuery] string ticket)
        {
            DESEncoder encoderASTGS = new DESEncoder(keyASTGS);
            DESEncoder encoderTGS_SS = new DESEncoder(keyTGS_SS);

            dynamic requestJson = JsonConvert.DeserializeObject(ticket);
            var dp = requestJson["tgt"];
            var q = encoderASTGS.Decrypt((string)dp);
            dynamic tgt = JsonConvert.DeserializeObject(encoderASTGS.Decrypt((string)requestJson["tgt"]));
            DESEncoder encoderCTGS = new DESEncoder(tgt["c_tgs"]);
            
            dynamic aut = JsonConvert.DeserializeObject(encoderCTGS.Decrypt((string)requestJson["aut"]));


            var a = aut["client"];
            var b = tgt["client"];
            var c = DateTime.Parse(tgt["expiration_time"]);
            var d = DateTime.Parse(aut["time"]);
            if (aut["client"] == tgt["client"] && DateTime.Parse(tgt["expiration_time"]) > DateTime.Parse(aut["time"])) 
            {
                var outTicket = new JObject();
                var response = new JObject();

                outTicket["client"] = (string) tgt["client"];
                outTicket["SS_id"] = (string) requestJson["SS_id"];
                outTicket["time"] = DateTime.Now;
                outTicket["expiration_time"] = DateTime.Now.AddDays(expirationTimeDays);
                outTicket["c_ss"] = keyC_SS;

                response["ticket"] = encoderTGS_SS.Encrypt(JsonConvert.SerializeObject(outTicket));
                response["c_ss"] = keyC_SS;

                return Ok(encoderCTGS.Encrypt(JsonConvert.SerializeObject(response)));
            }
            else
            {
                return BadRequest();
            }
            
        }
    }
}
