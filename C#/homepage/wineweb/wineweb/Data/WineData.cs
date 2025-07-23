using wineweb.Models;

namespace wineweb.Data
{
    public class WineData //DB 대체 임시 저장소
    {
        public static List<Wine> wines { get; set; } = new List<Wine> {
            new Wine{
                Name = "Chardonnay",
                Type = "white",
                Description = "Fresh and fruity white wine.",
                ImageUrl = "/images/chardonnay",
                Country = "France"
            },

            new Wine{
                Name = "Cabernet Sauvinon",
                Type = "Red",
                Description = "Full=bodied",
                ImageUrl = "/images/cabernet",
                Country = "USA"
            }
        };
    }
}
