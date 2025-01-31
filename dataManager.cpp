#pragma once
#include "dataManager.h"
//DataManager* DataManager::instance = nullptr;


DataManager* DataManager::getInstance()
{
	if (instance == nullptr) {
		instance = new DataManager();
	}
	return instance;
}

void DataManager::init() {
	readToursFromAFile();
	readUsersFromAFile();
	readRealizedToursFromAFile();
}

void DataManager::readToursFromAFile()
{

	try {
		this->tours.clear();
		ifstream fin(TOURS_FILE);
		while (1)
		{
			Tour obj;
			if (fin >> obj)
			{
				this->tours.push_back(obj);
			}
			else break;
		}
		fin.close();
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
	
	
}

void DataManager::writeToursToAFile()
{
	try {
		ofstream fout(TOURS_FILE, ios_base::trunc);
		for (register int i = 0; i < tours.size(); i++)
			fout << tours[i] << endl;
		fout.close();
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
}

void DataManager::readRealizedToursFromAFile()
{
	try {
		this->realizedTours.clear();
		ifstream fin(REALIZED_TOURS_FILE);
		while (1)
		{
			RealizedTour obj;
			if (fin >> obj)
			{
				this->realizedTours.push_back(obj);
			}
			else break;
		}
		fin.close();
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
	
}

void DataManager::writeRealizedToursToAFile()
{
	
	try {
		ofstream fout(REALIZED_TOURS_FILE, ios_base::trunc);
		for (register int i = 0; i < realizedTours.size(); i++)
			fout << realizedTours[i] << endl;
		fout.close();
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
	
}

void DataManager::readUsersFromAFile()
{
	try {
		this->accounts.clear();
		ifstream fin(ACCOUNTS_FILE);
		while (1)
		{
			Account obj;
			if (fin >> obj)
			{
				this->accounts.push_back(obj);
			}
			else break;
		}
		fin.close();
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
	
}

void DataManager::writeUsersToAFile()
{
	try {
		ofstream fout(ACCOUNTS_FILE, ios_base::trunc);
		for (register int i = 0; i < accounts.size(); i++)
			fout << accounts[i] << endl;
		fout.close();
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
	
}

bool DataManager::isUsersPresent()
{
	return !this->accounts.size();
}

void DataManager::registration(string role)
{
	Account obj = Account();
	while (true) {
		cout << "����������� ";
		if (role == "ADMIN")
			cout << "��������������" << endl;
		else
			cout << "������������" << endl;
		obj.setInfo(this->accounts, role);
		for (int i = 0; i < accounts.size(); i++) {
			if (obj.getLogin() == accounts[i].getLogin()) {
				cout << "������ ����� �����" << endl;
				continue;
			}
		}
		this->accounts.push_back(obj);
		writeUsersToAFile();
		cout << "����������� ������ �������" << endl;
		system("pause");
		return;
	}
}
	

string DataManager::autho()
{
	string login;
	string password;
	while (true) {
		system("cls");
		cout<<"�����������"<<endl;
		cout<<"������� �����: ";
		cin >> login;
		cout<<"������� ������: ";
		password = checks::enterPasswordWithStars();
		for (int i = 0; i < accounts.size(); i++) {
			if (login == accounts[i].getLogin() && checks::encrypt(password) == accounts[i].getPassword()) {
				system("cls");
				id_account = i;
				return accounts[i].getStatus();
			}
		}
		return "Error";
	}
}

void DataManager::outputCapUsers()
{
	cout << "\n|-----------------------------------------------------------|"
		<< "\n|                      ������� ������                       |"
		<< "\n|-----------------------------------------------------------|"
		<< "\n|  �  |      �����     |     ����     |    ������� � ���    |"
		<< "\n|-----------------------------------------------------------|\n";

}
void DataManager::outputAllUsers()
{
	if (this->accounts.size()) {
		outputCapUsers();
		for (int i = 0; i < this->accounts.size(); i++)
		{
			cout << "|" << setw(5) << left << i + 1 << "|"; this->accounts[i].outputInfo(); cout << endl;
		}
		cout << "|-----------------------------------------------------------|\n";
	}
	else {
		cout << "������ �����������" << endl;
	}
}

void DataManager::outputAllUsers(vector<Account> &acc)
{
	if (acc.size()) {
		outputCapUsers();
		for (int i = 0; i < acc.size(); i++)
		{
			cout << "|" << setw(5) << left << i + 1 << "|"; acc[i].outputInfo(); cout << endl;
		}
		cout << "|-----------------------------------------------------------|\n";
	}
	else {
		cout << "������ �����������" << endl;
	}
	
	
}

void DataManager::delUser()
{
	int choise;
	while (1)
	{
		system("cls");
		outputAllUsers();
		cout<<"������� ����� ������, ������� ������ ������� (0 - ��������� �����): ";
		choise = checks::checkInterval(0, this->accounts.size());;
		if (choise == 0)
			break;
		else if (choise-1==this->id_account)
		{
			system("cls");
			cout<<"������ ������� ������� ������ ��� ������� �� �����!"<<endl;
			system("pause");
		}
		else
		{
			cout<<"����������� ��������? (1-��, 2-���): ";
			int controller = checks::checkInterval(1, 2);
			if (controller == 1) {

				this->accounts.erase(accounts.begin() + choise - 1);
				writeUsersToAFile();
				cout<<"������������ ������"<<endl;
				if (id_account > choise-1) {
					id_account--;
				}
				system("pause");
			}

		}
	}
} 

void DataManager::editUser()
{
	Account obj;
	while (true) {
		system("cls");
		cout << "��������� ������" << endl;
		obj.setInfo(this->accounts, accounts[id_account].getStatus());
		for (int i = 0; i < accounts.size(); i++) {
			if (obj.getLogin() == accounts[i].getLogin() && i!= id_account) {
				cout << "������ ����� �����" << endl;
				continue;
			}
		}
		this->accounts[id_account] = obj;
		writeUsersToAFile();
		cout << "������ ��������" << endl;
		system("pause");
		return;
	}
}
void DataManager::sortUsers()
{
	system("cls");
	if (accounts.size()) {
		vector<Account> vecBuf;
		vecBuf = this->accounts;
		sort(accounts.begin(), accounts.end());
		cout << "��������������� ������ �� ������";
		outputAllUsers();
		this->accounts = vecBuf;
	}
	else {
		cout << "������������ �����������" << endl;
	}
	system("pause");
}

void DataManager::searchLoginUsers()
{
	system("cls");
	if (accounts.size()) {
		string login;
		cout << "������� �����: ";
		cin >> login;
		vector<Account> acc;
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i].getLogin() == login) {
				acc.push_back(accounts[i]);
			}
		}
		if (acc.size()) {
			cout << "��������� ������������" << endl;
			outputAllUsers(acc);
		}
		else {
			cout << "������ �� �������" << endl;
		}
	}
	else {
		cout << "������ �����������" << endl;
	}
	system("pause");
}

void DataManager::filtrRoleUsers()
{
	system("cls");
	if (accounts.size()) {
		string login;
		cout << "�������� ����(1-�����, 2-������������): ";
		int choice = checks::checkInterval(1, 2);
		string role;
		if (choice == 1)
			role = "ADMIN";
		else
			role = "USER";
		vector<Account> acc;
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i].getStatus() == role) {
				acc.push_back(accounts[i]);
			}
		}
		if (acc.size()) {
			cout << "��������� ������������" << endl;
			outputAllUsers(acc);
		}
		else {
			cout << "������ �� �������" << endl;
		}

	}
	else {
		cout << "������ �����������" << endl;
	}
	system("pause");
}

void DataManager::addTour()
{
	system("cls");
	cout << "���������� ����" << endl;
	Tour tour;
	tour.setInfo();
	this->tours.push_back(tour);
	writeToursToAFile();
	cout << "��� ��������" << endl;
	system("pause");
}

void DataManager::deleteTour()
{
	int choise;
	while (1)
	{
		if (tours.size()) {
			system("cls");
			outputAllTours();
			cout << "������� ����� ����, ������� ������ ������� (0 - ��������� �����): ";
			choise = checks::checkInterval(0, this->tours.size());
			if (choise == 0)
				break;
			else
			{
				cout << "����������� ��������? (1-��, 2-���): ";
				int controller = checks::checkInterval(1, 2);
				if (controller == 1) {

					this->tours.erase(this->tours.begin() + choise - 1);
					writeToursToAFile();
					cout << "��� ������" << endl;
					system("pause");
				}

			}
		}
		else {
			cout << "������ �����������" << endl;
			system("pause");
			return;
		}
		
	}
}

void DataManager::editTour()
{
	int choise;
	while (1)
	{
		if (tours.size()) {
			system("cls");
			outputAllTours();
			cout << "������� ����� ����, ������� ������ �������� (0 - ��������� �����): ";
			choise = checks::checkInterval(0, this->tours.size());
			if (choise == 0)
				break;
			else
			{
				Tour obj = Tour();
				system("cls");
				cout << "��������� ������" << endl;
				obj.setInfo();
				this->tours[choise-1] = obj;
				writeUsersToAFile();
				cout << "������ ��������" << endl;
				system("pause");
				return;

			}
		}
		else {
			cout << "������ �����������" << endl;
			system("pause");
			return;
		}
		
	}
	
}

void DataManager::sortDateTours()
{
	if (tours.size()) {
		vector<Tour> tours = this->tours;
		sort(tours.begin(), tours.end(), [](Tour& t1, Tour& t2)
			{
				return t1.getDate() < t2.getDate();
			});
		cout << "��������������� ������" << endl;
		outputAllTours(tours);
		system("pause");
	}
	else {
		cout << "������ �����������" << endl;
		system("pause");
		return;
	}
}

void DataManager::sortCostTours()
{
	if (tours.size()) {
		vector<Tour> tours = this->tours;
		sort(tours.begin(), tours.end(), [](Tour& t1, Tour& t2)
			{
				return t1.getCost() < t2.getCost();
			});
		cout << "��������������� ������" << endl;
		outputAllTours(tours);
		system("pause");
	}
	else {
		cout << "������ �����������" << endl;
		system("pause");
		return;
	}
}

void DataManager::sortCountdaysTours()
{
	if (tours.size()) {
		vector<Tour> tours = this->tours;
		sort(tours.begin(), tours.end(), [](Tour& t1, Tour& t2)
			{
				return t1.getCountDays() < t2.getCountDays();
			});
		cout << "��������������� ������" << endl;
		outputAllTours(tours);
		system("pause");
	}
	else {
		cout << "������ �����������" << endl;
		system("pause");
		return;
	}
	
}

void DataManager::filtrCostTours()
{
	system("cls");
	if (tours.size()) {
		int number1, number2;
		cout << "������� ����������� ����: ";
		number1 = checks::checkInterval(1, 100000);
		cout << "������� ������������ ����: ";
		number2 = checks::checkInterval(number1+1, 100000);
		vector<Tour> t;
		for (int i = 0; i < tours.size(); i++) {
			if (tours[i].getCost()>number1&& tours[i].getCost()<number2) {
				t.push_back(tours[i]);
			}
		}
		if (t.size()) {
			cout << "��������� ����" << endl;
			outputAllTours(t);
		}
		else {
			cout << "������ �� �������" << endl;
		}
	}
	else {
		cout << "������ �����������" << endl;
	}
	system("pause");
}

void DataManager::filtrTypeTours()
{
	system("cls");
	if (tours.size()) {
		string type;
		cout << "������� ��� ����: ";
		getline(cin,type);
		vector<Tour> t;
		for (int i = 0; i < tours.size(); i++) {
			if (tours[i].getTypeTour() == type) {
				t.push_back(tours[i]);
			}
		}
		if (t.size()) {
			cout << "��������� ����" << endl;
			outputAllTours(t);
		}
		else {
			cout << "������ �� �������" << endl;
		}
	}
	else {
		cout << "������ �����������" << endl;
	}
	system("pause");
}

void DataManager::filtrCountryTours()
{
	system("cls");
	if (tours.size()) {
		string country;
		cout << "������� ������: ";
		cin >> country;
		vector<Tour> t;
		for (int i = 0; i < tours.size(); i++) {
			if (tours[i].getCountry() == country) {
				t.push_back(tours[i]);
			}
		}
		if (t.size()) {
			cout << "��������� ����" << endl;
			outputAllTours(t);
		}
		else {
			cout << "������ �� �������" << endl;
		}
	}
	else {
		cout << "������ �����������" << endl;
	}
	system("pause");
}

void DataManager::buyTour()
{
	if (tours.size()) {
		system("cls");
		outputAllTours();
		cout << "������� ����� ����, ������� ������ ������ (0 - ��������� �����): ";
		int choise = checks::checkInterval(0, this->tours.size());;
		if (choise == 0)
			return;
		else
		{
			RealizedTour realizedTour;
			realizedTour.setInfo(accounts[id_account].getLogin(), tours[choise - 1]);
			realizedTours.push_back(realizedTour);
			writeRealizedToursToAFile();
			cout << "������� ������� �����������" << endl;
			system("pause");
		}
	}
	else {
		cout << "������ �����������" << endl;
		system("pause");
		return;
	}
}

void DataManager::outputAllTours()
{
	if (this->tours.size()) {
		outputCapTours();
		for (int i = 0; i < this->tours.size(); i++)
		{
			cout << "|" << setw(5) << left << i + 1 << "|"; this->tours[i].outputInfo(); cout << endl;
		}
		cout << "|----------------------------------------------------------------------------------------------------------------|\n";
	}
	else {
		cout << "������ �����������" << endl;
	}
}

void DataManager::outputAllTours(vector<Tour> t)
{
	if (t.size()) {
		outputCapTours();
		for (int i = 0; i < t.size(); i++)
		{
			cout << "|" << setw(5) << left << i + 1 << "|"; t[i].outputInfo(); cout << endl;
		}
		cout << "|----------------------------------------------------------------------------------------------------------------|\n";
	}
	else {
		cout << "������ �����������" << endl;
	}
}

void DataManager::outputCapTours()
{
	cout << "\n|----------------------------------------------------------------------------------------------------------------|"
		<< "\n|                                                      ����                                                      |"
		<< "\n|----------------------------------------------------------------------------------------------------------------|"
		<< "\n|  �  |      ��� �������      | ������  ���������� |   ��� ����������   | ���-�� ���� |  ��������� | ���� ������ |"
		<< "\n|----------------------------------------------------------------------------------------------------------------|\n";
}

void DataManager::deleteRealizedTour()
{
	int choise;
	while (1)
	{
		if (realizedTours.size()) {
			system("cls");
			outputAllRealizedTours();
			cout << "������� ����� �������������� ����, ������� ������ ������� (0 - ��������� �����): ";
			choise = checks::checkInterval(0, this->realizedTours.size());
			if (choise == 0)
				break;
			else
			{
				cout << "����������� ��������? (1-��, 2-���): ";
				int controller = checks::checkInterval(1, 2);
				if (controller == 1) {

					this->realizedTours.erase(this->realizedTours.begin() + choise - 1);
					writeRealizedToursToAFile();
					cout << "������������� ��� ������" << endl;
					system("pause");
				}

			}
		}
		else {
			cout << "������ �����������" << endl;
			system("pause");
			return;
		}

	}
}

void DataManager::sortDateRealizedTours()
{
	if (realizedTours.size()) {
		vector<RealizedTour> t = this->realizedTours;
		sort(t.begin(), t.end(), [](RealizedTour& t1, RealizedTour& t2)
			{
				return t1.getTour().getDate() < t2.getTour().getDate();
			});
		cout << "��������������� ������" << endl;
		outputAllRealizedTours(t);
		system("pause");
	}
	else {
		cout << "������ �����������" << endl;
		system("pause");
		return;
	}
}

void DataManager::sortCostRealizedTours()
{
	if (realizedTours.size()) {
		vector<RealizedTour> t = this->realizedTours;
		sort(t.begin(), t.end(), [](RealizedTour& t1, RealizedTour& t2)
			{
				return t1.getTour().getCost() < t2.getTour().getCost();
			});
		cout << "��������������� ������" << endl;
		outputAllRealizedTours(t);
		system("pause");
	}
	else {
		cout << "������ �����������" << endl;
		system("pause");
		return;
	}
}

void DataManager::sortCountdaysRealizedTours()
{
	if (realizedTours.size()) {
		vector<RealizedTour> t = this->realizedTours;
		sort(t.begin(), t.end(), [](RealizedTour& t1, RealizedTour& t2)
			{
				return t1.getTour().getCountDays() < t2.getTour().getCountDays();
			});
		cout << "��������������� ������" << endl;
		outputAllRealizedTours(t);
		system("pause");
	}
	else {
		cout << "������ �����������" << endl;
		system("pause");
		return;
	}
}

void DataManager::sortLoginRealizedTours()
{
	if (realizedTours.size()) {
		vector<RealizedTour> t = this->realizedTours;
		sort(t.begin(), t.end(), [](RealizedTour& t1, RealizedTour& t2)
			{
				return t1.getLogin() < t2.getLogin();
			});
		cout << "��������������� ������" << endl;
		outputAllRealizedTours(t);
		system("pause");
	}
	else {
		cout << "������ �����������" << endl;
		system("pause");
		return;
	}
}

void DataManager::filtrCostRealizedTours()
{
	system("cls");
	if (realizedTours.size()) {
		int number1, number2;
		cout << "������� ����������� ����: ";
		number1 = checks::checkInterval(1, 100000);
		cout << "������� ������������ ����: ";
		number2 = checks::checkInterval(number1 + 1, 100000);
		vector<RealizedTour> t;
		for (int i = 0; i < realizedTours.size(); i++) {
			if (realizedTours[i].getTour().getCost() > number1 &&realizedTours[i].getTour().getCost() < number2) {
				t.push_back(realizedTours[i]);
			}
		}
		if (t.size()) {
			cout << "��������� ������������� ����" << endl;
			outputAllRealizedTours(t);
		}
		else {
			cout << "������ �� �������" << endl;
		}
	}
	else {
		cout << "������ �����������" << endl;
	}
	system("pause");
}

void DataManager::filtrTypeRealizedTours()
{
	system("cls");
	if (realizedTours.size()) {
		string type;
		cout << "������� ��� �������: ";
		getline(cin, type);
		vector<RealizedTour> t;
		for (int i = 0; i < realizedTours.size(); i++) {
			if (realizedTours[i].getTour().getTypeTour() == type) {
				t.push_back(realizedTours[i]);
			}
		}
		if (t.size()) {
			cout << "��������� ������������� ����" << endl;
			outputAllRealizedTours(t);
		}
		else {
			cout << "������ �� �������" << endl;
		}
	}
	else {
		cout << "������ �����������" << endl;
	}
	system("pause");
}

void DataManager::filtrCountryRealizedTours()
{
	system("cls");
	if (realizedTours.size()) {
		string country;
		cout << "������� c�����: ";
		getline(cin, country);
		vector<RealizedTour> t;
		for (int i = 0; i < realizedTours.size(); i++) {
			if (realizedTours[i].getTour().getCountry() == country) {
				t.push_back(realizedTours[i]);
			}
		}
		if (t.size()) {
			cout << "��������� ������������� ����" << endl;
			outputAllRealizedTours(t);
		}
		else {
			cout << "������ �� �������" << endl;
		}
	}
	else {
		cout << "������ �����������" << endl;
	}
	system("pause");
}

void DataManager::filtrLoginRealizedTours()
{
	system("cls");
	if (realizedTours.size()) {
		string login;
		cout << "������� �����: ";
		getline(cin, login);
		vector<RealizedTour> t;
		for (int i = 0; i < realizedTours.size(); i++) {
			if (realizedTours[i].getLogin() == login) {
				t.push_back(realizedTours[i]);
			}
		}
		if (t.size()) {
			cout << "��������� ������������� ����" << endl;
			outputAllRealizedTours(t);
		}
		else {
			cout << "������ �� �������" << endl;
		}
	}
	else {
		cout << "������ �����������" << endl;
	}
	system("pause");
}

void DataManager::outputAllRealizedTours()
{
	if (this->realizedTours.size()) {
		outputCapRealizedTours();
		for (int i = 0; i < this->realizedTours.size(); i++)
		{
			cout << "|" << setw(5) << left << i + 1 << "|"; this->realizedTours[i].outputInfo(); cout << endl;
		}
		cout << "|---------------------------------------------------------------------------------------------------------------------------------|\n";
	}
	else {
		cout << "������ �����������" << endl;
	}
}

void DataManager::outputAllRealizedTours(vector<RealizedTour> t)
{
	if (t.size()) {
		outputCapRealizedTours();
		for (int i = 0; i < t.size(); i++)
		{
			cout << "|" << setw(5) << left << i + 1 << "|"; t[i].outputInfo(); cout << endl;
		}
		cout << "|---------------------------------------------------------------------------------------------------------------------------------|\n";
	}
	else {
		cout << "������ �����������" << endl;
	}
}

void DataManager::outputAllRealizedToursForUser()
{
	vector<RealizedTour> t;
	for (int i = 0; i < realizedTours.size(); i++) {
		if (realizedTours[i].getLogin() == accounts[id_account].getLogin()) {
			t.push_back(realizedTours[i]);
		}
	}
	outputAllRealizedTours(t);
}

void DataManager::outputCapRealizedTours()
{
	cout << "\n|---------------------------------------------------------------------------------------------------------------------------------|"
		<< "\n|                                                            ������������� ����                                                   |"
		<< "\n|---------------------------------------------------------------------------------------------------------------------------------|"
		<< "\n|  �  |      ��� �������      | ������  ���������� |   ��� ����������   | ���-�� ���� |  ��������� | ���� ������ | ����� �����-�� |"
		<< "\n|---------------------------------------------------------------------------------------------------------------------------------|\n";
}

void DataManager::outputReport()
{
	system("cls");
	if (realizedTours.size()) {
		int sum = 0;
		for (int i = 0; i < realizedTours.size(); i++) {
			sum += realizedTours[i].getTour().getCost();
		}
		cout << "����� ������ �������" << endl;
		cout << "����� ������� ������� - " << realizedTours.size();
		cout << "\n����� ������� - " << sum;
		outputAllRealizedTours();
		system("pause");
	}
	else {
		cout << "������ �����������" << endl;
		system("pause");
	}
}
