using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;

namespace Lab_2.KDC.Controllers
{  
    [Route("api/[controller]")]
    [ApiController]
    public class ASController : Controller
    {
        string keyC = "C";
        string keyCTGS = "CTGS";
        string keyASTGS = "ASTGS";
        Guid TGSID = new Guid("2d1300f6-26e6-4c45-9f68-2f1e4f88f7fb");
        int expirationTimeDays = 5;

        [HttpGet("get-connect")]
        public async Task<IActionResult> GetConnect([FromQuery] Guid clientId)
        {
            DESEncoder encoderC = new DESEncoder(keyC);
            DESEncoder encoderCTGS = new DESEncoder(keyCTGS);
            DESEncoder encoderASTGS = new DESEncoder(keyASTGS);

            var jsonTGT = new JObject();
            var outJson = new JObject();

            jsonTGT["client"] = clientId;
            jsonTGT["tgs"] = TGSID;
            jsonTGT["time"] = DateTime.Now;
            jsonTGT["expiration_time"] = DateTime.Now.AddDays(expirationTimeDays);
            jsonTGT["c_tgs"] = keyCTGS;

            outJson["tgt"] = encoderASTGS.Encrypt(JsonConvert.SerializeObject(jsonTGT));
            outJson["c_tgs"] = keyCTGS;
            var f = encoderC.Encrypt(JsonConvert.SerializeObject(outJson));
            return Ok(encoderC.Encrypt(JsonConvert.SerializeObject(outJson)));
        }
    }
}
