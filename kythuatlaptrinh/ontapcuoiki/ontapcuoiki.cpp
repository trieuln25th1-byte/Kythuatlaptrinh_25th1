
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
#include <string.h> // Thư viện để dùng hàm strcmp so sánh chuỗi ký tự
using namespace std;

// Cấu trúc dữ liệu cho một cuốn sách
struct Book {
	int id;
	double price;
	char name[50];

	// Nạp chồng toán tử nhập >>
	friend istream& operator>>(istream& in, Book& b) {
		cout << "Book information: " << endl;
		cout << "\t+ Id: ";
		in >> b.id;
		cout << "\t+ Name: ";
		in.ignore(); // Xóa bộ nhớ đệm
		in.getline(b.name, 50);
		cout << "\t+ Price: ";
		in >> b.price;
		return in;
	}

	// Nạp chồng toán tử xuất <<
	friend ostream& operator<<(ostream& out, const Book& b) {
		out << "\t+ Id: " << b.id << endl;
		out << "\t+ Name: " << b.name << endl;
		out << "\t+ Price: " << b.price << endl;
		return out;
	}
};

// Cấu trúc một nút (Node) trong danh sách liên kết đơn
struct Node {
	Book data;   // Dữ liệu là một cuốn sách
	Node* next;  // Con trỏ trỏ đến nút kế tiếp
};

// Quản lý danh sách liên kết bằng con trỏ Head (quản lý phần tử đầu tiên)
Node* head = NULL;
bool sorted = false; // Biến kiểm tra xem danh sách đã được sắp xếp chưa

// Hàm tạo một Node mới chứa cuốn sách b (Cấp phát động - Chương 2)
Node* CreateNode(Book b) {
	Node* newNode = new Node();
	newNode->data = b;
	newNode->next = NULL;
	return newNode;
}

// Hàm thêm sách vào cuối danh sách (Chương 3)
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
	sorted = false; // Khi thêm sách mới, trật tự sắp xếp cũ có thể bị phá vỡ
}

// Hàm hiển thị danh sách toàn bộ sách (Chương 3)
void Show() {
	if (head == NULL) {
		cout << "The book list is empty!" << endl;
		return;
	}
	Node* temp = head;
	int i = 1;
	while (temp != NULL) {
		cout << "Book [" << i << "]: " << endl;
		cout << temp->data; // Sử dụng nạp chồng toán tử <<
		temp = temp->next;
		i++;
	}
}

// Hàm Sắp xếp sách theo Id tăng dần - Thuật toán Exchange Sort (Chương 7)
void Sort() {
	if (head == NULL || head->next == NULL) {
		cout << "Not enough books to sort." << endl;
		return;
	}
	// So sánh từng cặp phần tử và hoán đổi dữ liệu nếu sai thứ tự
	for (Node* i = head; i->next != NULL; i = i->next) {
		for (Node* j = i->next; j != NULL; j = j->next) {
			if (i->data.id > j->data.id) {
				// Hoán đổi (Swap) cấu trúc dữ liệu bên trong hai Node
				Book temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
	cout << "Books sorted successfully by ID!" << endl;
}

// Hàm Tìm kiếm sách theo Id bằng thuật toán Tìm kiếm tuần tự (Chương 6)
void Find(int bookId) {
	Node* temp = head;
	bool found = false;

	while (temp != NULL) {
		if (temp->data.id == bookId) {
			cout << "Book Found: " << endl;
			cout << temp->data;
			found = true;
			break; // Tìm thấy thì dừng vòng lặp
		}
		temp = temp->next;
	}

	if (!found) {
		cout << "Cannot find book with ID " << bookId << endl;
	}
}

// Hàm giải phóng bộ nhớ của danh sách liên kết khi thoát chương trình (Chương 2 & 3)
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
			cin >> b; // Gọi toán tử nạp chồng >>
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
			FreeList(); // Giải phóng bộ nhớ động trước khi tắt chương trình
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