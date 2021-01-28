#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Human {

	string FIO; // ���
	int Year; // ��� ��������
	float Height; // ����
	float Weight; // ���

	Human() {

		FIO = "\0";
		Year = 0;
		Height = 0.0;
		Weight = 0.0;

	} // ����������� ���������

	~Human() {} // ����������� ���������

	void DeleteElement(Human*, int*, int);

}; // ��������� ��������


int HowStrokesInFile(char FileName[]) {

	int Count = 0; // ������� ���-�� ����� � �����
	string Str = "\0"; // ����������� ������

	ifstream Read(FileName);

	while (getline(Read, Str))
		Count++; // ����������� ������� ��� ���������� ������

	Read.close();

	return Count;

} // ������� �������� ���-�� ����� � �����

void Show_Base(Human* Humans, int Count) {

	for (int i = 0; i < Count; i++) {

		cout << "������� # " << i + 1 << ":\n";
		cout << "���: " << Humans[i].FIO << "\n";
		cout << "��� ��������: " << Humans[i].Year << " �.\n";
		cout << "���� ��������: " << Humans[i].Height << " ��\n";
		cout << "��� ��������: " << Humans[i].Weight << " ��\n";
		cout << "-----------------------\n";

	}

} // ������� ����������� ������ �� ���������

void Human::DeleteElement(Human* Objects, int* Index, int NumDel_Element) {

	int Counter = 0;

	Human Temp;

	for (int i = 0; i <= *Index; i++) {

		Temp = Objects[i]; // �������� ������ ��������� �� ��������� ������

		if (i != NumDel_Element) { // ���� �������� ������� �� ���, ������� ����� ��� ��������

			Objects[Counter] = Temp;
			Counter++;

		} // �������������� ������ �� ���������

	}

	*Index = *Index - 1;

} // ����� ��������� = �������� ����������� ��������

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // ��������� � �������
	system("title ������������ ������ � 8, ������� 5");

	char FileName[] = "base.txt"; // �������� �����, � ������� ���������� ���������� � �����

	cout << "��������� <�������>:\n";
	cout << "- �������, ���, ��������\n";
	cout << "- ��� ��������\n";
	cout << "- ����\n";
	cout << "- ���\n";
	cout << "������� ��� ������� � ��������� ������ � �����, �������� ������� ����� �������� � ��������� ��������\n\n";

	int MaxCountHumans = 100; // ������������ ����� ������� � ����
	Human* Humans = new Human[MaxCountHumans]; // ������������ ������ �������� ��������� Human
	int HumanIndex = HowStrokesInFile(FileName); // ������ ���������� �������� � ����
	string Str = "\0";

	ifstream Read(FileName);

	for (int i = 0; i < HumanIndex; i++) {

		Read >> Humans[i].FIO;
		Read >> Str;
		Humans[i].FIO += " " + Str;
		Read >> Str;
		Humans[i].FIO += " " + Str; // ��������� ��� ��������

		Read >> Humans[i].Year; // ��������� ��� ��������
		Read >> Humans[i].Height; // ��������� ����
		Read >> Humans[i].Weight; // ��������� ���

	}

	Read.close();

	cout << "����������� ���� ����� �� �����:\n\n";
	Show_Base(Humans, HumanIndex); // ���������� ���������� ����

	float H = 0;
	float W = 0;

	cout << "\n������� ���� (�������� ��� ��������): ";
	cin >> H;
	cout << "������� ��� (�������� ��� ��������): ";
	cin >> W;
	int Count = HumanIndex;

	for (int i = 0; i < Count; i++) {

		if (Humans[i].Height == H && Humans[i].Weight == W)
			Humans[i].DeleteElement(Humans, &HumanIndex, i);

	} // ����� � �������� ����� �� ���� �� �������� ����� � ����

	cout << "\n������������ ���� �����:\n\n";
	Show_Base(Humans, HumanIndex); // ���������� ������������ ����


	delete[] Humans; // ������������ ������

	//system ("pause");

	return 0; // ���������� ���������

}
