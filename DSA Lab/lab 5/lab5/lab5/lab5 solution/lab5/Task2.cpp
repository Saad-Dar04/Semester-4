
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



// im going to write up all the necessary code for this code
// basically the working of both circular and normal queue is the same with the only difference being time complexity
// i will do this now using normal queue and then include the circular queue later on after grasping better concept of it's working
#include"myLinearQueue.h"
#include <String>

class CustomerDetail {
protected:
	string customerName;
	string coffeeName;
public:
	CustomerDetail(string customerName = "", string coffeeName = "") :customerName(customerName), coffeeName(coffeeName) {};
	
	void setCustomerName(string name) {
		this->customerName = name;
	}

	void setCoffeeName(string coffeeName) {
		this->coffeeName = coffeeName;
	}

	string getCustomerName() {
		return this->customerName;
	}

	string getCoffeeName() {
		return this->coffeeName;
	}

	void Display() {
		cout << "Customer Name: " << getCustomerName() << "\t\t\t  Coffee : " << getCoffeeName();
		cout << endl;
	}
	
	// have to make a copy constructor for this class :)

	~CustomerDetail() {};

};

class CoffeeShop {
protected:
	myLinearQueue<CustomerDetail> customerQueue;
	// i will hardcode that the customer queue can hold a maximum of 10 customers:)

public:
	// making constructor for CoffeeShop
	// hard coded the customerQueue can hold a total of 10 customers in the queue... :)
	CoffeeShop() :customerQueue(10) {

	}

	void addCustomer() {
		string temp1 = "";
		string temp2 = "";
		
		cout << "Enter the Name of the Customer : ";
		cin >> temp1;
		cout << "Enter the Name of Coffee : " ;
		cin >> temp2;
		
		// creating an object with the following details
		CustomerDetail temp(temp1, temp2);
		customerQueue.enqueue(temp);
	}

	void removeFirstCustomer() {
		CustomerDetail temp = customerQueue.dequeue();
		cout << "Customer has been served: \t\t"; temp.Display();
	}

	void numberOfCustomer() {
		cout << "Customers waiting in line: " << customerQueue.size();
	}
	
	// gives out details of the first customer in queue.
	void firstCustomerInQueue() {
		// the first customer will always be residing in the first element :)
		// for this function to work i need to access an private attribute of that class
		// this is not possible without decalring both classes to be friends of each other??
		// is that possbile am i doing it finally.... :::)
		//customerQueue.arr[0]
	}

	void lastCustomerInQueue() {

	}

};


int main() {
	while (1) {
		
		cout << "\t\t\t Menu \t\t\t";
		cout << "1.Add customer to Queue" << endl;
		cout << "2.Remove the First Customer from Queue" << endl;
		cout << "3.Display the number of customer waiting in Queue" << endl;
		cout << "4.View the First Customer in Queue " << endl;
		cout << "5.View the Last Customer in Queue " << endl;
		cout << "6.EXIT" << endl;

		int option = 0;
		cout << "Select an option: ";
		cin >> option;

		if (option == 1) {

		}

		else if (option == 2) {

		}

		else if (option == 3) {

		}

		else if (option == 4) {

		}

		else if (option == 5) {

		}

		else if (option == 6) {
			cout << "EXITING PROGRAM ";
			break;
		}
	}
}



