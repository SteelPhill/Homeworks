using System.Collections.Generic;
using WPFHomework.Entities;

namespace WPFHomework.Databases;

public class TrainingTextDB : ITrainingTextDB
{
    private readonly List<TrainingText> trainingTexts;

    public List<TrainingText> TrainingTexts { get => trainingTexts; }

    public TrainingTextDB(List<TrainingText> trainingTexts)
        => this.trainingTexts = trainingTexts;

    public void AddTrainingText(TrainingText trainingText)
        => trainingTexts.Add(trainingText);

    public void RemoveTrainingText(TrainingText trainingText)
        => trainingTexts.Remove(trainingText);
}