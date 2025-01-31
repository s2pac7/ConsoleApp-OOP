#include "menu.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	Menu menu = Menu();
	menu.startMenu();
}

