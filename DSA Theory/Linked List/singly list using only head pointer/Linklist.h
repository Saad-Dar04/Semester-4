#include"Node.h"

class Linklist
{
	Node* head;
public:
	Linklist(){
		head = nullptr;
	}
	void add(int value){
		if (head == nullptr)
		{
			head = new Node;
			this->head->data = value;
			this->head->next = nullptr;
		}
		else
		{
			Node *curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = new Node;
			curr->next->data = value;
			curr->next->next = nullptr;
		}
	}
	void printList()
	{
		Node *itr = head;
		while (itr != nullptr)
		{
			cout << itr->data << " ";
			itr = itr->next;
		}
		cout << endl;
	}
};