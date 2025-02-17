using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace C_Sharp_SQL_HW4.Database.Migrations
{
    /// <inheritdoc />
    public partial class GameTableSplitting : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Countries",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(450)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Countries", x => x.Id);
                    table.CheckConstraint("CK_Country_Name", "LEN(Name) > 0");
                });

            migrationBuilder.CreateTable(
                name: "Genres",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(450)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Genres", x => x.Id);
                    table.CheckConstraint("CK_Genre_Name", "LEN(Name) > 0");
                });

            migrationBuilder.CreateTable(
                name: "Studios",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(450)", nullable: false),
                    IsDeleted = table.Column<bool>(type: "bit", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Studios", x => x.Id);
                    table.CheckConstraint("CK_Studio_Name", "LEN(Name) > 0");
                });

            migrationBuilder.CreateTable(
                name: "Cities",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(450)", nullable: false),
                    CountryId = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Cities", x => x.Id);
                    table.CheckConstraint("CK_City_Name", "LEN(Name) > 0");
                    table.ForeignKey(
                        name: "FK_Cities_Countries_CountryId",
                        column: x => x.CountryId,
                        principalTable: "Countries",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "CitiesStudios",
                columns: table => new
                {
                    CityId = table.Column<int>(type: "int", nullable: false),
                    StudioId = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_CitiesStudios", x => new { x.CityId, x.StudioId });
                    table.ForeignKey(
                        name: "FK_CitiesStudios_Cities_CityId",
                        column: x => x.CityId,
                        principalTable: "Cities",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_CitiesStudios_Studios_StudioId",
                        column: x => x.StudioId,
                        principalTable: "Studios",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.Sql(@"
                INSERT INTO Genres (Name)
                SELECT DISTINCT Genre
                FROM Games
                WHERE Genre IS NOT NULL;
            ");

            migrationBuilder.Sql(@"
                INSERT INTO Studios (Name, IsDeleted)
                SELECT DISTINCT Studio, 0
                FROM Games
                WHERE Studio IS NOT NULL;
            ");

            migrationBuilder.AddColumn<int>(
                name: "GenreId",
                table: "Games",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
               name: "StudioId",
               table: "Games",
               type: "int",
               nullable: false,
               defaultValue: 0);

            migrationBuilder.Sql(@"
                UPDATE Games
                SET GenreId = (SELECT Id FROM Genres WHERE Genres.Name = Games.Genre);
            ");

            migrationBuilder.Sql(@"
                UPDATE Games
                SET StudioId = (SELECT Id FROM Studios WHERE Studios.Name = Games.Studio);
            ");

            migrationBuilder.Sql(@"
                INSERT INTO Countries (Name) VALUES
                ('Country1'),
                ('Country2'),
                ('Country3');
            ");

            migrationBuilder.Sql(@"
                INSERT INTO Cities (Name, CountryId) VALUES
                ('City1', 1),
                ('City2', 1),
                ('City3', 2);
            ");

            migrationBuilder.Sql(@"
                INSERT INTO CitiesStudios (CityId, StudioId) VALUES
                (1, 3),
                (2, 2),
                (3, 1);
            ");         

            migrationBuilder.CreateIndex(
                name: "IX_Games_GenreId",
                table: "Games",
                column: "GenreId");

            migrationBuilder.CreateIndex(
                name: "IX_Games_StudioId",
                table: "Games",
                column: "StudioId");

            migrationBuilder.CreateIndex(
                name: "IX_Cities_CountryId",
                table: "Cities",
                column: "CountryId");

            migrationBuilder.CreateIndex(
                name: "IX_Cities_Name",
                table: "Cities",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_CitiesStudios_StudioId",
                table: "CitiesStudios",
                column: "StudioId");

            migrationBuilder.CreateIndex(
                name: "IX_Countries_Name",
                table: "Countries",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Genres_Name",
                table: "Genres",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Studios_Name",
                table: "Studios",
                column: "Name",
                unique: true);

            migrationBuilder.AddForeignKey(
                name: "FK_Games_Genres_GenreId",
                table: "Games",
                column: "GenreId",
                principalTable: "Genres",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_Games_Studios_StudioId",
                table: "Games",
                column: "StudioId",
                principalTable: "Studios",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);          

            migrationBuilder.DropCheckConstraint(
                name: "CK_Game_Genre",
                table: "Games");

            migrationBuilder.DropCheckConstraint(
                name: "CK_Game_Studio",
                table: "Games");

            migrationBuilder.DropColumn(
                name: "Genre",
                table: "Games");

            migrationBuilder.DropColumn(
                name: "Studio",
                table: "Games");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Games_Genres_GenreId",
                table: "Games");

            migrationBuilder.DropForeignKey(
                name: "FK_Games_Studios_StudioId",
                table: "Games");

            migrationBuilder.DropIndex(
                name: "IX_Games_GenreId",
                table: "Games");

            migrationBuilder.DropIndex(
                name: "IX_Games_StudioId",
                table: "Games");

            migrationBuilder.AddColumn<string>(
                name: "Genre",
                table: "Games",
                type: "nvarchar(450)",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "Studio",
                table: "Games",
                type: "nvarchar(450)",
                nullable: true);

            migrationBuilder.Sql(@"
                UPDATE Games
                SET Genre = (SELECT Name FROM Genres WHERE Genres.Id = Games.GenreId);
            ");

            migrationBuilder.Sql(@"
                UPDATE Games
                SET Studio = (SELECT Name FROM Studios WHERE Studios.Id = Games.StudioId);
            ");

            migrationBuilder.DropColumn(
                name: "GenreId",
                table: "Games");

            migrationBuilder.DropColumn(
                name: "StudioId",
                table: "Games");

            migrationBuilder.DropTable(
                name: "CitiesStudios");

            migrationBuilder.DropTable(
                name: "Cities");

            migrationBuilder.DropTable(
                name: "Countries");

            migrationBuilder.DropTable(
                name: "Studios");

            migrationBuilder.DropTable(
                name: "Genres");
        }
    }
}
