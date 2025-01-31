#include "menu.h"

Menu::Menu()
{
	this->dataManager = DataManager::getInstance();
	this->dataManager->init();
}

void Menu::startMenu()
{
	if (dataManager->isUsersPresent()) {
		dataManager->registration("ADMIN");
	}
	vector<string> menu = { "Авторизация", "Регистрация", "Выход" };
	string name = "Добро пожаловать";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			string res = dataManager->autho();
			if (res == "ADMIN") {
				adminMenu();
			}
			else if (res == "USER") {
				userMenu();
			}
			else {
				cout << "\nОшибка авторизации" << endl;
				system("pause");
			}
			break;
		}
		case 2:
		{
			dataManager->registration("USER");
			break;
		}
		case 3:
		{
			return;
		}
		}
	}
}

void Menu::adminMenu()
{
	vector<string> menu = { "Туры", "Реализованные туры","Учетные записи", "Редактировать собственные данные", "Выход"};
	string name = "Меню администратора";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			toursInfoMenu();
			break;
		}
		case 2:
		{
			realizedToursInfoMenu();
			break;
		}
		case 3:
		{
			usersInfoMenu();
			break;
		}
		case 4:
		{
			dataManager->editUser();
			break;
		}
		case 5:
		{
			return;
		}
		}
	}
}



void Menu::userMenu()
{
	vector<string> menu = { "Просмотор туров","Купить путевку","Сортировка туров","Фильтрация туров", "Просмотр купленных путевок","Редактирование собственных данных", "Выход"};
	string name = "Меню пользователя";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			system("cls");
			dataManager->outputAllTours();
			system("pause");
			break;
		}
		case 2:
		{
			dataManager->buyTour();
			break;
		}
		case 3:
		{
			sortToursMenu();
			break;
		}
		case 4:
		{
			searchToursMenu();
			break;
		}
		case 5:
		{
			system("cls");
			dataManager->outputAllRealizedToursForUser();
			system("pause");
			break;
		}
		case 6:
		{
			dataManager->editUser();
			break;
		}
		case 7:
		{
			return;
		}
		}
	}
}

void Menu::usersInfoMenu()
{
	vector<string> menu = { "Добавить администратора", "Просмотор учетных записей","Удалить учетную запись","Сортировка учетных записей","Фильтрация учетных записей", "Выход" };
	string name = "Пользователи";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			dataManager->registration("ADMIN");
			break;
		}
		case 2:
		{
			system("cls");
			dataManager->outputAllUsers();
			system("pause");
			break;
		}
		case 3:
		{
			dataManager->delUser();
			break;
		}
		case 4:
		{
			dataManager->sortUsers();
			break;
		}
		case 5:
		{
			searchUsersMenu();
			break;
		}
		case 6:
		{
			return;
		}
		}
	}
}

void Menu::toursInfoMenu()
{
	vector<string> menu = { "Добавить тур", "Просмотор туров","Удалить тур","Сортировка туров","Фильтрация туров","Изменить тур", "Выход"};
	string name = "Туры";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			dataManager->addTour();
			break;
		}
		case 2:
		{
			system("cls");
			dataManager->outputAllTours();
			system("pause");
			break;
		}
		case 3:
		{
			dataManager->deleteTour();
			break;
		}
		case 4:
		{
			sortToursMenu();
			break;
		}
		case 5:
		{
			searchToursMenu();
			break;
		}
		case 6:
		{
			dataManager->editTour();
			break;
		}
		case 7:
		{
			return;
		}
		}
	}
}

void Menu::realizedToursInfoMenu()
{
	vector<string> menu = { "Просмотор реализованных туров","Удалить реализованный тур","Сортировка реализованных туров","Фильтрация реализованных туров","Отчет о продажах","Выход" };
	string name = "Реализованные туры";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			system("cls");
			dataManager->outputAllRealizedTours();
			system("pause");
			break;
		}
		case 2:
		{
			dataManager->deleteRealizedTour();
			break;
		}
		case 3:
		{
			sortRealizedToursMenu();
			break;
		}
		case 4:
		{
			searchRealizedToursMenu();
			break;
		}
		case 5:
		{
			dataManager->outputReport();
			break;
		}
		case 6:
		{
			return;
		}
		}
	}
}

void Menu::searchUsersMenu() {
	vector<string> menu = { "Поиск по логину", "Фильтрация по роли", "Выход" };
	string name = "Поиск пользователей";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			dataManager->searchLoginUsers();
			break;
		}
		case 2:
		{
			dataManager->filtrRoleUsers();
			break;
		}
		case 3:
		{
			return;
		}
		}
	}
}

void Menu::searchToursMenu()
{
	vector<string> menu = { "Поиск по стране", "Поиск по типу тура","Фильтрация по цене", "Выход"};
	string name = "Поиск туров";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			dataManager->filtrCountryTours();
			break;
		}
		case 2:
		{
			dataManager->filtrTypeTours();
			break;
		}
		case 3:
		{
			dataManager->filtrCostTours();
			break;
		}
		case 4:
		{
			return;
		}
		}
	}
}

void Menu::sortToursMenu()
{
	vector<string> menu = { "Сортировка по цене", "Сортировка по количеству дней","Сортировка по дате", "Выход" };
	string name = "Сортировка туров";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			dataManager->sortCostTours();
			break;
		}
		case 2:
		{
			dataManager->sortCountdaysTours();
			break;
		}
		case 3:
		{
			dataManager->sortDateTours();
			break;
		}
		case 4:
		{
			return;
		}
		}
	}
}

void Menu::sortRealizedToursMenu()
{
	vector<string> menu = { "Сортировка по цене", "Сортировка по количеству дней","Сортировка по дате", "Сортировака по логину", "Выход"};
	string name = "Сортировка реализованных туров";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			dataManager->sortCostRealizedTours();
			break;
		}
		case 2:
		{
			dataManager->sortCountdaysRealizedTours();
			break;
		}
		case 3:
		{
			dataManager->sortDateRealizedTours();
			break;
		}
		case 4:
		{
			dataManager->sortLoginRealizedTours();
			break;
		}
		case 5:
		{
			return;
		}
		}
	}
}

void Menu::searchRealizedToursMenu()
{
	vector<string> menu = { "Поиск по стране", "Поиск по типу тура","Фильтрация по цене", "Поиск по логину", "Выход"};
	string name = "Поиск реализованных туров";
	while (true) {
		switch (checks::checkMenu(menu, name))
		{
		case 1:
		{
			dataManager->filtrCountryRealizedTours();
			break;
		}
		case 2:
		{
			dataManager->filtrTypeRealizedTours();
			break;
		}
		case 3:
		{
			dataManager->filtrCostRealizedTours();
			break;
		}
		case 4:
		{
			dataManager->filtrLoginRealizedTours();
			break;
		}
		case 5:
		{
			return;
		}
		}
	}
}
