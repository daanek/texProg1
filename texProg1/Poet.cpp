#include"Poet.h";

using namespace std;

poet::poet()
{
	cout << "konstructor poet" << endl;
	Base::setfio();
	setproz();
	data();
}
	poet::poet(ifstream& f)
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

	void poet::data()
	{
		cout << "input date birth author";
		getline(cin, birth);
		cout << "input date death author or 0, if he is alive";
		getline(cin, death);
	}
	void poet::printData()
	{
		cout << "years of life ";
		if (death == "0")
		{
			cout << birth << " - ..." << endl;
		}
		else
		{
			cout << birth << " - " << death << endl;
		}
	}

	void poet::showall(int col)
	{
		cout << "Poet" << endl;
		cout << getfio() << endl;
		if (col == 2)
			return;
		getproz();
		printData();


	}
	void poet::writeall(ofstream& f) 
	{
		f << "1" << endl;
		f << fio << endl;
		f << getnproz() << endl;
		for (int i = 0; i < getnproz(); i++)
		{
			f << proz[i] << endl;
		}
		f << birth << endl;
		f << death << endl;

	}
	void poet::redakone(int a) 
	{
		switch (a)
		{
		case 1: {setfio(); break; }

		case 2: {setproz(); break; }

		case 3: {data(); break; }
		}
	}

	poet::~poet()
	{
		cout << "poet = " << proz << endl;
		delete proz;
	}
