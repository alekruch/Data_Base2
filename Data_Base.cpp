#include "Functions.h"
//#include "functions.cpp"
//#include "functions.cpp"

int stateMenu;

int random() {
	int start = 10;
	int end = 500;
	int x = rand() % (end - start + 1) + start;
	return x;
}

void Welcome() {
	string a = "Welcome to my project.......   -_-";
	for (int i = 0; i < a.length(); i++)
	{
		
		Sleep(random());
		cout << a[i];
		//Beep(350, x);
		
		
	}
	cout << "\n";
}

void Menu() {
	cout << "Выберите действие: " << "\n"
		<< "(0) Выход из программы " << "\n"
		<< "(1) Ввод данных " << "\n"
		<< "(2) Вывод " << "\n"
		<< "(3) Изменение " << "\n"
		<< "(4) Удалене " << "\n"
		<< "(5) Добавление " << "\n"
		<< "(6) Сортировка " << "\n"
		<< "(7) Сохранение " << "\n"
		<< "Ваш выбор: ";
	cin >> stateMenu;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	system("Color E0");
	Welcome();
	cout << "\n";
	Sleep(250);

	Menu();

	int actions = 0;
	int amountOfData = 0;
	string fileName;

	// массив данных
	Data* d = new Data[amountOfData];

	while (stateMenu != 0) {
		switch (stateMenu)
		{
		case 1:
			system("cls");
			cout << "Ввод вручную или из файла?: ";
			cin >> actions;
			system("cls");

			if (actions == 1) {
				DataEntry(d, amountOfData);
			}
			else {
				cout << "Введите название файла: ";
				cin >> fileName;

				ReadingData(d, amountOfData, fileName);
			}
			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			if (amountOfData != 0) {
				Print(d, amountOfData);

			}
			else cout << "Данные пусты!" << "\n";
			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");
			
			if (amountOfData != 0) {
				DataChange(d, amountOfData);
			}
			else cout << "Данные пустые!" << "\n";

			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");

			if (amountOfData != 0) {
				DeleteData(d, amountOfData);
			}
			else cout << "Данные пусты!" << "\n";
			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");

			if (amountOfData != 0) {
				AddData(d, amountOfData);
				amountOfData++;
			}
			else cout << "Данные пусты!" << "\n";
			system("pause");
			system("cls");
			Menu();
			break;

		case 6:
			system("cls");

			if (amountOfData != 0) {
				DataSorting(d, amountOfData);
			}
			else cout << "Данные пусты!" << "\n";
			system("pause");
			system("cls");
			Menu();
			break;

		case 7:
			system("cls");
			cout << "Введите название файла: ";
			cin >> fileName;

			if (amountOfData != 0) {
				SavingData(d, amountOfData, fileName);
			}
			else cout << "Данные пусты!" << "\n";

			system("pause");
			system("cls");
			Menu();
			break;

		default:
			cout << "Неверно введен номер дейтвия!" << "\n";
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
}

