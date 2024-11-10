using Game2048.Entities;
using GalaSoft.MvvmLight;

namespace Game2048.Models;

public class CellModel : ObservableObject
{
    private CellValues _value;

    public CellValues Value
    {
        get => _value;
        set => Set(ref _value, value);
    }

    public CellModel(CellValues value)
    {
        Value = value;
    }

    public bool IsEmpty()
    {
        return Value == CellValues.Empty;
    }
}