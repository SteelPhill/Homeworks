using System;
using System.Windows;
using System.Windows.Input;
using GalaSoft.MvvmLight.CommandWpf;
using GalaSoft.MvvmLight.Messaging;
using Game2048.Base;
using Game2048.Entities;
using Game2048.Logic;
using Game2048.Messages;
using Game2048.Models;

namespace Game2048.Views.GameWindow;

public class GameViewModel : ViewModel<GameWindow>
{
    public override object Header => "2048";

    private readonly IMessenger _messenger;
    private readonly User _user;

    private Game _game;

    private UserModel _userModel;
    private FieldModel _fieldModel;
    private int _score;

    public UserModel UserModel
    {
        get => _userModel;
        set => Set(ref _userModel, value);
    }

    public FieldModel FieldModel
    {
        get => _fieldModel;
        set => Set(ref _fieldModel, value);
    }

    public int Score
    {
        get => _score;
        set => Set(ref _score, value);
    }

    private ICommand _contentRenderedCommand;
    private ICommand _keyDownCommand;
    private ICommand _restartCommand;

    public ICommand ContentRenderedCommand => _contentRenderedCommand ??= new RelayCommand(OnContentRendered);
    public ICommand KeyDownCommand => _keyDownCommand ??= new RelayCommand<KeyEventArgs>(OnKeyboardArrow);
    public ICommand RestartCommand => _restartCommand ??= new RelayCommand(OnRestart);

    public GameViewModel(IMessenger messenger, User user)
    {
        _messenger = messenger;
        _user = user;

        UserModel = new UserModel();
        FieldModel = new FieldModel();

        Score = 0;
    }

    private void OnContentRendered()
    {
        UserModel.Name = _user.Name;
        UserModel.HighScore = _user.HighScore;
        UserModel.IsRememberMe = _user.IsRememberMe;

        _game = new Game(FieldModel);
    }

    private void OnKeyboardArrow(KeyEventArgs e)
    {
        switch (e.Key)
        {
            case Key.Left:
            case Key.A:
                MakeMove(() => _game.TryMoveLeft());
                break;
            case Key.Up:
            case Key.W:
                MakeMove(() => _game.TryMoveUp());
                break;
            case Key.Right:
            case Key.D:
                MakeMove(() => _game.TryMoveRight());
                break;
            case Key.Down:
            case Key.S:
                MakeMove(() => _game.TryMoveDown());
                break;
            default:
                break;
        }
    }

    private void MakeMove(Func<bool> action)
    {
        if (action())
        {
            Score = _game.Score;

            if (_game.IsWin())
            {
                GameOver("You win!");
                return;
            }

            if (!_game.IsNoFreeSpace())
                _game.InsertTwoOrFour();

            if (_game.IsNoFreeSpace() && _game.IsNoMoves())
                GameOver("You lose!");
        }
    }

    private void GameOver(string message)
    {
        MessageBox.Show(message, "Game over");
        if (UserModel.HighScore < Score)
            UserModel.HighScore = Score;
        Score = 0;
        _game.Restart();
    }

    private void OnRestart()
    {
        _game.Restart();
        Score = 0;
    }

    public override void Cleanup()
    {
        _user.HighScore = UserModel.HighScore;
        _messenger.Send(new RequestCloseMessage(this, null));

        base.Cleanup();

        _messenger.Unregister(this);
    }

    public interface IFactory
    {
        GameViewModel Create(User user);
    }
}