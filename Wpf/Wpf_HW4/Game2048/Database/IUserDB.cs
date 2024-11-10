using Game2048.Entities;
using System.Collections.Generic;

namespace Game2048.Database;

public interface IUserDB
{
    List<User> Users { get; }

    void Add(User user);
    void Read();
    void Write();
}