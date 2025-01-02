using Microsoft.EntityFrameworkCore;
using C_Sharp_SQL_HW2.Context;
using C_Sharp_SQL_HW2.Entities;
using C_Sharp_SQL_HW2.Extensions;
using C_Sharp_SQL_HW2.Helpers;
using C_Sharp_SQL_HW2.Menus.Logic;

namespace C_Sharp_SQL_HW2.Menus;

public static class MainMenu
{
	[StaticConsoleMenuCommand("Заполнить пустую базу данных")]
	public static async Task FillDatabaseIfEmpty()
	{
		await using var context = new ApplicationContext();

		if (await context.Products.AnyAsync() ||
			await context.ProductTypes.AnyAsync() ||
			await context.ProductSuppliers.AnyAsync())
			return;

		var types = Enumerable.Range(0, 3)
			.Select(index => new ProductType { Name = $"Type{index + 1}" })
			.ToArray();

		await context.ProductTypes.AddRangeAsync(types);

		var suppliers = Enumerable.Range(0, 4)
			.Select(index => new ProductSupplier { Name = $"Supplier{index + 1}" })
			.ToArray();

		await context.ProductSuppliers.AddRangeAsync(suppliers);

		var products = Enumerable.Range(0, 8)
			.Concat(Enumerable.Range(0, 5))
			.Select(index => new Product
			{
				Name = $"Name{index + 1}",
				Count = index + 1,
				Price = (index + 1) * 10 + 100,
				Date = DateTime.Now.AddDays(-index),
				ProductType = types[index / 3],
				ProductSupplier = suppliers[index % 3]
			});
		await context.Products.AddRangeAsync(products);

		await context.SaveChangesAsync();
	}

    [StaticConsoleMenuCommand("Отображение всех товаров")]
    public static async Task DisplayAllProduct()
    {
        await using var context = new ApplicationContext();

        var products = await context.Products
            .AsNoTracking()
            .Include(product => product.ProductType)
            .Include(product => product.ProductSupplier)
            .ToArrayAsync();

        Console.WriteLine();
        Console.WriteLine("Список товаров:");
        products.ForEach(PrintProduct);
    }

    [StaticConsoleMenuCommand("Отображение всей информации о товаре")]
	public static async Task DisplayProduct()
	{
		await using var context = new ApplicationContext();

		var products = await context.Products
            .AsNoTracking()
            .Include(product => product.ProductType)
			.Include(product => product.ProductSupplier)
			.ToArrayAsync();

		ConsoleMenuHelper.PrintCommands(products.Select(product => product.Name));
		var selector = ConsoleReadHelper.ReadInt(" => ", 0, products.Length);
		if (selector == 0)
			return;

		PrintProduct(products[selector - 1]);
	}

	[StaticConsoleMenuCommand("Отображение всех типов товаров")]
	public static async Task DisplayAllProductTypes()
	{
		await using var context = new ApplicationContext();

		var names = await context.ProductTypes
            .AsNoTracking()
            .Select(productType => productType.Name)
			.ToArrayAsync();

        Console.WriteLine();
        Console.WriteLine("Список типов товаров:");
        Console.WriteLine();
		names.ForEach(Console.WriteLine);
	}

	[StaticConsoleMenuCommand("Отображение всех поставщиков")]
	public static async Task DisplayAllProductSuppliers()
	{
		await using var context = new ApplicationContext();

		var names = await context.ProductSuppliers
            .AsNoTracking()
            .Select(productType => productType.Name)
			.ToArrayAsync();

        Console.WriteLine();
        Console.WriteLine("Список поставщиков:");
        Console.WriteLine();
        names.ForEach(Console.WriteLine);
	}

	[StaticConsoleMenuCommand("Показать товар с максимальным количеством")]
	public static async Task DisplayProductWithMaxCount()
	{
		await using var context = new ApplicationContext();

		var product = await context.Products
            .AsNoTracking()
			.Include(product => product.ProductType)
			.Include(product => product.ProductSupplier)
			.OrderByDescending(product => product.Count)
			.FirstOrDefaultAsync();

        if (product != default)
		    PrintProduct(product);
	}

	[StaticConsoleMenuCommand("Показать товар с минимальным количеством")]
	public static async Task DisplayProductWithMinCount()
	{
		await using var context = new ApplicationContext();

		var product = await context.Products
            .AsNoTracking()
            .Include(product => product.ProductType)
			.Include(product => product.ProductSupplier)
			.OrderBy(product => product.Count)
			.FirstOrDefaultAsync();

        if (product != default)
            PrintProduct(product);
    }

	[StaticConsoleMenuCommand("Показать товар с минимальной себестоимостью")]
	public static async Task DisplayProductWithMaxPrice()
	{
		await using var context = new ApplicationContext();

		var product = await context.Products
            .AsNoTracking()
            .Include(product => product.ProductType)
			.Include(product => product.ProductSupplier)
			.OrderBy(product => product.Price)
            .FirstOrDefaultAsync();

        if (product != default)
            PrintProduct(product);
    }

	[StaticConsoleMenuCommand("Показать товар с максимальной себестоимостью")]
	public static async Task DisplayProductWithMinPrice()
	{
		await using var context = new ApplicationContext();

		var product = await context.Products
            .AsNoTracking()
            .Include(product => product.ProductType)
			.Include(product => product.ProductSupplier)
			.OrderByDescending(product => product.Price)
            .FirstOrDefaultAsync();

        if (product != default)
            PrintProduct(product);
    }

	[StaticConsoleMenuCommand("Показать товары, заданной категории")]
	public static async Task DisplayProductWithSelectedType()
	{
		await using var context = new ApplicationContext();

		var productTypes = await context.ProductTypes.AsNoTracking().ToArrayAsync();

		ConsoleMenuHelper.PrintCommands(productTypes.Select(productType => productType.Name));
		var selector = ConsoleReadHelper.ReadInt(" => ", 0, productTypes.Length);
		if (selector == 0)
			return;

		var selectedProductTypeId = productTypes[selector - 1].Id;
		var products = await context.Products
            .AsNoTracking()
            .Include(product => product.ProductType)
			.Include(product => product.ProductSupplier)
			.Where(product => product.ProductTypeId == selectedProductTypeId)
			.ToArrayAsync();

		products.ForEach(PrintProduct);
	}

	[StaticConsoleMenuCommand("Показать товары, заданного поставщика")]
	public static async Task DisplayProductWithSelectedSupplier()
	{
		await using var context = new ApplicationContext();

		var productSuppliers = await context.ProductSuppliers.AsNoTracking().ToArrayAsync();

		ConsoleMenuHelper.PrintCommands(productSuppliers.Select(productSupplier => productSupplier.Name));
		var selector = ConsoleReadHelper.ReadInt(" => ", 0, productSuppliers.Length);
		if (selector == 0)
			return;

		var selectedProductSupplierId = productSuppliers[selector - 1].Id;
		var products = await context.Products
            .AsNoTracking()
            .Include(product => product.ProductType)
			.Include(product => product.ProductSupplier)
			.Where(product => product.ProductSupplierId == selectedProductSupplierId)
			.ToArrayAsync();

		products.ForEach(PrintProduct);
	}

	[StaticConsoleMenuCommand("Показать самый старый товар на складе")]
	public static async Task DisplayProductWithMinDate()
	{
		await using var context = new ApplicationContext();

		var product = await context.Products
            .AsNoTracking()
            .Include(product => product.ProductType)
			.Include(product => product.ProductSupplier)
			.OrderBy(product => product.Date)
            .FirstOrDefaultAsync();

        if (product != default)
            PrintProduct(product);
    }

	[StaticConsoleMenuCommand("Показать среднее количество товаров по каждому типу товара")]
	public static async Task DisplayAverageCountByProductType()
	{
		await using var context = new ApplicationContext();

		var result = await context.ProductTypes
            .AsNoTracking()
            .Select(productType => new
			{
				productType.Name,
				Average = productType.Products.Average(product => product.Count)
			})
			.ToArrayAsync();

        Console.WriteLine();
		result.Select(res => $"{res.Name}: {res.Average}").ForEach(Console.WriteLine);
	}

    [StaticConsoleMenuCommand("Вставка новых товаров")]
    public static async Task AddNewProduct()
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

        Console.Write("Введите дату поставки => ");
		if (!DateTime.TryParse(Console.ReadLine(), out var date))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена добавления");
            return;
        }

        await using var context = new ApplicationContext();

        Console.WriteLine();
        Console.WriteLine("Выберите тип товара:");
        var productTypes = await context.ProductTypes.ToArrayAsync();
        ConsoleMenuHelper.PrintCommands(productTypes.Select(productType => productType.Name));
        var typeSelector = ConsoleReadHelper.ReadInt(" => ", 0, productTypes.Length);
		if (typeSelector == 0)
		{
            Console.WriteLine();
            Console.WriteLine("Отмена добавления");
            return;
		}

		Console.WriteLine();
        Console.WriteLine("Выберите поставщика:");
        var productSuppliers = await context.ProductSuppliers.ToArrayAsync();
        ConsoleMenuHelper.PrintCommands(productSuppliers.Select(productSupplier => productSupplier.Name));
        var supplierSelector = ConsoleReadHelper.ReadInt(" => ", 0, productSuppliers.Length);
        if (supplierSelector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена добавления");
            return;
        }

		await context.AddAsync(new Product { 
            Name = name, 
            Count = count,
            Price = price,
            Date = date,
            ProductType = productTypes[typeSelector - 1],
            ProductSupplier = productSuppliers[supplierSelector - 1]
        });
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Товар добавлен");
    }

    [StaticConsoleMenuCommand("Вставка новых типов товаров")]
    public static async Task AddNewProductType()
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
        await context.ProductTypes.AddAsync(new ProductType { Name = name });
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Новый тип товаров добавлен");
    }

    [StaticConsoleMenuCommand("Вставка новых поставщиков")]
    public static async Task AddNewProductSupplier()
    {
        Console.WriteLine();
        Console.Write("Введите название поставщика => ");
		var name = Console.ReadLine();
		if (string.IsNullOrEmpty(name))
		{
            Console.WriteLine();
            Console.WriteLine("Отмена добавления");
            return;
        }

        await using var context = new ApplicationContext();
        await context.ProductSuppliers.AddAsync(new ProductSupplier { Name = name });
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Новый поставщик добавлен");
    }

    [StaticConsoleMenuCommand("Обновление информации о существующих товарах")]
    public static async Task UpdateProductInfo()
    {
        await using var context = new ApplicationContext();

        var products = await context.Products
            .Include(product => product.ProductType)
            .Include(product => product.ProductSupplier)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(products.Select(product => product.Name));
        var productSelector = ConsoleReadHelper.ReadInt(" => ", 0, products.Length);
        if (productSelector == 0)
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
        products[productSelector - 1].Name = name;

        products[productSelector - 1].Count = ConsoleReadHelper.ReadInt("Введите количество товара => ", 1);

        products[productSelector - 1].Price = ConsoleReadHelper.ReadInt("Введите стоимость товара => ", 1);

        Console.Write("Введите дату поставки => ");
        if (!DateTime.TryParse(Console.ReadLine(), out var date))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }
        products[productSelector - 1].Date = date;

        Console.WriteLine();
        Console.WriteLine("Выберите тип товара:");
        var productTypes = await context.ProductTypes.ToArrayAsync();
        ConsoleMenuHelper.PrintCommands(productTypes.Select(productType => productType.Name));
        var typeSelector = ConsoleReadHelper.ReadInt(" => ", 0, productTypes.Length);
        if (typeSelector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }
        products[productSelector - 1].ProductType = productTypes[typeSelector - 1];

        Console.WriteLine();
        Console.WriteLine("Выберите поставщика:");
        var productSuppliers = await context.ProductSuppliers.ToArrayAsync();
        ConsoleMenuHelper.PrintCommands(productSuppliers.Select(productSupplier => productSupplier.Name));
        var supplierSelector = ConsoleReadHelper.ReadInt(" => ", 0, productSuppliers.Length);
        if (supplierSelector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }
        products[productSelector - 1].ProductSupplier = productSuppliers[supplierSelector - 1];

        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Товар обновлён");
    }

    [StaticConsoleMenuCommand("Обновление информации о существующих типах товаров")]
    public static async Task UpdateProductTypeInfo()
    {
        await using var context = new ApplicationContext();

        var productTypes = await context.ProductTypes.ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(productTypes.Select(productType => productType.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, productTypes.Length);
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
		productTypes[selector - 1].Name = name;

        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Тип товаров обновлён");
    }

    [StaticConsoleMenuCommand("Обновление информации о существующих поставщиках")]
    public static async Task UpdateProductSupplierInfo()
    {
        await using var context = new ApplicationContext();

        var productSuppliers = await context.ProductSuppliers.ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(productSuppliers.Select(productSupplier => productSupplier.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, productSuppliers.Length);
        if (selector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }

        Console.WriteLine();
        Console.Write("Введите название поставщика => ");
        var name = Console.ReadLine();
        if (string.IsNullOrEmpty(name))
        {
            Console.WriteLine();
            Console.WriteLine("Отмена обновления");
            return;
        }
        productSuppliers[selector - 1].Name = name;

        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Поставщик обновлён");
    }

    [StaticConsoleMenuCommand("Удаление товаров")]
    public static async Task RemoveProduct()
    {
        await using var context = new ApplicationContext();

        var products = await context.Products
            .Include(product => product.ProductType)
            .Include(product => product.ProductSupplier)
            .ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(products.Select(product => product.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, products.Length);
        if (selector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена удаления");
            return;
        }

        context.Products.Remove(products[selector - 1]);

        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Товар удалён");
    }

    [StaticConsoleMenuCommand("Удаление типов товаров")]
    public static async Task RemoveProductType()
    {
        await using var context = new ApplicationContext();

        var productTypes = await context.ProductTypes.ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(productTypes.Select(productType => productType.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, productTypes.Length);
        if (selector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена удаления");
            return;
        }

        context.ProductTypes.Remove(productTypes[selector - 1]);

        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Тип товаров удалён");
    }

    [StaticConsoleMenuCommand("Удаление поставщиков")]
    public static async Task RemoveProductSupplier()
    {
        await using var context = new ApplicationContext();

        var productSuppliers = await context.ProductSuppliers.ToArrayAsync();

        ConsoleMenuHelper.PrintCommands(productSuppliers.Select(productSupplier => productSupplier.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, productSuppliers.Length);
        if (selector == 0)
        {
            Console.WriteLine();
            Console.WriteLine("Отмена удаления");
            return;
        }

        context.ProductSuppliers.Remove(productSuppliers[selector - 1]);

        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Поставщик удалён");
    }

    [StaticConsoleMenuCommand("Показать информацию о поставщике с наибольшим количеством товаров на складе")]
    public static async Task DisplaySupplierWithLargestProductsNumber()
    {
        await using var context = new ApplicationContext();

        var productSupplierWithMaxNumber = await context.ProductSuppliers
            .AsNoTracking()
            .Select(productSupplier => new
            {
                ProductSupplier = productSupplier,
                ProductsNumber = productSupplier.Products.Sum(product => product.Count)
            })
            .OrderByDescending(x => x.ProductsNumber)
            .FirstOrDefaultAsync();

        if (productSupplierWithMaxNumber != default)
        {
            Console.WriteLine($"Id:   {productSupplierWithMaxNumber.ProductSupplier.Id}");
            Console.WriteLine($"Name: {productSupplierWithMaxNumber.ProductSupplier.Name}");
        }
    }

    [StaticConsoleMenuCommand("Показать информацию о поставщике с наименьшим количеством товаров на складе")]
    public static async Task DisplaySupplierWithLeastProductsNumber()
    {
        await using var context = new ApplicationContext();

        var productSupplierWithMinNumber = await context.ProductSuppliers
            .AsNoTracking()
            .Select(productSupplier => new
            {
                ProductSupplier = productSupplier,
                ProductsNumber = productSupplier.Products.Sum(product => product.Count)
            })
            .OrderBy(x => x.ProductsNumber)
            .FirstOrDefaultAsync();

        if (productSupplierWithMinNumber != default)
        {
            Console.WriteLine($"Id:   {productSupplierWithMinNumber.ProductSupplier.Id}");
            Console.WriteLine($"Name: {productSupplierWithMinNumber.ProductSupplier.Name}");
        }
    }

    [StaticConsoleMenuCommand("Показать информацию о типе товаров с наибольшим количеством товаров на складе")]
    public static async Task DisplayTypeWithLargestProductsNumber()
    {
        await using var context = new ApplicationContext();

        var productTypeWithMaxNumber = await context.ProductTypes
            .AsNoTracking()
            .Select(productType => new
            {
                ProductType = productType,
                ProductsNumber = productType.Products.Sum(product => product.Count)
            })
            .OrderByDescending(x => x.ProductsNumber)
            .FirstOrDefaultAsync();

        if (productTypeWithMaxNumber != default)
        {
            Console.WriteLine($"Id:   {productTypeWithMaxNumber.ProductType.Id}");
            Console.WriteLine($"Name: {productTypeWithMaxNumber.ProductType.Name}");
        }
    }

    [StaticConsoleMenuCommand("Показать информацию о типе товаров с наименьшим количеством товаров на складе")]
    public static async Task DisplayTypeWithLeastProductsNumber()
    {
        await using var context = new ApplicationContext();

        var productTypeWithMinNumber = await context.ProductTypes
            .AsNoTracking()
            .Select(productType => new
            {
                ProductType = productType,
                ProductsNumber = productType.Products.Sum(product => product.Count)
            })
            .OrderBy(x => x.ProductsNumber)
            .FirstOrDefaultAsync();

        if (productTypeWithMinNumber != default)
        {
            Console.WriteLine($"Id:   {productTypeWithMinNumber.ProductType.Id}");
            Console.WriteLine($"Name: {productTypeWithMinNumber.ProductType.Name}");
        }
    }

    [StaticConsoleMenuCommand("Показать товары с поставки, которых прошло заданное количество дней")]
    public static async Task DisplayProductsPassedSpecifiedDaysFromDelivery()
    {
        await using var context = new ApplicationContext();

        Console.WriteLine();
        Console.WriteLine("Введите количество дней");
        var days = ConsoleReadHelper.ReadInt(" => ", 0);

        var products = await context.Products
            .AsNoTracking()
            .Include(product => product.ProductType)
            .Include(product => product.ProductSupplier)
            .Where(product => product.Date < DateTime.Now.AddDays(-days))
            .ToArrayAsync();

        Console.WriteLine();
        Console.WriteLine($"Список товаров, с поставки которых прошло {days} дней:");
        products.ForEach(PrintProduct);
    }

    private static void PrintProduct(Product product)
	{
		Console.WriteLine();
		Console.WriteLine($"Id:    {product.Id}");
		Console.WriteLine($"Name:  {product.Name}");
		Console.WriteLine($"Count: {product.Count}");
		Console.WriteLine($"Price: {product.Price}");
		Console.WriteLine($"Date:  {product.Date}");
		Console.WriteLine($"ProductTypeName:     {product.ProductType.Name}");
		Console.WriteLine($"ProductSupplierName: {product.ProductSupplier.Name}");
	}
}