// повторение пройденного материала.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
const int MAXSIZE = 50;
const int NUMSIZE = 10;
int workerCounter = 0; //количество уже добавленных сотрудников
struct Worker
{
	char* name = new char[MAXSIZE];
	char* surname = new char[MAXSIZE];
	char* phoneNumber = new char[NUMSIZE];
	double salary;
};
Worker* workbook = new Worker[MAXSIZE]; //максимальное количество работников в книге пускай будет 50
void showInfo()
{
	if (workerCounter < 1)
	{
		cout << "В книге пока нет работников" << endl;
		return;
	}
	else 
	{ 
		for (int i = 1; i < workerCounter; i++)
		{
			cout << "Сотрудник № " << i << endl;
			cout << "Имя: " << workbook[i - 1].name << endl;
			cout << "Фамилия: " << workbook[i - 1].surname << endl;
			cout << "Номер телефона: " << workbook[i - 1].phoneNumber << endl;
			cout << "Зарплата: " << workbook[i - 1].salary << endl;
		}
		return;
	}
	
}
void addWorker()
{
	if (workerCounter < MAXSIZE)
	{
		cout << "Введите информацию о вашем сотрудгике" << endl;
		cout << "Имя: ";
		cin >> workbook[workerCounter].name;
		cout << endl;
		cout << "Фамилия: " ;
		cin >> workbook[workerCounter].surname;
		cout << endl;
		cout << "Номер телефона: ";
		cin >> workbook[workerCounter].phoneNumber;
		cout << endl;
		cout << "Зарплата:";
		cin >> workbook[workerCounter].salary;
		cout << endl;
	}
	else
	{
		cout << "Ваша книга с работниками переполнена. Вы не можете добавить сотрудника" << endl;
	}
	
}
void searchBySurname()
{
	if (workerCounter < 1)
	{
		cout << "В книге пока нет работников" << endl;
		return;
	}
	else
	{
		char* userSurname = new char[MAXSIZE];
		cout << "Введите искомую фамилию:";
		cin >> userSurname;
		for (int i = 0; i < workerCounter; i++)
		{
			if (strcmp(userSurname, workbook[i].surname) == 0)
				cout << workbook[i].surname << endl;
		}
	}
	

}
int main()
{
	setlocale(LC_ALL, "");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
