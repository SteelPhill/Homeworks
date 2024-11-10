using GalaSoft.MvvmLight.Messaging;

namespace Game2048.Views.AuthorizationWindow;

public class DemoModel : AuthorizationViewModel
{
	public DemoModel() : base(null, Messenger.Default, null)
	{
	}
}