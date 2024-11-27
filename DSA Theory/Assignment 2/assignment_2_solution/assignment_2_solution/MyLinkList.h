
#include "AbstractLinkList.h"

template <typename t>
class MyLinkList : public AbstractLinkList<t> {
protected:

public:
	// constructor of MyLinkList
	MyLinkList() : AbstractLinkList<t>() {};

	// definition of the virtual funcitons
	void insertAtHead(t) override;
	void insertAtTail(t) override;
	bool deleteFromHead()override;
	bool deleteFromTail()override;
	bool isEmpty() override;
	void display() override;
	bool search(t) override; // if we find the value inside the loop we will return 1 , meaning k value mil gai hae hamein ;)
	Node<t>*& returnHead();


	~MyLinkList() {
		while (!isEmpty()) {
			deleteFromHead(); // it will delete until it becomes empty :)
			// all the dynamiacally allocated nodes will delete.
		}
		// end pae the pointers would be left head and tail waley they will be nullptr but still i'll do em here
		AbstractLinkList<t>::head = nullptr;
		AbstractLinkList<t>::tail = nullptr;
		// and now the pointers would simply deallocate the memory themselves.
		// i j need to keep track of the dynamically allocated memory that i've taken care of nicely ;)
	}

	// friend functions
	//friend void insertNth(Node* head) -> the problem with this is that it would modify the memory location that head is pointing towards
	// aik copy baney ge node* ki and it would store that address and changes would be implemented on that address only
	// agar koi new node start pae end kr diya hae tou wou temporary node* would point at it and not our orignal node , so in order to counter this
	// problem we would be sending it be reference takkey jou b changes ayein node k andar hamara orignal node b unki trf point kr rha houga. ;)
	friend void insertNth(Node<t> *& head, int n, t data);
	friend void deleteNth(Node<t>*& head, int n);
};

// pass by reference vs pass by values
// we are passing the head pointer by reference takkey jitni b changes houn , head orignal pointer jou linked list
// k andar use hou rha hae to keep track of the linked list wou b update houta rahy sath sath
// agar we only send by value e.g. node<t>* mylinklist<t>::returnhead(){} this would just return the memory address that
// it's pointing towards aur doosra neya pointer would catch it, tou wou new pointer jou us funciton mae banaey ga usky andar jou
// changes ayein ge those changes wont be updated in the head/orignal pointer , that's why in this case we pass it by reference.
template <typename t>
Node<t>*& MyLinkList<t>::returnHead() {
	return AbstractLinkList<t>::head;
}

template <typename t>
void deleteNth(Node<t>*& head, int n) {
	int count = 0;

	Node<t> * temp = head;

	// head!=nullptr checks if the loop is empty no need to remove.
	while (n >= count && head != nullptr && temp->next!=nullptr) {
		
		// want to remove the first element
		if (n == 0) {
			// only one node exists
			if (head->next == nullptr) {
				delete head;
				head = nullptr; // indicated the linked list is empty now
				break;
			}
			// normal case
			else {
				head = head->next;
				delete temp;
				break;
			}
		}

		else if (n != 0 && count == n - 1) {
			Node<t> * temp_to_delete = temp->next;
			if (temp_to_delete->next == nullptr) {		// if we are trying to remove the last node in the linked list
				temp->next = nullptr;			
			}
			else {									// else if we are trying to node that exists in between..
				temp->next = temp->next->next;
			}									
			// im trying to get nullptr but it cannot fetch it bss memory address kou catch kr skta hae thats why the error
			delete temp_to_delete;					// so i will just add another condition here ;)
			break;
		}

		temp = temp->next;
		count++;
	}

	if (head == nullptr) {
			cout << "Linked List is Empty , cannot remove" << endl;
	}
	
	else if(n<count){
		cout << "nth value is greater than the current size of the linked list." << endl;
	}
}

// redifintion of the friend function
template <typename t>
void insertNth(Node<t> *& head, int n, t data) {
	// no implicit by the compiler
	// we have to specifically mention the type of data that the node stores inside of it , in case of templates.
	int count = 0;
	Node<t>* newNode = new Node<t>;
	newNode->data = data;
	newNode->next = nullptr;
	
	Node<t> *temp = head;

	while (n>=count) {


		if (n==0) {
			// we want to add the value at the head
			if (head == nullptr) {
				head = newNode;
			
			}
			else {
				newNode->next = head;
				head = newNode;
			}
		}
		
		// if n>0 then 2 conditions.
		// either it will come in between or we will try to add at the end of the node. ;)
		else if(n!=0 && count==n-1) {
			newNode->next = temp->next;
			temp->next = newNode;
		}

		// it means k 0 sae greater number pae add krwana hae and we have reached the end of the linked list
		// issey agey there's nothing in the linked list tou hamein end pae element rkhwana houga. 
		// but updating the tail would not be possbile because i dont have access to the parent class's attributes but it doesnot
		// matter at this point
		// or chatgpt and find out kou parent class k protected members/private members kou kaisya acces miley ge idhr.
		// optimized approach
		else if (n != 0 && temp->next==nullptr) {
			// in that case the node will be inserted at the end of the linked list.
			temp->next = newNode;
			newNode->next =nullptr;
			// i need to update the tail at this point but how will i to that??? ask sir.

			break;
		}
		
		// shifting temp to the next after each loop.
		temp = temp->next;
		count++;
	}
}

template <typename t>
void MyLinkList<t>::insertAtHead(t value) {
	// dynamically allocate memory to node
	Node<t>* newNode = new Node<t>;
	//we have a pointer that  				= dynamically allocated memory for a node of type t
	//	it pointing towards a 				= meaning it could hold a value of type t and
	//	memory that holds a node of t type	=  it has a pointer that is pointing towards a type t.
	(*newNode).data = value;
	newNode->next = nullptr;

	// if the linked list is empty
	if (AbstractLinkList<t>::head == nullptr && AbstractLinkList<t>::tail == nullptr) {
		AbstractLinkList<t>::head = newNode;
		AbstractLinkList<t>::tail = newNode;
	}

	// if linked list is non empty
	else {
		newNode->next = AbstractLinkList<t>::head;
		AbstractLinkList<t>::head = newNode;
	}

}

template <typename t>
void MyLinkList<t>::insertAtTail(t value) {

	Node<t>* newNode = new Node<t>;
	newNode->data = value;
	newNode->next = nullptr;

	// if linked list is empty
	if (AbstractLinkList<t>::head == nullptr && AbstractLinkList<t>::tail == nullptr) {
		AbstractLinkList<t>::head = newNode;
		AbstractLinkList<t>::tail = newNode;
	}

	// if link list is non empty :)
	else {
		// try making the struct inside the class next time :p
		AbstractLinkList<t>::tail->next = newNode;
		AbstractLinkList<t>::tail = newNode;
	}

}

template <typename t>
bool MyLinkList<t>::deleteFromHead() {
	// if linked list is empty
	if (AbstractLinkList<t>::head == nullptr && AbstractLinkList<t>::tail == nullptr) {
		// linked list is empty ;)
		cout << "linked list is empty cannot delete" << endl;
		return 0;
	}

	// link list is not empty
	else {
		// both are pointing towards same node , means single node exists.
		if (AbstractLinkList<t>::head == AbstractLinkList<t>::tail) {
			delete AbstractLinkList<t>::head; // dynamically deleted memory
			// head and tail are wild pointers at this point.
			AbstractLinkList<t>::head = nullptr;
			AbstractLinkList<t>::tail = nullptr;
			return 1; // 1 meaning successfully removed value from linked list.
		}

		// means multiple nodes exist.
		else {
			Node<t>* temp = AbstractLinkList<t>::head;
			AbstractLinkList<t>::head = AbstractLinkList<t>::head->next;
			delete temp;
			temp = nullptr; // goood programming practice , in oder to avoid danglin pointer.
			return 1; // meaning k successfully removed value from link list
		}

	}
}

template <typename t>
bool MyLinkList<t>::deleteFromTail() {
	// if linked list is empty
	if (AbstractLinkList<t>::head == nullptr && AbstractLinkList<t>::tail == nullptr) {
		// linked list is empty ;)
		cout << "linked list is empty cannot delete" << endl;
		return 0;
	}

	else {

		if (AbstractLinkList<t>::head == AbstractLinkList<t>::tail) {
			delete AbstractLinkList<t>::tail; // dynamically deleted memory
			// head and tail are wild pointers at this point.
			AbstractLinkList<t>::head = nullptr;
			AbstractLinkList<t>::tail = nullptr;
			return 1; // 1 meaning successfully removed value from linked list.
		}

		// multiple nodes
		else {
			Node<t>* temp = AbstractLinkList<t>::head;
			while (temp->next != AbstractLinkList<t>::tail) {
				temp = temp->next;
			}
			// tail sae aik previous node pae poonch kr we wil come out of the loop :)
			delete AbstractLinkList<t>::tail;
			// both the tail and previous node ka next(temp->next) will be dangling
			// cus they are still pointing towards memory that has been freed up isliye
			// we will properly deal with them.
			AbstractLinkList<t>::tail = temp;
			AbstractLinkList<t>::tail->next = nullptr;
		}
	}

}

template <typename t>
bool MyLinkList<t>::isEmpty() {
	// linked list going to be empty if head and tail are both pointing towards nullptr.
	return (AbstractLinkList<t>::head == nullptr && AbstractLinkList<t>::tail == nullptr);
}

template <typename t>
void MyLinkList<t>::display() {
	// we will only display if the linked list is not empty :)
	if (!isEmpty()) {
		// if not empty-> then we would display , otherwise we would just tell that the link list is empty :)
		Node<t>* temp = AbstractLinkList<t>::head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}cout << endl;
		// traversed through the entire loop...
	}
	else {
		cout << "link list is empty" << endl;
	}
}

template <typename t>
bool MyLinkList<t>::search(t value) {
	// if loop is not empty , then serach otherwise
	if (!isEmpty()) {
		Node<t>* temp = AbstractLinkList<t>::head;
		while (temp != nullptr) {
			if (temp->data == value) {
				return 1;
			}
			temp = temp->next;
		}
		return 0;
		// if traversed through the entire loop and we didnt find the value
		// then return 0 to show that value could'nt be found ;)
	}

	else {
		cout << "link list is empty" << endl;
		return 0;
	}
}


