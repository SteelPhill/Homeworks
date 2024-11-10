using GalaSoft.MvvmLight;

namespace Game2048.Models;

public class UserModel : ObservableObject
{
    private string _name;
    private int _highScore;
    private bool _isRememberMe;

    public string Name
    {
        get => _name;
        set => Set(ref _name, value);
    }

    public int HighScore
    {
        get => _highScore;
        set => Set(ref _highScore, value);
    }

    public bool IsRememberMe
    {
        get => _isRememberMe;
        set => Set(ref _isRememberMe, value);
    }
}