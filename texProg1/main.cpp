#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<conio.h>
#include <Windows.h>
#include <fstream>
using namespace std;
//+ git
class Base
{
public:
	string fio;
	string* proz;
	int nproz;

	string getfio() { return fio; };
	
	string* getproz() {
		cout << "Books: " << endl;//only for consol
		for (int i = 0; i < nproz; i++)
		{
			cout << "--" << proz[i] << endl;
		}
		
		return proz;
	};
	int getnproz()
	{
		return nproz;
	}
	void setfio()
	{
		cout << "input FIO: ";
		getline(cin, fio);
	};
	void setproz()
	{
		string buf;
		cout << "input number book ";
		cin >> nproz;
		cout << "input books" << endl;
		getline(cin, buf);//chtobi prochitala last char
		
		proz = new string[nproz];

		for (int i = 0; i < nproz; i++)
		{
			getline(cin, buf);
			proz[i] = buf;
			
		}
	};


	
	virtual void showall(int col = 1) = 0;

	virtual void writeall(ofstream &f) = 0;
	 
	virtual ~Base() = 0;

	virtual void redakone(int a) = 0;
};
Base::~Base() {};


class poet:public Base
{
	string birth;
	string death;
public:
	poet() 
	{
		cout << "konstructor poet" << endl;
		setfio();
		setproz();
		data();
	}
	poet(ifstream &f)
	{
		string buf;
		getline(f, fio);

		getline(f, buf);
		nproz = stoi(buf);
		
		proz = new string[nproz];
		for (int i = 0; i < nproz; i++)
		{
			getline(f, proz[i]);
			
		}
		getline(f, birth);
		getline(f, death);
	
	}
	
	void data()
	{
		cout << "input date birth author";
		getline(cin, birth);
		cout << "input date death author or 0, if he is alive";
		getline(cin, death);
	}
	void printData()
	{
		cout << "years of life ";
		if (death == "0")
		{cout << birth << " - ..." << endl;}
		else
		{cout << birth << " - " <<death<< endl;}
	}
	
	void showall(int col = 1) override
	{
		cout << "Poet" << endl;
		cout << getfio() << endl;
		if (col == 2)
			return;
		getproz();
		printData();


	}
	void writeall(ofstream& f) override
	{
		f << "1" << endl;
		f << fio << endl;
		f << getnproz() << endl;
		for (int i = 0; i < getnproz(); i++)
		{
			f<< proz[i] << endl;
		}
		f << birth << endl;
		f << death << endl;

	}
	void redakone(int a) override
	{
		switch (a)
		{
		case 1: {setfio(); break; }

		case 2: {setproz(); break; }

		case 3: {data(); break; }
		}
	}

	~poet()
	{
		cout << "poet = " << proz << endl;
		delete proz;
	}
};

class roman:public Base
{
	string birth;
	string death;
	string biograf;
public:

	roman()
	{
		cout << "konstructor roman" << endl;
		setfio();
		setproz();
		data();
		setbiograf();
	}


	roman(ifstream& f)
	{
		string buf;
		getline(f, fio);

		getline(f, buf);
		nproz = stoi(buf);

		proz = new string[nproz];
		for (int i = 0; i < nproz; i++)
		{
			getline(f, proz[i]);
		}
		getline(f, birth);
		getline(f, death);
		getline(f, biograf);
	}

	void setbiograf() 
	{
		cout << "input brief biography" << endl;
		getline(cin,biograf);
		
	}
	void getbiograf()
	{
		int j =0;
		int i = 0;
		int len=biograf.length();
		cout << "brief biography" << endl;
		for(i = 0;i < len;i++)
		{
			cout << biograf[i];
			j++;
			if ((biograf[i]==' ') and (j>20))
			{
				cout << endl;
				j = 0;
			}
		}
		cout << endl;
	}
	void data()
	{
		cout << "input date birth author";
		getline(cin, birth);
		cout << "input date death author or 0, if he is alive";
		getline(cin, death);
	}
	void printData()
	{
		if (death =="0")
		{
			cout << birth << " - ..." << endl;
		}
		else
		{
			cout << birth << "-" << death << endl;
		}
	}
	void showall(int col = 1) override
	{
		cout << "Romantist" << endl;
		cout << getfio() << endl;
		if (col == 2)
			return;
		getproz();
		printData();
		getbiograf();
	}
	void writeall(ofstream &f) override
	{
		f << "2" << endl;
		f << fio << endl;
		f << getnproz() << endl;
		for (int i = 0; i < getnproz(); i++)
		{
			f << proz[i] << endl;

		}
		f << birth << endl;
		f << death << endl;
		f << biograf << endl;

	}

	~roman()
	{
		cout << "roman = " << proz << endl;
		delete proz;
	}
	void redakone(int a) override
	{

		switch (a)
		{
		case 1: {setfio(); break; }

		case 2: {setproz(); break; }

		case 3: {data(); break; }

		case 4: {setbiograf(); break; }
		}

	}
	
};
class fantas:public Base
{
	string film;
public:

	fantas()
	{
		cout << "konstructor fantas" << endl;
		setfio();
		setproz();
		setfilm();
	}
	fantas(ifstream& f)
	{
		string buf;
		getline(f, fio);

		getline(f, buf);
		nproz = stoi(buf);

		proz = new string[nproz];
		for (int i = 0; i < nproz; i++)
		{
			getline(f, proz[i]);
		}
		getline(f, film);
	}
	~fantas()
	{
		cout << "fantast = " <<proz<< endl;
		delete proz;
	}
	void setfilm()
	{
		cout << "Is there a movie based on the book?" << endl<<"0 - NO"<<endl<<"1 - YES"<<endl;
		getline(cin, film);
	}
	void getfilm()
	{
		cout << "movie based on the book: ";
		if (film == "0")
			cout << "NO";
		else
		{
			cout << "YES";
		}
		cout << endl;
	}
	void showall(int col = 1) override
	{
		cout << "Fantast" << endl;
		cout << getfio() << endl;
		if (col == 2)
			return;
		getproz();
		getfilm();
	}
	void writeall(ofstream& f) override
	{
		f << "3" << endl;
		f << fio << endl;
		f << getnproz() << endl;
		for (int i = 0; i < getnproz(); i++)
		{
			f << proz[i] << endl;
		}
		f << film << endl;
	}
	void redakone(int a) override
	{
		switch (a)
		{
		case 1: {setfio(); break; }

		case 2: {setproz(); break; }

		case 3: {setfilm(); break; }
		}
	}
};

class Keeper {
	Base** arr;
	int n;
public:
	Keeper()
	{
		n = 0;
		arr = new Base*[n];
	}
	Keeper(const Keeper& other)
	{
		this->arr = new Base * [other.n];
		this->n = other.n;

		for (int i = 0; i < this->n; i++)
		{
			this->arr[i] = other.arr[i];
		}
		
	}
	~Keeper()
	{
		delete arr;
	}
	Keeper operator +(int a)
	{
		int i;
		Base** buf(arr);
		n++;
		arr = new Base * [n];
		for (i = 0; i < this->n-1; i++)
		{
			this->arr[i] = buf[i];
		}
		switch (a)
		{
		case 1: {arr[i] = new poet(); break; }

		case 2: {arr[i] = new roman(); break; }

		case 3: {arr[i] = new fantas(); break; }

		}
		return*this;
	}

	void ShowAll()
	{
		for (int i = 0; i < n; i++)
		{
			arr[i]->showall();
		}
	}

	void save()
	{
		string file = "file.txt";
		ofstream f;
		f.open(file);
		f << n << endl;
		for (int i = 0; i < n; i++)
		{
			arr[i]->writeall(f);
		}
		f.close();
	}
	void read()
	{
		int a;

		string text = "file.txt";
		ifstream file;
		try 
		{
			file.open(text);
		if (!file.is_open())
			throw text;
		}
		catch(string tt)
		{
			cout << "file " << tt << " does not exist" << endl;
			system("pause");
			return;
		}
		string buf;

		getline(file, buf);
		n = stoi(buf);
		arr = new Base * [n];
		int i = 0;
		while (!file.eof()&& i<n)
		{
			
			getline(file, buf);
			a = stoi(buf);

			switch (a)
			{
			case 1: {arr[i] = new poet(file); i++; break; }

			case 2: {arr[i] = new roman(file); i++; break; }

			case 3: {arr[i] = new fantas(file); i++; break; }
			}
		}
		file.close();
	}
	void delet()
	{
		int a;
		string buf;
		Keeper buff(*this);

		for (int i = 0; i < n; i++)
		{
			cout << i+1  << " ";
			arr[i]->showall(2);
			cout << endl;
		}
		cout << "input number element for delete ";

		getline(cin, buf);

		a = stoi(buf);
	
		int j = 0;
		if (n!=0)
			n--;
		arr = new Base* [n];
		
		for (int i = 0; i < n; i++)
		{
			if (i == a-1)
			{
				j++;
			}
			arr[i] = buff.arr[j];
			j++;
		}
	}

	void fiooutput()
	{
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << " ";
			arr[i]->showall(2);
			cout << endl;
		}
	}

	void redak()
	{
		string buf;
		int poz,poz2;
		fiooutput();
		cout << "who to edit? ";
		getline(cin, buf);
		poz = stoi(buf);
		arr[poz-1]->showall();

		cout << "what to edit? ";
		getline(cin, buf);
		poz2 = stoi(buf);
		arr[poz-1]->redakone(poz2);
	}
		
};

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








