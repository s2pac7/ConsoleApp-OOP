#include "checks.h"

int checks::checkMenu(vector<string> menu, string name)
{
		system("cls");
		cout << name << endl;
		for (int i = 0; i < menu.size(); i++) {
			cout << i + 1 << ". " << menu[i] << endl;
		}
		cout << "Выберите пункт: ";
		int i = checkInterval(1,menu.size());
		return i;
}

int checks::enterInt()
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	int value, counter = 0;
	SmartPointer<char> BufForWriting(new char[256]);
	cin.clear();
	cin.getline(BufForWriting.getPtr(), 256, '\n');
	for (int i = 0; BufForWriting.getPtr()[i] != '\0'; i++)
		if (isdigit(BufForWriting.getPtr()[i]))
			counter++;
	if (strlen(BufForWriting.getPtr()) != counter ||
		(BufForWriting.getPtr()[0] == '0' && strlen(BufForWriting.getPtr()) > 1))
		value = -1;
	else value = atoi(BufForWriting.getPtr());
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	return value;
}
int checks::checkInterval(int min, int max)
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	int value;
	value = enterInt();
	while (value < min || value > max)
	{
		string str = "Число должно быть от ";
		str += to_string(min);
		str += " до ";
		str += to_string(max);
		cout << str << endl;
		value = enterInt();
	}
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	return value;
}
double checks::enterDouble()
{
	while (true)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		int controller1 = 0, controller2 = 0;
		double value;
		SmartPointer<char> BufForWriting(new char[256]);
		cin.clear(); cin.getline(BufForWriting.getPtr(), 100, '\n');
		for (int i = 0; BufForWriting.getPtr()[i] != '\0'; i++)
		{
			if (isdigit(BufForWriting.getPtr()[i]))
				controller1++;
			if (BufForWriting.getPtr()[i] == ',')
				controller2++;
		}
		if (strlen(BufForWriting.getPtr()) != (controller1 + controller2) ||
			(BufForWriting.getPtr()[0] == '0' && BufForWriting.getPtr()[1] == '0') ||
			BufForWriting.getPtr()[0] == ',' || controller2 > 1)
		{
			cout<<"Ошибка ввода, повторите ввод: ";
			continue;
		}
		else value = atof(BufForWriting.getPtr());
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		return value;
	}
}
double checks::checkInterval(double min, double max)
{
	double value;
	while (true)
	{
		value = checks::enterDouble();
		if (value < min || value > max) {
			string str = "Число должно быть от " + to_string(min) + " до " + to_string(max);
			cout<< str<<endl;
		}
		else
			break;
	}
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	return value;
}

string checks::enterPasswordWithStars()
{
	string password;
	char c;

	while (true) {
		int i = 0;
		while ((c = _getch()) != 13)
		{
			if (c == 8) {
				if (i == 0)
					continue;
				cout << (char)8 << ' ' << (char)8;
				if (!password.empty())
					password.pop_back();
				i--;
				continue;
			}
			password += c;
			_putch('*');
			i++;
		}
		if (i < 3 || i>20) {
			cout<<"\nДлина пароля от 2 до 19 символов";
			password = "";
		}
		else
			break;
	}
	return password;

}

string checks::encrypt(string message)
{
	int key = 10;
	string result = "";
	int len = message.length();
	for (int i = 0; i < len; i++) {
		// Если символ является буквой английского алфавита
		if (isalpha(message[i])) {
			// Определяем новый символ
			char new_char = message[i] + key;
			// Если новый символ выходит за пределы алфавита, то циклически переносим его в начало или конец алфавита
			if (new_char > 'z') {
				new_char = 'a' + (new_char - 'z' - 1);
			}
			else if (new_char < 'a') {
				new_char = 'z' - ('a' - new_char - 1);
			}
			result += new_char;
		}
		else {
			result += message[i];
		}
	}
	return result;
}

string checks::replaceSpacingOnStar(string str)
{
	replace(str.begin(), str.end(), ' ', '*');
	return str;
}

string checks::replaceStarOnSpacing(string str)
{
	replace(str.begin(), str.end(), '*', ' ');
	return str;
}
