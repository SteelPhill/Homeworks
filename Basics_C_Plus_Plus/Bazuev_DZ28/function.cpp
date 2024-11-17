#include <iostream>
#include <algorithm>
#include "function.h"
using namespace std;

void FillArrayInt(int* arr, const int size, const int beginValue, const int endValue)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (endValue - beginValue + 1) + beginValue;
}

void FillArrayDouble(double* arr, const int size, int beginValue, int endValue)
{
	beginValue *= 10;
	endValue *= 10;

	for (int i = 0; i < size; i++)
		arr[i] = (rand() % (endValue - beginValue + 1) + beginValue) / 10.0;
}

void FillArrayChar(char* arr, const int size, char beginValue, char endValue)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (endValue - beginValue + 1) + beginValue;
}

void ShowArrayInt(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void ShowArrayDouble(double* arr, const int size)
{
	for (int i = 0; i < size; i++)
		printf("%.1f  ", arr[i]);
	cout << endl;
}

void ShowArrayChar(char* arr, const int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int SearchMinValueInt(int* arr, const int size)
{
	int indexMin = 0;
	int valueMin = arr[0];

	for (int i = 1; i < size; i++)
		if (valueMin > arr[i])
		{
			indexMin = i;
			valueMin = arr[i];
		}

	return indexMin;
}

int SearchMinValueDouble(double* arr, const int size)
{
	int indexMin = 0;
	double valueMin = arr[0];

	for (int i = 1; i < size; i++)
		if (valueMin > arr[i])
		{
			indexMin = i;
			valueMin = arr[i];
		}

	return indexMin;
}

int SearchMinValueChar(char* arr, const int size)
{
	int indexMin = 0;
	char valueMin = arr[0];

	for (int i = 1; i < size; i++)
		if (valueMin > arr[i])
		{
			indexMin = i;
			valueMin = arr[i];
		}

	return indexMin;
}

int SearchMaxValueInt(int* arr, const int size)
{
	int indexMax = 0;
	int valueMax = arr[0];

	for (int i = 1; i < size; i++)
		if (valueMax < arr[i])
		{
			indexMax = i;
			valueMax = arr[i];
		}

	return indexMax;
}

int SearchMaxValueDouble(double* arr, const int size)
{
	int indexMax = 0;
	double valueMax = arr[0];

	for (int i = 1; i < size; i++)
		if (valueMax < arr[i])
		{
			indexMax = i;
			valueMax = arr[i];
		}

	return indexMax;
}

int SearchMaxValueChar(char* arr, const int size)
{
	int indexMax = 0;
	char valueMax = arr[0];

	for (int i = 1; i < size; i++)
		if (valueMax < arr[i])
		{
			indexMax = i;
			valueMax = arr[i];
		}

	return indexMax;
}

void AscSortArrayInt(int* arr, const int size)
{
	sort(arr, arr + size,
		[](int left, int right)
		{
			return left < right;
		});
}

void AscSortArrayDouble(double* arr, const int size)
{
	sort(arr, arr + size,
		[](double left, double right)
		{
			return left < right;
		});
}

void AscSortArrayChar(char* arr, const int size)
{
	sort(arr, arr + size,
		[](char left, char right)
		{
			return left < right;
		});
}

void EditArrayInt(int* arr, const int index, const int newValue)
{
	arr[index] = newValue;
}

void EditArrayDouble(double* arr, const int index, const double newValue)
{
	arr[index] = newValue;
}

void EditArrayChar(char* arr, const int index, const char newValue)
{
	arr[index] = newValue;
}