#include "singlyLInkedList.h"
#include<iostream>
using namespace std;

int main() {

	int option = 0;
	string name = "";
	string designation = "";
	float salary = 0.0;
	int id = 0;
	EmployeeSystem list;


	while (1) {
		cout << "\n\n\t\t\tMenu\t\t\t\t" << endl;
			
		cout << "	1. Add Employee														" <<endl;
		cout << "	2. Remove Employee 													" <<endl;
		cout << "	3. Search Employee 													" <<endl;
		cout << "	4. Update Salaries  												" <<endl;
		cout << "	5. Sort Employees 													" <<endl;
		cout << "	6. Display Employees : List all employees with their details.		" <<endl;
		cout << "	7. Exit : Terminate the program.									" <<endl;
																					
		cout << "choose an option: " << endl;
		cin >> option;
		if (option == 1) {
			cout << "Enter employee id: ";
			cin >> id;
			cin.ignore();
			cout << "Enter employee name: ";
			getline(cin, name);
			cout << "employee designation: ";
			getline(cin, designation);
			cout << "enter salary: ";
			cin >> salary;
			cin.ignore();
			
			if (designation == "manager") {
				list.insertAtHead(id, name, designation, salary);
			}

			else if (designation == "team lead") {
				list.insertAtNthPosition(id, name, designation, salary);
			}

			else if (designation == "developer") {
				list.insertAtTail(id, name, designation, salary);
			}

			else {
				cout << "Enter a proper designation" << endl;
			}
		}
		else if (option == 2) {
			cout << "ENTER EMPLOYEE ID: ";
			cin >> id;
			list.removeEmployee(id);
		}
		else if (option == 3) {
			cout << "ENTER EMPLOYEE ID: ";
			cin >> id;
			list.Search(id);
		}
		else if (option == 4) {
			cout << "UPDATING SALARIES OF EMPLOYEES" << endl;
			list.increaseSalaries();
		}
		else if (option == 5) {
			cout << "INCREASING SALAREIES AND SORTING EMPLOYEES IN DESCENDING ORDER" << endl;
			list.sortEmployees();
		}
		else if (option == 6) {
			cout << "LISTING ALL EMPLOYEES ALONG WITH DETAILS" << endl;
			list.display();
		}
		else if (option == 7) {
			cout << "CLOSING THE PROGRAM" << endl;
			break;
		}

	}
	return 0;
}