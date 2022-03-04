#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int maxDiv(int num1, int num2);

int resurveNumber(int num);

int sortArrAndSearch(int array[], int length, int key);

void randomArr(int array[], int length, int num1, int num2);


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n1, n2;

			//Задача 1
	cout << "Задача 1\nВведите два числа: ";
	cin >> n1 >> n2;
	cout << "Наибольший общий делитель этих двух чисел = " << maxDiv(n1, n2) << endl << endl;

			//задача 2
	cout << "Задача 2\nВведите число: ";
	cin >> n1;
	cout <<"Зеркальное число числа " << n1 << " = " << resurveNumber(n1) << endl << endl;

			//Задача 3
	cout << "Задача 3" << endl;
	cout << "Дан изначальный массив из 50-и элементов:\n[";
	int arr[50];
	for (int i = 0; i < 50; i++) {
		arr[i] = rand() % 50 + 1;
		cout << arr[i] << ", ";
	}
	cout << "\b\b]\n";
	cout << "Введите число: ";
	cin >> n1;
	
	cout << "Первая позиция числа " << n1 << " = " << sortArrAndSearch(arr, 50, n1) << endl << endl;
	
			//Задача 4
	cout << "Задача 4\nВведите диапазон рандома: ";
	cin >> n1 >> n2;
	if (n1 > n2)
		swap(n1, n2);
	int z1[500];
	randomArr(z1, 500, n1, n2);
	


	return 0;
}
void randomArr(int array[], int length, int num1, int num2) {
	cout << "Заполненый массив:\n[";
	for (int i = 0; i < length; i++) {
		array[i] = rand() % ((num2) - (num1) + 1) + (num1);
		cout << array[i] << ", ";
	}
	cout << "\b\b]\n\n";
}

int sortArrAndSearch(int array[], int length, int key) {
	int n = -1;
	for (int i = 0; i < length; i++) {
		if (array[i] == key) {
			n = i;
			break;
		}
	}
	for (int i = length - 1; i > n; i--)				
		for (int j = n; j < i; j++)
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
	cout << "отсортированный массив:\n[";
	for (int i = 0; i < length; i++) {
		cout << array[i] << ", ";
	}
	cout << "\b\b]\n\n";

	return n;
}

int resurveNumber(int num) {		//тут я загуглил этот код, но всё равно не понимаю как он работает... пытался пропустить через отладчик, но он не показывает работу функции.
		int n = 0;
		while (num) {
			n = 10 * n + num % 10;
			num /= 10;
		}

		return n;
	}

int maxDiv(int num1, int num2) {
	int n = 0;
	for (int i = 1; i <= num1; i++)
		if (num1 % i == 0 && num2 % i == 0)
			n = i;
	return n;
}