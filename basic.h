#pragma once
#include "checks.h"
// ����������� �����
class BasicClass
{
public:
	virtual void setInfo() = 0;
	virtual string outputAllInfo() = 0;
};

// ����� ���
class Name : public BasicClass
{
private:

	string surname; // �������
	string name; // ���

public:

	Name() {
		surname = "";
		name = "";
	} // �����������

	void setSurname() { getline(cin, this->surname); } // ���� �������
	void setName() { getline(cin, this->name); } // ���� �����

	void setInfo(const string surname, const string name); // ��������� ����������
	void setInfo() override; // ��������� ����������

	string getSurname() { return this->surname; } // ������� �������
	string getName() { return this->name; } // ������� ������

	string outputAllInfo() override; // ������� ���� ����������

	friend istream& operator>>(istream& stream, Name& obj); // ���������� ��������� >>
	friend ostream& operator<<(ostream& stream, const Name& obj); // ���������� ��������� <<
	void operator=(const Name& obj) { Name::setInfo(obj.surname, obj.name); } // ���������� ��������� =

};

// ����
class Date : public BasicClass
{
private:

	int day; // ����
	int month; // �����
	int year; // ���
	string fullDate; // ������ ����

public:

	Date() : day(0), month(0), year(0), fullDate("") { } // �����������

	Date(int day, int month, int year) { this->day = day; this->month = month; this->year = year; }

	void setDay() { this->day = checks::checkInterval(1, 31); } // ��������� ����
	void setMonth() { this->month = checks::checkInterval(1, 12); } // ��������� ������
	void setYear(int min, int max) { this->year = checks::checkInterval(min, max); } // ��������� ����

	void setInfo(int day, int month, int year) { this->day = day; this->month = month; this->year = year; } // ��������� ������
	void setInfo() override; // ��������� ������
	void setDate();

	int getDay() { return this->day; } // ������� ���
	int getMonth() { return this->month; } // ������� ������
	int getYear() { return this->year; } // ������� ����

	string outputAllInfo() override; // ������� ������ ����

	friend istream& operator>>(istream& stream, Date& obj); // ���������� ��������� >>
	friend ostream& operator<<(ostream& stream, const Date& obj); // ���������� ��������� <<
	void operator=(const Date& obj); // ���������� ��������� =
	bool operator<=(const Date& obj); // ���������� ��������� <=
	bool operator>=(const Date& obj); // ���������� ��������� >=
	bool operator<(const Date& obj); // ���������� ��������� <
	bool operator==(const Date& obj); // ���������� ��������� ==

};