using Microsoft.EntityFrameworkCore;
using C_Sharp_SQL_HW3.Context;
using C_Sharp_SQL_HW3.Entities;
using C_Sharp_SQL_HW3.Extensions;
using C_Sharp_SQL_HW3.Helpers;
using C_Sharp_SQL_HW3.Menus.Logic;

// ReSharper disable UnusedMember.Global

namespace C_Sharp_SQL_HW3.Menus;

public static class MainMenu
{
	[StaticConsoleMenuCommand("Заполнить пустую базу данных")]
	public static async Task FillDatabaseIfEmpty()
	{
		var random = new Random(1);
		await using var context = new ApplicationContext();

		if (await context.Companies.AnyAsync() ||
			await context.Managers.AnyAsync() ||
			await context.Stationeries.AnyAsync() ||
			await context.StationeryTypes.AnyAsync())
			return;

		var companies = Enumerable.Range(1, 3)
			.Select(index => new Company { Name = $"Company{index}", IsDeleted = false })
			.ToArray();

		await context.Companies.AddRangeAsync(companies);

		var managers = Enumerable.Range(1, 4)
			.Select(index => new Manager { Name = $"Manager{index}", IsDeleted = false })
			.ToArray();

		await context.Managers.AddRangeAsync(managers);

		var stationeryTypes = Enumerable.Range(1, 8)
			.Select(index => new StationeryType { Name = $"Type{index}", IsDeleted = false })
			.ToArray();

		await context.StationeryTypes.AddRangeAsync(stationeryTypes);

		var stationeries = Enumerable.Range(0, 45)
			.Select(index =>
			{
				var isSold = random.Next(0, 3) % 2 == 0;
				var count = random.Next(1, 10);
				var price = random.Next(10, 31) * 10;

				return new Stationery
				{
					Name = $"Name{index}",
					Count = count,
					Price = price,
					SellingCount = isSold ? random.Next(1, count + 1) : null,
					SellingPrice = isSold ? random.Next(1, price + 1) : null,
					SellingDate = isSold ? DateOnly.FromDateTime(DateTime.Now.AddDays(-random.Next(1, 10))) : null,
					BuyerCompany = isSold ? companies[random.Next(0, companies.Length)] : null,
					SellingManager = isSold ? managers[random.Next(0, managers.Length)] : null,
					StationeryType = stationeryTypes[random.Next(0, stationeryTypes.Length)],
                    IsDeleted = false
                };
			})
			.ToArray();

		await context.Stationeries.AddRangeAsync(stationeries);

		await context.SaveChangesAsync();
	}

    [StaticConsoleMenuCommand("Отображение всей информации о канцтоварах")]
    public static async Task DisplayStationery()
    {
        await using var context = new ApplicationContext();

        var stationeries = await context.Stationeries
            .AsNoTracking()
            .Include(s => s.BuyerCompany)
            .Include(s => s.SellingManager)
            .Include(s => s.StationeryType)
            .Where(s => !s.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(stationeries.Select(s => s.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, stationeries.Length);
        if (selector == 0)
            return;

        PrintStationery(stationeries[selector - 1]);
    }

	[StaticConsoleMenuCommand("Отображение всех типов канцтоваров")]
    public static async Task DisplayAllStationeryTypes()
    {
        await using var context = new ApplicationContext();

        var names = await context.StationeryTypes
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .Select(s => s.Name)
            .ToArrayAsync();

        Console.WriteLine();
        names.ForEach(Console.WriteLine);
    }

    [StaticConsoleMenuCommand("Отображение всех менеджеров по продажам")]
    public static async Task DisplayAllManagers()
    {
        await using var context = new ApplicationContext();

        var names = await context.Managers
            .AsNoTracking()
            .Where(m => !m.IsDeleted)
            .Select(m => m.Name)
            .ToArrayAsync();

        Console.WriteLine();
        names.ForEach(Console.WriteLine);
    }

    [StaticConsoleMenuCommand("Показать канцтовары с максимальным количеством единиц")]
    public static async Task DisplayStationeryWithMaxCount()
    {
        await using var context = new ApplicationContext();

        var stationery = await context.Stationeries
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .Include(s => s.BuyerCompany)
			.Include(s => s.SellingManager)
			.Include(s => s.StationeryType)
            .OrderByDescending(s => s.Count)
            .FirstAsync();

        PrintStationery(stationery);
    }

    [StaticConsoleMenuCommand("Показать канцтовары с минимальным количеством единиц")]
    public static async Task DisplayStationeryWithMinCount()
    {
        await using var context = new ApplicationContext();

        var stationery = await context.Stationeries
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .Include(s => s.BuyerCompany)
			.Include(s => s.SellingManager)
			.Include(s => s.StationeryType)
            .OrderBy(s => s.Count)
            .FirstAsync();

        PrintStationery(stationery);
    }

    [StaticConsoleMenuCommand("Показать канцтовары с минимальной себестоимостью единицы")]
    public static async Task DisplayStationeryWithMaxPrice()
    {
        await using var context = new ApplicationContext();

        var stationery = await context.Stationeries
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .Include(s => s.BuyerCompany)
			.Include(s => s.SellingManager)
			.Include(s => s.StationeryType)
            .OrderBy(s => s.Price)
            .FirstAsync();

        PrintStationery(stationery);
    }

    [StaticConsoleMenuCommand("Показать канцтовары с максимальной себестоимостью единицы")]
    public static async Task DisplayStationeryWithMinPrice()
    {
        await using var context = new ApplicationContext();

        var stationery = await context.Stationeries
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .Include(s => s.BuyerCompany)
			.Include(s => s.SellingManager)
			.Include(s => s.StationeryType)
            .OrderByDescending(s => s.Price)
            .FirstAsync();

        PrintStationery(stationery);
    }

    [StaticConsoleMenuCommand("Показать канцтовары, заданного типа")]
    public static async Task DisplayStationeryWithSelectedType()
    {
        await using var context = new ApplicationContext();

        var stationeryTypes = await context.StationeryTypes
            .AsNoTracking()
            .Where(t => !t.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(stationeryTypes.Select(s => s.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, stationeryTypes.Length);
        if (selector == 0)
            return;

        var selectedStationeryTypeId = stationeryTypes[selector - 1].Id;
        var stationeries = await context.Stationeries
            .AsNoTracking()
			.Include(s => s.BuyerCompany)
			.Include(s => s.SellingManager)
			.Include(s => s.StationeryType)
            .Where(s => !s.IsDeleted && s.StationeryTypeId == selectedStationeryTypeId)
            .ToArrayAsync();

        stationeries.ForEach(PrintStationery);
    }

    [StaticConsoleMenuCommand("Показать канцтовары, которые продал конкретный менеджер по продажам")]
    public static async Task DisplayStationeryWithSelectedManager()
    {
        await using var context = new ApplicationContext();

        var managers = await context.Managers
            .AsNoTracking()
            .Where(m => !m.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(managers.Select(m => m.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, managers.Length);
        if (selector == 0)
            return;

        var selectedManagerId = managers[selector - 1].Id;
        var stationeries = await context.Stationeries
            .AsNoTracking()
			.Include(s => s.BuyerCompany)
			.Include(s => s.SellingManager)
			.Include(s => s.StationeryType)
            .Where(s => !s.IsDeleted && s.SellingManagerId == selectedManagerId)
            .ToArrayAsync();

        stationeries.ForEach(PrintStationery);
    }

    [StaticConsoleMenuCommand("Показать канцтовары, которые купила конкретная фирма покупатель")]
    public static async Task DisplayStationeryWithSelectedCompany()
    {
        await using var context = new ApplicationContext();

        var companies = await context.Companies
            .AsNoTracking()
            .Where(c => !c.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(companies.Select(c => c.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, companies.Length);
        if (selector == 0)
            return;

        var selectedCompanyId = companies[selector - 1].Id;
        var stationeries = await context.Stationeries
            .AsNoTracking()
			.Include(s => s.BuyerCompany)
			.Include(s => s.SellingManager)
			.Include(s => s.StationeryType)
            .Where(s => !s.IsDeleted && s.BuyerCompanyId == selectedCompanyId)
            .ToArrayAsync();

        stationeries.ForEach(PrintStationery);
    }

    [StaticConsoleMenuCommand("Показать информацию о самой недавней продаже")]
    public static async Task DisplayStationeryWithMaxDate()
    {
        await using var context = new ApplicationContext();

        var stationery = await context.Stationeries
            .AsNoTracking()
            .Include(s => s.BuyerCompany)
			.Include(s => s.SellingManager)
			.Include(s => s.StationeryType)
			.Where(s => !s.IsDeleted && s.SellingDate.HasValue)
            .OrderByDescending(s => s.SellingDate)
            .FirstAsync();

        PrintStationery(stationery);
    }

	[StaticConsoleMenuCommand("Показать среднее количество товаров по каждому типу канцтоваров")]
	public static async Task DisplayAverageCountByStationeryType()
	{
		await using var context = new ApplicationContext();

		var result = await context.StationeryTypes
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .Select(stationeryType => new
			{
				stationeryType.Name,
                stationeryType.Stationeries.Count,
				Average = (double?) stationeryType.Stationeries.Average(s => s.Count)
			})
			.ToArrayAsync();

		Console.WriteLine();
		result.Select(r => $"{r.Name}: {r.Count} / {r.Average}").ForEach(Console.WriteLine);
	}

    [StaticConsoleMenuCommand("Вставка новых канцтоваров")]
    public static async Task AddNewStationery()
    {
        Console.WriteLine();
        Console.Write("Введите название товара => ");
        var name = Console.ReadLine();
        if (string.IsNullOrEmpty(name))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена добавления");
            return;
        }

        var count = ConsoleReadHelper.ReadInt("Введите количество товара => ", 1);
        var price = ConsoleReadHelper.ReadInt("Введите стоимость товара => ", 1);

        await using var context = new ApplicationContext();

        Console.WriteLine("Выберите тип товара:");
        var stationeryTypes = await context.StationeryTypes.Where(s => !s.IsDeleted).ToArrayAsync();
        ConsoleMenuHelper.PrintCommands(stationeryTypes.Select(s => s.Name));
        var typeSelector = ConsoleReadHelper.ReadInt(" => ", 0, stationeryTypes.Length);
        if (typeSelector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена добавления");
            return;
        }

        await context.AddAsync(new Stationery
        {
            Name = name,
            Count = count,
            Price = price,
            StationeryType = stationeryTypes[typeSelector - 1],
            IsDeleted = false
        });
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Товар добавлен");
    }

    [StaticConsoleMenuCommand("Вставка новых типов канцтоваров")]
    public static async Task AddNewStationeryType()
    {
        Console.WriteLine();
        Console.Write("Введите название типа => ");
        var name = Console.ReadLine();
        if (string.IsNullOrEmpty(name))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена добавления");
            return;
        }

        await using var context = new ApplicationContext();

        await context.StationeryTypes.AddAsync(new StationeryType { Name = name, IsDeleted = false });
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Новый тип канцтоваров добавлен");
    }

    [StaticConsoleMenuCommand("Вставка новых менеджеров по продажам")]
    public static async Task AddNewManager()
    {
        Console.WriteLine();
        Console.Write("Введите ФИО менеджера => ");
        var name = Console.ReadLine();
        if (string.IsNullOrEmpty(name))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена добавления");
            return;
        }

        await using var context = new ApplicationContext();

        await context.Managers.AddAsync(new Manager { Name = name, IsDeleted = false });
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Новый менеджер добавлен");
    }

    [StaticConsoleMenuCommand("Вставка новых фирм покупателей")]
    public static async Task AddNewBuyerCompany()
    {
        Console.WriteLine();
        Console.Write("Введите название фирмы => ");
        var name = Console.ReadLine();
        if (string.IsNullOrEmpty(name))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена добавления");
            return;
        }

        await using var context = new ApplicationContext();

        await context.Companies.AddAsync(new Company { Name = name, IsDeleted = false });
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Новая фирма добавлена");
    }

    [StaticConsoleMenuCommand("Обновление информации о существующих канцтоварах")]
    public static async Task UpdateStationeryInfo()
    {
        await using var context = new ApplicationContext();

        var stationeries = await context.Stationeries
            .Where(s => !s.IsDeleted)
            .Include(s => s.StationeryType)
            .Include(s => s.SellingManager)
            .Include(s => s.BuyerCompany)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(stationeries.Select(s => s.Name));
        var stationerySelector = ConsoleReadHelper.ReadInt(" => ", 0, stationeries.Length);
        if (stationerySelector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }

        Console.WriteLine();
        Console.Write("Введите название товара => ");
        var name = Console.ReadLine();
        if (string.IsNullOrEmpty(name))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }
        stationeries[stationerySelector - 1].Name = name;

        stationeries[stationerySelector - 1].Count = ConsoleReadHelper.ReadInt("Введите количество товара => ", 1);
        stationeries[stationerySelector - 1].Price = ConsoleReadHelper.ReadInt("Введите стоимость товара => ", 1);

        Console.WriteLine("Выберите тип товара:");
        var stationeryTypes = await context.StationeryTypes.Where(s => !s.IsDeleted).ToArrayAsync();
        ConsoleMenuHelper.PrintCommands(stationeryTypes.Select(s => s.Name));
        var typeSelector = ConsoleReadHelper.ReadInt(" => ", 0, stationeryTypes.Length);
        if (typeSelector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }
        stationeries[stationerySelector - 1].StationeryType = stationeryTypes[typeSelector - 1];

        if (stationeries[stationerySelector - 1].SellingCount != null)
            stationeries[stationerySelector - 1].SellingCount = ConsoleReadHelper.ReadInt("Введите количество проданного товара => ", 1);

        if (stationeries[stationerySelector - 1].SellingPrice != null)
            stationeries[stationerySelector - 1].SellingPrice = ConsoleReadHelper.ReadInt("Введите стоимость продажи товара => ", 1);

        if (stationeries[stationerySelector - 1].SellingDate != null)
            stationeries[stationerySelector - 1].SellingDate = ConsoleReadHelper.ReadDateTime("Введите дату продажи => ").ToDateOnly();

        if (stationeries[stationerySelector - 1].SellingManager != null)
        {
            Console.WriteLine("Выберите менеджера по продажам:");
            var managers = await context.Managers.Where(m => !m.IsDeleted).ToArrayAsync();
            ConsoleMenuHelper.PrintCommands(managers.Select(m => m.Name));
            var managerSelector = ConsoleReadHelper.ReadInt(" => ", 0, managers.Length);
            if (managerSelector == 0)
            {
                Console.WriteLine();
                Console.WriteLine("Отмена обновления");
                return;
            }
            stationeries[stationerySelector - 1].SellingManager = managers[managerSelector - 1];
        }

        if (stationeries[stationerySelector - 1].BuyerCompany != null)
        {
            Console.WriteLine("Выберите фирму покупателя:");
            var companies = await context.Companies.Where(c => !c.IsDeleted).ToArrayAsync();
            ConsoleMenuHelper.PrintCommands(companies.Select(c => c.Name));
            var companySelector = ConsoleReadHelper.ReadInt(" => ", 0, companies.Length);
            if (companySelector == 0)
            {
                Console.WriteLine();
                Console.WriteLine("Отмена обновления");
                return;
            }
            stationeries[stationerySelector - 1].BuyerCompany = companies[companySelector - 1];
        }

        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Товар обновлён");
    }

    [StaticConsoleMenuCommand("Обновление информации о существующих типах канцтоваров")]
    public static async Task UpdateStationeryTypeInfo()
    {
        await using var context = new ApplicationContext();

        var stationeryTypes = await context.StationeryTypes
            .Where(s => !s.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(stationeryTypes.Select(s => s.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, stationeryTypes.Length);
        if (selector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }

        Console.WriteLine();
        Console.Write("Введите название типа => ");
        var name = Console.ReadLine();
        if (string.IsNullOrEmpty(name))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }
        stationeryTypes[selector - 1].Name = name;

        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Тип товаров обновлён");
    }

    [StaticConsoleMenuCommand("Обновление информации о существующих менеджерах по продажам")]
    public static async Task UpdateManagerInfo()
    {
        await using var context = new ApplicationContext();

        var managers = await context.Managers
            .Where(m => !m.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(managers.Select(m => m.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, managers.Length);
        if (selector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }

        Console.WriteLine();
        Console.Write("Введите ФИО менеджера => ");
        var name = Console.ReadLine();
        if (string.IsNullOrEmpty(name))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }
        managers[selector - 1].Name = name;

        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Информация о менеджере обновлена");
    }

    [StaticConsoleMenuCommand("Обновление информации о существующих фирмах покупателях")]
    public static async Task UpdateCompanyInfo()
    {
        await using var context = new ApplicationContext();

        var companies = await context.Companies
            .Where(c => !c.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(companies.Select(c => c.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, companies.Length);
        if (selector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }

        Console.WriteLine();
        Console.Write("Введите название компании => ");
        var name = Console.ReadLine();
        if (string.IsNullOrEmpty(name))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }
        companies[selector - 1].Name = name;

        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Информация о компании обновлена");
    }

    [StaticConsoleMenuCommand("Удаление канцтоваров")]
    public static async Task DeleteSelectedStationery()
    {
        await using var context = new ApplicationContext();

        var stationeries = await context.Stationeries
            .Where(s => !s.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(stationeries.Select(s => s.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, stationeries.Length);
        if (selector == 0)
            return;

        stationeries[selector - 1].IsDeleted = true;

        await context.SaveChangesAsync();
    }

    [StaticConsoleMenuCommand("Удаление типов канцтоваров")]
    public static async Task DeleteSelectedStationeryType()
    {
        await using var context = new ApplicationContext();

        var stationeryTypes = await context.StationeryTypes
            .Include(s => s.Stationeries)
            .Where(s => !s.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(stationeryTypes.Select(s => s.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, stationeryTypes.Length);
        if (selector == 0)
            return;

        stationeryTypes[selector - 1].IsDeleted = true;

        foreach (var stationery in stationeryTypes[selector - 1].Stationeries)
            stationery.IsDeleted = true;

        await context.SaveChangesAsync();
    }

    [StaticConsoleMenuCommand("Удаление менеджеров по продажам")]
    public static async Task DeleteSelectedManager()
    {
        await using var context = new ApplicationContext();

        var managers = await context.Managers
            .Where(m => !m.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(managers.Select(m => m.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, managers.Length);
        if (selector == 0)
            return;

        managers[selector - 1].IsDeleted = true;

        await context.Stationeries
            .Where(s => s.SellingManager.Name == managers[selector - 1].Name)
            .ExecuteUpdateAsync(x => x.SetProperty(s => s.SellingManagerId, s => null));

        await context.SaveChangesAsync();
    }

    [StaticConsoleMenuCommand("Удаление фирмы покупателя")]
    public static async Task DeleteSelectedCompany()
    {
        await using var context = new ApplicationContext();

        var companies = await context.Companies
            .Where(c => !c.IsDeleted)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(companies.Select(c => c.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, companies.Length);
        if (selector == 0)
            return;

        companies[selector - 1].IsDeleted = true;

        await context.Stationeries
            .Where(s => s.BuyerCompany.Name == companies[selector - 1].Name)
            .ExecuteUpdateAsync(x => x.SetProperty(s => s.BuyerCompanyId, s => null));

        await context.SaveChangesAsync();
    }

    [StaticConsoleMenuCommand("Показать информацию о менеджере с наибольшим количеством продаж по количеству единиц")]
    public static async Task DisplayManagerWithMostSales()
    {
        await using var context = new ApplicationContext();

        var manager = await context.Managers
            .AsNoTracking()
            .Include(m => m.Stationeries)
            .Where(m => !m.IsDeleted)
            .Select(manager => new
            {
                Manager = manager,
                CountSelling = manager.Stationeries.Sum(s => s.SellingCount)
            })
            .OrderByDescending(count => count.CountSelling)
            .FirstOrDefaultAsync();

        if (manager == default)
            return;

        Console.WriteLine($"Id:    {manager.Manager.Id}");
        Console.WriteLine($"Name:  {manager.Manager.Name}");
        Console.WriteLine($"Sales: {manager.CountSelling}");
    }

    [StaticConsoleMenuCommand("Показать информацию о менеджере по продажам с наибольшей суммой прибыли")]
    public static async Task DisplayManagerWithHighestAmountProfit()
    {
        await using var context = new ApplicationContext();

        var manager = await context.Managers
            .AsNoTracking()
            .Include(m => m.Stationeries)
            .Where(m => !m.IsDeleted)
            .Select(manager => new
            {
                Manager = manager,
                SellingPriceSum = manager.Stationeries.Sum(s => s.SellingPrice)
            })
            .OrderByDescending(count => count.SellingPriceSum)
            .FirstOrDefaultAsync();

        if (manager == default)
            return;

        Console.WriteLine($"Id:   {manager.Manager.Id}");
        Console.WriteLine($"Name: {manager.Manager.Name}");
        Console.WriteLine($"Sum:  {manager.SellingPriceSum}");
    }

    [StaticConsoleMenuCommand("Показать информацию о менеджере по продажам с наибольшей суммой прибыли за указанный промежуток времени")]
    public static async Task DisplayManagerWithHighestAmountProfitInPeriod()
    {
        await using var context = new ApplicationContext();

        var firstDate = ConsoleReadHelper.ReadDateTime("Введите начальную дату => ").ToDateOnly();
        var secondDate = ConsoleReadHelper.ReadDateTime("Введите конечную дату => ").ToDateOnly();

        if (firstDate > secondDate)
            (_, _) = (secondDate, firstDate);

        var manager = await context.Managers
            .AsNoTracking()
            .Include(m => m.Stationeries)
            .Where(m => !m.IsDeleted)
            .Select(manager => new
            {
                Manager = manager,
                SellingPriceSum = manager.Stationeries
                    .Where(s => s.SellingDate >= firstDate && s.SellingDate <= secondDate)
                    .Sum(s => s.SellingPrice)
            })
            .OrderByDescending(count => count.SellingPriceSum)
            .FirstOrDefaultAsync();

        if (manager == default)
            return;

        Console.WriteLine($"Id:   {manager.Manager.Id}");
        Console.WriteLine($"Name: {manager.Manager.Name}");
        Console.WriteLine($"Sum:  {manager.SellingPriceSum}");
    }

    [StaticConsoleMenuCommand("Показать информацию о фирме, которая купила на самую большую сумму")]
    public static async Task DisplayCompanyWithHighestAmountDeal()
    {
        await using var context = new ApplicationContext();

        var company = await context.Companies
            .AsNoTracking()
            .Include(с => с.Stationeries)
            .Where(с => !с.IsDeleted)
            .Select(company => new
            {
                Company = company,
                SellingPriceSum = company.Stationeries.Sum(s => s.SellingPrice)
            })
            .OrderByDescending(count => count.SellingPriceSum)
            .FirstOrDefaultAsync();

        if (company == default)
            return;

        Console.WriteLine($"Id:   {company.Company.Id}");
        Console.WriteLine($"Name: {company.Company.Name}");
        Console.WriteLine($"Sum:  {company.SellingPriceSum}");
    }

    [StaticConsoleMenuCommand("Показать информацию о типе канцтоваров с наибольшим количеством продаж по единицам")]
    public static async Task DisplayStationeryTypeWithMostCountSales()
    {
        await using var context = new ApplicationContext();

        var stationeryType = await context.StationeryTypes
            .AsNoTracking()
            .Include(s => s.Stationeries)
            .Where(s => !s.IsDeleted)
            .Select(stationeryType => new
            {
                StationeryType = stationeryType,
                CountSelling = stationeryType.Stationeries.Sum(s => s.SellingCount)
            })
            .OrderByDescending(count => count.CountSelling)
            .FirstOrDefaultAsync();

        if (stationeryType == default)
            return;

        Console.WriteLine($"Id:    {stationeryType.StationeryType.Id}");
        Console.WriteLine($"Name:  {stationeryType.StationeryType.Name}");
        Console.WriteLine($"Sales: {stationeryType.CountSelling}");
    }

    [StaticConsoleMenuCommand("Показать информацию о типе самых прибыльных канцтоваров")]
    public static async Task DisplayStationeryTypeMostProfitable()
    {
        await using var context = new ApplicationContext();

        var stationeryType = await context.StationeryTypes
            .AsNoTracking()
            .Include(s => s.Stationeries)
            .Where(s => !s.IsDeleted)
            .Select(stationeryType => new
            {
                StationeryType = stationeryType,
                SellingPriceSum = stationeryType.Stationeries.Sum(s => s.SellingPrice)
            })
            .OrderByDescending(count => count.SellingPriceSum)
            .FirstOrDefaultAsync();

        if (stationeryType == default)
            return;

        Console.WriteLine($"Id:   {stationeryType.StationeryType.Id}");
        Console.WriteLine($"Name: {stationeryType.StationeryType.Name}");
        Console.WriteLine($"Sum:  {stationeryType.SellingPriceSum}");
    }

    [StaticConsoleMenuCommand("Показать название самых популярных канцтоваров")]
    public static async Task DisplayMostPopularStationery()
    {
        await using var context = new ApplicationContext();

        var stationery = await context.Stationeries
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .OrderByDescending(s => s.SellingCount)
            .FirstOrDefaultAsync();

        if (stationery == default)
            return;

        Console.WriteLine($"Name: {stationery.Name}");
    }

    [StaticConsoleMenuCommand("Показать название канцтоваров, которые не продавались заданное количество дней")]
    public static async Task DisplayStationeryNotSoldSpecifiedNumberDays()
    {
        await using var context = new ApplicationContext();
        Console.Write("Введите количество дней => ");
        if (!int.TryParse(Console.ReadLine(), out var days))
            return;

        var startDate = DateOnly.FromDateTime(DateTime.Now.AddDays(-days));

        var stationeries = await context.Stationeries
            .Include(s => s.BuyerCompany)
            .Include(s => s.SellingManager)
            .Include(s => s.StationeryType)
            .Where(s => !s.IsDeleted && s.SellingDate <= startDate)
            .OrderBy(product => product.Name)
            .ToListAsync();

        if (stationeries.Count == 0)
            return;

        stationeries.ForEach(PrintStationery);
    }

    private static void PrintStationery(Stationery stationery)
	{
		Console.WriteLine();
		Console.WriteLine($"Id:    {stationery.Id}");
		Console.WriteLine($"Name:  {stationery.Name}");
		Console.WriteLine($"Count: {stationery.Count}");
		Console.WriteLine($"Price: {stationery.Price}");
		Console.WriteLine($"SellingCount: {stationery.SellingCount?.ToString() ?? "none"}");
		Console.WriteLine($"SellingPrice: {stationery.SellingPrice?.ToString() ?? "none"}");
		Console.WriteLine($"SellingDate:  {stationery.SellingDate?.ToString() ?? "none"}");
		Console.WriteLine($"BuyerCompanyName:   {stationery.BuyerCompany?.Name ?? "none"}");
		Console.WriteLine($"SellingManagerName: {stationery.SellingManager?.Name ?? "none"}");
		Console.WriteLine($"StationeryTypeName: {stationery.StationeryType?.Name ?? "none"}");
    }
}