#include "realizedTour.h"
#pragma once

void RealizedTour::setTour(Tour tour)
{
	this->tour = tour;
}

void RealizedTour::setLogin(string login)
{
	this->login = login;
}

string RealizedTour::getLogin()
{
	return login;
}

Tour RealizedTour::getTour()
{
	return tour;
}

void RealizedTour::setInfo(string login, Tour tour)
{
	this->login = login;
	this->tour = tour;
}

void RealizedTour::outputInfo()
{
	tour.outputInfo();
	cout << " " << setw(15) << left << login << "|";
}

bool RealizedTour::operator<(RealizedTour& obj)
{
	return this->tour<obj.tour;
}

istream& operator>>(istream& stream, RealizedTour& obj)
{
	string login;
	Tour tour;
	if (stream >> login >> tour)
	{
		obj.setInfo(login, tour);
	}
	return stream;
}

ostream& operator<<(ostream& stream, RealizedTour& obj)
{
	stream << obj.login << " " << obj.tour;
	return stream;
}
