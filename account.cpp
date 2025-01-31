#include "account.h"

Account::Account()
{
	status = "";
	login = "";
	password = "";
}

Account::Account(string status)
{
	login = "";
	password = "";
	this->status = status;
}

void Account::setLogin(vector<Account>& obj)
{
	string new_login;
	while (true) {
		cout<<"Введите логин: ";
		int prov = 0;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, new_login);
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		// Проверка на корректность ввода
		for (int i = 0; i < new_login.size(); i++) {
			if ((new_login[i] < 'a' || new_login[i] > 'z') && (new_login[i] < 'A' || new_login[i] > 'Z') && (new_login[i] < '0' || new_login[i] > '9')) {
				prov = 1;
			}
		}
		if (new_login.size() < 4)
		{
			cout << "Логин должен быть длиннее 4 символов, повторите ввод" << endl;
			continue;
		}
		//Проверка на дубликат Логина
		for (int i = 0; i < obj.size(); i++) {
			if (new_login == obj[i].login) prov = 3;
		}

		if (prov == 3) {

			cout<<"Такой логин уже существует, повторите ввод"<<endl;

		}
		else
			if (prov == 0) { this->login = new_login; return; }
			else {
				cout<<"Логин может содержать буквы латинского алфавита и цифры, повторите ввод"<<endl;
			}
	}

}

void Account::setPassword()
{
	string pass;
	while (true) {
		cout<<"Введите пароль: ";
		int prov = 0, kolchi = 0, kolsym = 0;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, pass);
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		// Проверка на корректность ввода
		for (int i = 0; i < pass.size(); i++) {
			if ((pass[i] < 'a' || pass[i] > 'z') && (pass[i] < 'A' || pass[i] > 'Z') && (pass[i] < '0' || pass[i] > '9')) {
				prov = 1;
			}
			if ((pass[i] >= 'a' && pass[i] <= 'z') || (pass[i] >= 'A' && pass[i] <= 'Z')) {
				kolsym++;
			}
			if (pass[i] >= '0' && pass[i] <= '9') {
				kolchi++;
			}
		}
		if (prov == 0 && kolchi >= 1 && pass.size() > 4 && kolsym >= 1) {
			this->password = checks::encrypt(pass);
			return;
		}
		else {
			cout<<"Пароль должен состоять из цифр и латинских букв и быть длинне 4 символов, повторите ввод";
		}
	}
}
void Account::setRole(string role)
{
	this->status = role;
}
void Account::setName(Name name)
{
	this->name = name;
}
string Account::getStatus()
{
	return this->status;
}
string Account::getLogin()
{
	return this->login;
}
string Account::getPassword()
{
	 return this->password; 
}
void Account::setInfo(const string status, const string login, const string password, Name name)
{
	this->status = status;
	this->login = login;
	this->password = password;
	this->name = name;
}
Name Account::getName()
{
	return this->name;
}
void Account::setInfo(vector<Account>& obj, string role)
{
	system("cls");
	name.setInfo();
	setLogin(obj);
	setPassword();
	this->status = role;
}

void Account::outputInfo()
{

	cout << setw(16) << this->login << "|" << setw(14) << this->status << "|" << setw(21) << this->name.outputAllInfo()<<"|";
}

bool Account::operator<(Account& obj)
{
	if (this->login < obj.login)
		return true;
	else return false;
}

istream& operator>>(istream& stream, Account& obj)
{
	string status;
	string login, password;
	Name name;
	if (stream >> status >> login >> password >>name)
	{
		obj.Account::setInfo(status, login, password, name);
	}
	return stream;
}
ostream& operator<<(ostream& stream, Account& obj)
{
	stream << obj.getStatus() << " " << obj.getLogin() << " " << obj.getPassword() << " " << obj.getName();
	return stream;
}
