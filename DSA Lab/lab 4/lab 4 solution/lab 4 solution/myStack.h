#include"AbstractStack.h"

template <typename T>
class Stack : public AbstractStact<T> {

public:
	
	// constructor
	Stack(int currentSize) : AbstractClass<T>(currentSize) {};

	void isFull() {
		return AbstractStack<T>::currentSize == Abstract<T>::maxSize;
	}

	void isEmpty() {
		return AbstractStack<T>::currentSize == 0;
	}

	void push(T value) {
		if (!isFull()) {
			AbstractStack<T>::array[AbstractStack<T>::currentsize++];
		}
		else
			cout << "Stack is full" << endl;
	}
	
	T pop() {
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
		}
		else {
			// pre decrement to decrement from 3 to 2 and return the value of 2
			// the next value will be stored at 2.
			return AbstractStack::arr[--AbstractStack<T>::currentsize];
		}
	}

	T top() const {
		// constant function means that no value could be updated in this function 
		return AbstractStack<T>::[AbstractStack<T>::currentSize - 1];
	}

	// virtual functions...


};