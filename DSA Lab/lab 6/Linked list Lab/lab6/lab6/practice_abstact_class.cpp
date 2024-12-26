#include"MyLinkList.h"

int main() {
	// insertathead,tail , deletefrom head,tail are working exceptionally , search is working fine , 
	MyLinkList<int> a;
	a.insertAtHead(30);
	a.insertAtHead(40);
	a.insertAtTail(50);
	a.insertAtTail(70);

	// sorting is working perfectly.. :)
	cout << "unsorted linked list: "; a.display();
	// 40 , 30 , 50 , 70
	
	cout << "sorted linked list: "; a.bubbleSortLinkedList(); a.display();
	
	cout << "inserting at start of ll: "; a.insertSorted(20); a.display();
	cout << "inserting at end of ll: "; a.insertSorted(80); a.display();
	cout << "inserting in between the linked list: "; a.insertSorted(30); a.display();
	cout << "inserting in between the linked list: "; a.insertSorted(80); a.display();


	cout << endl << endl << endl;

	system("pause");
	return 0;
}