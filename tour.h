#pragma once
#include "basic.h"

class Tour {
private:
	string type_tour; // Тип путевки
	string country; // Страна
	string type_of_transport; // Тип транспорта
	int count_days; // Количество дней
	int cost; // Стоимость
	Date date; // Дата отправления
	

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

	friend istream& operator>>(istream& stream, Tour& obj); // Перегрузка оператора >>
	friend ostream& operator<<(ostream& stream, Tour& obj); // Перегрузка оператора <<
	bool operator<(Tour& obj); // Перегрузка оператора <


};