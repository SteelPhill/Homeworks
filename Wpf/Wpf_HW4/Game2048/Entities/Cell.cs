namespace Game2048.Entities;

public class Cell
{
    public CellValues Value { get; set; }

    public Cell()
    {
        Value = CellValues.Empty;
    }
}