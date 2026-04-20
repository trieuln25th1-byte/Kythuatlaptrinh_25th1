#include <string>
using namespace std;
struct Account {
	int id;
	string lnk, usr, pwd, desc;
	friend ostream& operator<<(ostream& os, Account& b) {
		os << "account information: " << endl;
		os << "\t+ Link: " << b.lnk << endl;
		os << "\t+ usr: " << b.usr << endl;
		os << "\t+ pwd: " << b.pwd << endl;
		os << "\t+ desc: " << b.desc << endl;
		return os;
	}
	friend istream& operator>> (istream& in, Account& b) {
		cout << "Account information: " << endl;
		cout << "\t+ Link: ";
		in.ignore();
		getline(in, b.lnk);
		cout << "\t+ User name: ";
		in.ignore();
		getline(in, b.usr);
		cout << "\t+ Password: ";
		in.ignore();
		getline(in, b.pwd);
		cout << "\t+ Description: ";
		in.ignore();
		getline(in, b.desc);
		return in;
	}
};
