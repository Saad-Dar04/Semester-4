#include "LinkedList.h"

class myLL :public LinkedList
{
	void insertAtTail(int);
	void insertAtHead(int);
public:
	void display();
	int deleteFromHead();
	int deleteFromTail();
	bool search(int);
	bool deleteValue(int);
	void insertSorted(int);
};

void myLL::insertSorted(int value)
{
	if (head == nullptr && tail == nullptr) //LL is empty
	{
		Node*newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
		head = newNode;
		tail = newNode;
	}

	else
	{
		if (value >= head->data) //largest value
			insertAtHead(value);

		else if (value <= tail->data) //smallest value
			insertAtTail(value);

		else //somewhere in between
		{
			Node*newNode = new Node;
			newNode->data = value;
			newNode->next = nullptr;

			Node*t = head;

			while (true)
			{
				if (value < t->data && value >= t->next->data)
				{
					//insert Value after t
					newNode->next= t->next;
					t->next = newNode;


					break;
				}

				else 
					t = t->next;
			}
		}
	}
}

bool myLL::deleteValue(int value)
{
	if (head == nullptr && tail == nullptr)
		return false;

	else if (head == tail)
	{
		if (head->data == value)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}

		else
			return false;
	}

	else if (value == head->data)
	{
		deleteFromHead();
		return true;
	}

	else if (value == tail->data)
	{
		deleteFromTail();
		return true;
	}

	else
	{
		Node*p = head;

		while (true)
		{
			if (p->next->data == value)
				break;

			p = p->next;

			if (p == tail)
				return false;
		}

		Node*d = p->next;
		p->next = d->next;
		delete d;
		d = nullptr;
		return true;
	}
}

bool myLL::search(int value)
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return false;
	}

	else
	{
		Node*t = head;

		while (1)
		{
			if (t->data == value)
				return true;

			t = t->next;

			if (t == nullptr)
				return false;
		}
	}
}

int myLL::deleteFromTail()
{
	if (head == nullptr && tail == nullptr) //LL is empty
	{
		cout << "LL is empty" << endl;
		return NULL;
	}

	else if (head == tail) //single node in LL
	{
		int returningValue = head->data;

		delete tail; //delete head;
		head = nullptr;
		tail = nullptr;

		return returningValue;
	}

	else //non empty LL
	{
		int returningValue = tail->data;

		Node*t = head;

		while (true)
		{
			if (t->next == tail)
				break;

			t = t->next;
		}

		delete tail;
		tail = t;
		t->next = nullptr;

		return returningValue;
	}
}

int myLL::deleteFromHead()
{
	if (head == nullptr && tail == nullptr) //LL is empty
	{
		cout << "LL is empty" << endl;
		return NULL;
	}

	else if (head == tail) //single node in LL
	{
		int returningValue = head->data;

		delete tail; //delete head;
		head = nullptr;
		tail = nullptr;

		return returningValue;
	}

	else //non empty LL
	{
		int returningValue = head->data;

		Node*t = head;
		head = head->next;
		delete t;
		t = nullptr;
		return returningValue;
	}
}

void myLL::display()
{
	if (head != nullptr && tail != nullptr)
	{
		Node* t = head;

		while (true)
		{
			cout << t->data << endl;
			t = t->next;

			if (t == nullptr)
				break;

		}

	}

	else
		cout << "The Linked List in empty" << endl;

}

void myLL::insertAtHead(int value)
{
	Node* newNode;
	newNode = new Node;
	newNode->next = nullptr;
	newNode->data = value;

	if (head == nullptr && tail == nullptr) //LL is empty
	{
		head = newNode;
		tail = newNode;
	}

	else //non empty LL
	{
		newNode->next = head;
		head = newNode;
	}




}

void myLL::insertAtTail(int value)
{
	Node*nn = new Node;
	nn->data = value;
	nn->next = nullptr;


	if (head == nullptr && tail == nullptr) //Empty LL
	{
		head = nn;
		tail = nn;
	}

	else //Non-empty Linked List
	{
		tail->next = nn;
		tail = nn;
	}
}