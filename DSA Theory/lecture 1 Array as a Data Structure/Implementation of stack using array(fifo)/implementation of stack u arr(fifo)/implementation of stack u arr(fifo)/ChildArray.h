#include"Array.h"

template <typename t>
class childArray : public Array<t> {
public:
	// constructor of childArray class
	childArray(int s) : Array<t>(s) {}
	// the childArray constructor would call the constructor of the parent class and would pass the size to it.
	// the constructor of Array cannot be called directly by making an object bcz it's an abstract class.

	// redifinition of pure virtual function , this is necessary or this class would inherit the above pure virtual functions rendering this class to be
	// be an abstract class as well.
	bool isEmpty() {
		// in templates if you want to use the data member of an parent template class you would have to 
		if (Array<t>::currentSize == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	bool isFull() {
		if (Array<t>::currentSize == Array<t>::maxSize) {
			return 1;
		}
		else {
			return 0;
		}
	}

	void add(t value) {
		if (!isFull()) {
			Array<t>::arr[Array<t>::currentSize++] = value;
		}
		else {
			cout << "stack is full" << endl;
		}
	}

	t remove() {
		if (!isEmpty()) {
			// remove the 0th index and move all the elements back.
			t temp = Array<t>::arr[0];
			for (int i = 0; i < Array<t>::currentSize - 1; i++) {
				Array<t>::arr[i] = Array<t>::arr[i + 1];
			}
			Array<t>::currentSize--;
			return temp;
		}
		else {
			cout << "the stack is empty" << endl;
		}
	}

	void display() {
		for (int i = 0; i < Array<t>::currentSize; i++) {
			cout << Array<t>::arr[i] << "  ";
		}cout << endl;
	}

};