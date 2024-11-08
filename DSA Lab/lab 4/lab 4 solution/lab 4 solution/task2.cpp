// library management system
#include"myStack.h"
#include"String"

template <typename T>
void reverseBooks( myStack<T>& obj1, myStack<T>& obj2) {
	string temp = "";
	while(!obj1.isEmpty() )  {
		cout << "here" << endl;
		temp =  obj1.pop();
		cout << temp << endl;
		obj2.push(temp);
		cout << obj2.top();
	}
	
	// using the copy constructor to copy all the contents of obj2 into obj1
	// so that it can store the reversed stack and build up from that point
	// while the object2 can be again used up the reverse the stack..
	
}

int main() {

	myStack<string> a(10);
	myStack<string> b(10);
	while (1) {
		int option = 0;
		string bookName = "";
		cout << "\t\t\t	MENU \t\t\t" << endl;
		cout << "press 1 to add book " << endl;
		cout << "press 2 diplay the books " << endl;
		cout << "press 3 to remove last added book " << endl;
		cout << "press 4 to top book " << endl;
		cout << "press 5 to reverse the stack of books " << endl;
		cin >> option;

		if (option == 1) {
			cout << "enter the book name: ";
			cin >> bookName;
			a.push(bookName);
		}
		else if (option == 2) {
			a.display();
		}
		else if (option == 3) {
			cout << "book removed is: " << a.pop();
		}
		else if (option == 4) {
			cout << "the last added book is: " << a.pop();
		}
		else if (option == 5) {
			reverseBooks(a, b);
		}
		else if (option == 0) {
			break;
		}
	}
	return 0;
}