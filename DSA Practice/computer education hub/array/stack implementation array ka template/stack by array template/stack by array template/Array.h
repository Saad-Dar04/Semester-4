#include<iostream>
using namespace std;

// default template parameter.
template <typename t>
class Array {
protected:
	t* arr;
	int maxSize;
	int currentSize;
public:
	Array(int);
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
	virtual void addValue(t val) = 0;
	virtual t removeValue() = 0;
	virtual void display() = 0;
	virtual t peek() = 0;
};

template <typename t>
Array<t>::Array(int val) : maxSize(val), currentSize(0) {
	// dynamically allocated memory to the stack
	arr = new t[maxSize]{};
}
