
#include "AbstractLinkList.h"

template <typename t>
class MyLinkList : public AbstractLinkList<t> {
protected:

public:
	// constructor of MyLinkList
	MyLinkList() : AbstractLinkList<t>() {};
	
	// definition of the virtual funcitons
	void insertAtHead(t) override;
	void insertAtTail(t) override ;
	bool deleteFromHead()override ;
	bool deleteFromTail()override ;
	bool isEmpty() override;
	void display() override;
	bool search(t) override; // if we find the value inside the loop we will return 1 , meaning k value mil gai hae hamein ;)
	bool deleteValue(t) override;
	void insertSorted(t) override; // used to delete a specific value from the linked list :)

	void bubbleSortLinkedList();

	// -----------> adding function for task2
	// function for displaying the top element of the stack
	t topElement() {
		if (!isEmpty()) {
			return AbstractLinkList<t>::tail->data;
		}
		else {
			cout << "The stack is empty" << endl;
			return t();
		}
	}

	// ------------> adding function for task3
	// function for displaying the front element in the queue
	t frontElement() {
		if (!isEmpty()) {
			return AbstractLinkList<t>::head->data;
		}
		else {
			cout << "The stack is empty" << endl;
			return t();
		}
	}

	// ------------> adding function for task4
	// function for deleting all the duplicate values in the linked list.
	void deleteDuplicate() {

	}

	// -------------> adding function for task5
	int nodeCount() {
		int count = 0;
		Node<t>* temp = AbstractLinkList<t>::head;
		while (temp != nullptr) {
			temp = temp->next;
			count++;
		}
		return count;
	}


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
};

template <typename t>
void MyLinkList<t>::insertAtHead(t value) {
	// dynamically allocate memory to node
	Node<t>*newNode=new Node<t>;
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

	Node<t>* newNode=new Node<t>;
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
void MyLinkList<t>::bubbleSortLinkedList() {
	Node<t>* i = AbstractLinkList<t>::head;
	Node<t>* j = nullptr;
	// this will traverse the linked list bss last element kou check nhi krey ga.
	
	if (!isEmpty()) { // agar linked list is not empty phir hi isky andar jaey ga warna nhi jaey ga;)

		while (i->next != nullptr) {


			// this would traverse till the end.
			j = i->next;
			while (j != nullptr) {
				// if the value is greater or smaller wou wali condition idhr apply houge.
				if (i->data > j->data) {
					// the nodes would remain at the same place bss values interchange houjain ge. :)
					t temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
				// we need to update the j and move it to next node
				j = j->next;
			}
			// innner loop khtm honay k baad this would move one step forward jaisay
			// apky normal bubble sort k andar houta hae.
			i = i->next;
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
			return 1;
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

template <typename t>
bool MyLinkList<t>::deleteValue(t key) {
	
	Node<t>* temp = AbstractLinkList<t>::head;
	while (temp != nullptr) {
		if (temp == AbstractLinkList<t>::head) {
			// both the single node and the head wala node would be checked here
			// if key is matched.
			if (temp->data == key) {
				deleteFromHead();
				return 1; 
			}
		}
		
		if (temp->next == nullptr) {
			return 0;
			// couldnt be found
		}
		// else nhi aye ga idhr ye wali condition jb first time loop chaley ga tou udhr sae hi check houna shuru kr dae ge. ;)
		if (temp->next->data == key) {
				// value is found at the tail node
				if (temp->next == AbstractLinkList<t>::tail){
					deleteFromTail();
					return 1;
				}

				// tou phir mid wali value houge.
				else {
					Node<t>* to_be_deleted = temp->next;
					temp->next = temp->next->next;
					delete to_be_deleted;
					return 1;
				}
		}
		
		
		// the last node has been checked and we've reached the end of the loop
		// to idhr sae hi break kr dou cus agar dubara upar geya it would try to access the value of nullptr (Temp->next->data k andar) tou idhr sae hi break krwa dou
		// if upr condition laga temp->next!=nullptr tou wou loop k andar na ghusta ;)
		
		temp = temp->next;
	}
	return 0 ;
}


////// wrong >>>>>>>>>>>>>>>>>>>>>>
// 
//template <typename t>
//bool MyLinkList<t>::deleteValue(t key) {
//	// if linked list is empty
//	if (isEmpty()) {
//		cout << "linked list is empty" << endl;
//		return 0;
//	}
//	// linked list is non_empty
//	else {
//		// contains a single node
//		if (AbstractLinkList<t>::head == AbstractLinkList<t>::tail) {
//			// still check if the single node is what we are looking for.
//			if (AbstractLinkList<t>::head->data == key) {
//				// delete the node
//				return deleteFromHead(); // as deleteFromHead return type is bool so on successful deletion it would return
//				// 1 , which would be further returned. :)
//			}
//
//			// only a single node and it isnt our value , no need to delete it as we didnt dlt anything we return 0.
//			else
//				return 0;
//
//		}
//
//		// meaning that multiple nodes exist :)
//		else if (AbstractLinkList<t>::head != AbstractLinkList<t>::tail) {
//			Node<t>* temp = AbstractLinkList<t>::head;
//			// meaning that we would traverse through the entire array :)
//			while (temp->next != nullptr) {
//				// could be at the head
//				if (temp == AbstractLinkList<t>::head) {
//					if (temp->data == key) {
//						deleteFromHead();
//						return 1;
//					}
//				}
//				// not head seperate algo will be followed
//				else {
//					if (temp->next->data == key) {
//						// if it's tail
//						if (temp->next == AbstractLinkList<t>::tail) {
//							cout << "tail kou access kr pa rhy hain" << endl;
//							deleteFromTail();
//							return 1;
//						}
//						// if it's not tail and lies in btw.
//						else {
//							Node<t> * to_delete = temp->next;
//							// linking the nodes
//							temp->next = temp->next->next;
//							// temp->next = to_delete->next; -> same shit ;)
//							// deleting using the to_delete pointer
//							to_delete->next = nullptr;
//							delete to_delete;
//							to_delete = nullptr; // dangling pointer
//							return 1;
//						}
//
//					}
//					else {
//						// going to the next node :)
//						temp = temp->next;
//					}
//				}
//				
//				
//
//			}
//			// reached here meaning we could'nt find it inside the linked list
//			return 0; // meaning we could'nt find the required data inside the entire linked list , and so we didnt dlt shit as well ;)
//		}
//
//	}
//}


template <typename t>
void MyLinkList<t>::insertSorted(t insertValue) {
	// we need to make sure the linked list is sorted
	bubbleSortLinkedList(); // this would sort the linked list in ascending order.
	
	Node<t>* temp = AbstractLinkList<t>::head;
	

	while (temp!=nullptr) {
		// head kou hamesha check krey ga... :)
		if (temp == AbstractLinkList<t>::head) {
			if (insertValue <= temp->data) {
				insertAtHead(insertValue);
				break;
			}
		}

		if (temp->next != nullptr) {
			// the values in between will be checked here.
			if (insertValue <= temp->next->data) {
				// condition fullfilled -> memory allocate to node aur usey rkha dou next node se pehly
				Node<t>* newNode = new Node<t>;
				newNode->data = insertValue;
				newNode->next = temp->next;
				temp->next =newNode;
				break;
			}
		}

		else {
		// if it's equal to nullptr it means that we've reached the last node aur abhi tk value include nhi hou ski.. ;)
			insertAtTail(insertValue);
			break;
		}

		temp = temp->next;
	}

	// now to add values in the sorted linked list.
}


// <<<<<<<<<<<<<< wrong >>>>>>>>>>
// 
//template <typename t>
//void MyLinkList<t>::insertSorted(t value){
//	// used to insert node at the appropriate position in a sorted linked list
//	// for this the linked list needs to be sorted and then after that i will write code
//	// to insert it at the appropriate position. :)
//
//	// first trying to sort the linked list using bubble sorting technique ;)
//	// we will only be sorting if the loop is notempty and has multiple nodes
//	if (!isEmpty() && AbstractLinkList<t>::head != AbstractLinkList<t>::tail) {
//
//		Node<t>* i = AbstractLinkList<t>::head;
//		Node<t>* j = nullptr;
//		// outerloop
//		while (i != AbstractLinkList<t>::tail) {
//			// j hamesha i sae aik agly waley node pae rahy ga just like how bubble sort works:)
//			cout << "coming in " << endl;
//			j = i->next;
//			//innerloop
//			while (j->next != nullptr) {
//				// if the i wala node is smaller than j wala node
//				if (i->data > j->data) {
//					// for swapping all 3 positions would be taken into consideration
//					
//					// swapping with head
//					if (i == AbstractLinkList<t>::head) {
//						cout << "coming here " << endl;
//						i->next = j->next;
//						j->next = i;
//						AbstractLinkList<t>::head = j;
//						// swapping the positions of i and j for the loop to properly work
//						j = i;
//						i = AbstractLinkList<t>::head;
//					}
//
//					// the nodes lie between the head and tail
//					else if (i != AbstractLinkList<t>::head && j != AbstractLinkList<t>::tail) {
//						i->next = j->next;
//						j->next = i;
//						// to get the previous node we will have to use loop as it goes one side.
//						Node<t>* temp = AbstractLinkList<t>::head;
//						while (temp->next != i) { temp = temp->next; }
//						temp->next = j;
//						// swapping the i and j
//						temp = j;
//						j = i;
//						i = temp;
//					}
//
//					// if tail wala node needs to be swapped
//					if (j == AbstractLinkList<t>::tail) {
//						i->next = nullptr;
//						j->next = i;
//						AbstractLinkList<t>::tail = i;
//						// to get the previous node we have to use loop
//						Node<t>* temp = AbstractLinkList<t>::head;
//						while (temp->next != i) { temp = temp->next; }
//						temp->next = j;
//						// swappping i and j
//						temp = j;
//						j = i;
//						i = temp;
//					}
//				}
//				else {
//					// move j one node forward , just like how bubble sort works
//					j = j->next;
//				}
//
//			}
//
//			// jab j sara traverse hougeya hae phir i aik increment houta hae meaning aik node agey ajaey ga ;)
//			i = i->next;
//		}
//
//
//
//	}
//	else {
//		cout << "no sorting cus is empty or has a single node" << endl;
//	}
//}

