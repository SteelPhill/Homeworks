using WPFHomework.Enums;

namespace WPFHomework.Entities;

public class TrainingText
{
    public string Text { get; set; }
    public DifficultyLevels Difficulty { get; set; }

    public TrainingText() : this(default, default) { }

    public TrainingText(string text, DifficultyLevels difficulty)
    {
        Text = text;
        Difficulty = difficulty;
    }
}