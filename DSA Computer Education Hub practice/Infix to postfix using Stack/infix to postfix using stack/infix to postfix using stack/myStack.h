#include"Stack.h"

template <typename t>
class myStack : public Stack<t> {

public:
	// constructor of the class
	myStack(const char*);

	// redifinition  of the pure virtual functions in inherited class.
	bool isFull();
	bool isEmpty();
	void push(char);
	void pop();
	//t top();

	// infix to postfix function
	void infix_to_postfix();
};


template <typename t>
myStack<t>::myStack(const char* infix) : Stack<t>(infix) {

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
void myStack<t>::push(char value) {
	// store at 0 index and after storing it , post increment the index to 1 ;)
	// the next value will be stored at index 1 and will be post incremented to 2 ;)
	if (!isFull()) {
		Stack<t>::arr[Stack<t>::currentSize++] = value;
	}
	else {
		cout << "stack is full" << endl;
	}
}

template <typename t>
void myStack<t>::pop() {
	// returns the last added value following the rules of lifo :)
	if (!isEmpty()) {
		Stack<t>::currentSize--;
		if (Stack<t>::arr[Stack<t>::currentSize] >= '*' && Stack<t>::arr[Stack<t>::currentSize] <= '/') {
			// we will move it to number , or we could also do is k iskou cout krwa dein :)
			Stack<t>::number_store[Stack<t>::number_index++] = Stack<t>::arr[Stack<t>::currentSize];
		}
	}
	else {
		Stack<t>::currentSize--;
		cout << "this shi wont be stored" << endl;
	}
}
//
//template <typename t>
//t myStack<t>::top() {
//
//	// returns the last added value
//	if (isEmpty()) {
//
//		return t();
//	}
//	else {
//
//		return Stack<t>::arr[Stack<t>::currentSize - 1];
//	}
//}

template<typename t>
void myStack<t>::infix_to_postfix() {


	for (int i = 0; Stack<t>::infix_stored[i] != '\0' ; i++) {
		cout << "value to be worked on : " << Stack<t>::infix_stored[i] << endl;
		// if it is a number , stored it inside the number.
		if (Stack<t>::infix_stored[i] >= '0' && Stack<t>::infix_stored[i] <= '9') {
			Stack<t>::number_store[Stack<t>::number_index++] = Stack<t>::infix_stored[i];
			Stack<t>::display();
		}

		// if it is a '(' , 'operator' , we would push() it into the stack.
		else if (Stack<t>::infix_stored[i] == '(' || (Stack<t>::infix_stored[i] >= '*' && Stack<t>::infix_stored[i] <= '/')) {
			// push it into stack
			push(Stack<t>::infix_stored[i]);
			Stack<t>::display();
		}

		// if we encounter a closing paranthesis we would call the pop() twice
		else if (Stack<t>::infix_stored[i] == ')') {
			pop();
			pop();
			Stack<t>::display();
		}

	}

}
