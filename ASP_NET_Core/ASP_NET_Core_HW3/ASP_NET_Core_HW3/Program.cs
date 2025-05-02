namespace ASP_NET_Core_HW3;

/*
 *          ������� �1
 *
 * �������� � ������ ������� ���������� ����������� ������ ������. 
 * ���������� ������ ��: 
 * - �������� ������; 
 * - ���������; 
 * - �����; 
 * - �������� ��������; 
 * - ������ �������. 
 * ������ �����, ��� �� �����, ��� � �� ������� ��������. 
 * ����� ������ ���������� ������������ ������������� ����������� ����������� ���� ������� � ����������.
 * 
 *          ������� �2
 *          
 * �������� � ������ ������� ���������� ����������� �������������� ������. 
 * �������������� ������ ������������ ����� �����. 
 * ���� ����� ������ ���� ��������� ����������� � ������. 
 * ����� ��������� �������������� ����� �������� ��� ������ � ����������. 
 * 
 *          ������� �3
 *          
 * �������� � ������ ������� ���������� ����������� ���������� ������. 
 * ���������� ������ ������������ ����� �����. 
 * ����� ��������� ���������� ����� �������� ��� ������ � ����������.
 * 
 *          ������� �4
 *          
 * �������� � ������ ������� ���������� ����������� �������� ������. 
 * ����� ��������� ����� �������� � ������������, ������������� �� �� ����� ��������� ��������. 
 * ����� ��������� �������� ����� �������� ��� ������ � ����������.   
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