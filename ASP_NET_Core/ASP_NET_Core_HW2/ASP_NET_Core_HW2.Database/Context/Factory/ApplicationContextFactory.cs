namespace ASP_NET_Core_HW2.Database.Context.Factory;

public class ApplicationContextFactory : IApplicationContextFactory
{
    private static readonly ApplicationContext Context = new();

    public ApplicationContext Create()
    {
        return Context;
    }
}