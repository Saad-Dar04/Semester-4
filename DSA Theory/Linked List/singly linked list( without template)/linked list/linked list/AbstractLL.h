#include"Node.h"

class AbstractLL {
protected:
	Node* head;
	Node* tail;
public:
	// constructor
	AbstractLL();

	// pure virtual functions
	virtual void insertAtHead(int) = 0;
	virtual void insertAtTail(int) = 0;
	virtual void display() = 0;  // it will traverse through the loop.
	virtual int deleteFromHead() = 0;
	virtual int deleteFromTail() = 0;


	// <<<<<<<<< write this up after doing every other shit
	// it will clean up memory , and dlt all the memory allocated to the nodes atp that the lie btw head and tail pointer. ;0
	//// destructors
	//~AbstractLL() {
	//	// dangling pointer agar reh ge hain tou unhe equal to nullptr krwa dou
	//	cout << "Destructor AbstractLL is being called" << endl;
	//	i
	//}
};

// constructor definition
AbstractLL::AbstractLL() {
	// memory will be allocated to pointers.
	// if i donot assign nullptr to them 
	// they will be wild pointers and will start pointing towards random memory addresses.
	head = nullptr;
	tail = nullptr;
}