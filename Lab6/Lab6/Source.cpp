#pragma warning(disable : 4996)
#include <string>
#include <windows.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // ��������� � �������
	system("title ������������ ������ � 6, ������� 5");

	cout << "���������� ��� �����, ������� ��������� � �� ������ ������\n\n";

	char S[255];
	int l = 0;
	int z = 0;
	puts("������� �����������: ");
	gets_s(S);
	char* ptr;
	char* secptr;
	ptr = strtok(S, " ");
	secptr = ptr;
	ptr = strlwr(ptr);
	cout << "\n������ �����: " << ptr << "\n\n";
	while (secptr != 0)
	{
		secptr = strtok(0, "' ' . ");
		if (secptr)
		{
			if (strlen(ptr) > strlen(secptr))
				z = strlen(ptr);
			else
				z = strlen(secptr);
			for (int i = 0; i < z; i++)
			{
				if (secptr[i] == ptr[i])
					l++;
			}
			if (l == z)
				cout << "����� ����������� � ������ � ������: " << secptr << '\n';
			l = 0;
		}
	}

	system("pause");

	return 0; // ���������� ���������

}