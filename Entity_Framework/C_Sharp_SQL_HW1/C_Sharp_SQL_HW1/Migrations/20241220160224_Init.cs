using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace C_Sharp_SQL_HW1.Migrations
{
    /// <inheritdoc />
    public partial class Init : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Fruits",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Color = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Calories = table.Column<int>(type: "int", nullable: false),
                    Type = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Fruits", x => x.Id);
                    table.CheckConstraint("CK_Fruits_Calories", "Calories > 0");
                    table.CheckConstraint("CK_Fruits_Color", "LEN(Color) > 0");
                    table.CheckConstraint("CK_Fruits_Name", "LEN(Name) > 0");
                    table.CheckConstraint("CK_Fruits_Type", "Type = 0 OR Type = 1");
                });
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Fruits");
        }
    }
}
