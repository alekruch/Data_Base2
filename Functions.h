#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>

using namespace std;

struct Person {
	string surname;
	string patronymic;
	string name;
};

struct Date {
	int year;
	int day;
	int month;
	

};

struct Address {
	string city;
	int home;
};

struct Data {
	Person person;
	Date date;
	Address addres;

};

void DataEntry(Data* (&d), int& n);
void ReadingData(Data* (&d), int& n, string fileName);
void Print(Data* d, int n);
void Copy(Data* (&d_new), Data* (&d_old), int n);
void Copy_2(Data& d_new, Data& d_old);
void DataChange(Data* (&d), int& n);
void DeleteData(Data* (&d), int& n);
void AddData(Data* (&d), int& n);
void DataSorting(Data* d, int n);
void SavingData(Data* d, int n, string fileName);