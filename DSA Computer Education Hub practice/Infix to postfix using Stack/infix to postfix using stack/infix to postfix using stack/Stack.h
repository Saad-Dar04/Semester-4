//infix to postfix using stack
// for this we need to have paranthesis wali infix notation equation which we will convert into postfix notation.
// rules
// 1. store the operator and ( into the stack
// 2. store the numbers in a seperate array or cout them
// 3. call pop() function two times when you encounter ')'
#include<iostream>
using namespace std;

// creating an abstract class for stack
template <typename t>
class Stack {

protected:
	char* arr;
	int currentSize;
	int maxSize;
	char number_store[100]{};
	int number_index;
	char* infix_stored;

public:
	// constructor
	Stack(const char*);

	// pure virtual functions
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
	virtual void push(char) = 0;
	virtual void pop() = 0;
	//virtual t top() = 0;

	void display();

};

// className along with scope resoltion operator to tell the compiler k knsi
// class k function ki redifinition hou rhi hae.
// in case of templates we need to add the typename along with the name of the class.
template <typename t>
Stack<t>::Stack(const char* infix) : currentSize(0), number_index(0) {
	// count the size of the infix notation to set the size of stack
	int size = 0;
	for (int i = 0; infix[i] != '\0'; i++) {

		size++;
		// finding out the size of stack and assigning value to it/
		if (infix[i] == '(' || infix[i] >= '*' && infix[i] <= '/') {
			maxSize++;
		}

	}

	// dynamically allocating memory according to the same and datatype
	arr = new char[maxSize]{};

	// dynamically allocating memory to the char pointer
	infix_stored = new char[size + 1]{};
	// transferring all the characters by using a loop
	for (int i = 0; i < size; i++) {
		infix_stored[i] = infix[i];
	}
	// adding null pointer to the last index
	infix_stored[size] = '\0';
}

template <typename t>
void Stack<t>::display() {
	cout << "stack is : " << endl;
	cout << arr << endl;
	cout << "number store is : " << endl;
	cout << number_store << endl;
}
