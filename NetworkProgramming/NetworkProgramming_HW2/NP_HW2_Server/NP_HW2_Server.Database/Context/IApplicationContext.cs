using NP_HW2_Server.Domain.Entities;

namespace NP_HW2_Server.Database.Context;

public interface IApplicationContext
{
    List<Recipe> Recipes { get; }
}