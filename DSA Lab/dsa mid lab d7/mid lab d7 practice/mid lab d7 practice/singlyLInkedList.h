#include<iostream>
#include<string>
using namespace std;

struct Employee {
	int EmployeeID;
	string Name;
	string Designation;
	float Salary;
	Employee(int id = 0, string n = "", string d = "", float s= 0.00) : EmployeeID(id), Name(n), Designation(d), Salary(s) {}
	~Employee() {}
	void display() {
		cout << "EmployeeID: " << EmployeeID << endl;
		cout << "Name: " << Name << endl;
		cout << "Designation: " << Designation << endl;
		cout << "Salary: " << Salary << endl;
	}
};


class EmployeeSystem {

public:

	struct Node {
		Employee value;
		Node* next;
		Node(Employee value= Employee() , Node* next = nullptr){
			this->value = value;
			this->next = next;
		}
	};

	EmployeeSystem() {
		head = nullptr;
		tail = nullptr;
	}

	void insertAtHead(int id , string n , string d, float s) {
		Node* newNode = new Node;
		newNode->value.EmployeeID = id;
		newNode->value.Name = n;
		newNode->value.Designation = d;
		newNode->value.Salary = s;
		newNode->next = nullptr;
		
		// if the linked list is empty.
		if (head == nullptr && tail == nullptr) {
			head = newNode;
			tail = newNode;
		}
		// if linked list is not empty , then just insert at head.
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	void insertAtNthPosition(int id, string n, string d, float s) {
		
		Node* temp = head;

		if (head == nullptr && tail == nullptr) {
			// allocating memory
			Node* newNode = new Node;
			newNode->value.EmployeeID = id;
			newNode->value.Name = n;
			newNode->value.Designation = d;
			newNode->value.Salary = s;
			newNode->next = nullptr;
			head = newNode;
			tail = newNode;
		}
		
		// means the linked list is not empty.
		else {
			// check the first and last node
			// checking first node
			if (head->value.Designation != "manager") {
				// means start mae mae manager nhi hae tou we can include in manager
				insertAtHead(id, n, d, s);
			}

			else if (tail->value.Designation != "developer") {
				insertAtTail(id, n, d, s);
			}

			else {
				while (temp!=nullptr) {
					if (temp->next->value.Designation != "manager") {
						// allocating memroy
						Node* newNode = new Node;
						newNode->value.EmployeeID = id;
						newNode->value.Name = n;
						newNode->value.Designation = d;
						newNode->value.Salary = s;
						newNode->next = nullptr;

						// inserting the node in between
						newNode->next = temp->next;
						temp->next = newNode;

						break;
					}
					temp = temp->next;
				}
			}

		}
	}
	void insertAtTail(int id, string n, string d, float s) {
		Node* newNode = new Node;
		newNode->value.EmployeeID = id;
		newNode->value.Name = n;
		newNode->value.Designation = d;
		newNode->value.Salary = s;
		newNode->next = nullptr;

		if (head==nullptr && tail==nullptr) {
			head = newNode;
			tail = newNode;
		}
		// if atleast one node is available.
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	void removeEmployee(int id) {
		Node* temp = head;
		bool flag = false;
		while (temp->next!=nullptr) {
			if (temp == head) {
				if (temp->value.EmployeeID == id) {
					// remove from head;
					Node* to_be_deleted = head;
					head = head->next;
					delete to_be_deleted;
					break;
					flag = true;
				}
			}

			if (temp->next->value.EmployeeID == id) {
				Node* to_be_deleted = temp->next;
				temp->next = temp->next->next;
				delete to_be_deleted; 
				break;
				flag = true;
			}
				temp = temp->next;
		}
		if (!flag) {
			cout << "id not found" << endl;
		}
	}


	void Search(int id) {
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->value.EmployeeID == id) {
				temp->value.display();
			}
			temp = temp->next;
		}
	}

	void increaseSalaries() {
		Node* temp = head;
		while (temp != nullptr) {
			if ((*temp).value.Designation == "manager") {
				temp->value.Salary *= 1.20;
			}

			else if (temp->value.Designation == "team lead") {
				temp->value.Salary *= 1.15;
			}

			else if (temp->value.Designation == "developers") {
				temp->value.Salary *= 1.10;
			}

			temp = temp->next;
		}
	}
	
	// sorting employees in descending order of salary.
	void sortEmployees() {
		// after updating salaries.
		increaseSalaries();

		// sorting employees based on salaries
		Node* i = head;
		Node* j = nullptr;
		while (i->next!=nullptr) {
			j = i->next;
			while (j!=nullptr) {

				if (i->value.Salary < j->value.Salary) {
					// exchange the objects within.
					Employee temp = i->value;
					i->value = j->value;
					j->value = temp;
				}

				j = j->next;
			}
			i = i->next;
		}
	}


	void display() {
		Node* temp = head;
		while (temp != nullptr) {
			temp->value.display();
			cout << endl;
			temp = temp->next;
		}
	}

	




protected:

	Node* head;
	Node* tail;


};