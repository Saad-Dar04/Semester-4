#include"AbstractStack.h"
#include"String"
#include<cmath>

template <typename T>
class myStack : public AbstractStack<T> {
private:


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
		//else
			//cout << "Stack is full" << endl;
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
			//cout << "Stack is Empty" << endl;
			return T();
		}

		return AbstractStack<T>::arr[AbstractStack<T>::currentSize - 1];
	}

	// display function , exclusive function
	void display() {
		for (int i = 0; i < AbstractStack<T>::currentSize; i++) {
			cout << AbstractStack<T>::arr[i] << " ";
		}	cout << endl;
	}

	~myStack() override {
		//cout << "myStack destructor has been called" << endl;
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

	// i dont need to make these functions friend functions , becuase i am directly instantiating the objects in the functions
	// friend functions are required when we need to use the object(by passing it into another function)
	// agar main mae object bana kr us function kou infix to postfix mae pass karwata in that case mujhy friend function kou bananey ki zaroorat parti(is waley mae zaroorat nhi hae)
	/*friend void infixToPostfix(const char* ptr);
	friend void infixToPrefix(const char* ptr);*/

};

int sizeOfArray(const char* ptr) {
	int size = 0;
	for (int i = 0; ptr[i] != '\0'; i++) {
		size++;
	}
	return size;
}

int precedence(const char symbol) {
	if (symbol == '^') {
		return 3;
	}
	else if (symbol == '/' || symbol == '*') {
		return 2;
	}
	else if (symbol == '+' || symbol == '-') {
		return 1;
	}
	else {
		return 0;
	}
}

void infixToPostfix(const char* ptr) {
	// stack ka datatype would be decided considering k kis trhan ka data hum nae stack k andar rkhwana hae
	// in this case hum nae char type rkhwana tha , isliye char banaya hae... :)
	// making a new object to store the stack
	myStack<char> a(10);
	cout << "infix: " << ptr << endl;
	cout << "postfix: ";
	//cout << size(ptr) << endl;   //3
	for (int i = 0; ptr[i]!='\0' ; i++) {
		
		// if we encounter '(' just push it into the stack
		if (ptr[i] == '(') {
			a.push(ptr[i]);
		}

		// if we encounter an operand we would simply console output it or 
		// store it in an array according to our requirement.
		else if (ptr[i] >= 'A' && ptr[i] <= 'Z' || ptr[i] >= 'a' && ptr[i] <= 'z') {
			cout << ptr[i];
		}

		// if we encounter an ')' we would pop all the elements until we encounter ')'
		else if (ptr[i] == ')') {
			while (a.top() != '(') {
				cout << a.pop();
			}
			// we would simply pop the '(' and would not be printing it ;)
			a.pop();
		}

		else if (ptr[i] == '^' || ptr[i] == '*' || ptr[i] == '/' || ptr[i] == '-' || ptr[i] == '+') {
			while (!a.isEmpty() && precedence(a.top()) >= precedence(ptr[i])) {
				cout << a.pop();
			}
			a.push(ptr[i]);
		}

	}

	// we will empty the stack , if there are any operators left unkou b nikaal dein gae.
	while (!a.isEmpty()) {
		cout << a.pop();
	}

	cout << endl;
}

// converts the char number to int value
int charToint(char a) {
	int temp = a - '0';
	return temp;
}

int calculator(int& num1, int& num2 , char operation) {
	if (operation == '^') {
		return pow(num2 , num1);
	}
	else if (operation == '/') {
		return num2 / num1;
	}
	else if (operation == '*') {
		return num2 * num1;
	}
	else if (operation == '+') {
		return num2 + num1;
	}
	else if (operation == '-') {
		return num2 - num1;
	}
}


// didn't implement the associativity rule yet...
// l -> R ( pop() till precedence and same , after that push() )
// R -> L ( just push() the current operator onto the stack )
// baaki algo has been implemented ..
void PostfixEvaluation(const char* ptr) {
	
	// instantiating a stack of int type , in order to store the int values of size 10.
	myStack<int> a(10);
	int num1 = 0;
	int num2 = 0;

	for (int i = 0; ptr[i] != '\0'; i++) {
		// if we encounter operand we would push it's int value into stack
		if (ptr[i] >= '0' && ptr[i] <= '9') {
			a.push(charToint(ptr[i])); // will convert the char to int value and it would be stored on the int type stack.
		}

		// if we encounter a operand we would pop()
		// pop() two operands and perform the operation , keep track of the positions because of ^ , / , - the order matters.
		else if (ptr[i] == '^' || ptr[i] == '*' || ptr[i] == '/' || ptr[i] == '+' || ptr[i] == '-') {
			num1 = a.pop();
			num2 = a.pop();
			// after performing the calculation it would push the result to stack
			a.push(calculator(num1, num2, ptr[i]));
		}
	}

	// after performing all the operations the last operations would be left in stack , since after performing operation we are pushing the result onto the stack
	// hence at this point we would pop() the last int value that is our anwser and return it to user.
	// i decided not to return this value , instead j console output it to keep the program the same , bss
	// isi function k sath cout na lagana parey.
	cout << "The postfix expression is : " << ptr <<endl;
	cout << "After postfix evaluation: " << a.pop() << endl;
}

void loopback() {
	cout << "Made by Nawal Tariq" << endl;
}


void infixToPrefix(const char* str) {

	// instantiating char type stack  , that would store characters insdie of size 10.
	myStack<char> a(10);  
	// instead of console output i'm goin gto store it inside an array.
	char prefix[100]{};
	int j = 0;			// to keep variables being added to prefix.
	char string[100]{};

// 1. reverse the string
	int size = sizeOfArray(str);
	for (int i = 0 ; i < size; i++) {
		string[i] = str[(size-1)-i];
	} 
	string[size] = '\0';  // putting null at the end of the string , so that we know k yahan pae end houge.

	//cout << string << endl;
	
	// 2. will traverse through the whole array until we encounter '\0'
	for (int i = 0; string[i] != '\0'; i++) {
		
		// applying all the condition
		// simply push the operand onto the array
		if (string[i] >= 'A' && string[i] <= 'Z' || string[i] >= 'a' && string[i] <= 'z') {
			prefix[j++] = string[i];
		}
		


		// the rules for brackets will be inversed as we have rotated the array
		else if (string[i] == ')') {
			// simply push into stack
			a.push(string[i]);
		}
		else if (string[i] == '(') {
			// pop() all the operators until we approach ')' and store in prefix ,
			//also pop() that but donot store it in prefix
			while (a.top() != ')') {
				prefix[j++] = a.pop();
			}
			// when ')' is encounterd we will simply pop() it
			a.pop();
		}




		//	operators will be dealt in the same way except associativity  
		// the rules for precedence would remian the same
		// the only rule change will be for associativity , it would reverse because our string has also reversed.
		else if (string[i] == '^' || string[i] == '/' || string[i] == '*' || string[i] == '+' || string[i] == '-') {
			while(!a.isEmpty() && precedence(a.top())>=precedence(string[i]) ){
				if (precedence(a.top()) > precedence(string[i])) {
					prefix[j++] = a.pop();
				}
				else if (precedence(a.top()) == precedence(string[i])) {
					// associativity will reverse here
					// for left->right
					if (a.top() == '/' || a.top() == '*' || a.top() == '+' || a.top() == '-') {
						break;
					}
					else {
						prefix[j++] = a.pop();
					}
				}
				break;
			}
			a.push(string[i]);
		}


	}
	// after we've transversed through the complete loop , now we will empty up the stack..
	while (!a.isEmpty()) {
		prefix[j++] = a.pop();
	} prefix[j] = '\0';


	
	char final[100]{};
	for (int i = 0; i < j; i++) {
		final[i] = prefix[(j - 1) - i];
		//cout << "value being transferred is: " << prefix[(j - 1) - i]<<endl;
		//cout << "final value is: " << final[i] << endl;
	} final[j] = '\0';
	//cout << final << endl;

	cout << "infix: " << str << endl;
	cout << "prefix: " << final << endl;
	//cout << "after reversing correct anwser is:  " << final<< endl;
}

void postfixToInfix(const char* str) {
	
	myStack<string> a(20); // made a stack that could store 20 inside of it :)
	// the str contains characters , so before sending the single character we will have to convert it into a string.

	string second = "";
	string first = "";
	string complete = "";

	for (int i = 0; str[i] != '\0'; i++) {
		// if operand we would ----> push it onto stack
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
			a.push(string(1, str[i]));
			// will convert the char into a string and then it would push it
			// onto the stack ..
		}

		// if we encounter an operand---> we would pop() stack two times ----> thus bringing out the operators
		// we would store all in a string followed by brackets. and then push the whole onto the stack
		else if (str[i] >= '^' || str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-') {
			// pop() two times
			first = a.pop();
			second = a.pop();
			//string concatenation
			complete = "(" + second + string(1, str[i]) + first + ")";
			// push this complete string onto the stack
			a.push(complete);
		}

	}
	// after we've iterated through the whole array the last string would be the last element of the stack
	// we would pop and display it
	cout << "The infix expression : " << str << endl;
	cout << "The postfix expression : " << a.pop() << endl;
}


// converting a prefix equation to infix
void prefixToInfix(const char* str) {
	
	myStack<string> a(10);

	int size = sizeOfArray(str);
	
	string first = "";
	string second = "";
	string complete = "";

	
	for (int i = size - 1; i>=0 ; i--) {

		// if operand --->> push onto stack
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
			a.push(string(1 ,str[i]));
		}

		// if operator
		else if (str[i] >= '^' || str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-') {
			first = a.pop();
			second = a.pop();
			// string concatenation , achived through operator overloading
			complete = "(" + first + string(1, str[i]) + second + ")";
			a.push(complete);
		}
	}

	cout << "The prefix expression: " << str << endl;
	cout << "The infix expression : " << a.pop() << endl;
}
