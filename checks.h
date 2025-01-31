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

// ��������� ������
namespace checks
{
	int checkMenu(vector<string> menu, string name); // ����� ����
	int enterInt(); // ���� int
	int checkInterval(int min, int max); // ���� int � ��������
	double enterDouble(); // ���� double
	double checkInterval(double min, double max); // ���� double � ��������
	string enterPasswordWithStars(); // ���� ������ �����������
	string encrypt(string); // ����������
	string replaceSpacingOnStar(string str);
	string replaceStarOnSpacing(string str);
};
