using Game2048.Entities;
using Game2048.Models;
using System.Linq;

namespace Game2048.Logic;

public class Game
{
    private readonly FieldModel _fieldModel;

    public int Score { get; private set; }

    public Game(FieldModel fieldModel)
    {
        _fieldModel = fieldModel;

        for (var i = 0; i < Constants.InitialNonEmptyCellsNumber; i++)
            InsertTwoOrFour();

        Score = 0;
    }

    public bool IsWin() => 
        _fieldModel.Field.Any(c => c.Any(v => v.Value == CellValues.TwoThousandFortyEight));

    public bool IsNoFreeSpace() => 
        !_fieldModel.Field.Any(c => c.Any(v => v.Value == CellValues.Empty));

    public bool IsNoMoves()
    {
        for (var i = 0; i < Constants.FieldSideSize; i++)
            for (var j = 0; j < Constants.FieldSideSize - 1; j++)
                if (_fieldModel.Field[i][j].Value == _fieldModel.Field[i][j + 1].Value ||
                    _fieldModel.Field[j][i].Value == _fieldModel.Field[j + 1][i].Value)
                    return false;

        return true;
    }

    public void Restart()
    {
        Score = 0;
        _fieldModel.Clear();

        for (var i = 0; i < Constants.InitialNonEmptyCellsNumber; i++)
            InsertTwoOrFour();
    }

    public void InsertTwoOrFour()
    {
        var position = GetEmptyCoordinates();
        _fieldModel.Field[position.Row][position.Column].Value = GetTwoOrFour();
    }

    private CellValues GetTwoOrFour()
    {
        return Utile.Random.Next(1, Constants.OneHundredPercent) >= Constants.NinetyPercent
            ? CellValues.Four
            : CellValues.Two;
    }

    private Coordinates GetEmptyCoordinates()
    {
        var coordinates = new Coordinates();

        do
        {
            coordinates.Row = Utile.Random.Next(0, Constants.FieldSideSize);
            coordinates.Column = Utile.Random.Next(0, Constants.FieldSideSize);

        } while (!_fieldModel.Field[coordinates.Row][coordinates.Column].IsEmpty());

        return coordinates;
    }

    public bool TryMoveRight()
    {
        var isMove = false;

        for (var i = 0; i < Constants.FieldSideSize; i++)
        {
            var column = Constants.FieldSideSize - 1;

            for (var j = Constants.FieldSideSize - 2; j >= 0; j--)
            {
                if (_fieldModel.Field[i][j].IsEmpty())
                    continue;

                if (_fieldModel.Field[i][column].IsEmpty())
                {
                    _fieldModel.Field[i][column].Value = _fieldModel.Field[i][j].Value;
                    if (j != column)
                        _fieldModel.Field[i][j].Value = CellValues.Empty;
                    isMove = true;
                }
                else if (_fieldModel.Field[i][column].Value == _fieldModel.Field[i][j].Value)
                {
                    var newValue = (CellValues)((int)_fieldModel.Field[i][column].Value * 2);
                    _fieldModel.Field[i][column].Value = newValue;
                    _fieldModel.Field[i][j].Value = CellValues.Empty;
                    column--;
                    Score += (int)newValue;
                    isMove = true;
                }
                else
                {
                    column--;
                    if (column == j)
                        continue;

                    _fieldModel.Field[i][column].Value = _fieldModel.Field[i][j].Value;
                    _fieldModel.Field[i][j].Value = CellValues.Empty;
                    isMove = true;
                }
            }
        }

        return isMove;
    }

    public bool TryMoveDown()
    {
        var isMove = false;

        for (var j = 0; j < Constants.FieldSideSize; j++)
        {
            var row = Constants.FieldSideSize - 1;

            for (var i = Constants.FieldSideSize - 2; i >= 0; i--)
            {
                if (_fieldModel.Field[i][j].IsEmpty())
                    continue;

                if (_fieldModel.Field[row][j].IsEmpty())
                {
                    _fieldModel.Field[row][j].Value = _fieldModel.Field[i][j].Value;
                    if (i != row)
                        _fieldModel.Field[i][j].Value = CellValues.Empty;
                    isMove = true;
                }
                else if (_fieldModel.Field[row][j].Value == _fieldModel.Field[i][j].Value)
                {
                    var newValue = (CellValues)((int)_fieldModel.Field[row][j].Value * 2);
                    _fieldModel.Field[row][j].Value = newValue;
                    _fieldModel.Field[i][j].Value = CellValues.Empty;
                    row--;
                    Score += (int)newValue;
                    isMove = true;
                }
                else
                {
                    row--;
                    if (row == i)
                        continue;

                    _fieldModel.Field[row][j].Value = _fieldModel.Field[i][j].Value;
                    _fieldModel.Field[i][j].Value = CellValues.Empty;
                    isMove = true;
                }
            }
        }
        return isMove;
    }

    public bool TryMoveLeft()
    {
        var isMove = false;

        for (var i = 0; i < Constants.FieldSideSize; i++)
        {
            var column = 0;

            for (var j = 1; j < Constants.FieldSideSize; j++)
            {
                if (_fieldModel.Field[i][j].IsEmpty())
                    continue;

                if (_fieldModel.Field[i][column].IsEmpty())
                {
                    _fieldModel.Field[i][column].Value = _fieldModel.Field[i][j].Value;
                    if (j != column)
                        _fieldModel.Field[i][j].Value = CellValues.Empty;
                    isMove = true;
                }
                else if (_fieldModel.Field[i][column].Value == _fieldModel.Field[i][j].Value)
                {
                    var newValue = (CellValues)((int)_fieldModel.Field[i][column].Value * 2);
                    _fieldModel.Field[i][column].Value = newValue;
                    _fieldModel.Field[i][j].Value = CellValues.Empty;
                    column++;
                    Score += (int)newValue;
                    isMove = true;
                }
                else
                {
                    column++;
                    if (column == j)
                        continue;

                    _fieldModel.Field[i][column].Value = _fieldModel.Field[i][j].Value;
                    _fieldModel.Field[i][j].Value = CellValues.Empty;
                    isMove = true;
                }
            }
        }

        return isMove;
    }

    public bool TryMoveUp()
    {
        var isMove = false;

        for (var j = 0; j < Constants.FieldSideSize; j++)
        {
            var row = 0;

            for (var i = 1; i < Constants.FieldSideSize; i++)
            {
                if (_fieldModel.Field[i][j].IsEmpty())
                    continue;
                
                if (_fieldModel.Field[row][j].IsEmpty())
                {
                    _fieldModel.Field[row][j].Value = _fieldModel.Field[i][j].Value;
                    if (i != row)
                        _fieldModel.Field[i][j].Value = CellValues.Empty;
                    isMove = true;
                }
                else if (_fieldModel.Field[row][j].Value == _fieldModel.Field[i][j].Value)
                {
                    var newValue = (CellValues)((int)_fieldModel.Field[row][j].Value * 2);
                    _fieldModel.Field[row][j].Value = newValue;
                    _fieldModel.Field[i][j].Value = CellValues.Empty;
                    row++;
                    Score += (int)newValue;
                    isMove = true;
                }
                else
                {
                    row++;
                    if (row == i)
                        continue;

                    _fieldModel.Field[row][j].Value = _fieldModel.Field[i][j].Value;
                    _fieldModel.Field[i][j].Value = CellValues.Empty;
                    isMove = true;
                }
            }
        }

        return isMove;
    }
}