#pragma once
template<typename T>
struct Node {
	T data;
	Node* next;
};
template <typename YT>
struct Linkedlist {
	Node <T>* head;
	void Show();

};
template <typename T>
void Linkedlist<T>::Show(){
	if (head == NULL) {
		cout << "NO item available" << endl;
		return;
	}
	Node<T>* iteam = head;
	while (item != NULL) {
		cout << item->data << endl;
		item = item->next;
	}
}
bool Linkedlist<T>::Remove(int id) {
	if (!head) {
		cout << "No account available" << endl;
		return false;
	}
	Node<T>* item = head;
	if (item->data.id == id) {
		head = item->next;
		delete item;
		return
	}
}




