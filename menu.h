#pragma once
#include "dataManager.h"

class Menu {
private:
	DataManager* dataManager; // Объект управления данными
public:
	Menu();

	void startMenu();

	void adminMenu();

	void userMenu();

	void usersInfoMenu();

	void toursInfoMenu();

	void realizedToursInfoMenu();

	void searchUsersMenu();

	void searchToursMenu();

	void sortToursMenu();

	void sortRealizedToursMenu();

	void searchRealizedToursMenu();
};