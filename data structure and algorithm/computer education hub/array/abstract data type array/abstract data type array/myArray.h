#include "Array.h"

class myArray : public Array {
protected:

public:
	// parameterized constructor for the program
	myArray(int size);
	// cus this is child class it will call the default constructor of it's parent class , if the default constructor of the parent class doesnot exist it will
	// show an error so will will have to implicitly call the constructor of the parent class in order for this to work.
	
	// redifinitions of all the virtual functions.. ;)
	void addValue(int size);
	int removeValue();
	bool isFull();
	bool isEmpty();
	void display();

};

// definition of the constructor of myArray class
myArray::myArray(int size) : Array(size) {};

bool myArray::isFull() {
	return maxSize == currentSize;
}

bool myArray::isEmpty() {
	return currentSize == 0;
}

void myArray::addValue(int size) {
	if (!isFull()) {
		// using post decrement it will store the value at 0 and then increment it to 1..
		this->arr[currentSize++] = size;
	}
	else
		cout << "stack is full." << endl;
}

int myArray::removeValue() {

	if (!isEmpty()) {
		// it will predecrement and return the value
		return arr[--currentSize];
	}
	else {
		cout << "stack is empty" << endl;
		return NULL;
	}

}

void myArray::display() {
	cout << "Max Size: " << maxSize << endl;
	cout << "Current Size: " << currentSize << endl;
	for (int i = 0; i < this->currentSize ; i++) {
		cout << this->arr[i] << " ";
	}	cout << endl;
}