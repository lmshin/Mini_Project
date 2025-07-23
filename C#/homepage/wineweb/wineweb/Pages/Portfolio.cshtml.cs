using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using wineweb.Data;
using wineweb.Models;

namespace wineweb.Pages
{
    [Authorize]
    public class PortfolioModel : PageModel
    {
        public List<Wine> Wines { get; set; }
        public void OnGet()
        {
            Wines = WineData.wines; //DB와 같은 역할
        }

        public IActionResult OnPostDelete(string name) 
        { 
            var wine = WineData.wines.FirstOrDefault(w => w.Name == name);
            if (wine != null) {
                WineData.wines.Remove(wine);
            }
            return RedirectToPage();
        }
    }
}
