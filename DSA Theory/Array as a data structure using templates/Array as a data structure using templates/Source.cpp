#include"childArray.h"

int main() {

	childArray<int> obj(5);
	// trying to remove when the stack is empty
	obj.remove();
	
	// adding elements uptill the required size
	for (int i = 0; i < 5; i++) {
		obj.add(i);
		obj.display();
	}

	// trying to add the sixth element
	obj.add(23);

	
	// removing all the elements until no element is left
	for (int i = 5; i > 0; i--) {
		obj.remove();
		obj.display();
	}

	// trying to remove after all the elements have been removed.
	obj.remove();

	return 0;
}