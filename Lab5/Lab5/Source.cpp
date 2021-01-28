#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // ��������� � �������
	system("title ������������ ������ � 5, ������� 5");

	cout << "���������� �������� �� ������� �����������������, �. �. �����, ��� ��������� ������������ ������\n ���� ��������� ����� ����� 0, � ��������� ������������ ������ ����� �� ���� ����� 1\n\n";

	int sum = 0;
	int square = 0;
	int n = 0; // ����������� �������

	cout << "������� ���������� �������: ";
	cin >> n;

	int** a = new int* [n];

	for (int i = 0; i < n; i++)
		a[i] = new int[n]; // ��������� ������������ ������ ��� �������

//���� ���������
	cout << "\n��������� �������� �������:\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << "[" << i << "][" << j << "]: ";
			cin >> a[i - 1][j - 1];
		}
		cout << "\n";
	}

	//����� ���������
	cout << "\n������������ �������:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	//��������� ����������� �����
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

	//��������� ������������ ������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			square += a[i][j] * a[i][j];
		}
	}

	//�����
	if (sum > 0 || square != 3) {
		cout << "\n������� �� �����������������!" << endl;
	}
	else {
		cout << "\n������� �����������������!" << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] a[i];

	delete[] a; // ������������� ������
	system("pause");

	return 0; // ���������� ���������

}
