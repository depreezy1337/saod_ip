#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <conio.h>
//#include <graphics.h>
#include<ctime>
#pragma warning(disable:4996)

using namespace std;


struct record
{
	char employee[30];
	short int department;
	char post[22];
	char birthdate[10];
	

	bool operator >(record other) {
		if (department == other.department) {
			for (int i = 0; i < 30; i++) {
				if (this->employee[i] == other.employee[i])
					continue;
				return this->employee[i] > other.employee[i];
			}
		}
		return department > other.department;
		
	}
};
void heapify(record* arr, int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(record* arr, int n)
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}

/* Вспомогательная функция для вывода на экран массива размера n*/
//void printArray(int arr[], int n)
//{
//	for (int i = 0; i < n; ++i)
//		cout << arr[i] << " ";
//	cout << "\n";
//}



int main()
{
	SetConsoleOutputCP(866);
	FILE* fp;
	fp = fopen("testBase2.dat", "rb");
	record* mas = new record[4000];
	int i = 0, sum = 0;
	int ch[10];
	i = fread((record*)mas, sizeof(record), 4000, fp);
	heapSort(mas,4000);
	for (int i = 0; i < 30; i++){
		char c = mas[14].employee[i];
		cout << c;
	}
		
	
		



	for (int i = 0, j = 0; i < 4000; ++i, ++j) {
		if (j == 20) {
			SetConsoleOutputCP(1251);
			cout << "Нажмите любую клавишу, чтобы продолжить или введите q для выхода ";
			SetConsoleOutputCP(866);
			char c = getch();
			if (c == 'q')
				break;
			system("cls");
			j = 0;
		}
		cout << mas[i].employee << "\t" << mas[i].department << "\t" << mas[i].post << "\t" << mas[i].birthdate << "\t" << endl;
	}
	return 0;
}