#include "myLL.h"

int main()
{
	myLL obj;
	obj.insertSorted(99);
	obj.insertSorted(887);
	obj.insertSorted(1000);
	obj.insertSorted(-3);
	obj.insertSorted(500);
	obj.insertSorted(900);
	obj.insertSorted(23);


	cout << "The current values in Linked List are: " << endl;
	obj.display();
	

	return 0;
}