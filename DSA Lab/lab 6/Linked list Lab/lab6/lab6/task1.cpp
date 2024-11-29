//#include "MyLinkList.h"
//// all the previous re_written functions are being used in this task.
//
//int main() {
//
//	int option = 0;
//	int value = 0;
//	MyLinkList<int> ll; // ll is the name of the object
//
//	while (1) {
//			cout << "<<<<<<<\t\t\tMENU\t\t\t>>>>>>" << endl;
//			cout << "1.	Add node to the linked list				" <<endl;
//			cout << "2.	Insert node in sorted order				" <<endl;
//			cout << "3.	Delete a node from the linked list		" <<endl;
//			cout << "4.	Search for a node in the linked list	" <<endl;
//			cout << "5.	Display the linked list					" <<endl;
//			cout << "6.	Exit									" <<endl;
//
//			cout << "Enter your option: ";
//			cin >> option;
//
//			if (option == 1) {
//				cout << "Enter the value to be added: ";
//				cin >> value;
//				ll.insertAtTail(value);
//			}
//
//			else if (option == 2) {
//				cout << "Enter the value to be added: ";
//				cin >> value;
//				ll.insertSorted(value);
//			}
//
//			else if (option == 3) {
//				cout << "Enter the value to be deleted: ";
//				cin >> value;
//				ll.deleteValue(value);
//			}
//
//			else if (option == 4) {
//				cout << "Enter the value to be Searched: ";
//				cin >> value;
//				if (ll.search(value)) {
//					cout << "VALUE FOUND" << endl;
//				}
//				else
//					cout << "VALUE NOT FOUND" << endl;
//			}
//
//			else if (option == 5) {
//				 ll.display();
//			}
//
//			else if (option == 6) {
//				break;
//			}
//	}
//
//
//	return 0;
//}