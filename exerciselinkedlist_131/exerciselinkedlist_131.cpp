#include <iostream>
#include <string>
using namespace std; 

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;

public:
	CircularLinkedList() {
		LAST = NULL;
	}

	void addNode();
	bool search(int rollno, Node** putri, Node** ikhda);
	bool listEmpty();
	bool delNode();
	void tranverse();
};

void CircularLinkedList::addNode() {												// membuat node baru
}

bool CircularLinkedList::search(int rollno, Node** putri, Node** ikhda) {			//step a.2
	*putri = LAST->next;															//step a.3
	*ikhda = LAST->next;															//step a.4

	while (*ikhda != LAST) {
		if (rollno == (*ikhda)->rollNumber) {
			return true;
		}
		*putri = *ikhda;
		*ikhda = (*ikhda)->next;
	}

	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() {												// menghapus node

}

void CircularLinkedList::tranverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* ikhdaNode = LAST->next;
		while (ikhdaNode != LAST) {
			cout << ikhdaNode->rollNumber << " " << ikhdaNode->name << endl;
			ikhdaNode = ikhdaNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. add a record to the list" << endl;
			cout << "2. delete a record from the list" << endl;
			cout << "3. view all the record in the list" << endl;
			cout << "4. exit" << endl;
			cout << "\nenter your choice (1-5) : ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {

			}
			case '2': {

			}
			case '3': {
				obj.tranverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}