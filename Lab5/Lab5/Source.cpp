#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // кириллица в консоли
	system("title Лабораторная работа № 5, задание 5");

	cout << "Определить является ли матрица ортонормированной, т. е. такой, что скалярное произведение каждой\n пары различных строк равно 0, а скалярное произведение строки самой на себя равно 1\n\n";

	int sum = 0;
	int square = 0;
	int n = 0; // размерность матрицы

	cout << "Задайте размернось матрицы: ";
	cin >> n;

	int** a = new int* [n];

	for (int i = 0; i < n; i++)
		a[i] = new int[n]; // выделение динамической памяти под матрицу

//Ввод элементов
	cout << "\nЗаполните элементы матрицы:\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << "[" << i << "][" << j << "]: ";
			cin >> a[i - 1][j - 1];
		}
		cout << "\n";
	}

	//Вывод элементов
	cout << "\nПолучившаяся матрица:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	//Скалярное прозиведние строк
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++) {
				if (k != i) {
					sum += a[i][j] * a[k][j];
				}
				else {
					continue;
				}
			}
		}
	}

	//Скалярное произведение строки
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			square += a[i][j] * a[i][j];
		}
	}

	//Вывод
	if (sum > 0 || square != 3) {
		cout << "\nМатрица не ортонормированная!" << endl;
	}
	else {
		cout << "\nМатрица ортонормированная!" << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] a[i];

	delete[] a; // высвобождение памяти
	system("pause");

	return 0; // завершение программы

}
