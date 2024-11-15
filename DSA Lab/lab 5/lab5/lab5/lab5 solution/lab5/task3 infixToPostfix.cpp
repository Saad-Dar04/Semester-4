#include"myStack.h"

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

// converts the char number to int value
int charToint(char a) {
	int temp = a - '0';
	return temp;
}

int calculator(int& num1, int& num2, char operation) {
	if (operation == '^') {
		return pow(num2, num1);
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


void infixToPrefix(const char* str) {

	// instantiating char type stack  , that would store characters insdie of size 10.
	myStack<char> a(10);
	// instead of console output i'm goin gto store it inside an array.
	char prefix[100]{};
	int j = 0;			// to keep variables being added to prefix.
	char string[100]{};

	// 1. reverse the string
	int size = sizeOfArray(str);
	for (int i = 0; i < size; i++) {
		string[i] = str[(size - 1) - i];
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
			while (!a.isEmpty() && precedence(a.top()) >= precedence(string[i])) {
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

int main() {

	int choice = 0;
	char str[100]{};
	cout << "Enter the infix equation: ";
	cin.getline(str, 99);
	infixToPrefix(str);
	system("pause");
	return 0;
}