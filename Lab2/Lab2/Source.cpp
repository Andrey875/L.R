#include <string>
#include <windows.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // ��������� � �������
	system("title ������������ ������ � 2, ������� 5");

	cout << "������ ��������� ������� ����� ���� � ��������� e=10-4, ����� ���� ��������:\n";
	cout << "(-1)^(n-1)\n";
	cout << "----------\n";
	cout << "     n^n  \n";

	double Eps = pow(10, -4); // ��������
	double n = 0; // �����
	double a = 0; // ������������� ���������
	double Sum = 0; // �������� ���������

	cout << "\n������� �������� n: ";
	cin >> n;

	do {

		a = (pow(-1, (n - 1))) / pow(n, n);
		Sum += a;
		n++;

	} while (abs(a) > Eps);

	cout << "\n����� ����,����������� � �������� ���������  =  " << Sum << endl;
	system("pause");

	return 0; // ���������� ���������

}
