//#include <iostream>
//using namespace std;
//
//struct Book {
//	int id;
//	double price;
//	char name[50];
//	friend istream& operator>>(istream& in, Book& b) {
//		cout << "book information: " << endl;
//		cout << "\t+ Id: ";
//		in >> b.id;
//		cout << "\t+ Name: ";
//		in.ignore();
//		in.getline(b.name, 50);
//		cout << "\t+ Price: ";
//		in >> b.price;
//		return in;
//	}
//	friend ostream& operator<<(ostream& out, Book& b) {
//		out << "\t+ Id: " << b.id << endl;
//		out << "\t+ Name: " << b.name << endl;
//		out << "\t+ Price: " << b.price << endl;
//		return out;
//
//	}
//
//};
//#define MAX 100
//
//int nBook = 0;
//Book books[MAX];
//void Addbook(Book b) {
//	if (nBook >= MAX){
//		cout << "no storage available " << endl;
//		return;
//}
//books[nBook++] = b;
//}
//void Show() {
//	for (int i = 0; i < nBook; i++) {
//		cout << "Book [" << (i + 1) << "]: " << endl;
//		cout << book[i];
//	}
//}
//int main() 
//{
//
//	do {
//
//		system("cls");
//		cout << "--------- BOOK MANAGEMENT ---------" << endl;
//		cout << "1. Add a book " << endl;
//		cout << "2. Show book" << endl;
//		cout << "3. Sort book" << endl;
//		cout << "4. Find a book" << endl;
//		cout << "0. Exit" << endl;
//		cout << "-----------------------------------" << endl;
//		cout << "Choose: ";
//		int choose;
//		cin >> choose;
//		switch (choose) {
//		case 1: {
//			Book(b);
//			cin >> b;
//			Addbook(b);
//			break;
//		}
//		case 2: {
//			Show();
//
//			break;
//		}
//		case 3: {
//			Sort();
//			sorted = true;
//
//			break;
//		}
//		case 4: {
//			if (!sorted)
//			{
//				cout << "Books aren't sorted " << endl;
//			}
//			else {
//				int bookId;
//				cout << "Book id to find: ";
//				Find(bookId);
//			}
//				
//			break;
//		}
//		case 0: {
//			return;
//		}
//		default: {
//			cout << "invalid command" << endl;
//			break;
//		}
//		}
//		system("pause");
//		cout << "Press enter to continue" << endl;
//	} while (true);
//}
//
//
#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct sinhvien {
	string maso;
	string hoten;
	float diemCC, diemGK, diemCK;
	float diemHP;
	void tinhdiemHP() {
		diemHP = diemCC * 0.1 + diemGK * 0.3 + diemCK * 0.6;
	}
};
void sapxepdiemHP(vector<sinhvien>& ds) {
	for (int i = 0; i < ds.size() - 1;i++) {
		for (int j = i + 1;j < ds.size();j++) {
			if (ds[i].diemHP < ds[j].diemHP) {
				swap(ds[i], ds[j]);

			}
		}
	}
}
void sapxepmaso(vector<sinhvien>& ds) {
	sort(ds.begin(), ds.end(), [](const sinhvien& a, const sinhvien& b) {
		return a.maso < b.maso;
		});
}
int timkiemnhiphan(const vector<sinhvien>& ds, string x) {
	int left = 0, right = ds.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (ds[mid].maso == x)return mid;
		if (ds[mid].maso < x)left = mid + 1;
		else right = mid - 1;
	}
	return-1;
}
int main() {
	int n;
	cout << "nhap so luong sinh vien: ";
	cin >> n;
	vector<sinhvien> danhsach(n);
	for (int i = 0; i < n;i++) {
		cout << "Nhap msv, ho ten, diem cc, diem gk, diem ck: ";
		cin >> danhsach[i].maso;
		cin.ignore();
		getline(cin, danhsach[i].hoten);
		cin >> danhsach[i].diemCC >> danhsach[i].diemGK >> danhsach[i].diemCK;
		danhsach[i].tinhdiemHP();
	}
	sapxepdiemHP(danhsach);
	cout << "\nDanh sach sau khi sap xep giam dan theo diem HP: \n";
	string x;
	cout << "\nNhap ma so sinh vien can tim: ";
	cin >> x;
	sapxepmaso(danhsach);
	int res = timkiemnhiphan(danhsach, x);
	if (res != -1) cout << "timthay sinh vien: " << danhsach[res].hoten;
	else cout << "khong tim thay";
	return 0;

	
}