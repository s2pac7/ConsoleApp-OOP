#pragma once
#include "checks.h"
// Абстрактный класс
class BasicClass
{
public:
	virtual void setInfo() = 0;
	virtual string outputAllInfo() = 0;
};

// Класс ФИО
class Name : public BasicClass
{
private:

	string surname; // Фамилия
	string name; // Имя

public:

	Name() {
		surname = "";
		name = "";
	} // Конструктор

	void setSurname() { getline(cin, this->surname); } // Ввод Фамилии
	void setName() { getline(cin, this->name); } // Ввод Имени

	void setInfo(const string surname, const string name); // Установка параметров
	void setInfo() override; // Установка параметров

	string getSurname() { return this->surname; } // Возврат Фамилии
	string getName() { return this->name; } // Возврат Иммени

	string outputAllInfo() override; // Возврат всей информации

	friend istream& operator>>(istream& stream, Name& obj); // Перегрузка оператора >>
	friend ostream& operator<<(ostream& stream, const Name& obj); // Перегрузка оператора <<
	void operator=(const Name& obj) { Name::setInfo(obj.surname, obj.name); } // Перегрузка оператора =

};

// Дата
class Date : public BasicClass
{
private:

	int day; // День
	int month; // Месяц
	int year; // Год
	string fullDate; // Полная дата

public:

	Date() : day(0), month(0), year(0), fullDate("") { } // Конструктор

	Date(int day, int month, int year) { this->day = day; this->month = month; this->year = year; }

	void setDay() { this->day = checks::checkInterval(1, 31); } // Установка даты
	void setMonth() { this->month = checks::checkInterval(1, 12); } // Установка месяца
	void setYear(int min, int max) { this->year = checks::checkInterval(min, max); } // Установка года

	void setInfo(int day, int month, int year) { this->day = day; this->month = month; this->year = year; } // Установка данных
	void setInfo() override; // Установка данных
	void setDate();

	int getDay() { return this->day; } // Возврат дня
	int getMonth() { return this->month; } // Возврат месяца
	int getYear() { return this->year; } // Возврат года

	string outputAllInfo() override; // Возврат полной даты

	friend istream& operator>>(istream& stream, Date& obj); // Перегрузка оператора >>
	friend ostream& operator<<(ostream& stream, const Date& obj); // Перегрузка оператора <<
	void operator=(const Date& obj); // Перегрузка оператора =
	bool operator<=(const Date& obj); // Перегрузка оператора <=
	bool operator>=(const Date& obj); // Перегрузка оператора >=
	bool operator<(const Date& obj); // Перегрузка оператора <
	bool operator==(const Date& obj); // Перегрузка оператора ==

};