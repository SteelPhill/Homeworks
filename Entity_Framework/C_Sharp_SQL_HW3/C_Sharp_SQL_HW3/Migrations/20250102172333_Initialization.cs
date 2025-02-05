using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace C_Sharp_SQL_HW3.Migrations
{
    /// <inheritdoc />
    public partial class Initialization : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Companies",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(450)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Companies", x => x.Id);
                    table.CheckConstraint("CK_Companies_Name", "LEN(Name) > 0");
                });

            migrationBuilder.CreateTable(
                name: "Managers",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(450)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Managers", x => x.Id);
                    table.CheckConstraint("CK_Managers_Name", "LEN(Name) > 0");
                });

            migrationBuilder.CreateTable(
                name: "StationeryTypes",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(450)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_StationeryTypes", x => x.Id);
                    table.CheckConstraint("CK_StationeryTypes_Name", "LEN(Name) > 0");
                });

            migrationBuilder.CreateTable(
                name: "Stationeries",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(450)", nullable: false),
                    Count = table.Column<int>(type: "int", nullable: false),
                    Price = table.Column<int>(type: "int", nullable: false),
                    SellingCount = table.Column<int>(type: "int", nullable: true),
                    SellingPrice = table.Column<int>(type: "int", nullable: true),
                    SellingDate = table.Column<DateOnly>(type: "date", nullable: true),
                    BuyerCompanyId = table.Column<int>(type: "int", nullable: true),
                    SellingManagerId = table.Column<int>(type: "int", nullable: true),
                    StationeryTypeId = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Stationeries", x => x.Id);
                    table.CheckConstraint("CK_Stationeries_Count", "Count > 0");
                    table.CheckConstraint("CK_Stationeries_Name", "LEN(Name) > 0");
                    table.CheckConstraint("CK_Stationeries_Price", "Price > 0");
                    table.CheckConstraint("CK_Stationeries_SellingCount", "SellingCount IS NULL OR SellingCount > 0");
                    table.CheckConstraint("CK_Stationeries_SellingPrice", "SellingPrice IS NULL OR SellingPrice > 0");
                    table.ForeignKey(
                        name: "FK_Stationeries_Companies_BuyerCompanyId",
                        column: x => x.BuyerCompanyId,
                        principalTable: "Companies",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_Stationeries_Managers_SellingManagerId",
                        column: x => x.SellingManagerId,
                        principalTable: "Managers",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_Stationeries_StationeryTypes_StationeryTypeId",
                        column: x => x.StationeryTypeId,
                        principalTable: "StationeryTypes",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_Companies_Name",
                table: "Companies",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Managers_Name",
                table: "Managers",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Stationeries_BuyerCompanyId",
                table: "Stationeries",
                column: "BuyerCompanyId");

            migrationBuilder.CreateIndex(
                name: "IX_Stationeries_Name",
                table: "Stationeries",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Stationeries_SellingManagerId",
                table: "Stationeries",
                column: "SellingManagerId");

            migrationBuilder.CreateIndex(
                name: "IX_Stationeries_StationeryTypeId",
                table: "Stationeries",
                column: "StationeryTypeId");

            migrationBuilder.CreateIndex(
                name: "IX_StationeryTypes_Name",
                table: "StationeryTypes",
                column: "Name",
                unique: true);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Stationeries");

            migrationBuilder.DropTable(
                name: "Companies");

            migrationBuilder.DropTable(
                name: "Managers");

            migrationBuilder.DropTable(
                name: "StationeryTypes");
        }
    }
}
