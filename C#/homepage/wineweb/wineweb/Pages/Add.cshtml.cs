using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using wineweb.Data;
using wineweb.Models;

namespace wineweb.Pages
{
    [Authorize]
    public class AddModel : PageModel
    {
        [BindProperty]
        public Wine NewWine { get; set; }
        public void OnGet()
        {
        }
        public IActionResult OnPost() {
            if (!ModelState.IsValid)
                return Page();
            WineData.wines.Add(NewWine);
            return RedirectToPage("Portfolio");
        }
    }
}
