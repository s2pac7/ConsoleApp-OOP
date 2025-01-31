#pragma once
#include "basic.h" 


// Пользователь
class Account
{
private:
	string status; // Статус пользователя
	string login; // Логин пользователя
	string password; // Пароль
	Name name;

public:

	Account();// Конструктор
	Account(string status);

	void setLogin(vector<Account>& obj); // Ввод логина
	void setPassword(); // Ввод пароля
	void setRole(string role); 
	void setName(Name name);

	string getStatus(); // Возврат статуса
	string getLogin(); // Возврат логина
	string getPassword(); // Возврат пароля
	Name getName();

	void setInfo(vector<Account>& obj, string role); // Установка данных
	void setInfo(const string status, const string login, const string password, const Name name); // Установка данных
	void outputInfo(); // Вывод данных

	friend istream& operator>>(istream& stream, Account& obj); // Перегрузка оператора >>
	friend ostream& operator<<(ostream& stream, Account& obj); // Перегрузка оператора <<
	bool operator<(Account& obj); // Перегрузка оператора <

};

