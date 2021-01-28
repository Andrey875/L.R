#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Human {

	string FIO; // фио
	int Year; // год рождения
	float Height; // рост
	float Weight; // вес

	Human() {

		FIO = "\0";
		Year = 0;
		Height = 0.0;
		Weight = 0.0;

	} // конструктор структуры

	~Human() {} // декструктор структуры

	void DeleteElement(Human*, int*, int);

}; // структура человека


int HowStrokesInFile(char FileName[]) {

	int Count = 0; // счетчик кол-ва строк в файле
	string Str = "\0"; // считываемая строка

	ifstream Read(FileName);

	while (getline(Read, Str))
		Count++; // увеличиваем счетчик при считывании строки

	Read.close();

	return Count;

} // функция подсчета кол-ва строк в файле

void Show_Base(Human* Humans, int Count) {

	for (int i = 0; i < Count; i++) {

		cout << "Человек # " << i + 1 << ":\n";
		cout << "ФИО: " << Humans[i].FIO << "\n";
		cout << "Год рождения: " << Humans[i].Year << " г.\n";
		cout << "Рост человека: " << Humans[i].Height << " см\n";
		cout << "Вес человека: " << Humans[i].Weight << " кг\n";
		cout << "-----------------------\n";

	}

} // функция отображения данных по студентам

void Human::DeleteElement(Human* Objects, int* Index, int NumDel_Element) {

	int Counter = 0;

	Human Temp;

	for (int i = 0; i <= *Index; i++) {

		Temp = Objects[i]; // копируем данные владельца во временный объект

		if (i != NumDel_Element) { // если нынешний элемент не тот, который нужен для удаления

			Objects[Counter] = Temp;
			Counter++;

		} // перезаписываем данные об владельце

	}

	*Index = *Index - 1;

} // метод структуры = удаление конктреного элемента

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // кириллица в консоли
	system("title Лабораторная работа № 8, задание 5");

	char FileName[] = "base.txt"; // название файла, в котором содержится информации о людях

	cout << "Структура <Человек>:\n";
	cout << "- фамилия, имя, отчество\n";
	cout << "- год рождения\n";
	cout << "- рост\n";
	cout << "- вес\n";
	cout << "Удалить все элемент с указанным ростом и весом, добавить элемент после элемента с указанной фамилией\n\n";

	int MaxCountHumans = 100; // максимальное число человек в базе
	Human* Humans = new Human[MaxCountHumans]; // динамический массив объектов структуры Human
	int HumanIndex = HowStrokesInFile(FileName); // индекс последнего человека в базе
	string Str = "\0";

	ifstream Read(FileName);

	for (int i = 0; i < HumanIndex; i++) {

		Read >> Humans[i].FIO;
		Read >> Str;
		Humans[i].FIO += " " + Str;
		Read >> Str;
		Humans[i].FIO += " " + Str; // считываем фио человека

		Read >> Humans[i].Year; // считываем год рождения
		Read >> Humans[i].Height; // считываем рост
		Read >> Humans[i].Weight; // считываем вес

	}

	Read.close();

	cout << "Изначальная база людей из файла:\n\n";
	Show_Base(Humans, HumanIndex); // отображаем актуальную базу

	float H = 0;
	float W = 0;

	cout << "\nЗадайте рост (критерий для удаления): ";
	cin >> H;
	cout << "Задайте вес (критерий для удаления): ";
	cin >> W;
	int Count = HumanIndex;

	for (int i = 0; i < Count; i++) {

		if (Humans[i].Height == H && Humans[i].Weight == W)
			Humans[i].DeleteElement(Humans, &HumanIndex, i);

	} // поиск и удаление людей из базы по критерию роста и веса

	cout << "\nПолучившаяся база людей:\n\n";
	Show_Base(Humans, HumanIndex); // отображаем получившуюся базу


	delete[] Humans; // высвобождаем память

	//system ("pause");

	return 0; // завершение программы

}
