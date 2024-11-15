
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//            
//	WRITTEN BY : SAAD SALMAN DAR 
//  DONOT COPY WITHOUT PRIOR AUTHORIZATION 
//  YOU COULD REACH OUT TO ME ON MY GITHUB FOR APPROVAL 
//  FOLLOW OR FACE DIRE CONSEQUENCES :  https://github.com/Saad-Dar04 

// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			SATIRE						>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	


// forward declaration of class
class CoffeeShop;

#include<iostream>
using namespace std;

template <typename t>
class AbstractLinearQueue {
protected:
	t* arr;
	int maxSize; 
	int currentSize;
public:
	
	// constructor
	AbstractLinearQueue(int maxQueueSize = 0) : currentSize(0){
		this->maxSize = maxQueueSize;
		// dynamically allocating memory
		arr = new t[maxSize];
	}


	// pure virtual function
	virtual	void enqueue(t data) = 0;
	virtual t dequeue() = 0;
	virtual t peek() = 0;
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
	virtual int size() = 0;

	// destructor
	virtual ~AbstractLinearQueue(){
		cout << "abstract linear queue destrutor called" << endl;
		delete[] arr;
	}

	// declaring coffeshop as a friend class so that we could access it's attributes
	friend class CoffeeShop;

};