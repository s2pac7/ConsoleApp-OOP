#include "basic.h"

void Name::setInfo(const string surname, const string name)
{
	this->name = name;
	this->surname = surname;
}
void Name::setInfo()
{
	cout <<"Фамилия: "; setSurname();
	cout<<"Имя: "; setName();
}
string Name::outputAllInfo()
{
	return this->surname + " " + this->name;
}
istream& operator>>(istream& stream, Name& obj)
{
	string surname, name;
	if (stream >> surname >> name)
		obj.setInfo(surname, name);
	return stream;
}
ostream& operator<<(ostream& stream, const Name& obj)
{
	stream << obj.surname << " " << obj.name;
	return stream;
}

void Date::setInfo()
{
	cout<<"День: "; setDay();
	cout<<"Месяц: "; setMonth();
	cout<<"Год: "; setYear(1950, 2023);
}
void Date::setDate()
{

	time_t t = time(0);
	tm current = *localtime(&t);
	Date date = Date(current.tm_mday, current.tm_mon + 1, current.tm_year + 1900);

	while (true) {
		cout<<"День: "; setDay();
		cout<<"Месяц: "; setMonth();
		cout<<"Год: "; setYear(2023, 2025);
		if (*this < date) {
			cout << "Невозможно выбрать прошедшую дату" << endl;
		}
		else {
			break;
		}
	}
}
string Date::outputAllInfo()
{
	char date[11];
	char day[3], month[3], year[5];
	strcpy(date, _itoa(this->day, day, 10));
	if (date[1] == '\0')
		date[1] = ' ';
	date[2] = '.'; date[3] = '\0';
	strcat(date, _itoa(this->month, month, 10));
	if (date[4] == '\0')
		date[4] = ' ';
	date[5] = '.'; date[6] = '\0';
	strcat(date, _itoa(this->year, year, 10));
	this->fullDate = date;
	return this->fullDate;
}
void Date::operator=(const Date& obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}
bool Date::operator<=(const Date& obj)
{
	if ((this->year < obj.year) ||
		(this->year == obj.year && this->month < obj.month) ||
		(this->year == obj.year && this->month == obj.month && this->day <= obj.day)) {
		return true;
	}
	else return false;
}
bool Date::operator>=(const Date& obj)
{
	if ((this->year > obj.year) ||
		(this->year == obj.year && this->month > obj.month) ||
		(this->year == obj.year && this->month == obj.month && this->day >= obj.day)) {
		return true;
	}
	else return false;
}
bool Date::operator<(const Date& obj)
{
	if ((this->year < obj.year) ||
		(this->year == obj.year && this->month < obj.month) ||
		(this->year == obj.year && this->month == obj.month && this->day < obj.day)) {
		return true;
	}
	else return false;
}
bool Date::operator==(const Date& obj)
{
	if (obj.year == this->year && obj.month == this->month && obj.day == this->day)
		return true;
	else return false;
}
istream& operator>>(istream& stream, Date& obj)
{
	int day, month, year;
	if (stream >> day >> month >> year)
		obj.setInfo(day, month, year);
	stream.get();
	return stream;
}
ostream& operator<<(ostream& stream, const Date& obj)
{
	stream << obj.day << " " << obj.month << " " << obj.year;
	return stream;
}