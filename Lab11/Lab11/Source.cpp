#pragma warning(disable : 4996)
#include <string>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <time.h>
using namespace std;

void cls() {

	system("cls");

} // фукнция чистки экрана

char FileName[] = "list.txt";


int HowElementsInFile(char FileName[]) {

	int Count = 0; // счетчик кол-ва строк в файле
	int Num = 0; // считываемая строка

	ifstream Read(FileName);

	while (Read >> Num)
		Count++; // увеличиваем счетчик при считывании строки

	Read.close();

	return Count;

} // функция подсчета кол-ва элементов в файле

// Описание структуры
struct Telem
{
	int inf;
	Telem* link;
} *begL, * endL;
//================================================================
// Добавление элемента в начало списка
void addElemAToBeginList()
{
	Telem* p = new Telem;
	printf("Введите новый элемент: ");
	scanf("%d", &p->inf);
	if (begL == NULL)
	{
		endL = p;
	}
	p->link = begL;
	begL = p;
	printf("\n");
};
//================================================================
// Добавление элемента в конец списка
void addElemToEndList()
{
	Telem* p = new Telem;
	printf("Введите новый элемент: ");
	scanf("%d", &p->inf);
	if (begL == NULL)
	{
		begL = p;
	}
	else
	{
		endL->link = p;
	}
	p->link = NULL;
	endL = p;
	printf("\n");
};
//================================================================
// Подсчёт общего количества элементов списка
int countElem()
{
	Telem* p = begL;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}

	return count;
};
//================================================================
// Вставка элемента в список после заданного
void insertElemAfterSet()
{
	Telem* p = new Telem;
	Telem* pk = begL; // Указатель на заданный элемент
	if (begL == NULL)
	{
		printf("Список уже пуст, вставить невозможно!");
		printf("\n\n");
	}
	else
	{
		int index;
		printf("Общее кол-во элементов в списке: %d", countElem());
		printf("\n\n");
		printf("Введите номер элемента после которого вставить новый элемент: ");
		scanf("%d", &index);
		printf("\n");
		if ((index >= countElem()) || (index <= 0))
		{
			printf("Вставка элемента невозможна, список не сформирован!\n\n");
		}
		else
		{
			for (int i = 1; i < index; i++)
			{
				pk = pk->link;
			}
			printf("Введите новый элемент: ");
			scanf("%d", &p->inf);
			p->link = pk->link;
			pk->link = p;
			printf("\n");
		}
	}
};
//================================================================
// Вставка элемента в список перед заданным
void insertElemBeforeSet()
{
	Telem* p = new Telem;
	Telem* pk = begL; // Указатель на заданный элемент
	if (begL == NULL)
	{
		printf("Список пуст, вставиь невозможно");
		printf("\n\n");
	}
	else
	{
		int index;
		printf("Общее кол-во элементов в списке: %d", countElem());
		printf("\n\n");
		printf("Введите номер элемента после которого вставить новый элемент: ");
		scanf("%d", &index);
		printf("\n");
		if ((index > countElem()) || (index <= 1))
		{
			printf("Вставка элемента невозможна, список не сформирован!\n\n");
		}
		else
		{
			for (int i = 1; i < index; i++)
			{
				pk = pk->link;
			}
			printf("Введите новый элемент: ");
			scanf("%d", &p->inf);
			p->link = pk->link;
			pk->link = p;
			int tmp = pk->inf;
			pk->inf = p->inf;
			p->inf = tmp;
			printf("\n");
		}
	}
};
//================================================================
// Удаление элемента из начала списка
void deleteElemFromBeginList()
{
	Telem* p = begL;
	if (p == NULL)
	{
		printf("Список уже был пуст!");
		printf("\n\n");
	}
	else
	{
		begL = p->link;
		delete p;
	}
};
//================================================================
// Удаление элемента из конца списка
void deleteElemFromEndList()
{
	Telem* p = begL;
	if (p == NULL)
	{
		printf("Список уже был пуст!");
		printf("\n\n");
	}
	else
	{
		while ((p->link != endL) && (p->link != NULL))
		{
			p = p->link;
		}
		if (begL == endL)
		{
			begL = begL->link;
			endL = NULL;
			delete p;
		}
		else
		{
			endL = p;
			delete p->link;
			endL->link = NULL;
		}
	}
};
// Очистка всего списка
void deleteAllElem(bool Flag = false)
{
	Telem* p = begL;
	if (p == NULL && Flag == true)
	{
		printf("Список уже пуст!");
		printf("\n\n");
	}
	else
	{
		while (p != NULL)
		{
			begL = p->link;
			delete p;
			p = begL;
		}
		if (Flag == true)
			cout << "Список был удален!\n";
	}

};
//================================================================
// Отображение списка
void printListFromBeginToEnd(bool Flag = true)
{
	Telem* p = begL;
	if (p == NULL && Flag == false)
	{
		printf("Список пуст!");
		printf("\n\n");
	}
	else
	{
		printf("Элементы списка: ");
		while (p != NULL)
		{
			printf("%d ", p->inf);
			p = p->link;
		}
		printf("\n\n");
	}
};
// функция сохранения списка в файл
void Save_To_File(char FileName[], bool Flag = false) {

	ofstream Write(FileName);
	Telem* p = begL;
	if (p == NULL)
	{
		printf("Список пуст!");
		printf("\n\n");
	}
	else
	{
		while (p != NULL)
		{
			Write << p->inf << " ";
			p = p->link;
		}
	}

	Write.close();

	if (Flag == true) {

		deleteAllElem();
		printListFromBeginToEnd();

	}
}
// функция загрузки списка из файла
void Load_From_File(char FileName[], bool Flag = false) {

	deleteAllElem(false);
	ifstream Read(FileName);

	for (int i = 0; i < HowElementsInFile(FileName); i++) {

		Telem* p = new Telem;
		Read >> p->inf;

		if (begL == NULL)
		{
			begL = p;
		}
		else
		{
			endL->link = p;
		}
		p->link = NULL;
		endL = p;

	}

	if (Flag == true) {

		printf("Элементы успешно были считаны!\n");


	}

	printListFromBeginToEnd();

	Read.close();

}
// функция добавления K элементов
void Add_K_Elements() {

	int K = 0;
	int Start = 0;

	cout << "Добавление - Введите число K: ";
	cin >> K;

	cout << "Задайте № элемента, с которого начнется добавление: ";
	cin >> Start;

	char TempFile[] = "temp.txt";

	Save_To_File(TempFile);
	int Size = HowElementsInFile(FileName);

	int* Array = new int[Size * Size];

	ifstream Read(FileName);

	for (int i = 0; i < Size; i++)
		Read >> Array[i];

	Read.close();

	int Index = 0;

	int* Temp = new int[Size];

	for (int i = 0; i < Size; i++)
		Temp[i] = Array[i]; // копирование массива в другой временный

	for (int i = 0; i < Size + K; i++) {

		if (i >= Start && i < (Start + K))
			Array[i] = -10 + rand() % 30;

		else {

			Array[i] = Temp[Index];
			Index++;

		}



	}

	delete[] Temp;
	Size = Size + K;

	ofstream Write(TempFile);

	for (int i = 0; i < Size; i++)
		Write << Array[i] << " ";

	Write.close();

	Load_From_File(TempFile, false);
	cout << "\nПолучившийся список: ";
	printListFromBeginToEnd();

	delete[] Array;

}

void Delete_K_Elements() {

	int K = 0;
	int Start = 0;

	cout << "Добавление - Введите число K: ";
	cin >> K;

	cout << "Задайте № элемента, с которого начнется добавление: ";
	cin >> Start;

	char TempFile[] = "temp.txt";

	Save_To_File(TempFile);
	int Size = HowElementsInFile(FileName);

	int* Array = new int[Size * Size];

	ifstream Read(FileName);

	for (int i = 0; i < Size; i++)
		Read >> Array[i];

	Read.close();

	int Index = 0;

	for (int i = 0; i < Size; i++) {

		if (i < Start || i >= (Start + K)) {

			Array[Index] = Array[i];
			Index++;

		}

	}


	Size = Index;

	ofstream Write(TempFile);

	for (int i = 0; i < Size; i++)
		Write << Array[i] << " ";

	Write.close();

	Load_From_File(TempFile, false);
	cout << "\nПолучившийся список: ";
	printListFromBeginToEnd();

	delete[] Array;

}

int drawMenu()
{
	int numb;
	puts("			Меню программы:\n");
	puts(" 1 - Добавление элемента в начало списка");
	puts(" 2 - Добавление элемента в конец списка");
	puts(" 3 - Вставка элемента в список после заданного");
	puts(" 4 - Вставка элементв в список перед заданным");
	puts(" 5 - Удаление элемента из начала списка");
	puts(" 6 - Удаление элемента из конца списка");
	puts(" 7 - Очистка всего списка");
	puts(" 8 - Отображение списка");
	puts(" 9 - Запись в файл всего списка");
	puts(" 10 - Чтение из файла списка");
	puts(" 11 - Добавление K элементов, начиная с заданного номера");
	puts(" 12 - Удаление K элементов, начиная с заданного номера");
	puts(" 0 - Выход из программы");
	printf("\nВыберите один из пунктов меню: ");
	scanf("%d", &numb);

	return numb;
};
//================================================================

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // кириллица в консоли
	system("title Лабораторная работа № 11, задание 5");
	srand((unsigned short)time(NULL));

	begL = endL = NULL;
	int numb;
	do
	{
		do
		{
			numb = drawMenu();
			printf("\n");
		} while ((numb <= 1) && (numb >= 12));

		cls();
		switch (numb)
		{
		case 1:
		{
			addElemAToBeginList();
			break;
		}
		case 2:
		{
			addElemToEndList();
			break;
		}
		case 3:
		{
			insertElemAfterSet();
			break;
		}
		case 4:
		{
			insertElemBeforeSet();
			break;
		}
		case 5:
		{
			deleteElemFromBeginList();
			break;
		}
		case 6:
		{
			deleteElemFromEndList();
			break;
		}
		case 7:
		{
			deleteAllElem();
			break;
		}
		case 8:
		{
			printListFromBeginToEnd();
			break;
		}

		case 9:
		{
			Save_To_File(FileName, true);
			break;
		}

		case 10:
		{
			Load_From_File(FileName, true);
			break;

		}

		case 11:
		{
			Add_K_Elements();
			break;

		}

		case 12:
		{
			Delete_K_Elements();
			break;

		}

		}
	} while (numb != 0);

	deleteAllElem();

	return 0; // завершение программы

}
