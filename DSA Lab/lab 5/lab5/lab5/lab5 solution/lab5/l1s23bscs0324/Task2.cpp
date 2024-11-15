
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


 ////////////// <<<<<<<<<<<< have to implement >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 //////////////  implement what to do when the queue ends , send a message that their are no customers in the queue. :(
// im going to write up all the necessary code for this code
// basically the working of both circular and normal queue is the same with the only difference being time complexity
// i will do this now using normal queue and then include the circular queue later on after grasping better concept of it's working
#include"myLinearQueue.h"
#include <String>
#include<iostream>

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
	
	// operator<< function when trying to directly cout the object
	// it will be declared as a friend funciton in our class
	friend ostream& operator<<(ostream& os, const CustomerDetail& f);
	// watch video and read the chatgpt screenshots that i've attached.
	
	

	// copy constructor
	CustomerDetail(const CustomerDetail& obj) {
		customerName = obj.customerName;
		coffeeName = obj.coffeeName;
	}


	// assignment operator
	CustomerDetail& operator=(const CustomerDetail& otherobj) {
		customerName = otherobj.customerName;
		coffeeName = otherobj.coffeeName;
		return *this;
	}

	// have to make a copy constructor for this class :)

	~CustomerDetail() {};

};

// redefinition of the friend funciton outside the class ;)
ostream& operator<<(ostream& os, const CustomerDetail& f) {
	os << f.customerName << "  ----> " << f.coffeeName;
	return os;
}




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
		// implemented this if else so if the queue is empty it would return the defualt created object having "" for both attribtues , checking if it has returned those
		// default attributes then it is empty , in that case instead of printing out the names i would simply be printing N/A.
		if (temp.getCustomerName() == "" && temp.getCoffeeName() == "") {
			// THE OBJECT IS EMPTY , NOTHING WILL BE PRINTED. :)
		}
		else {
			cout << "Customer has been served: \t\t"; temp.Display();
		}
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
		
		// this is giving an error cus what i'm trying to do here is trying to cout CustomerDetail object , the program doesnt know how to deal with this
		// for this reason i have to make the operator<< function then the program will know how to deal with this effectively ;)
		if (customerQueue.size() == 0) {
			cout << "QUEUE IS EMPTY , NO CUSTOMERS IN QUEUE" << endl;
		}
		else {
			//
			cout << "The first customer in queue is: " << customerQueue.arr[0];

		}

		// or we could also do is get the pointer , aur phir us pointer kou use kr k hum apni marzi sae
		// call kr skty hain , so many different ways to do the same shit 

		// but i'll be implementing the declaring this class as a friend funciton in abstractlinearqueue in order to access it's private attribtues.



	}

	void lastCustomerInQueue() {

		if (customerQueue.isEmpty()) {
			cout << "NO CUSTOMERS IN QUEUE" << endl;
		}
		// wohi jou upr kiya hae , since i've declared this class as a friend function of the AbstractLinearQueue , i have access to all the private members.
		else {
			cout << "The last customer in queue is: " << customerQueue.arr[customerQueue.size() - 1];
		}
		// this would return an object residing at the maxSize-1 memory location and i've already defined the operator<< in case an object of the class customerDetial is encounterd...
		
	}

};


int main() {
	
	// making an object of the class coffeeShop.
	CoffeeShop list;
	
	while (1) {
		
		cout << "\t\t\t Menu \t\t\t\n";
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
			list.addCustomer();
		}

		else if (option == 2) {
			list.removeFirstCustomer();
		}

		else if (option == 3) {
			list.numberOfCustomer();
		}

		else if (option == 4) {
			list.firstCustomerInQueue();
		}

		else if (option == 5) {
			list.lastCustomerInQueue();
		}

		else if (option == 6) {
			cout << "EXITING PROGRAM ";
			break;
		}
		
		cout << "\n\n" << endl;
	}
}



