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

void infixToPostfix(const char* ptr) {
	// stack ka datatype would be decided considering k kis trhan ka data hum nae stack k andar rkhwana hae
	// in this case hum nae char type rkhwana tha , isliye char banaya hae... :)
	// making a new object to store the stack
	myStack<char> a(10);
	cout << "infix: " << ptr << endl;
	cout << "postfix: ";
	//cout << size(ptr) << endl;   //3
	for (int i = 0; ptr[i] != '\0'; i++) {

		// if we encounter '(' just push it into the stack
		if (ptr[i] == '(') {
			a.push(ptr[i]);
		}

		// if we encounter an operand we would simply console output it or 
		// store it in an array according to our requirement.
		else if (ptr[i] >= 'A' && ptr[i] <= 'Z' || ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i]>='1' || ptr[i]<='9') {
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

int main() {

	int choice = 0;
	char str[100]{};
	infixToPostfix("A*(B+C)/D");

	system("pause");
	return 0;
}