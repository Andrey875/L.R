#include <string>
#include <windows.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // кириллица в консоли
	system("title Лабораторная работа № 2, задание 5");

	cout << "Данная программа находит сумму ряда с точностью e=10-4, общий член которого:\n";
	cout << "(-1)^(n-1)\n";
	cout << "----------\n";
	cout << "     n^n  \n";

	double Eps = pow(10, -4); // точность
	double n = 0; // число
	double a = 0; // промежуточный результат
	double Sum = 0; // итоговый результат

	cout << "\nЗадайте значение n: ";
	cin >> n;

	do {

		a = (pow(-1, (n - 1))) / pow(n, n);
		Sum += a;
		n++;

	} while (abs(a) > Eps);

	cout << "\nСумма ряда,вычисленная с заданной точностью  =  " << Sum << endl;
	system("pause");

	return 0; // завершение программы

}
