
#include "Roman.h"


	roman::roman()
	{
		cout << "konstructor roman" << endl;
		setfio();
		setproz();
		data();
		setbiograf();
	}


	roman::roman(ifstream& f)
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

	void roman::setbiograf()
	{
		cout << "input brief biography" << endl;
		getline(cin, biograf);

	}
	void roman::getbiograf()
	{
		int j = 0;
		int i = 0;
		int len = biograf.length();
		cout << "brief biography" << endl;
		for (i = 0; i < len; i++)
		{
			cout << biograf[i];
			j++;
			if ((biograf[i] == ' ') and (j > 20))
			{
				cout << endl;
				j = 0;
			}
		}
		cout << endl;
	}
	void roman::data()
	{
		cout << "input date birth author";
		getline(cin, birth);
		cout << "input date death author or 0, if he is alive";
		getline(cin, death);
	}
	void roman::printData()
	{
		if (death == "0")
		{
			cout << birth << " - ..." << endl;
		}
		else
		{
			cout << birth << "-" << death << endl;
		}
	}
	void roman::showall(int col ) 
	{
		cout << "Romantist" << endl;
		cout << getfio() << endl;
		if (col == 2)
			return;
		getproz();
		printData();
		getbiograf();
	}
	void roman::writeall(ofstream& f) 
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

	roman::~roman()
	{
		cout << "roman = " << proz << endl;
		delete proz;
	}
	void roman::redakone(int a) 
	{

		switch (a)
		{
		case 1: {setfio(); break; }

		case 2: {setproz(); break; }

		case 3: {data(); break; }

		case 4: {setbiograf(); break; }
		}

	}

