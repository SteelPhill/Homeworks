﻿// <auto-generated />
using System;
using C_Sharp_SQL_HW3.Context;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Metadata;
using Microsoft.EntityFrameworkCore.Migrations;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;

#nullable disable

namespace C_Sharp_SQL_HW3.Migrations
{
    [DbContext(typeof(ApplicationContext))]
    [Migration("20250205193903_StationeryTypeColumnNotNull")]
    partial class StationeryTypeColumnNotNull
    {
        /// <inheritdoc />
        protected override void BuildTargetModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder
                .HasAnnotation("ProductVersion", "9.0.0")
                .HasAnnotation("Relational:MaxIdentifierLength", 128);

            SqlServerModelBuilderExtensions.UseIdentityColumns(modelBuilder);

            modelBuilder.Entity("C_Sharp_SQL_HW3.Entities.Company", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    SqlServerPropertyBuilderExtensions.UseIdentityColumn(b.Property<int>("Id"));

                    b.Property<bool>("IsDeleted")
                        .HasColumnType("bit");

                    b.Property<string>("Name")
                        .IsRequired()
                        .HasColumnType("nvarchar(450)");

                    b.HasKey("Id");

                    b.HasIndex("Name")
                        .IsUnique();

                    b.ToTable("Companies", t =>
                        {
                            t.HasCheckConstraint("CK_Companies_Name", "LEN(Name) > 0");
                        });
                });

            modelBuilder.Entity("C_Sharp_SQL_HW3.Entities.Manager", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    SqlServerPropertyBuilderExtensions.UseIdentityColumn(b.Property<int>("Id"));

                    b.Property<bool>("IsDeleted")
                        .HasColumnType("bit");

                    b.Property<string>("Name")
                        .IsRequired()
                        .HasColumnType("nvarchar(450)");

                    b.HasKey("Id");

                    b.HasIndex("Name")
                        .IsUnique();

                    b.ToTable("Managers", t =>
                        {
                            t.HasCheckConstraint("CK_Managers_Name", "LEN(Name) > 0");
                        });
                });

            modelBuilder.Entity("C_Sharp_SQL_HW3.Entities.Stationery", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    SqlServerPropertyBuilderExtensions.UseIdentityColumn(b.Property<int>("Id"));

                    b.Property<int?>("BuyerCompanyId")
                        .HasColumnType("int");

                    b.Property<int>("Count")
                        .HasColumnType("int");

                    b.Property<bool>("IsDeleted")
                        .HasColumnType("bit");

                    b.Property<string>("Name")
                        .IsRequired()
                        .HasColumnType("nvarchar(450)");

                    b.Property<int>("Price")
                        .HasColumnType("int");

                    b.Property<int?>("SellingCount")
                        .HasColumnType("int");

                    b.Property<DateOnly?>("SellingDate")
                        .HasColumnType("date");

                    b.Property<int?>("SellingManagerId")
                        .HasColumnType("int");

                    b.Property<int?>("SellingPrice")
                        .HasColumnType("int");

                    b.Property<int>("StationeryTypeId")
                        .HasColumnType("int");

                    b.HasKey("Id");

                    b.HasIndex("BuyerCompanyId");

                    b.HasIndex("Name")
                        .IsUnique();

                    b.HasIndex("SellingManagerId");

                    b.HasIndex("StationeryTypeId");

                    b.ToTable("Stationeries", t =>
                        {
                            t.HasCheckConstraint("CK_Stationeries_Count", "Count > 0");

                            t.HasCheckConstraint("CK_Stationeries_Name", "LEN(Name) > 0");

                            t.HasCheckConstraint("CK_Stationeries_Price", "Price > 0");

                            t.HasCheckConstraint("CK_Stationeries_SellingCount", "SellingCount IS NULL OR SellingCount > 0");

                            t.HasCheckConstraint("CK_Stationeries_SellingPrice", "SellingPrice IS NULL OR SellingPrice > 0");
                        });
                });

            modelBuilder.Entity("C_Sharp_SQL_HW3.Entities.StationeryType", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    SqlServerPropertyBuilderExtensions.UseIdentityColumn(b.Property<int>("Id"));

                    b.Property<bool>("IsDeleted")
                        .HasColumnType("bit");

                    b.Property<string>("Name")
                        .IsRequired()
                        .HasColumnType("nvarchar(450)");

                    b.HasKey("Id");

                    b.HasIndex("Name")
                        .IsUnique();

                    b.ToTable("StationeryTypes", t =>
                        {
                            t.HasCheckConstraint("CK_StationeryTypes_Name", "LEN(Name) > 0");
                        });
                });

            modelBuilder.Entity("C_Sharp_SQL_HW3.Entities.Stationery", b =>
                {
                    b.HasOne("C_Sharp_SQL_HW3.Entities.Company", "BuyerCompany")
                        .WithMany("Stationeries")
                        .HasForeignKey("BuyerCompanyId")
                        .OnDelete(DeleteBehavior.Cascade);

                    b.HasOne("C_Sharp_SQL_HW3.Entities.Manager", "SellingManager")
                        .WithMany("Stationeries")
                        .HasForeignKey("SellingManagerId")
                        .OnDelete(DeleteBehavior.Cascade);

                    b.HasOne("C_Sharp_SQL_HW3.Entities.StationeryType", "StationeryType")
                        .WithMany("Stationeries")
                        .HasForeignKey("StationeryTypeId")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("BuyerCompany");

                    b.Navigation("SellingManager");

                    b.Navigation("StationeryType");
                });

            modelBuilder.Entity("C_Sharp_SQL_HW3.Entities.Company", b =>
                {
                    b.Navigation("Stationeries");
                });

            modelBuilder.Entity("C_Sharp_SQL_HW3.Entities.Manager", b =>
                {
                    b.Navigation("Stationeries");
                });

            modelBuilder.Entity("C_Sharp_SQL_HW3.Entities.StationeryType", b =>
                {
                    b.Navigation("Stationeries");
                });
#pragma warning restore 612, 618
        }
    }
}
