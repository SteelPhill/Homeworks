#pragma warning disable CS8618 

namespace NP_HW2_Server.Domain.Entities;

public class Recipe
{
    public string Name { get; set; }
    public List<string> Ingredients { get; set; }
	public byte[] ImageBytes { get; set; }
}