#include "myStack.h"
#include<string>

template <typename T>
void infixToPostfix(const T& str) {
	// initializing a stack of size 10
	myStack<string> a(10);
	/*cout << str << endl;
	cout << size(str);*/
	// applying the algorithm for infix to postfix
	
	for (int i = 0; i < size(str); i++) {
		// if you find an operand console output
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
			cout << str[i];
		}

		//stringStack.push(string(1, 'a')); : Converts a character 'a' to a std::string and then pushes it.
		// if you encounter ( , push it onto stack
		else if (str[i] == '(') {
			
			// this is pushing a const char , which is an error because our template requires a string
			//a.push(')');
			
			// we could pass a string according to the above method or we could do is pass a string enclosed in double quotes ""
			a.push("(");
			
		}
		
		// if you encounter ) , console output all the operand until you encounter ( pop() it too but donot console output it..
		else if (str[i] == ')') {
			cout << a.pop();
			a.pop();
		}
		
		// if operands are encounterd
		// check the precedence of the operator residing in the stack , pop all the operators whose precedence is greater then the current operator and then push it
		else if (str[i] == '^' || str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-') {
			// push it onto stack
			a.push(string(1, str[i]));
		}
		
	}

	cout << endl;
	cout << endl;
}

int main() {

	
	// this function to be accepting a string.
	infixToPostfix<string>("((A*(B+C))/D)");
	// sir thought us only how to solve this if brackets are involved 
	// learn the precedence wala concept from nesoacademy(it has been expalined there in great detail ).
	return 0;
}