using ASP_NET_Core_HW2.Database.Context.Factory;

namespace ASP_NET_Core_HW2;

public class AspNetExampleModule
{
    public static void RegisterDependencies(IServiceCollection service, ConfigurationManager configuration)
    {
        var connectionString = configuration.GetConnectionString("DefaultConnection")!;

        service.AddSingleton<IApplicationContextFactory, ApplicationContextFactory>();
    }
}