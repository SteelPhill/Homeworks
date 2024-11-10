using System.Text;

namespace HomeworkCSharp;

public class Product
{
    public int Id { get; set; }
    public string Name { get; set; }
    public string Description { get; set; }

    public Product() : this(default, default, default) { }

    public Product(int id, string name, string description)
    {
        Id = id;
        Name = name;
        Description = description;
    }

    public override string ToString()
    {
        var sb = new StringBuilder();

        sb.AppendLine($"Id: {Id}");
        sb.AppendLine($"Name: {Name}");
        sb.AppendLine($"Description: {Description}");

        return sb.ToString();
    }
}