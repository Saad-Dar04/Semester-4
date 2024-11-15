#include"myStack.h"

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
	cout << "The postfix expression is : " << ptr << endl;
	cout << "After postfix evaluation: " << a.pop() << endl;
}

int main() {

	int choice = 0;
	char str[100]{};
	cout << "Enter the postfix expression " << endl;
	cin.getline(str, 99);
	PostfixEvaluation(str);

	system("pause");
	return 0;
}