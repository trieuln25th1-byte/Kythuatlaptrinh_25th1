#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct person {
	int id;
	string name;
	int age;
	string address;
};
void addperson(vector<person>& p) {
	person a;
	cout << "+ Id";
	cin >> a.id;
	cout << "+ Name: ";
	cin.ignore();
	getline(cin, a.name);
	cout << "+ age:";
	cin >> a.age;
	cout << "+ address: ";
	cin.ignore();
	getline(cin, a.address);
	p.push_back(a);
	cout << " add a person successfully" << endl;
}

void removeperson(vector<person>& p, int id) {
	for (auto i = p.begin(); i != p.end(); i++) {
		if (i->id == id) {

		p.erase(i);
		cout << "remove a person successfully" << endl;
		return;
	}
}
cout << "not found person with id: " << id << endl;
}

void viewpersonlist(vector<person> p) {
	if (p.size() == 0)
		cout << "An empty list" << endl;
	else {
		for (int i = 0; i < p.size(); i++) {
			cout << "person " << (i + 1) << endl;
			cout << "\t + id: " << p[i].id << endl;
			cout << "\t+ name: " << p[i].name << endl;
			cout << "\t+ age: " << p[i].age << endl;
			cout << "\t+ address: " << p[i].address << endl; 
		}
	}
}

int main() {
	vector<person> list;
	do {
		system("cls");
		cout << "--- HUMAN RESOURCE -------------" << endl;
		cout << "1. view person list" << endl;
		cout << "2. add a perso" << endl;
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
			viewpersonlist(list);

			break;
		}
		case 2: {
			addperson(list);
			break;
		}
		case 3: {
			int id;
			cout << "input ID to remove: ";
			cin >> id;
			removeperson(list, id);
			
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			break;
		}
		case 6: {
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