#pragma once
#include "basic.h"

class Tour {
private:
	string type_tour; // ��� �������
	string country; // ������
	string type_of_transport; // ��� ����������
	int count_days; // ���������� ����
	int cost; // ���������
	Date date; // ���� �����������
	

public:
	Tour();
	Tour(string type, string country, string type_of_transport, int count_days, int cost, Date date);
	void setTypeTour(string type);
	void setCountry(string country);
	void setTypeOfTransport(string type_of_transport);
	void setCountDays(int countDays);
	void setCost(int cost);
	void setDate(Date date);


	string getTypeOfTransport();
	string getCountry();
	string getTypeTour();
	int getCountDays();
	int getCost();
	Date getDate();
		
	void setInfo(string type, string country, string type_of_transport, int count_days, int cost, Date date);
	void setInfo();
	void outputInfo();

	friend istream& operator>>(istream& stream, Tour& obj); // ���������� ��������� >>
	friend ostream& operator<<(ostream& stream, Tour& obj); // ���������� ��������� <<
	bool operator<(Tour& obj); // ���������� ��������� <


};