#include"Base.h";
string Base:: getfio() { return fio; };

string* Base::getproz() {
	cout << "Books: " << endl;//only for consol
	for (int i = 0; i < nproz; i++)
	{
		cout << "--" << proz[i] << endl;
	}

	return proz;
};
int  Base:: getnproz()
{
	return nproz;
}
void Base::setfio()
{
	cout << "input FIO: ";
	getline(cin, fio);
};
void Base::setproz()
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
Base::~Base() {};

