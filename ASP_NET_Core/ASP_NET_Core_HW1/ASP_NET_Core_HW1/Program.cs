namespace ASP_NET_Core_HW1;

/*
 *          Задание №1
 *
 * Создайте и запустите базовое приложение ASP.NET Core, 
 * построенное на основании ASP.NET Razor Pages.
 * В веб-странице выведите номер текущего дня в году.
 * 
 *          Задание №2
 *          
 * Создайте и запустите базовое приложение ASP.NET Core, 
 * построенное на основании ASP.NET Razor Pages. 
 * В веб-странице в зависимости от случайного значения 
 * отображайте любую букву из английского алфавита.  
 * 
 *          Задание №3
 *          
 * Создайте и запустите базовое приложение ASP.NET Core, 
 * построенное на основании ASP.NET Razor Pages. 
 * Добавьте к базовому приложению новую страницу. 
 * Страница должна отображать информацию о ресторане. 
 * Доступ к странице по ссылке в верхнем меню страницы. 
 * 
 *          Задание №4
 *          
 * Добавьте к заданию 3 отображение списка ресторанов. 
 * Используйте возможности CSS для форматирования списка.   
 * 
 *          Задание №5
 *          
 * Создайте и запустите базовое приложение ASP.NET Core, 
 * построенное на основании ASP.NET Razor Pages. 
 * Добавьте к базовому приложению новую страницу. 
 * Страница должна отображать информацию о странах. 
 * Доступ к странице по ссылке в верхнем меню страницы. 
 * Используйте возможности CSS для форматирования списка.
 * 
 */

public class Program
{
    public static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);

        // Add services to the container.
        builder.Services.AddControllersWithViews();

        var app = builder.Build();

        // Configure the HTTP request pipeline.
        if (!app.Environment.IsDevelopment())
        {
            app.UseExceptionHandler("/Home/Error");
        }
        app.UseStaticFiles();

        app.UseRouting();

        app.UseAuthorization();

        app.MapControllerRoute(
            name: "default",
            pattern: "{controller=Home}/{action=Task1}/{id?}");

        app.Run();
    }
}