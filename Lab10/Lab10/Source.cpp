#include <string>
#include <windows.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

void PrintArray(int* a, int n) {

	int i = 0;
	printf("Кол-во элементов: %d\n", n);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

} // функция отображения массива

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // кириллица в консоли
	system("title Лабораторная работа № 10, задание 5");
	srand((unsigned short)time(NULL));

	int N = 0; // размерность массива
	int K = 0; // кол-во изменяемых элементов
	int Start = 0; // номер элемента, с которого будут происходить изменения элементов

	cout << "Сформировать одномерный массив. Удалить из него К элементов, начиная с заданного номера,\nдобавить К элементов, начиная с заданного номера\n\n";
	cout << "Задайте размерность массива: ";
	cin >> N;

	int* Array = new int[N * N];

	for (int i = 0; i < N * N; i++)
		Array[i] = 0; // зануление элементов

	for (int i = 0; i < N; i++)
		Array[i] = -10 + rand() % 30; // рандом значений элементов

	cout << "\nИсходный массив:\n\n";
	PrintArray(Array, N);
	cout << "\n\nУдаление - Введите число K: ";
	cin >> K;

	cout << "Задайте № элемента, с которого начнется удаление: ";
	cin >> Start;

	int Index = 0;

	for (int i = 0; i < N; i++) {

		if (i < Start || i >= (Start + K)) {

			Array[Index] = Array[i];
			Index++;

		}

	}


	N = Index;
	cout << "\nПолучившийся массив после удаления:\n\n";
	PrintArray(Array, N);
	cout << "\n\nДобавление - Введите число K: ";
	cin >> K;

	cout << "Задайте № элемента, с которого начнется добавление: ";
	cin >> Start;

	int* Temp = new int[N];

	for (int i = 0; i < N; i++)
		Temp[i] = Array[i]; // копирование массива в другой временный

	Index = 0;

	for (int i = 0; i < N + K; i++) {

		if (i >= Start && i < (Start + K))
			Array[i] = -10 + rand() % 30;

		else {

			Array[i] = Temp[Index];
			Index++;

		}



	}

	delete[] Temp;
	N = N + K;
	cout << "\nПолучившийся массив после добавления:\n\n";
	PrintArray(Array, N);

	delete[] Array;

	system("pause");

	return 0; // завершение программы

}
