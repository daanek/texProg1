#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<conio.h>
#include <Windows.h>
#include <fstream>
#include "Keeper.h"
using namespace std;
//+ git C:\Users\skaku\source\repos\tstaexProg1\texProg1\main.cpp

int main()
{
	Keeper one;
	setlocale(LC_ALL, "");
	int z;
	string buf;
	char mennu[8][40];

	strcpy(mennu[0], "Option: \n");
	strcpy(mennu[1], "1) Добавить элемент  \n");
	strcpy(mennu[2], "2) Удалить элемент   \n");
	strcpy(mennu[3], "3) Показать \n");
	strcpy(mennu[4], "4) Соxранить в файл  \n");
	strcpy(mennu[5], "5) Изъять из файла\n");
	strcpy(mennu[6], "6) Редактирование \n");
	strcpy(mennu[7], "0) Выйти \n");
	HANDLE hStdout;
	WORD foregroundColor;
	WORD foregroundColor1;
	WORD backgroundColor;
	foregroundColor = FOREGROUND_INTENSITY |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE;
	foregroundColor1 = FOREGROUND_INTENSITY |
		FOREGROUND_BLUE |
		FOREGROUND_GREEN |
		FOREGROUND_RED;
	backgroundColor = 0;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int flag = 1;
	char s = 0;;
	while (1)
	{
		flag = 1;
		s = 0;
		while (s != 13)
		{
			system("cls");
			if (s == -32) { s = _getch(); }
			if (s == 72)
			{
				if (flag == 1)
					flag = 7;
				else
					flag--;
			}
			if (s == 80)
			{
				if (flag == 7)
				{
					flag = 1;
				}
				else
					flag++;
			}
			for (int i = 0; i < 8; i++)
			{
				if (i == flag)
				{
					printf(" ");
					SetConsoleTextAttribute(hStdout, foregroundColor | backgroundColor);
					printf(" %s", mennu[i]);

					SetConsoleTextAttribute(hStdout, foregroundColor1);
				}
				else
					printf("%s", mennu[i]);
			}
			s = _getch();
		}
		switch (flag) {
		case 1:
			cout << "1 - Poet" << endl << "2 - Romantist" << endl << "3 - Fantast" << endl;
			getline(cin, buf);
			z = stoi(buf);
			switch (z)
			{
			case 1:
				{
				one + 1;
					break;
				}
			case 2:
				{
				one + 2;
					break;
				}
			case 3:
				{
				one + 3;
					break;
				}
			}
			break;
		case 2:
			one.delet();
			break;
		case 3:
		{
			one.ShowAll();
			system("pause");
			break;
		}
		case 4:
		{
			one.save();
			system("pause");
			break;
		}
		case 5:
		{
			one.read();
			break;
		}
		case 6:
		{
			one.redak();
			break;
		}
		case 7: {return 0; break; }
		}
	} 
}








