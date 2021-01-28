#include <string>
#include <windows.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // кириллица в консоли
	system("title Лабораторная работа № 1, задание 5");

	cout << "Задание 1: Данная программа вычисляет следующее:\n";
	cout << "(a + b)^3 - (a^3)\n";
	cout << "----------------------\n";
	cout << "3ab^2 + b^3 + 3a^2b\n\n";

	double a = 1000.0;
	double b = 0.0001;

	cout << "a = " << a << "\n";
	cout << "b = " << b << "\n";

	double Numerator = (pow(a, 3) - 3 * pow(a, 2) * b + 3 * a * pow(b, 2) - pow(b, 3)) - (pow(a, 3) - 3 * a * pow(b, 2)); // числитель
	double Denominator = pow(b, 3) - 3 * pow(a, 2) * b; // знаменатель
	double Result = Numerator / Denominator; // результат

	cout << "\nЧислитель равен: " << Numerator << "\n";
	cout << "\nЗнаменатель равен: " << Denominator << "\n";
	cout << "Результат вычисления: " << Result << "\n";

	cout << "\n\nЗадание 2: Данная програмама вычисляет значений выражений: \n";
	cout << "1) --m-++n\n";
	cout << "2) m*n<n++\n";
	cout << "3) n-- > m++\n";

	double n = 0.0;
	double m = 0.0;

	cout << "\nЗадайте значение n: ";
	cin >> n;
	cout << "\nЗадайте значение m: ";
	cin >> m;

	double Res1 = m * n < n++;
	double Res2 = n-- > m++;
	cout << "\nРезультат:\n";
	cout << "1. " << --m - ++n << "\n";
	cout << "2. " << Res1 << "\n";
	cout << "3. " << Res2 << "\n";

	system("pause");

	return 0; // завершение программы

}