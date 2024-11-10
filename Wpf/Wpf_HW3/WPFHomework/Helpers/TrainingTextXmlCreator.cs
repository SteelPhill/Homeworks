using System.Collections.Generic;
using WPFHomework.Entities;
using WPFHomework.Enums;

namespace WPFHomework.Helpers;

public static class TrainingTextXmlCreator
{
    private static ISerializer serializer = new Serializer();

    public static void Create()
    {
        List<TrainingText> trainingTexts = new()
        {
            new TrainingText("Travelling to far countries is always a thrilling and interesting adventure", DifficultyLevels.Easy),
            new TrainingText("You can go to the reading room or take the book home", DifficultyLevels.Easy),
            new TrainingText("Books are a great source of knowledge of our ancestors and just simple modern writers", DifficultyLevels.Easy),
            new TrainingText("Each person chooses on his own how to live his life", DifficultyLevels.Easy),
            new TrainingText("Internet is a worldwide network that transmits data to different parts of the Earth", DifficultyLevels.Easy),
            new TrainingText("Internet is not only an entertaining place, but also a learning platform.", DifficultyLevels.Medium),
            new TrainingText("Heading for the other end of the world, it`s impossible to go without such an aircraft as \"a plane\".", DifficultyLevels.Medium),
            new TrainingText("Books on traveling, novels, adventure, fictions - in the library you will find it all and even more.", DifficultyLevels.Medium),
            new TrainingText("Spring (March, April, May) is the most delightful season of the year.", DifficultyLevels.Medium),
            new TrainingText("Nowadays advertising doesn`t limit itself by a word 'publicity'.", DifficultyLevels.Medium),
            new TrainingText("The metal coins appeared in Greece, 2700 years ago.", DifficultyLevels.Hard),
            new TrainingText("Halloween originated in 16th-century Ireland with the Celtic people.", DifficultyLevels.Hard),
            new TrainingText("New Zealand is a state with a whole area of 268,700 square meters.", DifficultyLevels.Hard),
            new TrainingText("Saint Petersburg was the capital of the Russian Empire for over 200 years.", DifficultyLevels.Hard),
            new TrainingText("Leo Tolstoy, a renowned Russian writer, was born on September 9, 1828.", DifficultyLevels.Hard),
            new TrainingText("$Working% as a trainee, I received only 30% of the #whole salary ^:", DifficultyLevels.Insane),
            new TrainingText("{Aleksander} [Pushkin] was born /on\\ <June> 6, 1799, in @Moscow~", DifficultyLevels.Insane),
            new TrainingText("{Socrates! was a ancient Greek ~ philosopher who* lived ^around [470] to (399) BCE?}", DifficultyLevels.Insane),
            new TrainingText("Hollywood ~ is a famous place in %The United States known for \\making\\ /movies/ #and 'stars'!", DifficultyLevels.Insane),
            new TrainingText("Leonardo da Vinci@ was born` in [{1452} in a small town] in Italy? called* Vinci.$", DifficultyLevels.Insane)
        };

        serializer.Serialize(trainingTexts, Constants.TrainingTextsXmlPath);
    }
}