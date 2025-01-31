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
	vector<Tour> tours; // Вектор с турами
	vector<Account> accounts; // Вектор с пользователями
	vector<RealizedTour> realizedTours; // Вектор с реализованными турами
	inline static DataManager* instance = nullptr; // экземпляр класса	
	int id_account = -1;
	DataManager() {};
	DataManager(const DataManager&);
public:
	
	// Создание объекта
	static DataManager* getInstance();
	void init();

	// Считывание из файла
	void readToursFromAFile();
	void writeToursToAFile();
	void readRealizedToursFromAFile();
	void writeRealizedToursToAFile();
	void readUsersFromAFile();
	void writeUsersToAFile();
	
	//Проверка присутствия данных
	bool isUsersPresent();

	void registration(string role); //Регистрация
	string autho();	//Авторизация
	void outputCapUsers(); // Вывод шапки таблицы пользователей
	void outputAllUsers(); // Вывод таблицы пользователей
	void outputAllUsers(vector<Account> &acc); // Вывод таблицы пользователей
	void delUser(); // Удаление пользователя из контейнера
	void editUser(); // Изменение данных о пользователях
	void sortUsers(); // Сортировка пользователей 
	void searchLoginUsers(); // Поиск по логину
	void filtrRoleUsers(); // Фильтрация по роли

	//работа с турами
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

	//Работа с реализованными турами
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

	// Вывод отчета
	void outputReport();
};


