// implementation of stack using linked list :)
#include "MyLinkList.h"

// stack ki class baney ge that would inherit the previous linked list ki class kou
// aur phir stack k saarey functions likhein ge using linked list
// ab stack is inheriting MyLInkList mtlb k redefinition waley parts kou inherit kr rha aur na k virtual funcitons kou
// tou redifinition of the functions is not required here.


// no i dropped that idea of inheritance , ab seedha class k andar MyLinkList ka object bana diya hae aur 
// us k through stack k saarey functions ki implementation kar doun ga..
template <typename t>
class Stack {
protected:
	MyLinkList<t> ll;
	int currentSize;
	//int maxSize; // in case of linked list there would be no maxSize , apni marzi sae linke list
				// k size kou jitna marzi increase kr skty hain.. ;)
public:
	Stack() :currentSize(0) {};
	void push(t value) {
		// in case of stack values hamesha end pae add houti hain.
		// tou insertAtTail will be used here.
		ll.insertAtTail(value);
		currentSize++;
	}

	void pop() {
		if (!ll.isEmpty()) {
			ll.deleteFromTail();
			currentSize--;
		}
		else {
			cout << "the stack is empty" << endl;
		}
	}

	void top() {
		// ye function MyLinkList k andar define kiya hae jakr
		// for the purpose of this linked list
		cout << ll.topElement();
	}

	void display() {
		ll.display();
	}
	

	bool isEmpty() {
		return ll.isEmpty();
	}


};

int main() {
	Stack<int> st;
	int option;
	int value;

	while (1) {
		cout << "<<<<<<<\t\t\tMENU\t\t\t>>>>>>" << endl;
		cout << "1.	Push element onto the stack				" << endl;
		cout << "2.	Pop element from the stack				" << endl;
		cout << "3.	Display the top element of the stack	" << endl;
		cout << "4.	Display the stack						" << endl;
		cout << "5.	Check if the stack is empty				" << endl;
		cout << "6.	Exit									" << endl;


		cout << "Select an option: ";
		cin >> option;

		if (option == 1) {
			cout << "Enter the value: ";
			cin >> value;
			st.push(value);
		}

		else if (option == 2) {
			st.pop();
			cout << endl;
		}

		else if (option == 3) {
			st.top();
			cout << endl;
		}

		else if (option == 4) {
			st.display();
		}

		else if (option == 5) {
			if (st.isEmpty()) {
				cout << "STACK IS EMPTY" << endl;
			}
			else {
				cout << "STACK , NOT EMPTY " << endl;
			}
		}

		else if (option == 6) {
			break;
		}
	}
}