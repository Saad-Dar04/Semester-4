#include"AbstractStack.h"
#include"String"
#include<cmath>

template <typename T>
class myStack : public AbstractStack<T> {
private:


public:

	// constructor
	myStack(int currentSize) : AbstractStack<T>(currentSize) {};

	// pure virtual functions...
	bool isFull() const {
		return (AbstractStack<T>::currentSize == AbstractStack<T>::maxSize);
	}

	bool isEmpty() const {
		return (AbstractStack<T>::currentSize == 0);
	}

	void push(T value) {
		if (!isFull()) {
			AbstractStack<T>::arr[AbstractStack<T>::currentSize++] = value;
		}
		//else
			//cout << "Stack is full" << endl;
	}

	T pop() {
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			return T();
		}
		else {
			// pre decrement to decrement from 3 to 2 and return the value of 2
			// the next value will be stored at 2.
			AbstractStack<T>::currentSize--;
			return AbstractStack<T>::arr[AbstractStack<T>::currentSize];
		}
	}

	T top() const {
		// constant function means that no value could be updated in this function 
		if (isEmpty()) {
			//cout << "Stack is Empty" << endl;
			return T();
		}

		return AbstractStack<T>::arr[AbstractStack<T>::currentSize - 1];
	}

	// display function , exclusive function
	void display() {
		for (int i = 0; i < AbstractStack<T>::currentSize; i++) {
			cout << AbstractStack<T>::arr[i] << " ";
		}	cout << endl;
	}

	~myStack() override {
		//cout << "myStack destructor has been called" << endl;
		// if any dynamic memory was to be allocated in this class
		// it's memory would've been freed up here
		// virtual destructor come in handy when we free up memory by deleting the baseClassPointer.
	}

	// getters
	int getcurrentSize() {
		return AbstractStack<T>::currentSize;
	}

	int getmaxSize() {
		return AbstractStack<T>::maxSize;
	}

	// i dont need to make these functions friend functions , becuase i am directly instantiating the objects in the functions
	// friend functions are required when we need to use the object(by passing it into another function)
	// agar main mae object bana kr us function kou infix to postfix mae pass karwata in that case mujhy friend function kou bananey ki zaroorat parti(is waley mae zaroorat nhi hae)
	/*friend void infixToPostfix(const char* ptr);
	friend void infixToPrefix(const char* ptr);*/

};



// converts the char number to int value
int charToint(char a) {
	int temp = a - '0';
	return temp;
}

int calculator(int& num1, int& num2, char operation) {
	if (operation == '^') {
		return pow(num2, num1);
	}
	else if (operation == '/') {
		return num2 / num1;
	}
	else if (operation == '*') {
		return num2 * num1;
	}
	else if (operation == '+') {
		return num2 + num1;
	}
	else if (operation == '-') {
		return num2 - num1;
	}
}


