#include"AbstractStack.h"

template <typename T>
class myStack : public AbstractStack<T> {

public:
	
	// constructor
	myStack(int currentSize) : AbstractStack<T>(currentSize) {};

	// pure virtual functions...
	bool isFull() const {
		return (AbstractStack<T>::currentSize == AbstractStack<T>::maxSize);
	}

	bool isEmpty() const {
		return (AbstractStack<T>::currentSize == 0);
	}

	void push(T value) {
		if (!isFull()) {
			AbstractStack<T>::arr[AbstractStack<T>::currentSize++] = value;
		}
		else
			cout << "Stack is full" << endl;
	}
	
	T pop() {
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			return T();
		}
		else {
			// pre decrement to decrement from 3 to 2 and return the value of 2
			// the next value will be stored at 2.
			AbstractStack<T>::currentSize--;
			return AbstractStack<T>::arr[AbstractStack<T>::currentSize];
		}
	}

	T top() const {
		// constant function means that no value could be updated in this function 
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			return T();
		}

		return AbstractStack<T>::arr[AbstractStack<T>::currentSize-1];
	}

	// display function , exclusive function
	void display() {
		for (int i = 0; i < AbstractStack<T>::currentSize; i++) {
			cout << AbstractStack<T>::arr[i] << " ";
		}	cout << endl;
	}

	~myStack() override{
		cout << "myStack destructor has been called" << endl;
		// if any dynamic memory was to be allocated in this class
		// it's memory would've been freed up here
		// virtual destructor come in handy when we free up memory by deleting the baseClassPointer.
	}
	
	// getters
	int getcurrentSize() {
		return AbstractStack<T>::currentSize;
	}

	int getmaxSize() {
		return AbstractStack<T>::maxSize;
	}

	template <typename U>
	friend void stackOperations(const myStack<U>& obj);
	// friend function is a non member function but the benefit of using it
	// despite this fact it gets access to all the private members of this class.

	// task 3
	template <typename T>
	friend void infixToPostfix(const T& str);
	
	// task 2 friend function
	template <typename T>
	friend void reverseBooks(myStack<T>& obj1, myStack<T>& obj2);

	//// making copy constructor to be used inside task 2
	//myStack(const myStack& obj) {
	//	// destroying the previously allocated memory if any
	//	if (this->~AbstractStack<T>::arr != nullptr) {
	//		~myStack();
	//	}

	//	this->AbstractStack<T>::currentSize = obj.currentSize;
	//	this->~AbstractStack<T>::maxSize = obj.maxSize;
	//	for (int i = 0; i < obj.currentSize; i++) {
	//		this->arr[i] = obj[i];
	//	}

	//}

	myStack& operator=(const myStack& obj) {
		// destroying the previously allocated memory if any
		if (this->AbstractStack<T>::arr != nullptr) {
			~myStack();
		}

		myStack temp(obj.getmaxSize());
		temp.AbstractStack<T>::currentSize = obj.currentSize;
		for (int i = 0; i < obj.currentSize; i++) {
			temp.arr[i] = obj[i];
		}
		return temp;
	}
};

// provided a menu for users to preform the stack operations interactively.
template <typename U>
void stackOperations(myStack<U>& obj)
{
	// <<<<<<<<<<<<< important must read >>>>>>>>>>>>>>>
	//cout << "stackoperations has been reached" << endl;
	//// could'nt find out how to directly access the private members residing insdie the parent class
	//// tried declaring the friend function in the parent class as well along with forward decalaration
	//// of the derived class and friend function but it didnt work 
	//// so the best way that i came up with was to make a public getter function to get the currentSize of the array
	//// seems easy and a more logical way to do things..
	//cout << obj.getcurrentSize();
	//cout << endl;
	bool flag = 1;
	int option = 0;
	U value = U();
	while (1) {
		
		cout << "\t\t\t\t Menu \t\t\t\t " << endl;
		cout << "1.Push" << endl;
		cout << "2.Pop" << endl;
		cout << "3.Top" << endl;
		cout << "4.Current Size" << endl;
		cout << "5.Max Size" << endl;
		cout << "6.Display" << endl;
		cout << "press anyother key to exterminate program" << endl;
		// taking input from user.
		cin >> option;

		if (option == 1) {
			cout << "enter the value: " << endl;
			cin >> value;
			obj.push(value);
		}

		else if (option == 2) {
			cout << "the value removed is: " << obj.pop();
		}

		else if (option == 3) {
			cout << "the value at the top is: " << obj.top();
		}

		else if (option == 4) {
			cout << "the current size of the stack is: " << obj.getcurrentSize() << endl;
		}
		
		else if (option == 5) {
			cout << "the maxSize is of the stack is: " << obj.getmaxSize();
		}

		else if (option == 6) {
			obj.display();
		}

		else {
			break;
		}

		/*cout << "would you like to continue??" << endl;
		cout << "press 1 for continue \n press 0 to terminate program" << endl;
		cin >> flag;
		if (flag) {
			continue;
		}
		else {
			continue;
		}*/
	}
}