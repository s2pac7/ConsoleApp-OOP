#include "tour.h"

Tour::Tour()
{
	this->type_of_transport = "";
	this->type_tour = "";
	this->cost = 0;
	this->count_days = 0;
	this->country = "";
}

Tour::Tour(string type, string country, string type_of_transport, int count_days, int cost, Date date)
{
	this->type_of_transport = type_of_transport;
	this->type_tour = type;
	this->cost = cost;
	this->count_days = count_days;
	this->country = country;
	this->date = date;
}

void Tour::setTypeTour(string type)
{
	this->type_tour = type;
}

void Tour::setCountry(string country)
{
	this->country = country;
}

void Tour::setTypeOfTransport(string type_of_transport)
{
	this->type_of_transport = type_of_transport;
}

void Tour::setCountDays(int countDays)
{
	this->count_days = countDays;
}

void Tour::setCost(int cost)
{
	this->cost = cost;
}

void Tour::setDate(Date date)
{
	this->date = date;
}

string Tour::getTypeOfTransport()
{
	return type_of_transport;
}

string Tour::getCountry()
{
	return country;
}

string Tour::getTypeTour()
{
	return type_tour;
}

int Tour::getCountDays()
{
	return count_days;
}

int Tour::getCost()
{
	return cost;
}

Date Tour::getDate()
{
	return date;
}

void Tour::setInfo(string type, string country, string type_of_transport, int count_days, int cost, Date date)
{
	this->type_of_transport = type_of_transport;
	this->type_tour = type;
	this->cost = cost;
	this->count_days = count_days;
	this->country = country;
	this->date = date;
}

void Tour::setInfo()
{
	cout << "¬ведите тип тура: ";
	getline(cin, this->type_tour);
	cout << "¬ведите страну: ";
	getline(cin, this->country);
	cout << "¬ведите тип транспорта: ";
	getline(cin, this->type_of_transport);
	cout << "¬ведите стоимость: ";
	this->cost = checks::checkInterval(1, 10000);
	cout << "¬ведите количество дней: ";
	this->count_days = checks::checkInterval(1, 100);
	cout << "¬ведите дату выезда" << endl;
	this->date = Date();
	this->date.setDate();
}

void Tour::outputInfo()
{
	cout<< setw(23) << left << type_tour
		<< "| " << setw(19) << left << country
		<< "| " << setw(19) << left << type_of_transport
		<< "| " << setw(12) << left << count_days
		<< "| " << setw(11) << left << cost
		<< "| " << setw(12) << left << to_string(date.getDay()) +"." + to_string(date.getMonth())+"." + to_string(date.getYear()) << "|";
}

bool Tour::operator<(Tour& obj)
{
	return this->cost<obj.cost;
}

istream& operator>>(istream& stream, Tour& obj)
{
	string type, type_of_transport, country;
	int count, cost;
	Date date;
	if (stream >> type >> type_of_transport >> country >> count >> cost >> date)
	{
		obj.setInfo(checks::replaceStarOnSpacing(type), checks::replaceStarOnSpacing(country), checks::replaceStarOnSpacing(type_of_transport), count, cost, date);
	}
	return stream;
}

ostream& operator<<(ostream& stream, Tour& obj)
{
	stream << checks::replaceSpacingOnStar(obj.getTypeTour()) << " " << checks::replaceSpacingOnStar(obj.getTypeOfTransport()) << " " << checks::replaceSpacingOnStar(obj.getCountry()) << " " << obj.getCountDays()
		<< " " << obj.getCost() << " " << obj.date;
	return stream;
}
