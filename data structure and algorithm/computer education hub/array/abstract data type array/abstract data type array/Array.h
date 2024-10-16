#include<iostream>
using namespace std;

//abstract class so it means that it cannot be instantiated it j acts as a template aur baaki classes is se inherit hounge.
class Array {
protected:
	int maxSize;
	int currentSize;
	int* arr;
public:
	Array(int);
	// made virtual function which means that the redifinition of these functions is necessary in the child classes..
	virtual void addValue(int size = 0) = 0;
	virtual int removeValue() = 0;
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
	virtual void display() = 0;
};

Array::Array(int size = 0) :maxSize(size) , currentSize(0) {
	//dynamically allocating space for the stack on the heap
	this->arr = new int[maxSize] {};
}