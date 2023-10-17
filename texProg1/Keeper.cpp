#include"Keeper.h"

using namespace std;

	Keeper::Keeper()
	{
		n = 0;
		arr = new Base * [n];
	}
	Keeper::Keeper(const Keeper& other)
	{
		this->arr = new Base * [other.n];
		this->n = other.n;

		for (int i = 0; i < this->n; i++)
		{
			this->arr[i] = other.arr[i];
		}

	}
	Keeper::~Keeper()
	{
		cout << "disstructor Keeper" << endl;
		delete arr;
	}
	Keeper Keeper::operator +(int a)
	{
		int i;
		Base** buf(arr);
		n++;
		arr = new Base * [n];
		for (i = 0; i < this->n - 1; i++)
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

	void Keeper::ShowAll()
	{
		for (int i = 0; i < n; i++)
		{
			arr[i]->showall();
		}
	}

	void Keeper::save()
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
	void Keeper::read()
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
		catch (string tt)
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
		while (!file.eof() && i < n)
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
	void Keeper::delet()
	{
		int a;
		string buf;
		Keeper buff(*this);

		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << " ";
			arr[i]->showall(2);
			cout << endl;
		}
		cout << "input number element for delete ";

		getline(cin, buf);

		a = stoi(buf);

		int j = 0;
		if (n != 0)
			n--;
		arr = new Base * [n];

		for (int i = 0; i < n; i++)
		{
			if (i == a - 1)
			{
				j++;
			}
			arr[i] = buff.arr[j];
			j++;
		}
	}

	void Keeper::fiooutput()
	{
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << " ";
			arr[i]->showall(2);
			cout << endl;
		}
	}

	void Keeper::redak()
	{
		string buf;
		int poz, poz2;
		fiooutput();
		cout << "who to edit? ";
		getline(cin, buf);
		poz = stoi(buf);
		arr[poz - 1]->showall();

		cout << "what to edit? ";
		getline(cin, buf);
		poz2 = stoi(buf);
		arr[poz - 1]->redakone(poz2);
	}

