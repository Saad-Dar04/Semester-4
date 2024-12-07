//#include "bookStack.h"
//#include<iostream>
//using namespace std;
//
//int main() {
//
//	int option = 0;
//	string name = "";
//	int id = 0;
//	BookStack a(10);
//
//	while (1) {
//		cout << "\n\nMenu" << endl;
//		cout << "1. Push: Add a book to the stack." << endl;
//		cout << "2. Pop : Remove and display the book's details at the top of the stack.					" << endl;
//		cout << "3. Peek : Retrieve and view the details of the book currently at the top of the stack.		" << endl;
//		cout << "4. Display : List all books in the stack with their details.								" << endl;
//		cout << "5. Size : Calculate and return the total number of books currently in the stack.			" << endl;
//		cout << "6. Exit : Terminate																		" << endl;
//
//		cout << "choose an option: " << endl;
//		cin >> option;
//		if (option == 1) {
//			cout << "Enter BookID: ";
//			cin >> id;
//			cout << "Enter Book Title: ";
//			cin >> name;
//			Book temp(id, name);
//			a.push(temp);
//		}
//		else if (option == 2) {
//			a.pop();
//		}
//		else if (option == 3) {
//			a.peek();
//		}
//		else if (option == 4) {
//			a.display();
//		}
//		else if (option == 5) {
//			cout << "The size of book stack is: " << a.size();
//		}
//		else if (option == 6) {
//			break;
//		}
//	}
//	return 0;
//}