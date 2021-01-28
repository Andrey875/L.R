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
	SetConsoleOutputCP(1251); // кириллица в консоли
	system("title Лабораторная работа № 6, задание 5");

	cout << "Напечатать все слова, которые совпадают с ее первым словом\n\n";

	char S[255];
	int l = 0;
	int z = 0;
	puts("Введите предложение: ");
	gets_s(S);
	char* ptr;
	char* secptr;
	ptr = strtok(S, " ");
	secptr = ptr;
	ptr = strlwr(ptr);
	cout << "\nПервое слово: " << ptr << "\n\n";
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
				cout << "Слово совпадающее с первым в строке: " << secptr << '\n';
			l = 0;
		}
	}

	system("pause");

	return 0; // завершение программы

}