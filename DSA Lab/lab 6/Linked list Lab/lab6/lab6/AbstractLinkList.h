// read about nested classes https://www.geeksforgeeks.org/nested-classes-in-c/
#include<iostream>
#include<string>
using namespace std;

template <typename t>
struct Node {
	t data;
	Node* next; //implicit scope the compiler knows that you mean Node<int>* next;
				// within the definiton of the struct , implicit scope applies which means that the compiler knows k jou pointer hae wou aik integer type node ki trf point kr rha hae
				//but outside this struct/class(agar class houti) we would have to explicitly tell the compiler k idhr mae jou pointer hae wou node<int> * next aik integer type node ki taraf point kr rha hae
				// i can also write Node<int>* next here but it is redundant. ;)
	Node() :data(t()), next(nullptr) {};
	// no dynamically allocated memroy tou destructor k through delete krwaney ki zaroorat nhi hae. :)
	// automatic destructor is enough for this..
};


template <typename t>
class AbstractLinkList {
protected:

	Node<t>* head;		// implicit scope is only inside the class , outside the class explicit scope
	Node<t>* tail;		// you have to explicitly mention the type of data that the pointer is pointing towards
					// read the notes attached to this file for better understanding.

public:
	// constructor
	AbstractLinkList();

	// virtual functions
	virtual void insertAtHead(t) = 0;
	virtual void insertAtTail(t) = 0;
	virtual bool deleteFromHead() = 0;
	virtual bool deleteFromTail() = 0;
	virtual bool isEmpty() = 0;
	virtual void display() = 0;
	virtual bool search(t) = 0;
	virtual bool deleteValue(t) = 0; // it will delete the first value that it finds out in the linked list
	// i could also implement it to delete all the nodes containing that value:)
	virtual void insertSorted(t) = 0;

	
};

template <typename t>
AbstractLinkList<t>::AbstractLinkList() : head(nullptr), tail(nullptr) {};

