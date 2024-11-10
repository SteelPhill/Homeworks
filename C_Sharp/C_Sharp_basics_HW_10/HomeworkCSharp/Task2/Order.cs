using System.Collections.Generic;
using System.Text;

namespace HomeworkCSharp;

public class Order
{
    public int Id { get; set; }
    public List<Product> Products { get; set; }

    public Order() : this(default) { }

    public Order(int id)
    {
        Id = id;
        Products = new List<Product>();
    }

    public void AddProduct(Product product)
        => Products.Add(product);

    public void RemoveProduct(Product product)
        => Products.Remove(product);

    public override string ToString()
    {
        var sb = new StringBuilder();

        sb.AppendLine($"Id: {Id}\n");

        foreach (Product product in Products)
            sb.AppendLine($"\tProduct:\n{product}");

        return sb.ToString();
    }
}