#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "smartPointer.h"
#include <iomanip>
#include <algorithm>
using namespace std;

// Обработка данных
namespace checks
{
	int checkMenu(vector<string> menu, string name); // Выбор меню
	int enterInt(); // Ввод int
	int checkInterval(int min, int max); // Ввод int в пределах
	double enterDouble(); // Ввод double
	double checkInterval(double min, double max); // Ввод double в пределах
	string enterPasswordWithStars(); // Ввод пароля звездочками
	string encrypt(string); // шифрование
	string replaceSpacingOnStar(string str);
	string replaceStarOnSpacing(string str);
};
