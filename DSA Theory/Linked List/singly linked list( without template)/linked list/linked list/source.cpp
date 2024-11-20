#include "MyLL.h"
#include<Windows.h>

int main() {

	MyLL a; // creation of a linked list.
	a.insertAtHead(10); // adding first element.
	a.display();
	a.insertAtHead(20);
	a.display();
	a.insertAtTail(30);
	a.display();
	
	
	Sleep(600); // pauses the console for 600 milliseconds;)
	
	a.insertAtHead(40);
	a.display();
	a.insertAtTail(50);
	a.display();

	cout << a.deleteFromHead() << endl;
	a.display();

	cout << a.deleteFromHead() << endl;
	a.display();

	cout << a.deleteFromHead() << endl;
	a.display();


	cout << a.deleteFromHead() << endl;
	a.display();

	cout << a.deleteFromHead() << endl;
	a.display();
	

	cout << a.deleteFromHead() << endl;
	a.display();

	cout << a.deleteFromHead() << endl;
	a.display();
	system("pause");
	return 0;
}