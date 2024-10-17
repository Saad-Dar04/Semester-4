// Implementation of stack using array(fifo method)
// array abstract class using templates ( fifo METHOD ) 
// pure virtual functions-> abstract class->inherited classes need to redifine that funciton
// cannot make object of abstract class
#include<iostream>
using namespace std;

template <typename t>
class Array {

protected:
	int currentSize;
	int maxSize;
	t* arr;

public:
	// constructor of Array(abstract class)
	Array(int s) {
		// initializing the dynamically allocated memory 
		arr = new t[s]{};
		currentSize = 0;
		maxSize = s;
	}

	// pure virtual functions -> these functions make this class an abstract making it unable to make objects.
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual void add(t) = 0;
	// we will also return the value that is being removed :)
	virtual t remove() = 0;


	// making a function for display we dont need it pure virtual as it's going to be same for every child , but still im going to make it a pure virtual function
	virtual void display() = 0;
};