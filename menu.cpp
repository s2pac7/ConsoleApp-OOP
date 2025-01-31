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
	vector<string> menu = { "�����������", "�����������", "�����" };
	string name = "����� ����������";
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
				cout << "\n������ �����������" << endl;
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
	vector<string> menu = { "����", "������������� ����","������� ������", "������������� ����������� ������", "�����"};
	string name = "���� ��������������";
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
	vector<string> menu = { "��������� �����","������ �������","���������� �����","���������� �����", "�������� ��������� �������","�������������� ����������� ������", "�����"};
	string name = "���� ������������";
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
	vector<string> menu = { "�������� ��������������", "��������� ������� �������","������� ������� ������","���������� ������� �������","���������� ������� �������", "�����" };
	string name = "������������";
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
	vector<string> menu = { "�������� ���", "��������� �����","������� ���","���������� �����","���������� �����","�������� ���", "�����"};
	string name = "����";
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
	vector<string> menu = { "��������� ������������� �����","������� ������������� ���","���������� ������������� �����","���������� ������������� �����","����� � ��������","�����" };
	string name = "������������� ����";
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
	vector<string> menu = { "����� �� ������", "���������� �� ����", "�����" };
	string name = "����� �������������";
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
	vector<string> menu = { "����� �� ������", "����� �� ���� ����","���������� �� ����", "�����"};
	string name = "����� �����";
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
	vector<string> menu = { "���������� �� ����", "���������� �� ���������� ����","���������� �� ����", "�����" };
	string name = "���������� �����";
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
	vector<string> menu = { "���������� �� ����", "���������� �� ���������� ����","���������� �� ����", "����������� �� ������", "�����"};
	string name = "���������� ������������� �����";
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
	vector<string> menu = { "����� �� ������", "����� �� ���� ����","���������� �� ����", "����� �� ������", "�����"};
	string name = "����� ������������� �����";
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
