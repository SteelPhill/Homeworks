using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace C_Sharp_SQL_HW4.Database.Migrations
{
    /// <inheritdoc />
    public partial class AddGameSoldCopiesAndIsSingle : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<bool>(
                name: "IsSingle",
                table: "Games",
                type: "bit",
                nullable: false,
                defaultValue: false);

            migrationBuilder.AddColumn<int>(
                name: "SoldCopies",
                table: "Games",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddCheckConstraint(
                name: "CK_Game_SoldCopies",
                table: "Games",
                sql: "SoldCopies >= 0");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropCheckConstraint(
                name: "CK_Game_SoldCopies",
                table: "Games");

            migrationBuilder.DropColumn(
                name: "IsSingle",
                table: "Games");

            migrationBuilder.DropColumn(
                name: "SoldCopies",
                table: "Games");
        }
    }
}
