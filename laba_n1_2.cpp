#include <iostream>
#define zadanie 2
using namespace std;


int* genRandArray(int size, int maxValue) {
	int* arr = new int[size + 1];
	arr[0] = size;
	for (int i = 1; i < size + 1; i++) {
		arr[i] = rand() % (maxValue + 1);
	}
	return arr;
}




void print(int* arr) {
	cout << arr[0] << ": ";
	for (int i = 1; i < arr[0] + 1; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;

}





int** genRandMatrix(int size, int maxValue) {
	int** arr = new int* [size];

	for (int i = 0; i < size; i++) {

		arr[i] = genRandArray(rand() % 10, maxValue);

	}
	return arr;
}
void printMatrix(int** matrix) {
	int size = _msize(matrix) / sizeof(matrix[0]);
	cout << size << endl;
	for (int i = 0; i < size; i++) {
		print(matrix[i]);
	}

}




int main() {
	srand(time(NULL));

	int size = rand() % 10;
	int maxValue = 100;

	if (zadanie == 1) {
		int* arr = genRandArray(size, maxValue);
		print(arr);
		delete[] arr;
	}
	else if (zadanie == 2) {
		int** matrix = genRandMatrix(size, maxValue);
		printMatrix(matrix);
		delete[] matrix;
	}

	}
