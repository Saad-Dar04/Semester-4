#include "MyLinkList.h"


int main() {

	MyLinkList<int> a;
	a.insertAtHead(10);
	a.insertAtTail(20);
	a.insertAtTail(30);
	a.display();

	// need to handle the edge case when user enters a value greater than the size of the linked list..
	// simple break would let it come out of the loop

	//<<<<<<<<<<<<<<<<<< ALL CASES HAVE BEEN TESTED >>>>>>>>>>>>>>>>>>>>
	// insert at start of linked list
	cout << "insert at 0th position: ";
	insertNth(a.returnHead(), 0, 100);
	a.display();

	// insert at the mid
	cout << "inserting in the middle of linked list at 2nd position: ";
	insertNth(a.returnHead(), 2, 40);
	a.display();

	// insert at the end
	cout << "inserting at the end of linked list: ";
	insertNth(a.returnHead(), 10, 80);
	a.display();


	cout << endl << endl << endl;

	//<<<<<<<<<<<<<<<<<<<<<<< DELETE FROM NTH POSITION >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	cout << "Deleting from 0th position: ";
	deleteNth(a.returnHead(), 0);
	a.display();
	
	cout << "Deleting element from in between 2nd element: ";
	deleteNth(a.returnHead(), 2);
	a.display();

	cout << "Deleting from last element:";
	deleteNth(a.returnHead(), 3 );
	a.display();

	cout << "value of n is greater than size of linked list: ";
	deleteNth(a.returnHead(), 10);
	a.display();
	




	return 0;
}