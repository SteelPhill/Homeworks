#include <iostream>
using namespace std;

void FillArray(int* arr, int size, int beginValue, int endValue)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % (endValue - beginValue + 1) + beginValue;
}

template <typename TValue>
void ShowArray(TValue* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << "arr[" << i << "] = " << arr[i] << endl;
}


//			ЗАДАЧА №1
/*Написать программу «справочник». Создать два одномерных 
массива. Один массив хранит номера мобильных телефонов, 
второй — домашние телефонные номера. 
Реализовать меню для пользователя:
- Отсортировать по номерам мобильных
- Отсортировать по домашним номерам телефонов;
- Вывести пользовательский данные;
- Выход.*/

//enum MenuItems
//{
//	SortingByMobileNumbers = 1,
//	SortingByHomeNumbers = 2,
//	DataOutput = 3,
//	Exit = 4
//};
//
//void ShowUsersAndTheirPhoneNumbers(long long* arr1, int* arr2, int size)
//{
//	cout << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Пользователь №" << i + 1 << ": " << "Моб.тел.: " << arr1[i] << endl;
//		cout << "\t\t Дом.тел.: " << arr2[i] << endl;
//	}
//	cout << endl;
//}
//
//void CreatingPhoneNumbers(long long* arr, int size) //Неуспевает зарандомить больше пятизначного числа, поэтому пришлось рандомить число по частям
//{
//	const int beginValue = 0000;
//	const int endValue = 9999;
//	for (int i = 0; i < size; i++)
//		arr[i] = 89500000000 + ((rand() % (endValue - beginValue + 1) + beginValue) * 10000) + (rand() % (endValue - beginValue + 1) + beginValue);
//}
//
//void CreatingPhoneNumbers(int* arr, int size)
//{
//	const int beginValue = 00000;
//	const int endValue = 99999;
//	for (int i = 0; i < size; i++)
//		arr[i] = 500000 + (rand() % (endValue - beginValue + 1) + beginValue);
//}
//
//template <typename TValue1, typename TValue2>
//void SortingUsersByPhoneNumber(TValue1* arr1, TValue2* arr2,  int leftIndex, int rightIndex)
//{
//	if (leftIndex > rightIndex)
//		return;
//	int j = rightIndex;
//	int k = leftIndex;
//	long long c = arr1[(leftIndex + rightIndex) / 2];
//	do
//	{
//		while (arr1[k] < c)
//			k++;
//		while (arr1[j] > c)
//			j--;
//		if (k <= j)
//		{
//			swap(arr1[k], arr1[j]);
//			swap(arr2[k], arr2[j]);
//			k++;
//			j--;
//		}
//	} while (k <= j);
//	SortingUsersByPhoneNumber(arr1, arr2, leftIndex, j);
//	SortingUsersByPhoneNumber(arr1, arr2, k, rightIndex);
//}
//
//void MenuAndUserData(long long* mobilePhoneNumbers, int* homePhoneNumbers, int size)
//{
//	int choice = 0;
//	do
//	{
//		cout << "\t\t\tМеню:" << endl;
//		cout << endl;
//		cout << "1. Отсортировать пользователей по возрастанию мобильных номеров;" << endl;
//		cout << "2. Отсортировать пользователей по возрастанию домашних номеров;" << endl;
//		cout << "3. Вывести пользовательский данные;" << endl;
//		cout << "4. Выход." << endl;
//		cout << endl;
//		cout << "Выберите пункт меню => ";
//		cin >> choice;
//		while (choice < 1 || choice > 4)
//		{
//			cout << "Такого пункта меню несуществует!" << endl;
//			cout << "Выберите пункт меню => ";
//			cin >> choice;
//		}
//		system("cls");
//		cout << "Выбранный пункт меню: " << choice << endl;
//		cout << endl;
//		switch (choice)
//		{
//		case SortingByMobileNumbers:
//		{
//			SortingUsersByPhoneNumber(mobilePhoneNumbers, homePhoneNumbers, 0, size - 1);
//			break;
//		}
//		case SortingByHomeNumbers:
//		{
//			SortingUsersByPhoneNumber(homePhoneNumbers, mobilePhoneNumbers, 0, size - 1);		
//			break;
//		}
//		case DataOutput:
//		{
//			cout << "\tСписок пользователей:" << endl;
//			ShowUsersAndTheirPhoneNumbers(mobilePhoneNumbers, homePhoneNumbers, size);
//			break;
//		}
//		default:
//			return;
//		}
//	} while (choice != Exit);
//	system("cls");
//	cout << "Выбранный пункт меню: " << choice << endl;
//	cout << endl;
//}
//
//void main()
//{
//	const int Size = 5;
//
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	long long mobilePhoneNumbers[Size];
//	int homePhoneNumbers[Size];
//
//	CreatingPhoneNumbers(mobilePhoneNumbers, Size);
//	CreatingPhoneNumbers(homePhoneNumbers, Size);
//
//	cout << "\tСписок пользователей:" << endl;
//	ShowUsersAndTheirPhoneNumbers(mobilePhoneNumbers, homePhoneNumbers, Size);
//
//	MenuAndUserData(mobilePhoneNumbers, homePhoneNumbers, Size);
//	
//	cout << "Окончательный результат сортировки:" << endl;
//	ShowUsersAndTheirPhoneNumbers(mobilePhoneNumbers, homePhoneNumbers, Size);
//
//	cout << "Завершение работы программы..." << endl;
//	cout << endl;
//	system("pause");
//}


//		    ЗАДАЧА №2
/*Написать программу, реализующую сортировку массива с 
помощью усовершенствованной сортировки пузырьковым методом. 
Усовершенствование состоит в том, чтобы анализировать 
количество перестановок на каждом шагу, если это количество 
равно нулю, то продолжать сортировку нет смысла — массив 
отсортирован.*/

//void AdvancedBubbleSorting(int* arr, int size)
//{
//	int temp;
//	int count;
//	for (int i = 1; i < size; i++)
//	{
//		count = 0;
//		for (int j = 0; j < size - 1; j++)
//			if (arr[j + 1] < arr[j])
//			{
//				temp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = temp;
//				count++;
//			}
//		cout << "Количество перестановок на " << i << " шагу: " << count << endl;
//		if (count == 0)
//			break;
//	}
//}
//
//void main()
//{ 
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//	int size;
//	cout << "Введите размер массива => ";
//	cin >> size;
//	while (size < 1)
//	{
//		cout << "Размер массива не может быть меньше 1 !" << endl;
//		cout << "Введите размер массива => ";
//		cin >> size;
//	}
//	system("cls");
//	cout << "Размер массива: " << size << endl;
//	int* arr = new int[size];
//	FillArray(arr, size, 1, 100);
//	cout << endl;
//	cout << "Массив до сортирокви:" << endl;
//	ShowArray(arr, size);
//	cout << endl;
//	AdvancedBubbleSorting(arr, size);
//	cout << endl;
//	cout << "Массив после усовершенствованной пузырьковой сортирокви:" << endl;
//	ShowArray(arr, size);
//	cout << endl;
//	system("pause");
//}


//		    ЗАДАЧА №3
/*Есть стопка оладий различного радиуса. Единственная 
операция, проводимая с ними — между любыми двумя суем 
лопатку и меняем порядок оладий над лопаткой на обратный. 
Необходимо за минимальное количество операций таких 
отсортировать снизу вверх по убыванию радиуса.*/

//void ShowStackOfPancakes(int* arr, int size)
//{
//	cout << endl;
//	for (int i = 0; i < size; i++)
//		cout << "Радиус " << i + 1 << "-ой оладьи: " << arr[i] << endl;
//	cout << endl;
//}
//
//int PancakesOnSpatula(int size)
//{
//	cout << endl;
//	int choice;
//	cout << "Выберите, под какую оладью засунуть лопатку или введите 0 для завершения сортировки => ";
//	cin >> choice;
//	while (choice > size || choice < 0)
//	{
//		cout << "Такого количества оладий в стопке нет!" << endl;
//		cout << "Выберите, под какую оладью засунуть лопатку или введите 0 для завершения сортировки => ";
//		cin >> choice;
//	}
//	return choice;
//}
//
//void SortingPancakesOverSpatula(int* arr, int sizeOfTopStack)
//{
//	int i = 0;
//	int j = sizeOfTopStack - 1;
//
//	while (i <= j)
//	{
//		swap(arr[i], arr[j]);
//		i++;
//		j--;
//	}
//}
//
//int SortingPancakesByUser(int* arr, int size)
//{
//	int numberOfAttempts = 0;
//	cout << "\t\t\tСортировка оладий:" << endl;
//	cout << "1.Для сортировки необходимо выбрать, под какую оладью вы вставите лопатку." << endl;
//	cout << "2.После этого все оладьи, находящиеся над лопаткой, поменяют свой порядок на обратный." << endl;
//	cout << "3.Необходимо за минимальное количество попыток отсортировать оладьи по уменьшению размера, снизу вверх." << endl;
//	int choice = PancakesOnSpatula(size);
//
//	while (choice != 0)
//	{
//		SortingPancakesOverSpatula(arr, choice);
//		system("cls");
//		cout << "Стопка оладий в данный момент:" << endl;
//		ShowStackOfPancakes(arr, size);
//		numberOfAttempts++;
//		choice = PancakesOnSpatula(size);
//	}
//
//	cout << endl;
//	return numberOfAttempts;
//}
//
//void main()
//{ 
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//	cout << "Введите размер стопки оладий (их количество) => ";
//	int size;
//	cin >> size;
//	if (size < 1)
//	{
//		cout << "Оладий нет!" << endl;
//		system("pause");
//		return;
//	}
//	int* arr = new int[size];
//	FillArray(arr, size, 5, 15);
//	cout << endl;
//
//	if (size > 1)
//	{
//		cout << "Стопка оладий до сортировки:" << endl;
//		ShowStackOfPancakes(arr, size);
//		int numberOfAttempts = SortingPancakesByUser(arr, size);
//		system("cls");
//		cout << "Стопка оладий после сортировки:" << endl;
//		ShowStackOfPancakes(arr, size);
//		cout << "Количество совершенных перестановок для сортировки стопки оладий: " << numberOfAttempts << endl;
//	}
//
//	else
//	{
//		cout << "В стопке одна оладья." << endl;
//		cout << "Радиус оладьи: " << arr[0] << endl;
//		cout << "Сортировка не требуется." << endl;
//	}
//
//	cout << endl;
//	system("pause");
//}


//		    ЗАДАЧА №4
/*Написать программу, которая сравнивает число перестановок 
элементов при использовании сортировки «пузырьком» (усовершенствованная версия задани я 2)
и методом выбора. Выполнить ее тестирование на разных 10 массивах, 
содержащих 1000 случайных элементов, вычислить среднее 
число перестановок для каждого метода после тестирования.*/

//int AdvancedBubbleSorting(int* arr, int size)
//{
//	const int NumberOfRuns = 10;
//	int run = 1;
//	int temp;
//	int count = 0;
//	while (run <= NumberOfRuns)
//	{
//		for (int i = 1; i < size; i++)
//		{
//			for (int j = 0; j < size - 1; j++)
//				if (arr[j + 1] < arr[j])
//				{
//					temp = arr[j + 1];
//					arr[j + 1] = arr[j];
//					arr[j] = temp;
//					count++;
//				}
//			if (count == 0)
//				break;
//		}
//		FillArray(arr, size, 1, 1000);
//		run++;
//	}
//	return count / NumberOfRuns;
//}
//
//int SelectionSorting(int* arr, int size)
//{
//	const int NumberOfRuns = 10;
//	int run = 1;
//	int temp;
//	int count = 0;
//	while (run <= NumberOfRuns)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			for (int j =  i + 1; j < size; j++)
//				if (arr[i] > arr[j])
//				{
//					temp = arr[j];
//					arr[j] = arr[i];
//					arr[i] = temp;
//					count++;
//				}
//		}
//		FillArray(arr, size, 1, 1000);
//		run++;
//	}
//	return count / NumberOfRuns;
//}
//
//void main()
//{ 
//	const int Size = 1000;
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int arr1[Size];
//
//	FillArray(arr1, Size, 1, 1000);
//	int resultBubbleSorting = AdvancedBubbleSorting(arr1, Size);
//
//	FillArray(arr1, Size, 1, 1000);
//	int resultSelectionSorting = SelectionSorting(arr1, Size);
//	
//	cout << "Среднее число перестановок при использовании пузырьковой сортировки:" << endl;
//	cout << resultBubbleSorting << endl;
//	cout << endl;
//	cout << "Среднее число перестановок при использовании сортировки выбором:" << endl;
//	cout << resultSelectionSorting << endl;
// 
//	cout << endl;
//	system("pause");
//}