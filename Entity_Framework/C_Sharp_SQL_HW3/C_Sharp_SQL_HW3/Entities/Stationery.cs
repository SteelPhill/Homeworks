#pragma warning disable CS8618

namespace C_Sharp_SQL_HW3.Entities;

public class Stationery
{
	public int Id { get; set; }
	public string Name { get; set; }
	public int Count { get; set; }
	public int Price { get; set; }
	public int? SellingCount { get; set; }
	public int? SellingPrice { get; set; }
    public DateOnly? SellingDate { get; set; }
    public int? BuyerCompanyId { get; set; }
	public Company? BuyerCompany { get; set; }
	public int? SellingManagerId { get; set; }
	public Manager? SellingManager { get; set; }
	public int StationeryTypeId { get; set; }
	public StationeryType StationeryType { get; set; }
    public bool IsDeleted { get; set; }
}