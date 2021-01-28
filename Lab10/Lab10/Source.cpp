#include <string>
#include <windows.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

void PrintArray(int* a, int n) {

	int i = 0;
	printf("���-�� ���������: %d\n", n);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

} // ������� ����������� �������

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // ��������� � �������
	system("title ������������ ������ � 10, ������� 5");
	srand((unsigned short)time(NULL));

	int N = 0; // ����������� �������
	int K = 0; // ���-�� ���������� ���������
	int Start = 0; // ����� ��������, � �������� ����� ����������� ��������� ���������

	cout << "������������ ���������� ������. ������� �� ���� � ���������, ������� � ��������� ������,\n�������� � ���������, ������� � ��������� ������\n\n";
	cout << "������� ����������� �������: ";
	cin >> N;

	int* Array = new int[N * N];

	for (int i = 0; i < N * N; i++)
		Array[i] = 0; // ��������� ���������

	for (int i = 0; i < N; i++)
		Array[i] = -10 + rand() % 30; // ������ �������� ���������

	cout << "\n�������� ������:\n\n";
	PrintArray(Array, N);
	cout << "\n\n�������� - ������� ����� K: ";
	cin >> K;

	cout << "������� � ��������, � �������� �������� ��������: ";
	cin >> Start;

	int Index = 0;

	for (int i = 0; i < N; i++) {

		if (i < Start || i >= (Start + K)) {

			Array[Index] = Array[i];
			Index++;

		}

	}


	N = Index;
	cout << "\n������������ ������ ����� ��������:\n\n";
	PrintArray(Array, N);
	cout << "\n\n���������� - ������� ����� K: ";
	cin >> K;

	cout << "������� � ��������, � �������� �������� ����������: ";
	cin >> Start;

	int* Temp = new int[N];

	for (int i = 0; i < N; i++)
		Temp[i] = Array[i]; // ����������� ������� � ������ ���������

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
	cout << "\n������������ ������ ����� ����������:\n\n";
	PrintArray(Array, N);

	delete[] Array;

	system("pause");

	return 0; // ���������� ���������

}
