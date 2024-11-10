using Game2048.Entities;

namespace Game2048.Views.GameWindow.Logic;

public interface IGameWindowProvider
{
	void Show(User user);
	void CloseIfCreated();
}