#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;

long double fact(int N)
{
	if (N < 0) // ���� ������������ ���� ������������� �����
		return 0; // ���������� ����
	if (N == 0) // ���� ������������ ���� ����,
		return 1; // ���������� ��������� �� ���� - �� �����������, �� ��� 1 =)
	else // �� ���� ��������� �������
		return N * fact(N - 1); // ������ ��������.
}

double f(double x)
{
	double e = 2.7182818284;
	return pow(e, x);

}

double S(double x, int n, double e)
{
	double S = 0;

	do {

		for (int i = 0; i < n; i++)
			S += (pow(x, i) / fact(i));

	} while (e >= abs(f(x)));


	return S;
}

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // ��������� � �������
	system("title ������������ ������ � 3, ������� 5");

	double xn = 1.0, xk = 2.0, dx = 0.1, s = 0.0;
	double e = 0.0001;
	int i = 0;
	int n = 15;

	cout << "��� � ������������� �� a �� b � ����� (b-a)/k, ��� (k=10), ��������� ������� f(x)\n, ��������� �� ���������� � ��������� ��� � ���� �������:\n";
	cout << "�) ��� ��������� n\n";
	cout << "�) ��� �������� �������� e (e=0.0001)\n";
	cout << "��� ��������� ����� ������ �������� �������\n\n";
	cout << "�������: " << "y = e^x � ��������� " << xn << " <= x <= " << xk;
	cout << "\nn = " << n << "\n";
	cout << "�����: " << "S = 1 + (x / 1!) + (x^2 / 2!)...\n\n";

	cout << "���������: \n";

	double* x = new double[n];
	double* y = new double[n];
	cout << "|  x  |  Sum  |  f(x)  |\n";
	x[i] = xn;
	while (x[i] <= (xk + 0.1))
	{
		y[i] = f(x[i]);
		s = S(x[i], n, e);
		cout << setw(5) << setprecision(3) << x[i] << " | "
			<< setw(5) << setprecision(3) << s << " | "
			<< setw(5) << setprecision(3) << y[i] << " | "
			<< endl;
		i = i + 1;
		x[i] = x[i - 1] + dx;
	}

	system("pause");

	delete[] x;
	delete[] y;
	return 0;

}
