namespace Game2048.Entities;

public class User
{
    public string Name { get; set; }
    public int HighScore { get; set; }
    public bool IsRememberMe { get; set; }

    public User() : this(string.Empty) { }

    public User(string name)
    {
        Name = name;
        HighScore = 0;
        IsRememberMe = false;
    }
}