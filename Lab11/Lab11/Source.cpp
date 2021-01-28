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

} // ������� ������ ������

char FileName[] = "list.txt";


int HowElementsInFile(char FileName[]) {

	int Count = 0; // ������� ���-�� ����� � �����
	int Num = 0; // ����������� ������

	ifstream Read(FileName);

	while (Read >> Num)
		Count++; // ����������� ������� ��� ���������� ������

	Read.close();

	return Count;

} // ������� �������� ���-�� ��������� � �����

// �������� ���������
struct Telem
{
	int inf;
	Telem* link;
} *begL, * endL;
//================================================================
// ���������� �������� � ������ ������
void addElemAToBeginList()
{
	Telem* p = new Telem;
	printf("������� ����� �������: ");
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
// ���������� �������� � ����� ������
void addElemToEndList()
{
	Telem* p = new Telem;
	printf("������� ����� �������: ");
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
// ������� ������ ���������� ��������� ������
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
// ������� �������� � ������ ����� ���������
void insertElemAfterSet()
{
	Telem* p = new Telem;
	Telem* pk = begL; // ��������� �� �������� �������
	if (begL == NULL)
	{
		printf("������ ��� ����, �������� ����������!");
		printf("\n\n");
	}
	else
	{
		int index;
		printf("����� ���-�� ��������� � ������: %d", countElem());
		printf("\n\n");
		printf("������� ����� �������� ����� �������� �������� ����� �������: ");
		scanf("%d", &index);
		printf("\n");
		if ((index >= countElem()) || (index <= 0))
		{
			printf("������� �������� ����������, ������ �� �����������!\n\n");
		}
		else
		{
			for (int i = 1; i < index; i++)
			{
				pk = pk->link;
			}
			printf("������� ����� �������: ");
			scanf("%d", &p->inf);
			p->link = pk->link;
			pk->link = p;
			printf("\n");
		}
	}
};
//================================================================
// ������� �������� � ������ ����� ��������
void insertElemBeforeSet()
{
	Telem* p = new Telem;
	Telem* pk = begL; // ��������� �� �������� �������
	if (begL == NULL)
	{
		printf("������ ����, ������� ����������");
		printf("\n\n");
	}
	else
	{
		int index;
		printf("����� ���-�� ��������� � ������: %d", countElem());
		printf("\n\n");
		printf("������� ����� �������� ����� �������� �������� ����� �������: ");
		scanf("%d", &index);
		printf("\n");
		if ((index > countElem()) || (index <= 1))
		{
			printf("������� �������� ����������, ������ �� �����������!\n\n");
		}
		else
		{
			for (int i = 1; i < index; i++)
			{
				pk = pk->link;
			}
			printf("������� ����� �������: ");
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
// �������� �������� �� ������ ������
void deleteElemFromBeginList()
{
	Telem* p = begL;
	if (p == NULL)
	{
		printf("������ ��� ��� ����!");
		printf("\n\n");
	}
	else
	{
		begL = p->link;
		delete p;
	}
};
//================================================================
// �������� �������� �� ����� ������
void deleteElemFromEndList()
{
	Telem* p = begL;
	if (p == NULL)
	{
		printf("������ ��� ��� ����!");
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
// ������� ����� ������
void deleteAllElem(bool Flag = false)
{
	Telem* p = begL;
	if (p == NULL && Flag == true)
	{
		printf("������ ��� ����!");
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
			cout << "������ ��� ������!\n";
	}

};
//================================================================
// ����������� ������
void printListFromBeginToEnd(bool Flag = true)
{
	Telem* p = begL;
	if (p == NULL && Flag == false)
	{
		printf("������ ����!");
		printf("\n\n");
	}
	else
	{
		printf("�������� ������: ");
		while (p != NULL)
		{
			printf("%d ", p->inf);
			p = p->link;
		}
		printf("\n\n");
	}
};
// ������� ���������� ������ � ����
void Save_To_File(char FileName[], bool Flag = false) {

	ofstream Write(FileName);
	Telem* p = begL;
	if (p == NULL)
	{
		printf("������ ����!");
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
// ������� �������� ������ �� �����
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

		printf("�������� ������� ���� �������!\n");


	}

	printListFromBeginToEnd();

	Read.close();

}
// ������� ���������� K ���������
void Add_K_Elements() {

	int K = 0;
	int Start = 0;

	cout << "���������� - ������� ����� K: ";
	cin >> K;

	cout << "������� � ��������, � �������� �������� ����������: ";
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
		Temp[i] = Array[i]; // ����������� ������� � ������ ���������

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
	cout << "\n������������ ������: ";
	printListFromBeginToEnd();

	delete[] Array;

}

void Delete_K_Elements() {

	int K = 0;
	int Start = 0;

	cout << "���������� - ������� ����� K: ";
	cin >> K;

	cout << "������� � ��������, � �������� �������� ����������: ";
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
	cout << "\n������������ ������: ";
	printListFromBeginToEnd();

	delete[] Array;

}

int drawMenu()
{
	int numb;
	puts("			���� ���������:\n");
	puts(" 1 - ���������� �������� � ������ ������");
	puts(" 2 - ���������� �������� � ����� ������");
	puts(" 3 - ������� �������� � ������ ����� ���������");
	puts(" 4 - ������� �������� � ������ ����� ��������");
	puts(" 5 - �������� �������� �� ������ ������");
	puts(" 6 - �������� �������� �� ����� ������");
	puts(" 7 - ������� ����� ������");
	puts(" 8 - ����������� ������");
	puts(" 9 - ������ � ���� ����� ������");
	puts(" 10 - ������ �� ����� ������");
	puts(" 11 - ���������� K ���������, ������� � ��������� ������");
	puts(" 12 - �������� K ���������, ������� � ��������� ������");
	puts(" 0 - ����� �� ���������");
	printf("\n�������� ���� �� ������� ����: ");
	scanf("%d", &numb);

	return numb;
};
//================================================================

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // ��������� � �������
	system("title ������������ ������ � 11, ������� 5");
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

	return 0; // ���������� ���������

}
