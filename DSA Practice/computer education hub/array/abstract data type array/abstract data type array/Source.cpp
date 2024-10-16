//successfully implemented stack using array. :o
#include "myArray.h"

int main() {
	
	myArray a(5);
	cout << a.removeValue();
	cout << endl;
	a.display();

	int i = 1;
	while (!a.isFull()) {
		a.addValue(i++);
	}

	a.display();
	a.addValue(87);

	while (!a.isEmpty()) {
		cout << a.removeValue() << " ";

	}
	cout << endl;
	cout << a.removeValue();

		
	return 0;
}