#include "AbstractLL.h"

class MyLL : public AbstractLL {
protected:
	// no data members of this class all will be inherited from the previous class.
public:
	// constructor for this class.
	MyLL() :AbstractLL() {}; // constructor of this class will be called but it will further call the constructor of the parent class , memory will be allocated to the
								// data members head and tail and they will store nullptr inside of them.
	
	// definiton of the pure virtual functions.
	void insertAtHead(int) override;
	void insertAtTail(int) override;
	void display() override;
	int deleteFromHead() override;
	int deleteFromTail() override;
};

// redifiniton of the functions defined above.
void MyLL::insertAtHead(int value) {
	// step 1: dynamically allocated memory to the node
	// step 2: if linked list empty ( perform certain action)  else(perform certain action).
	Node* newNode= new Node; 
	newNode->data = 0;
	newNode->next = nullptr;

	// if linked list is empty , this is the first node that is going to be added
	if (head == nullptr && tail == nullptr) {
		head = newNode;
		tail = newNode;
		newNode->data = value;
	}

	// when the linked list is non empty...
	else {
		newNode->data = value;
		newNode->next = head;
		head = newNode;
	}

} // newNode destructor will be called atp because it's scope was limited only to this function. ):
	// nono , the destructor wont be called cus the node isn't being destroyed , the pointer will finish jou 8 byte ke memory wou hoard kr rha tha wou khtm houjaey ge. :)

void MyLL::insertAtTail(int value)  {

	Node* newNode = new Node;
	newNode->data = 0; 
	newNode->next = nullptr;

	if (head == nullptr && tail == nullptr) {
		head = newNode;
		tail = newNode;
		tail->data = value;
	}

	else {
		newNode->data = value;
		newNode->next = nullptr;
		tail->next = newNode;
		tail = newNode;
	}

} //new node ka destructor tb tk call nhi houge jb tk usey dynamically memory delete nhi krein ge.
	// aur idhr q k hum nae pointer banaya hae tou jou pointer 8 byte memory lae rha hae wou free up houjaey ge. ;)

void MyLL::display()  {
	
	// conditin for if linked list is empty takkey memory ptr aur loop na chaley , trying to optimize our code :)
	if (head == nullptr && tail == nullptr) {
		cout << "The ll is Empty , nothing to display" << endl;
	}
	else {
		Node* ptr = head;

		while (ptr != nullptr) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}	cout << endl;
	}
	// this loop will traverse through the linked list until it encounters 
}

int MyLL::deleteFromHead() {
	// 3 circumstances can exist
	// 1. linked list is empty
	// 2,3. linked list is not empty  -------> has single node
		//							  -------> has mutiple nodes
	// we have to keep in mind all of the above circumstances. :)

	//linked list is empty--> nothing to delete
	if (head == nullptr && tail == nullptr) {
		cout << "The linked list is empty" << endl;
		return int(); // the default value associated with int = 0 will be returned. ;)
	}

	// linked list is not empty
	else {
		// linked list has only one node
		if (head == tail) {
			int returningValue = head->data;
			// delete the dynamically allocated node using pointer head or tail any can be used
			delete head;
			// head and tail are dangling pointer -> pointing towards memory that has been freed up. 
			// good programming practice is setting them up equal to nullptr.
			head = nullptr;
			tail = nullptr;

			return returningValue;
		}

		// linked list has multiple node
		else if(head!=tail && head!=nullptr) {  // it was giving an error , only that is the reason idhr head!=nullptr , although code was still working , it was j confused cus this condition could arrive but their was no possibility that this could based on the fact that how linked list operates ;)
			// the condition would've been head!=tail
			int returningValue = 0;
			
			returningValue = head->data; // stored value of data in rv
			
			Node* temp = head;
			head = head->next;	// moved head to next node
			
			// deleted the head node using a temp node pointer
			delete temp;
			temp = nullptr;   // after deletion it was a dangling pointer hence nullptr
			// ( good programming practice )

			return returningValue;
		}
	}

}

inline int MyLL::deleteFromTail()
{
	// linked list is empty
	if (head == nullptr && tail == nullptr) {
		cout << "The linked list is Empty" << endl;
		return int();
	}

	// linked list is non-empty--> has a single node
	else if (head == tail) {
		int returningValue = head->data;
		delete head;

		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	// ll is non empty---> has multiple nodes.
	else if (head != nullptr) {
		int returningValue = tail->data;
		Node* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}

		delete tail;
		tail = temp;
		tail->next = nullptr;

		return returningValue;
	}

	else {
		cout << "konsi condition hae ye bhaiya ;(" << endl;
	}

	return int();
}
