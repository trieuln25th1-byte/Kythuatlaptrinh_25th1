//nếu muốn nó sắp xếp được thì xài thư viện include string.h
//friend istream operator>>  là 
//nạp chồng toán tử nhập, nó cho phép bạn nhập dữ liệu vào một đối tượng của lớp Book thông qua luồng nhập(như cin).
//Hàm này sẽ được gọi khi bạn sử dụng cú pháp như cin >> bookObject; để nhập thông tin cho một cuốn sách.Trong hàm này,
//bạn sẽ yêu cầu người dùng nhập các thuộc tính của cuốn sách như id, name và price,
//sau đó lưu trữ chúng vào đối tượng Book được truyền vào dưới dạng tham chiếu.
//friend ostream operator<< là nạp chồng toán tử xuất, 
//nó cho phép bạn xuất dữ liệu từ một đối tượng của lớp Book thông qua luồng xuất(như cout).
//Hàm này sẽ được gọi khi bạn sử dụng cú pháp như cout << bookObject; để hiển thị thông tin của một cuốn sách.
//Hàm này sẽ định dạng cách hiển thị các thuộc tính của cuốn sách như id, name và
//price, sau đó xuất chúng ra luồng xuất.Điều này giúp bạn dễ dàng hiển thị thông tin của một cuốn sách 
//chỉ bằng cách sử dụng toán tử << mà không cần phải gọi từng thuộc tính một cách riêng biệt.
//Node* CreateNode(const Book& b) {
//	Node* newNode = new Node; 
//	newNode->data = b;       
//	newNode->next = NULL;   
//	return newNode;         
//}
#include <iostream>
#include <string.h>
using namespace std;
struct Book {
	int id;
	char name[50];
	double price;

	friend istream& operator>>(istream& in, Book& m) { //tiếp thu thông tin sách 
		cout << "Book information: " << endl;
		cout << "\t+ ID: ";
		in >> m.id;
		cout << "/t+ Name: ";
		in.ignore();
		in.getline(m.name, 50);
		cout << "\t_ Price: ";
		in >> m.price;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Book& m) { //in thông tin sách đã tiếp thu trước đó
		out << "Book information: " << endl;
		out << "\t+ ID:" << m.id << endl;
		out << "\t+ Name:" << m.name << endl;
		out << "\t+ Price:" << m.price << endl;
		return out;
	}

};
struct node {
	Book data;
	node* next;
};
node* head = NULL;
bool sorted = false;

node* createnode(Book m) {  //tạo một cuốn sách mới 
	node* newnode = new node();
	newnode->data = m;  //data chuyển vào m để lưu thông tin sách
	newnode->next = NULL; //data next mà k tồn tại thì trả lại cuốn sách cho nó thành head
	return newnode;
}
void addbook(Book m) {
	node* newnode = createnode(m);
	if (head == NULL) {
		head = newnode;
		sorted = false;
	}

	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;

	}
	temp->next = newnode;



}
void show() {
	if (head == NULL) {
		cout << " NO books available" << endl;
		return;
	}
	node* temp = head;
	while (temp != NULL) {
		cout << "Book [ " << temp->data.id << " ] " << endl;
		cout << temp->data;
		temp = temp->next;


	}

}
void sort() {
	if (head == NULL || head->next == NULL) {
		cout << " not enough books to sort" << endl;
		return;
	}
	for (node* current = head; current->next != NULL; current = current->next) {
		for (node* next = current->next; next != NULL; next = next->next) {
			if (next->data.id > current->data.id) {
				Book temp = current->data;
				current->data = next->data;
				next->data = temp;

			}
		}
	}
	cout << " sach da duoc sap xep" << endl;
}
void find() {
	node* temp = head; 
	bool found = false ;
	while (temp != NULL) {
		if (temp-> data.id == Bookid) {
			cout << "data cua sach: " << endl;
			cout << temp->data;
			found = true;
		}
		temp = temp->next;
	}
	if (!found) {
		cout << " khong tim thay sach can tim" << endl;
	}
}
