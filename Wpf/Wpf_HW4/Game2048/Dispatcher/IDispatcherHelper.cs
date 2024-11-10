using System;
using System.Windows.Threading;

namespace Game2048.Dispatcher;

public interface IDispatcherHelper
{
	System.Windows.Threading.Dispatcher UiDispatcher { get; }

	void CheckBeginInvokeOnUI(Action action);
	DispatcherOperation RunAsync(Action action);
	void Reset();
}