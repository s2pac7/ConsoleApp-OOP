#pragma once
#include "tour.h"
#include "account.h"
#include "realizedTour.h"
#include <fstream>
#include <algorithm>

const string ACCOUNTS_FILE = "users.txt";
const string TOURS_FILE = "tours.txt";
const string REALIZED_TOURS_FILE = "realizedtours.txt";

class DataManager {
private:
	vector<Tour> tours; // ������ � ������
	vector<Account> accounts; // ������ � ��������������
	vector<RealizedTour> realizedTours; // ������ � �������������� ������
	inline static DataManager* instance = nullptr; // ��������� ������	
	int id_account = -1;
	DataManager() {};
	DataManager(const DataManager&);
public:
	
	// �������� �������
	static DataManager* getInstance();
	void init();

	// ���������� �� �����
	void readToursFromAFile();
	void writeToursToAFile();
	void readRealizedToursFromAFile();
	void writeRealizedToursToAFile();
	void readUsersFromAFile();
	void writeUsersToAFile();
	
	//�������� ����������� ������
	bool isUsersPresent();

	void registration(string role); //�����������
	string autho();	//�����������
	void outputCapUsers(); // ����� ����� ������� �������������
	void outputAllUsers(); // ����� ������� �������������
	void outputAllUsers(vector<Account> &acc); // ����� ������� �������������
	void delUser(); // �������� ������������ �� ����������
	void editUser(); // ��������� ������ � �������������
	void sortUsers(); // ���������� ������������� 
	void searchLoginUsers(); // ����� �� ������
	void filtrRoleUsers(); // ���������� �� ����

	//������ � ������
	void addTour();
	void deleteTour();
	void editTour();
	void sortDateTours();
	void sortCostTours();
	void sortCountdaysTours();
	void filtrCostTours();
	void filtrTypeTours();
	void filtrCountryTours();
	void buyTour();
	void outputAllTours();
	void outputAllTours(vector<Tour> t);
	void outputCapTours(); 

	//������ � �������������� ������
	void deleteRealizedTour();
	void sortDateRealizedTours();
	void sortCostRealizedTours();
	void sortCountdaysRealizedTours();
	void sortLoginRealizedTours();
	void filtrCostRealizedTours();
	void filtrTypeRealizedTours();
	void filtrCountryRealizedTours();
	void filtrLoginRealizedTours();
	void outputAllRealizedTours();
	void outputAllRealizedTours(vector<RealizedTour> t);
	void outputAllRealizedToursForUser();
	void outputCapRealizedTours();

	// ����� ������
	void outputReport();
};


