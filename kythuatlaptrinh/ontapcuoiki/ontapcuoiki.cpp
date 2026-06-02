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
//#include <iostream> 
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct sinhvien {
//	string maso;
//	string hoten;
//	float diemCC, diemGK, diemCK;
//	float diemHP;
//	void tinhdiemHP() {
//		diemHP = diemCC * 0.1 + diemGK * 0.3 + diemCK * 0.6;
//	}
//};
//void sapxepdiemHP(vector<sinhvien>& ds) {
//	for (int i = 0; i < ds.size() - 1;i++) {
//		for (int j = i + 1;j < ds.size();j++) {
//			if (ds[i].diemHP < ds[j].diemHP) {
//				swap(ds[i], ds[j]);
//
//			}
//		}
//	}
//}
//void sapxepmaso(vector<sinhvien>& ds) {
//	sort(ds.begin(), ds.end(), [](const sinhvien& a, const sinhvien& b) {
//		return a.maso < b.maso;
//		});
//}
//int timkiemnhiphan(const vector<sinhvien>& ds, string x) {
//	int left = 0, right = ds.size() - 1;
//	while (left <= right) {
//		int mid = left + (right - left) / 2;
//		if (ds[mid].maso == x)return mid;
//		if (ds[mid].maso < x)left = mid + 1;
//		else right = mid - 1;
//	}
//	return-1;
//}
//int main() {
//	int n;
//	cout << "nhap so luong sinh vien: ";
//	cin >> n;
//	vector<sinhvien> danhsach(n);
//	for (int i = 0; i < n;i++) {
//		cout << "Nhap msv, ho ten, diem cc, diem gk, diem ck: ";
//		cin >> danhsach[i].maso;
//		cin.ignore();
//		getline(cin, danhsach[i].hoten);
//		cin >> danhsach[i].diemCC >> danhsach[i].diemGK >> danhsach[i].diemCK;
//		danhsach[i].tinhdiemHP();
//	}
//	sapxepdiemHP(danhsach);
//	cout << "\nDanh sach sau khi sap xep giam dan theo diem HP: \n";
//	string x;
//	cout << "\nNhap ma so sinh vien can tim: ";
//	cin >> x;
//	sapxepmaso(danhsach);
//	int res = timkiemnhiphan(danhsach, x);
//	if (res != -1) cout << "timthay sinh vien: " << danhsach[res].hoten;
//	else cout << "khong tim thay";
//	return 0;
//
//	
//}
#include <iostream>
#include <string.h> // Th? vi?n ?? dùng hàm strcmp so sánh chu?i ký t?
using namespace std;

// C?u trúc d? li?u cho m?t cu?n sách
struct Book {
	int id;
	double price;
	char name[50];

	// N?p ch?ng toán t? nh?p >>
	friend istream& operator>>(istream& in, Book& b) {
		cout << "Book information: " << endl;
		cout << "\t+ Id: ";
		in >> b.id;
		cout << "\t+ Name: ";
		in.ignore(); // Xóa b? nh? ??m
		in.getline(b.name, 50);
		cout << "\t+ Price: ";
		in >> b.price;
		return in;
	}

	// N?p ch?ng toán t? xu?t <<
	friend ostream& operator<<(ostream& out, const Book& b) {
		out << "\t+ Id: " << b.id << endl;
		out << "\t+ Name: " << b.name << endl;
		out << "\t+ Price: " << b.price << endl;
		return out;
	}
};

// C?u trúc m?t nút (Node) trong danh sách liên k?t ??n
struct Node {
	Book data;   // D? li?u là m?t cu?n sách
	Node* next;  // Con tr? tr? ??n nút k? ti?p
};

// Qu?n lý danh sách liên k?t b?ng con tr? Head (qu?n lý ph?n t? ??u tiên)
Node* head = NULL;
bool sorted = false; // Bi?n ki?m tra xem danh sách ?ã ???c s?p x?p ch?a

// Hàm t?o m?t Node m?i ch?a cu?n sách b (C?p phát ??ng - Ch??ng 2)
Node* CreateNode(Book b) {
	Node* newNode = new Node();
	newNode->data = b;
	newNode->next = NULL;
	return newNode;
}

// Hàm thêm sách vào cu?i danh sách (Ch??ng 3)
void Addbook(Book b) {
	Node* newNode = CreateNode(b);
	if (head == NULL) {
		head = newNode;
		sorted = false;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	sorted = false; // Khi thêm sách m?i, tr?t t? s?p x?p c? có th? b? phá v?
}

// Hàm hi?n th? danh sách toàn b? sách (Ch??ng 3)
void Show() {
	if (head == NULL) {
		cout << "The book list is empty!" << endl;
		return;
	}
	Node* temp = head;
	int i = 1;
	while (temp != NULL) {
		cout << "Book [" << i << "]: " << endl;
		cout << temp->data; // S? d?ng n?p ch?ng toán t? <<
		temp = temp->next;
		i++;
	}
}

// Hàm S?p x?p sách theo Id t?ng d?n - Thu?t toán Exchange Sort (Ch??ng 7)
void Sort() {
	if (head == NULL || head->next == NULL) {
		cout << "Not enough books to sort." << endl;
		return;
	}
	// So sánh t?ng c?p ph?n t? và hoán ??i d? li?u n?u sai th? t?
	for (Node* i = head; i->next != NULL; i = i->next) {
		for (Node* j = i->next; j != NULL; j = j->next) {
			if (i->data.id > j->data.id) {
				// Hoán ??i (Swap) c?u trúc d? li?u bên trong hai Node
				Book temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
	cout << "Books sorted successfully by ID!" << endl;
}

// Hàm Tìm ki?m sách theo Id b?ng thu?t toán Tìm ki?m tu?n t? (Ch??ng 6)
void Find(int bookId) {
	Node* temp = head;
	bool found = false;

	while (temp != NULL) {
		if (temp->data.id == bookId) {
			cout << "Book Found: " << endl;
			cout << temp->data;
			found = true;
			break; // Tìm th?y thì d?ng vòng l?p
		}
		temp = temp->next;
	}

	if (!found) {
		cout << "Cannot find book with ID " << bookId << endl;
	}
}

// Hàm gi?i phóng b? nh? c?a danh sách liên k?t khi thoát ch??ng trình (Ch??ng 2 & 3)
void FreeList() {
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

int main()
{
	int choose;
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
		cin >> choose;

		switch (choose) {
		case 1: {
			Book b;
			cin >> b; // G?i toán t? n?p ch?ng >>
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
			if (!sorted) {
				cout << "Books aren't sorted! Please sort first (Option 3)." << endl;
			}
			else {
				int bookId;
				cout << "Book id to find: ";
				cin >> bookId;
				Find(bookId);
			}
			break;
		}
		case 0: {
			FreeList(); // Gi?i phóng b? nh? ??ng tr??c khi t?t ch??ng trình
			cout << "Exiting program..." << endl;
			return 0;
		}
		default: {
			cout << "Invalid command!" << endl;
			break;
		}
		}
		system("pause");
	} while (true);
	return 0;
}