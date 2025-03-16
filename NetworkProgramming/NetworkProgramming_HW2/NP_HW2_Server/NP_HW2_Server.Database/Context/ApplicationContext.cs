using NP_HW2_Server.Domain.Entities;
using System.IO;

namespace NP_HW2_Server.Database.Context;

public class ApplicationContext : IApplicationContext
{
    public List<Recipe> Recipes { get; private set; }

    public ApplicationContext()
    {
        Recipes =
        [
            new Recipe()
            {
                Name = "Греческий салат",
                Ingredients =
                [
                    "Помидор",
                    "Сладкий перец",
                    "Огурец",
                    "Фета",
                    "Маслины",
                    "Оливковое масло",
                    "Соль"
                ],
                ImageBytes = File.ReadAllBytes(Path.Combine(Directory.GetCurrentDirectory(), "pics", "GreekSalad.jpg"))
            },
            new Recipe()
            {
                Name = "Борщ",
                Ingredients =
                [
                    "Картофель",
                    "Капуста",
                    "Морковь",
                    "Зелень",
                    "Свекла",
                    "Мясной бульон",
                    "Соль"
                ],
                ImageBytes = File.ReadAllBytes(Path.Combine(Directory.GetCurrentDirectory(), "pics", "Borsch.jpg"))
            },
            new Recipe()
            {
                Name = "Шаурма",
                Ingredients =
                [
                    "Лаваш",
                    "Помидор",
                    "Огурец",
                    "Мясо",
                    "Лук",
                    "Соус",
                    "Зелень",
                    "Соль"
                ],
                ImageBytes = File.ReadAllBytes(Path.Combine(Directory.GetCurrentDirectory(), "pics", "Shawarma.jpg"))
            }
        ];
    }
}