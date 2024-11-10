using Game2048.Database;
using Game2048.Views.MainWindow.Logic;
using System;
using System.Windows;

namespace Game2048;

public partial class App : Application
{
    private readonly IUserDB _userDB;
    private readonly IAuthorizationWindowProvider _authorizationWindowProvider;

    public App(
        IUserDB userDB,
        IAuthorizationWindowProvider authorizationWindowProvider)
    {
        _userDB = userDB;
        _authorizationWindowProvider = authorizationWindowProvider;

        InitializeComponent();
    }

    protected override void OnStartup(StartupEventArgs e)
    {
        base.OnStartup(e);

        try
        {
            _userDB.Read();
        }
        catch (InvalidOperationException)
        {
            MessageBox.Show(Constants.FileReadingError, "Error");
            Environment.Exit(0);
        }

_authorizationWindowProvider.Show();
    }

    protected override void OnExit(ExitEventArgs e)
    {
        _userDB.Write();

        base.OnExit(e);
    }
}