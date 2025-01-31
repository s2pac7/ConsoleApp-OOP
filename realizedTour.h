#pragma once
#include "tour.h"

class RealizedTour {
private:
	string login; // ����� ������������, ������� ����� �������
	Tour tour; // ��������� �������
public:
	RealizedTour() = default;
	RealizedTour(string login, Tour tour) { this->login = login; this->tour = tour; }
	
	void setTour(Tour tour);
	void setLogin(string login);

	string getLogin();
	Tour getTour();

	void setInfo(string login, Tour tour);
	void outputInfo();

	friend istream& operator>>(istream& stream, RealizedTour& obj); // ���������� ��������� >>
	friend ostream& operator<<(ostream& stream, RealizedTour& obj); // ���������� ��������� <<
	bool operator<(RealizedTour& obj); // ���������� ��������� <
};