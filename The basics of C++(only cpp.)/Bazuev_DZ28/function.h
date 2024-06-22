#pragma once

#ifdef INTEGER

void FillArrayInt(int* arr, const int size, const int beginValue, const int endValue);
void ShowArrayInt(int* arr, const int size);
int SearchMinValueInt(int* arr, const int size);
int SearchMaxValueInt(int* arr, const int size);
void AscSortArrayInt(int* arr, const int size);
void EditArrayInt(int* arr, const int index, const int newValue);

#define FillArray FillArrayInt
#define ShowArray ShowArrayInt
#define SearchMin SearchMinValueInt
#define SearchMax SearchMaxValueInt
#define AscSortArray AscSortArrayInt
#define EditArray EditArrayInt

#endif 

#ifdef DOUBLE

void FillArrayDouble(double* arr, const int size, int beginValue, int endValue);
void ShowArrayDouble(double* arr, const int size);
int SearchMinValueDouble(double* arr, const int size);
int SearchMaxValueDouble(double* arr, const int size);
void AscSortArrayDouble(double* arr, const int size);
void EditArrayDouble(double* arr, const int index, const double newValue);

#define FillArray FillArrayDouble
#define ShowArray ShowArrayDouble
#define SearchMin SearchMinValueDouble
#define SearchMax SearchMaxValueDouble
#define AscSortArray AscSortArrayDouble
#define EditArray EditArrayDouble

#endif

#ifdef CHAR

void FillArrayChar(char* arr, const int size, char beginValue, char endValue);
void ShowArrayChar(char* arr, const int size);
int SearchMinValueChar(char* arr, const int size);
int SearchMaxValueChar(char* arr, const int size);
void AscSortArrayChar(char* arr, const int size);
void EditArrayChar(char* arr, const int index, const char newValue);

#define FillArray FillArrayChar
#define ShowArray ShowArrayChar
#define SearchMin SearchMinValueChar
#define SearchMax SearchMaxValueChar
#define AscSortArray AscSortArrayChar
#define EditArray EditArrayChar

#endif 

