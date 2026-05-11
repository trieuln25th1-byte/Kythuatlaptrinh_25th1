#include <iostream>
using namespace std;

struct Book {
	int id;
	double price;
	char name[50];
	friend istream& operator>>(istream& in, Book& b) {
		cout << "book information: " << endl;
		cout << "\t+ Id: ";
		in >> b.id;
		cout << "\t+ Name: ";
		in.ignore();
		in.getline(b.name, 50);
		cout << "\t+ Price: ";
		in >> b.price;
		return in;
	}
	friend ostream& operator<<(ostream& out, Book& b) {
		out << "\t+ Id: " << b.id << endl;
		out << "\t+ Name: " << b.name << endl;
		out << "\t+ Price: " << b.price << endl;
		return out;

	}

};
#define MAX 100

int nBook = 0;
Book books[MAX];
void Addbook(Book b) {
	if (nBook >= MAX){
		cout << "no storage available " << endl;
		return;
}
books[nBook++] = b;
}
void Show() {
	for (int i = 0; i < nBook; i++) {
		cout << "Book [" << (i + 1) << "]: " << endl;
		cout << book[i];
	}
}
int main() 
{

	do {

		system("cls");
		cout << "--------- BOOK MANAGEMENT ---------" << endl;
		cout << "1. Add a book " << endl;
		cout << "2. Show book" << endl;
		cout << "3. Sort book" << endl;
		cout << "4. Find a book" << endl;
		cout << "0. Exit" << endl;
		cout << "-----------------------------------" << endl;
		cout << "Choose: ";
		int choose;
		cin >> choose;
		switch (choose) {
		case 1: {
			Book(b);
			cin >> b;
			Addbook(b);
			break;
		}
		case 2: {
			Show();

			break;
		}
		case 3: {
			Sort();
			sorted = true;

			break;
		}
		case 4: {
			if (!sorted)
			{
				cout << "Books aren't sorted " << endl;
			}
			else {
				int bookId;
				cout << "Book id to find: ";
				Find(bookId);
			}
				
			break;
		}
		case 0: {
			return;
		}
		default: {
			cout << "invalid command" << endl;
			break;
		}
		}
		system("pause");
		cout << "Press enter to continue" << endl;
	} while (true);
}


