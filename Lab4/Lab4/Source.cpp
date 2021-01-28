#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>
#include <iostream>

using namespace std;

void PrintArray(long* a, int n) {

	int i = 0;
	printf("Кол-во элементов: %d\n", n);
	for (i = 0; i < n; i++) {
		printf("%ld ", a[i]);
	}

} // функция отображения массива

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // кириллица в консоли
	system("title Лабораторная работа № 4, задание 5");
	srand((unsigned short)time(NULL));

	long i, i1, k, n;
	long* a;

	cout << "1)Сформировать одномерный массив целых чисел, используя датчик случайных чисел.\n";
	cout << "2)Распечатать полученный массив.\n";
	cout << "3)Удалить элементы кратные 7.\n";
	cout << "4)Добавить после каждого нечетного элемента массива эле-мент со значением 0.\n";
	cout << "5)Распечатать полученный массив.\n\n";

	cout << "Введите первоначальную размерность массива: ";
	cin >> n;

	a = new long[n * n];

	for (i = 0; i < n; i++)
		a[i] = 0 + rand() % 10;

	cout << "\n\nИзначальный массив:\n";
	PrintArray(a, n);

	k = 0;

	for (i = 0;; i++) {

		for (i1 = i + k; i1 < n; i1++) {

			if ((a[i1] % 7) == 0)
				k++;
			else
				break;

		}
		if (i1 >= n)
			break;

		if (k > 0)
			a[i] = a[i1];

	}

	n = n - k;

	cout << "\n\nПолучившийся массив после удаление элементов кратных 7:\n";
	PrintArray(a, n);

	if ((n % 2) == 0)
		k = n / 2;

	else
		k = (n + 1) / 2;

	n = n + k;

	for (i = n - 1; i >= 0; i--) {
		if ((i % 3) == 1) {
			a[i] = 0;
			k--;
		}
		else {
			if (k > i)break;
			a[i] = a[i - k];
		}
	}

	cout << "\n\nКонечный массив, после добавления 0 на каждый нечетный элемент:\n";
	PrintArray(a, n);
	cout << "\n\n";

	system("pause");

	delete[] a;
	return 0;

}
