using IdentityModel;
using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using Serilog;
using System.Security.Claims;
using WEB_153501_Savonchik.IdentityServer.Data;
using WEB_153501_Savonchik.IdentityServer.Models;

namespace WEB_153501_Savonchik.IdentityServer
{
    public class SeedData
    {
        public static void EnsureSeedData(WebApplication app)
        {
            using (var scope = app.Services.GetRequiredService<IServiceScopeFactory>().CreateScope())
            {
                var context = scope.ServiceProvider.GetService<ApplicationDbContext>();
                context.Database.Migrate();

                var userMgr = scope.ServiceProvider.GetRequiredService<UserManager<ApplicationUser>>();
                var roleMgr = scope.ServiceProvider.GetRequiredService<RoleManager<IdentityRole>>();

                List<string> roles = new()
                {
                    "admin",
                    "user"
                };

                foreach (var role in roles)
                {
                    roleMgr.CreateAsync(new IdentityRole(role));
                }

                var alice = userMgr.FindByNameAsync("alice").Result;
                if (alice == null)
                {
                    alice = new ApplicationUser
                    {
                        UserName = "alice",
                        Email = "AliceSmith@email.com",
                        EmailConfirmed = true,
                    };
                    var result = userMgr.CreateAsync(alice, "Pass123$").Result;
                    if (!result.Succeeded)
                    {
                        throw new Exception(result.Errors.First().Description);
                    }

                    result = userMgr.AddClaimsAsync(alice, new Claim[]{
                            new Claim(JwtClaimTypes.Name, "Alice Smith"),
                            new Claim(JwtClaimTypes.GivenName, "Alice"),
                            new Claim(JwtClaimTypes.FamilyName, "Smith"),
                            new Claim(JwtClaimTypes.WebSite, "http://alice.com"),
                        }).Result;
                    if (!result.Succeeded)
                    {
                        throw new Exception(result.Errors.First().Description);
                    }
                    Log.Debug("alice created");
                }
                else
                {
                    Log.Debug("alice already exists");
                }

                var bob = userMgr.FindByNameAsync("bob").Result;
                if (bob == null)
                {
                    bob = new ApplicationUser
                    {
                        UserName = "bob",
                        Email = "BobSmith@email.com",
                        EmailConfirmed = true
                    };
                    var result = userMgr.CreateAsync(bob, "Pass123$").Result;
                    if (!result.Succeeded)
                    {
                        throw new Exception(result.Errors.First().Description);
                    }

                    result = userMgr.AddClaimsAsync(bob, new Claim[]{
                            new Claim(JwtClaimTypes.Name, "Bob Smith"),
                            new Claim(JwtClaimTypes.GivenName, "Bob"),
                            new Claim(JwtClaimTypes.FamilyName, "Smith"),
                            new Claim(JwtClaimTypes.WebSite, "http://bob.com"),
                            new Claim("location", "somewhere")
                        }).Result;
                    if (!result.Succeeded)
                    {
                        throw new Exception(result.Errors.First().Description);
                    }
                    Log.Debug("bob created");
                }
                else
                {
                    Log.Debug("bob already exists");
                }

                var admin = userMgr.FindByNameAsync("admin").Result;
                if (admin == null)
                {
                    admin = new ApplicationUser
                    {
                        UserName = "admin",
                        Email = "admin@email.com",
                        EmailConfirmed = true
                    };
                    var result = userMgr.CreateAsync(admin, "Admin123$").Result;
                    if (!result.Succeeded)
                    {
                        throw new Exception(result.Errors.First().Description);
                    }
                    
                    result = userMgr.AddClaimsAsync(admin, new Claim[]{
                            new Claim(JwtClaimTypes.Name, "admin"),
                            new Claim(JwtClaimTypes.GivenName, "admin"),
                            new Claim(JwtClaimTypes.FamilyName, "admin"),
                        }).Result;

                    if (!result.Succeeded)
                    {
                        throw new Exception(result.Errors.First().Description);
                    }

                    // добавление роли
                    userMgr.AddToRoleAsync(admin, "admin");

                    Log.Debug("admin created");
                }
                else
                {
                    Log.Debug("admin already exists");
                }

                var user = userMgr.FindByNameAsync("user").Result;
                if (user == null)
                {
                    user = new ApplicationUser
                    {
                        UserName = "user",
                        Email = "user@email.com",
                        EmailConfirmed = true,
                    };
                    var result = userMgr.CreateAsync(user, "User123$").Result;
                    if (!result.Succeeded)
                    {
                        throw new Exception(result.Errors.First().Description);
                    }

                    result = userMgr.AddClaimsAsync(user, new Claim[]{
                            new Claim(JwtClaimTypes.Name, "user"),
                            new Claim(JwtClaimTypes.GivenName, "user"),
                            new Claim(JwtClaimTypes.FamilyName, "user"),
                        }).Result;

                    if (!result.Succeeded)
                    {
                        throw new Exception(result.Errors.First().Description);
                    }

                    // добавление роли
                    userMgr.AddToRoleAsync(user, "user");

                    Log.Debug("user created");
                }
                else
                {
                    Log.Debug("user already exists");
                }
            }
        }
    }
}