#include <iostream>
#include "Account.h"
#include "Linkedlist.h"
using namespace std;
int main() {
	Linkedlist<Account> accounts = { NULL };
	do {
		system("cls");
		cout << "--- ACCOUNT MANAGEMENT -------------" << endl;
		cout << "1.Show all accounts " << endl;
		cout << "2.Add an account" << endl;
		cout << "3.Remove an account" << endl;
		cout << "4.Update an account" << endl;
		cout << "5.Find account " << endl;
		cout << "6.Export to file" << endl;
		cout << "7.Import from file" << endl;
		cout << "0.Exit" << endl;
		cout << "--------------------------------" << endl;
		cout << "Your command is:";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			accounts.Show();

			break;
		}
		case 2: {
			Account a;
			cin >> a;
			accounts.Add(a);

			break;
		}
		case 3: {
			int removeId;
			cout << "Enter id to remove: " << endl;
			cin >> removeId;
			bool res = accounts.Remove(removeId);
			if (res)
				cout << "remove account successfully" << endl;
			else
				cout << "invalid account id" << endl;



			break;
		}
		case 4: {
			int updateId;
			cout << "enter book id to update: ";
			cin >> updateId;
			bool res = books.Update(updateId);
			if (res)
				cout << "remove book successfully" << endl;
			else
				cout << "invalid book id" << endl;

			break;
		}
		case 5: {
			break;
		}
		case 6: {
			books.Export("25TH1.dla");
			cout << "Exported successfully" << endl;

			break;
		}
		case 7: {
			break;
		}

		case 0: {
			break;
		}
		default:
			cout << "invalid choice. Try again..." << endl;
		}
		system("pause");
		cout << "Press any key to continue...";
	} while (true);
	return 0;

}
	}
}
