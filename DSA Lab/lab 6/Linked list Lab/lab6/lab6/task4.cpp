#include "MyLinkList.h"

int main() {

	int option = 0;
	int value = 0;
	MyLinkList<int> ll;

	while (1) {
		cout << "<<<<<<<\t\t\tMENU\t\t\t>>>>>>" << endl;
		cout << "1.	Add a value to the linked list						" << endl;
		cout << "2.	Delete duplicate values from the linked list		" << endl;
		cout << "3.	Display the linked list								" << endl;
		cout << "4.	Exit												" << endl;
		cout << "Enter an option: "; cin >> option;

		if (option == 1) {
			cout << "Enter an value to be added: "; cin >> value;
			ll.insertAtTail(value);
		}

		else if (option == 2) {
			ll.deleteDuplicate();
		}

		else if (option == 3) {
			ll.display();
		}

		else if (option == 4) {
			break;
		}
	}
	return 0;
}