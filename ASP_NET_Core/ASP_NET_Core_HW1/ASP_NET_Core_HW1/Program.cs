namespace ASP_NET_Core_HW1;

/*
 *          ������� �1
 *
 * �������� � ��������� ������� ���������� ASP.NET Core, 
 * ����������� �� ��������� ASP.NET Razor Pages.
 * � ���-�������� �������� ����� �������� ��� � ����.
 * 
 *          ������� �2
 *          
 * �������� � ��������� ������� ���������� ASP.NET Core, 
 * ����������� �� ��������� ASP.NET Razor Pages. 
 * � ���-�������� � ����������� �� ���������� �������� 
 * ����������� ����� ����� �� ����������� ��������.  
 * 
 *          ������� �3
 *          
 * �������� � ��������� ������� ���������� ASP.NET Core, 
 * ����������� �� ��������� ASP.NET Razor Pages. 
 * �������� � �������� ���������� ����� ��������. 
 * �������� ������ ���������� ���������� � ���������. 
 * ������ � �������� �� ������ � ������� ���� ��������. 
 * 
 *          ������� �4
 *          
 * �������� � ������� 3 ����������� ������ ����������. 
 * ����������� ����������� CSS ��� �������������� ������.   
 * 
 *          ������� �5
 *          
 * �������� � ��������� ������� ���������� ASP.NET Core, 
 * ����������� �� ��������� ASP.NET Razor Pages. 
 * �������� � �������� ���������� ����� ��������. 
 * �������� ������ ���������� ���������� � �������. 
 * ������ � �������� �� ������ � ������� ���� ��������. 
 * ����������� ����������� CSS ��� �������������� ������.
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