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
struct Book {

};