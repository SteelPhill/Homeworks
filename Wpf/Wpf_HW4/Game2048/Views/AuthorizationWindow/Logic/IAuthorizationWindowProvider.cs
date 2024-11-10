namespace Game2048.Views.MainWindow.Logic;

public interface IAuthorizationWindowProvider
{
	void Show();
	void CloseIfCreated();
}