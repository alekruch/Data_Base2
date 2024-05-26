#include "Functions.h"


void DataEntry(Data* (&d), int& n) {
	cout << "Введите количество данных";
	cin >> n;
	d = new Data[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите ФИО: ";
		cin >> d[i].person.surname;
		cin >> d[i].person.patronymic;
		cin >> d[i].person.name;

		cout << "Введите дату: ";
		cin >> d[i].date.day;
		cin >> d[i].date.month;
		cin >> d[i].date.year;

		cout << "Введите адрес: ";
		cin >> d[i].addres.city;
		cin >> d[i].addres.home;

		cout << "__________________________________________" << "\n";
	}
}

void ReadingData(Data* (&d), int& n, string fileName) {
	ifstream fin(fileName);
	if (fin) {
		fin >> n;
		d = new Data[n];


		for (int i = 0; i < n; i++)
		{
			fin >> d[i].person.surname;
			fin >> d[i].person.patronymic;
			fin >> d[i].person.name;

			fin >> d[i].date.day;
			fin >> d[i].date.month;
			fin >> d[i].date.year;

			fin >> d[i].addres.city;
			fin >> d[i].addres.home;

		}
		cout << "Данные считанны!" << "\n";

	}
	else cout << "Ошибка файла!!!" << "\n";
	fin.close();
}

void Print(Data* d, int n) 
{
	for (int i = 0; i < n; i++)
	{
		cout << "Данные №" << i + 1 << ":" << "\n";
		cout << "ФИО: " << d[i].person.surname << " " << d[i].person.name << " " << d[i].person.patronymic << "\n";
		cout << "Дата: " << d[i].date.day << " " << d[i].date.month << " " << d[i].date.year << "\n";
		cout << "Адресс: " << d[i].addres.city << " " << d[i].addres.home << "\n";

		cout << "__________________________________________" << "\n";
	}

}

void DataChange(Data* (&d), int& n) {
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	int x;
	cin >> x;
	x--;

	system("cls");

	if (x >= 0 && x < n)
	{
		cout << "Введите ФИО: ";
		cin >> d[x].person.surname;
		cin >> d[x].person.patronymic;
		cin >> d[x].person.name;

		cout << "Введите дату: ";
		cin >> d[x].date.day;
		cin >> d[x].date.month;
		cin >> d[x].date.year;

		cout << "Введите адрес: ";
		cin >> d[x].addres.city;
		cin >> d[x].addres.home;

		system("cls");
		cout << "Данные изменены!" << "\n";

	}
	else cout << "Номер введен не верно! " << "\n";



}

//весь mass
void Copy(Data* (&d_new), Data* (&d_old), int n)
{
	for (int i = 0; i < n; i++)
	{
		d_new[i] = d_old[i];
	}
}

// 1 элемент
void Copy_2(Data& d_new, Data& d_old)
{
	d_new.person.surname = d_old.person.surname;
	d_new.person.name = d_old.person.name;
	d_new.person.patronymic = d_old.person.patronymic;

	d_new.date.year = d_old.date.year;
	d_new.date.day = d_old.date.day;
	d_new.date.month = d_old.date.month;
	

	d_new.addres.city = d_old.addres.city;
	d_new.addres.home = d_old.addres.home;

}

void DeleteData(Data* (&d), int& n) 
{
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	int x;
	cin >> x;
	x--;

    system("cls");

	if (x >= 0 && x < n)
	{
		//временный масиив
		Data* buf = new Data[n];
		Copy(buf, d, n);
		n--;

		d = new Data[n];

		int q = 0;

		for (int i = 0; i <= n; i++)
		{
			if (i != x) {
				d[q] = buf[i];
				q++;
			}
		}

		system("cls");
		delete[]buf;

		cout << "Данные удалены!" << "\n";

	}
	else cout << "Номер введен неверно!" << "\n";
}

void AddData(Data* (&d), int &n)
{
	//временный массив
	Data* buf;
	buf = new Data[n];

	Copy(buf,d,n);

	n++;
	d = new Data[n];
	//возвращаем
	Copy(d, buf, --n);
	 
	cout << "Введите ФИО: ";
	cin >> d[n].person.surname  >> d[n].person.patronymic >> d[n].person.name;
	//cin >> d[n].person.patronymic;
	//cin >> d[n].person.name;

	cout << "Введите дату: ";
	cin >> d[n].date.year >> d[n].date.month >> d[n].date.day;
	//cin >> d[n].date.month;
	//cin >> d[n].date.year;

	cout << "Введите адрес: ";
	cin >> d[n].addres.city >> d[n].addres.home;
	//cin >> d[n].addres.home;

	system("cls");
	cout << "Данные добавлены" << "\n";
	delete[]buf;


}
 
void DataSorting(Data* d, int n)
{
	Data buf;

	//пузырь
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (d[i].date.day > d[j].date.day)
			{
				Copy_2(buf, d[j]);
				Copy_2(d[j], d[i]);
				Copy_2(d[i], buf);
			}
			
		}
	}

	cout << "Данные отсортироывнны!" << "\n";
}

void SavingData(Data* d,int n, string fileName ) {
	ofstream out(fileName, ios::out);

	if (out)
	{
		out << n << "\n";

		for (int i = 0; i < n; i++)
		{
			out << d[i].person.surname << "\n";
			out << d[i].person.name << "\n";
			out << d[i].person.patronymic << "\n";

			out << d[i].date.day << " ";
			out << d[i].date.month << " ";
			out << d[i].date.year << "\n";

			out << d[i].addres.city << "\n";
			if (i < n - 1) {
				out << d[i].addres.home << "\n";
			}
			else out << d[i].addres.home << "\n";

		}
	}
	else  cout << "Ошибка открытия файла!" << "\n";

	out.close();
}