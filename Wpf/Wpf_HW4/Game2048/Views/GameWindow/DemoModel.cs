using GalaSoft.MvvmLight.Messaging;

namespace Game2048.Views.GameWindow;

public class DemoModel : GameViewModel
{
	public DemoModel() : base(Messenger.Default, null)
	{
	}
}