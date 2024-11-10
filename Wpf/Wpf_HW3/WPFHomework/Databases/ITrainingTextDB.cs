using System.Collections.Generic;
using WPFHomework.Entities;

namespace WPFHomework.Databases;

interface ITrainingTextDB
{
    List<TrainingText> TrainingTexts { get; }

    void AddTrainingText(TrainingText trainingText);
    void RemoveTrainingText(TrainingText trainingText);
}