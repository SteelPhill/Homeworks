using System.ComponentModel;
using System.Windows;
using Game2048.Dispatcher;
using Game2048.Services.View;
using Game2048.Views.AuthorizationWindow;

namespace Game2048.Views.MainWindow.Logic;

public class AuthorizationWindowProvider : IAuthorizationWindowProvider
{
	private readonly IViewService _viewService;
	private readonly IDispatcherHelper _dispatcherHelper;

	private Window _authorizationWindow;

	public AuthorizationWindowProvider(
		IViewService viewService,
		IDispatcherHelper dispatcherHelper)
	{
		_viewService = viewService;
		_dispatcherHelper = dispatcherHelper;
	}

	public void Show()
	{
		_dispatcherHelper.CheckBeginInvokeOnUI(() =>
		{
			_authorizationWindow ??= CreateWindow();
			Application.Current.MainWindow = _authorizationWindow;
			_authorizationWindow.Show();
		});
	}

	public void CloseIfCreated()
	{
		_dispatcherHelper.CheckBeginInvokeOnUI(() => _authorizationWindow?.Close());
	}

	private Window CreateWindow()
	{
		var window = _viewService.CreateWindow<AuthorizationViewModel>(WindowMode.Main);
		window.Closing += OnWindowClosing;
		return window;
	}

	private void OnWindowClosing(object sender, CancelEventArgs e)
	{
		_authorizationWindow.Closing -= OnWindowClosing;
		_authorizationWindow = null;
	}
}