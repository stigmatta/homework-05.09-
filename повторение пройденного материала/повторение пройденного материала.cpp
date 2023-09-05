// повторение пройденного материала.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	unsigned short choice;
	char path[MAXSIZE];
	int left, right;
	do
	{
		cout << "1 - Добавление сотрудника в книгу всех рабочих" << endl;
		cout << "2 - Вывод книги рабочих на экран" << endl;
		cout << "3 - Поиск сотрудников в рабочей книге по фамилии" << endl;
		cout << "4 - Поиск по диапазону зарплаты:" << endl;
		cout << "5 - Сортировать по фамилии" << endl;
		cout << "6 - Удаление сотрудника из книги" << endl;
		cout << "0 - закончить программу" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Type a path of your folder (for example: D:\\...)" << endl;
			cin >> path;
			addWorker(path);
			break;
		case 2:
			if (workerCounter < 1)
			{
				cout << "В книге пока нет работников" << endl;
				break;
			}
			else
			{
				for (int i = 0; i < workerCounter; i++)
				{
					cout << "Сотрудник № " << i + 1 << endl;
					showInfo(workbook[i]);
				}
			}
			break;
		case 3:
			searchBySurname();
			break;
		case 4:
			cout << "Введите первую границу диапазона зарплаты:" << endl;
			cin >> left;
			cout << "Введите вторую границу диапазона зарплаты:" << endl;
			cin >> right;
			for (int i = 0; i < workerCounter; i++)
			{
				salaryDiapason(workbook[i],left,right);
			}
			if (!flag)
			{
				cout << "В книге нет работников с таким диапазном зарплаты" << endl;
			}
			flag = 0;
			break;
		case 5:
			sortBySurname();
			break;
		case 6:
			workbook = deleteWorker();
			break;
		}
	} while (choice != 0);
	return 0;
}
void showInfo(Worker worker)
{

	cout << "Имя: " << worker.name << endl;
	cout << "Фамилия: " << worker.surname << endl;
	cout << "Номер телефона: " << worker.phoneNumber << endl;
	cout << "Зарплата: " << worker.salary << endl;

}
void readFile(const char* path)
{
	FILE* file = fopen(path, "r");
	const int SIZE = 1000;
	char buffer[SIZE];
	while (fgets(buffer, SIZE, file) != NULL)
		cout << buffer;
	fclose(file);
}
bool correctNumber(char* phoneNum)
{
	if (strlen(phoneNum) != 10)
	{
		cout << "Вы ввели некорректный номер.Попробуйте еще раз" << endl;
		return false;
	}
	return true;
}
void salaryDiapason(Worker worker, int left, int right)
{
	if (workerCounter < 1)
	{
		cout << "В книге пока нет работников" << endl;
		return;
	}
	if (worker.salary >= left && worker.salary <= right)
	{
		flag = 1;
		showInfo(worker);

	}

}
void addWorker(char path[])
{
	if (workerCounter < MAXSIZE)
	{
		FILE* file = fopen(path, "a");
		cout << "Введите информацию о вашем сотруднике" << endl;
		cout << "Имя: ";
		cin >> workbook[workerCounter].name;
		cout << endl;
		cout << "Фамилия: ";
		cin >> workbook[workerCounter].surname;
		cout << endl;
		cout << "Номер телефона: ";
		do {
			cin >> workbook[workerCounter].phoneNumber;
		} while (correctNumber(workbook[workerCounter].phoneNumber) == 0);
		cout << endl;
		cout << "Зарплата:";
		cin >> workbook[workerCounter].salary;
		cout << endl;
		++workerCounter;
		fprintf_s(file, "Имя: %s\n", workbook[workerCounter].name);
		fprintf_s(file, "Фамилия: %s\n", workbook[workerCounter].surname);
		fprintf_s(file, "Номер телефона: %s\n", workbook[workerCounter].phoneNumber);
		fprintf_s(file, "Зарплата: %f\n", workbook[workerCounter].salary);
		fclose(file);

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
				showInfo(workbook[i]);
		}
	}


}
void sortBySurname()
{
	for (int i = 0; i < workerCounter; i++)
	{
		for (int j = workerCounter - 1; j > i; j--)
		{
			if (strcmp(workbook[i].surname, workbook[j].surname) == 1)
				swap(workbook[j], workbook[j - 1]);
		}
	}
}
Worker* deleteWorker()
{
	int index;
	if (workerCounter < 1)
		cout << "Вы не можете удалить сотрудника" << endl;
	else
	{
		cout << "Сотрудника с каким номером вы хотите удалить из книги?" << endl;
		do {
			cin >> index;
			if (!(index > 0 && index < workerCounter))
				cout << "Сотрудника с таким номером нет" << endl;
		} while (!(index > 0 && index < workerCounter));
		--workerCounter;
		Worker* newBook = new Worker[workerCounter];
		for (int i = 0; i < workerCounter + 1; i++)
		{
			if (i < index - 1)
				newBook[i] = workbook[i];
			else if (i == index - 1)
				continue;
			else
				newBook[i - 1] = workbook[i];
			delete[]workbook;
			return newBook;
		}

	}
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
