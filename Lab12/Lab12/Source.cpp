#include <string>
#include <windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;

void print_info(string name = "Anon", int course = 0, int age = 0) {
	printf("Name: %s\nCourse: %d\nAge: %d\n", name.c_str(), course, age);
}

/// <summary>
/// ����� ������������� � ������������������
/// </summary>
/// <param name="amount">���������� ��������� � ������������������</param>
/// <param name="">amount ����������</param>
void print_max_even(int amount, ...) {
	int* p_i = &amount;
	int max = *(++p_i);

	int j = 1;
	while ((amount--) > 0) {
		if (j % 2 == 0 && max < *p_i) {
			max = *p_i;
		}
		p_i++;
		j++;
	}

	cout << "Max in array: " << max << endl;
}

int find_max(int size, int* arr) {
	int max = arr[0];

	for (int i = 1; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	return max;
}

double find_max(int size, float* arr) {
	float max = arr[0];

	for (int i = 1; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	return max;
}

template <typename T>
T find_max_t(int size, T* arr) {
	T max = arr[0];

	for (int i = 1; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	return max;
}


typedef float(*fptr)(float);
/// <summary>
/// ������� ������ ������� �������
/// </summary>
/// <param name="f">�������</param>
/// <param name="df">����������� �������</param>
/// <param name="eps">��������</param>
/// <param name="a">����� �������</param>
/// <param name="b">������ �������</param>
/// <returns>��������� �</returns>
float newton(fptr f, fptr df, float eps, int a, int b) {
	float x0 = a;
	float x = a;

	while ((f(x + eps) * f(x - eps)) > 0) {
		x = x0 - f(x0) / df(x0);
		x0 = x;
	}

	return x;
}

float f(float x) {
	return 0.25* x* x* x + x - 1.2502;
}

float df(float x) {
	return 0.75* x* x + 1;
}

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // ��������� � �������
	system("title ������������ ������ � 7 (�� 2-�� ���������), ������� 5");

	// Task 1 
	cout << "Task 1: �������� ������� � ������������� ����������� � ������������ � ���������, ������������������ ��������� ������� ������ �������\n";
	print_info("Leha", 3, 12);
	cout << endl;
	print_info();
	cout << endl;
	print_info("Leha");
	cout << endl;

	// Task 2
	cout << "Task 2: �������� ������� � ���������� ������ ���������� � ������������ � ���������, ������������������ ����� ������� � ��������� ������ ����������\n";
	print_max_even(4, 2, 3, 4, 5);
	cout << endl;

	// Task 3
	cout << "Task 3: �������� ������������� ������� � ������������ � ���������. �������� ���������������� ��������� ��� ������ ���� �������\n";
	int iarr[3] = { 1, 2, 3 };
	float farr[3] = { 4.0f, 5.0f, 6.0f };
	cout << find_max(sizeof(iarr) / sizeof(int), iarr) << endl;
	cout << find_max(sizeof(farr) / sizeof(float), farr) << endl;
	cout << endl;

	// Task 4
	cout << "Task 4: �������� ������ ������� ������ ������������� ������� �� ������� 3. �������� ���������������� ��������� ��� ������ ���� �������. ������ ����������\n";
	int iarr2[3] = { 1, 2, 3 };
	cout << find_max_t(sizeof(iarr2) / sizeof(int), iarr2) << endl;
	float farr2[3] = { 7.0f, 8.0f, 9.0f };
	cout << find_max_t(sizeof(farr2) / sizeof(int), farr2) << endl;
	cout << endl;

	// Task 5
	cout << "Task 5: ������ ��������� ��������� � �������� �������. ��������� �������� � ������� ��� �������� � ������� ���������.\n";

	cout << "x = " << newton(f, df, 1.0001f, 0, 2);

	system("pause");

	return 0; // ���������� ���������

}
