#pragma once
#include "basic.h" 


// ������������
class Account
{
private:
	string status; // ������ ������������
	string login; // ����� ������������
	string password; // ������
	Name name;

public:

	Account();// �����������
	Account(string status);

	void setLogin(vector<Account>& obj); // ���� ������
	void setPassword(); // ���� ������
	void setRole(string role); 
	void setName(Name name);

	string getStatus(); // ������� �������
	string getLogin(); // ������� ������
	string getPassword(); // ������� ������
	Name getName();

	void setInfo(vector<Account>& obj, string role); // ��������� ������
	void setInfo(const string status, const string login, const string password, const Name name); // ��������� ������
	void outputInfo(); // ����� ������

	friend istream& operator>>(istream& stream, Account& obj); // ���������� ��������� >>
	friend ostream& operator<<(ostream& stream, Account& obj); // ���������� ��������� <<
	bool operator<(Account& obj); // ���������� ��������� <

};

