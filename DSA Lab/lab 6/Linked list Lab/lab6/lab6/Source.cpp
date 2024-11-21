#include"MyLinkList.h"

int main() {
	// insertathead,tail , deletefrom head,tail are working exceptionally , search is working fine , 
	MyLinkList<int> a;
	a.insertAtHead(30);
	a.insertAtHead(40);
	a.display();
	
	a.insertSorted(10);
	a.display();


	system("pause");
	return 0;
}