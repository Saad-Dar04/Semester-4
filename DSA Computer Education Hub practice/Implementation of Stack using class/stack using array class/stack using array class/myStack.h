#include"Stack.h"

template <typename t>
class myStack : public Stack<t>{

public:
	// constructor of the class
	myStack(int);

	// redifinition  of the pure virtual functions in inherited class.
	bool isFull();
	bool isEmpty();
	void push(t);
	t pop();
	t top();

};


template <typename t>
myStack<t>::myStack(int maxSize) : Stack<t>(maxSize) {
	cout << " myStack constructor called" << endl;
};

// definition of the pure virtual functions.
template <typename t>
bool myStack<t>::isFull() {
	if (Stack<t>::currentSize == Stack<t>::maxSize) {
		return 1;
	}
	else
		return 0; 
}

template <typename t>
bool myStack<t>::isEmpty() {
	if (Stack<t>::currentSize == 0) {
		return 1;
	}
	else
		return 0; 
}

template <typename t>
void myStack<t>::push(t value) {
	// store at 0 index and after storing it , post increment the index to 1 ;)
	// the next value will be stored at index 1 and will be post incremented to 2 ;)
	if (!isFull()) {
		Stack<t>::arr[Stack<t>::currentSize++];
	}
	else {
		cout << "stack is full" << endl;
	}
}

template <typename t>
t myStack<t>::pop() {
	// returns the last added value following the rules of lifo :)
	if (!isEmpty()) {
		return Stack<t>::arr[Stack<t>::currentSize--];
	}
	else {
		cout << "stack is empty" << endl;
		return NULL;
	}
}

template <typename t>
t myStack<t>::top() {

	// returns the last added value
	if (isEmpty()) {
		cout << "the array is empyty" << endl;
	}
	else {
		return Stack<t>::arr[Stack<t>::currentSize - 1];
	}
}