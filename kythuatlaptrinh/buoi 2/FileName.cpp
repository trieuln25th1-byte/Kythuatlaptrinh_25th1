#include <iostream>
#include < string>
using namespace std;

struct person {
	int id;
	string name;
};
struct node {
    person data;
	node* next;
};
struct Linkedlist {
	node* head;
	void Show() {
		if (head == NULL) {
			cout << " Empty list" << endl;
			return;
		}
		node* item = head;
		while (item != NULL) {
			cout << " Id: " << item->data.id << endl;
			cout << "name: " << item->data.name << endl;
			item = item->next;
		}
	}

};
int main()
{

	Linkedlist list = { NULL };
do {
	system("cls");
	cout << "--- HUMAN RESOURCE -------------" << endl;
	cout << "1. view person list" << endl;
	cout << "2. add a person" << endl;
	cout << "3. remove a person" << endl;
	cout << "4. find a person by name" << endl;
	cout << "5. export to file" << endl;
	cout << "6. import from file" << endl;
	cout << "0. exit" << endl;
	cout << "--------------------------------" << endl;
	cout << "Your command is:";
	int cmd;
	cin >> cmd;
	switch (cmd)
	{
	case 1: {
		list.Show();

		break;
	}
	case 2: {
		
		break;
	}
	case 3: {
		int id;
		cout << "input ID to remove: ";
		cin >> id;
		

		break;
	}
	case 4: {
		string name;
		cout << "input name to find: ";
		cin.ignore();
		getline(cin, name);
		bool res = false;
		if (res) {
			cout << "found person with name" << name << endl;
		}
		else
			cout << "person isn't existed" << endl;
		break;
	}
	case 5: {
		cout << "export successfully" << endl;
		break;
	}
	case 6: {
		cout << "import successfully" << endl;
		break;
	}
	case 0: {
		return 0;
	}
	default:
		cout << "Your command isn't found. Try again..." << endl;
		break;
	}
	cout << "Press enter to continue...";
	cin.ignore();
	cin.get();
} while (true);
return 0;

};