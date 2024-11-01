#include<iostream>
using namespace std;

// creating an abstract class for stack
template <typename t>
class Stack {

protected:
	t* arr;
	int currentSize;
	int maxSize;

public:
	// constructor
	Stack(int);

	// pure virtual functions
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
	virtual void push(t) = 0;
	virtual t pop() = 0;
	virtual t top() = 0;

	void display();
};

// className along with scope resoltion operator to tell the compiler k knsi
// class k function ki redifinition hou rhi hae.
// in case of templates we need to add the typename along with the name of the class.
template <typename t>
Stack<t>::Stack(int maxSize) : maxSize(maxSize) , currentSize(0){
	// dynamically allocating memory according to the same and datatype
	arr = new t[maxSize]{};
}

template <typename t>
void Stack<t>::display() {
	for (int i = 0; i < currentSize; i++) {
		cout << arr[i] << " ";
	}cout << endl;
}
