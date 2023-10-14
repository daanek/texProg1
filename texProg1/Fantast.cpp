#include"Fantast.h"

fantas::fantas()
{
	cout << "konstructor fantas" << endl;
	setfio();
	setproz();
	setfilm();
}
fantas::fantas(ifstream& f)
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
fantas::~fantas()
{
	cout << "fantast = " << endl;
	delete proz;
}
void fantas::setfilm()
{
	cout << "Is there a movie based on the book?" << endl << "0 - NO" << endl << "1 - YES" << endl;
	getline(cin, film);
}
void fantas::getfilm()
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
void fantas::showall(int col )
{
	cout << "Fantast" << endl;
	cout << getfio() << endl;
	if (col == 2)
		return;
	getproz();
	getfilm();
}
void fantas::writeall(ofstream& f)
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
void fantas::redakone(int a)
{
	switch (a)
	{
	case 1: {setfio(); break; }

	case 2: {setproz(); break; }

	case 3: {setfilm(); break; }
	}
}
