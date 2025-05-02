namespace ASP_NET_Core_HW3;

/*
 *          Задание №1
 *
 * Добавьте к вашему проекту кинотеатра возможность поиска данных. 
 * Необходимо искать по: 
 * - Названию фильма; 
 * - Режиссеру; 
 * - Стилю; 
 * - Краткому описанию; 
 * - Списку сеансов. 
 * Искать нужно, как по части, так и по полному названию. 
 * После поиска необходимо пользователю предоставлять возможность отображения всех сеансов в кинотеатре.
 * 
 *          Задание №2
 *          
 * Добавьте к вашему проекту кинотеатра возможность редактирования данных. 
 * Редактирование данных производится через форму. 
 * Поля формы должны быть заполнены информацией о фильме. 
 * После успешного редактирования нужно показать все сеансы в кинотеатре. 
 * 
 *          Задание №3
 *          
 * Добавьте к вашему проекту кинотеатра возможность добавления данных. 
 * Добавление данных производится через форму. 
 * После успешного добавления нужно показать все сеансы в кинотеатре.
 * 
 *          Задание №4
 *          
 * Добавьте к вашему проекту кинотеатра возможность удаления данных. 
 * Перед удалением нужно уточнять у пользователя, действительно ли он хочет выполнить операцию. 
 * После успешного удаления нужно показать все сеансы в кинотеатре.   
 * 
 */

public static class Program
{
    public static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);

        builder.Services.AddControllersWithViews();

        builder.Services.AddControllersWithViews()
            .AddViewOptions(options =>
            {
                options.HtmlHelperOptions.ClientValidationEnabled = true;
            });

        AspNetExampleModule.RegisterDependencies(builder.Services, builder.Configuration);

        var app = builder.Build();

        if (!app.Environment.IsDevelopment())
        {
            app.UseExceptionHandler("/Home/Error");
        }
        app.UseStaticFiles();

        app.UseRouting();

        app.UseAuthorization();

        app.MapControllerRoute(
            name: "default",
            pattern: "{controller=Home}/{action=Index}/{id?}");

        app.Run();
    }
}