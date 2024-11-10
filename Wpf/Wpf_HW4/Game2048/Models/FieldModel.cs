using Game2048.Entities;
using System.Collections.ObjectModel;

namespace Game2048.Models;

public class FieldModel
{
    public ObservableCollection<ObservableCollection<CellModel>> Field { get; }

    public FieldModel()
    {
        Field = [];

        for (var i = 0; i < Constants.FieldSideSize; i++)
        {
            var row = new ObservableCollection<CellModel>();

            for (var j = 0; j < Constants.FieldSideSize; j++)
                row.Add(new CellModel(CellValues.Empty));

            Field.Add(row);
        }
    }

    public void Clear()
    {
        foreach (var row in Field)
            foreach (var cell in row)
                cell.Value = CellValues.Empty;
    }
}