// implementation of queue using linked list
#include "MyLinkList.h"

template <typename t>
class Queue {
protected:
	MyLinkList<t> ll;
	int size;
public:
	Queue() : size(0) {};
	
	void Enqueue(t value) {
		ll.insertAtTail(value);
		size++;
	}

	void Dequeue() {
		ll.deleteFromHead();
		size--;
	}

	t front() {
		// gets the front element of the queue
		return ll.frontElement();
	}

	bool isEmpty() {
		return ll.isEmpty();
	}

	void display() {
		ll.display();
	}

	~Queue() {
		// no dynamically allocated memory so no need to delete , every thing would free up itself when the
		// destructor is called ;)
	}
};


int main() {

	Queue<int> q;
	int option;
	int value;

	while (1) {
		cout << "<<<<<<<\t\t\tMENU\t\t\t>>>>>>" << endl;
		cout << "	1.	Enqueue an element to the queue			" << endl;
		cout << "	2.	Dequeue an element from the queue		" << endl;
		cout << "	3.	Get the front element of the queue		" << endl;
		cout << "	4.	Check if the queue is empty				" << endl;
		cout << "	5.	Display the queue						" << endl;
		cout << "	6.	Exit									" << endl;
		cout << "Enter option: ";
		cin >> option;

		if (option == 1) {
			cout << "Enter an Value: ";
			cin >> value;
			q.Enqueue(value);
		}

		else if (option == 2) {
			q.Dequeue();
		}

		else if (option == 3) {
			cout << q.front();
			cout << endl;
		}

		else if (option == 4) {
			if (q.isEmpty()) {
				cout << "QUEUE IS EMPTY" << endl;
			}
			else
				cout << "QUEUE IS NOT EMPTY" << endl;
		}

		else if (option == 5) {
			q.display();
		}

		else if (option == 6) {
			break;
		}

	}

	return 0;
}