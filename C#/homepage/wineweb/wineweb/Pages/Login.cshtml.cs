using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.Security.Claims;

public class LoginModel : PageModel
{
    public async Task<IActionResult> OnPostAsync()
    {
        var form = Request.Form;
        string id = form["username"];
        string pw = form["password"];

        // ?? 아주 단순한 관리자 계정 (DB 없이)
        if (id == "admin" && pw == "1234")
        {
            var claims = new List<Claim>
            {
                new Claim(ClaimTypes.Name, "admin")
            };
            var identity = new ClaimsIdentity(claims, "MyAuth");
            var principal = new ClaimsPrincipal(identity);

            await HttpContext.SignInAsync("MyAuth", principal);

            return RedirectToPage("/Portfolio");
        }

        return Page();
    }

    public async Task<IActionResult> OnPostLogoutAsync()
    {
        await HttpContext.SignOutAsync("MyAuth");
        return RedirectToPage("/Index");
    }

}
