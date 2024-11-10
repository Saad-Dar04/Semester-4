#include "myStack.h"
#include"String"
int main() {

	int choice = 0;
	char str[100]{};
	
	while (1) {
							cout << "\t\t\t\tMenu\t\t\t\t" << endl;
		cout << "Press 1 ->Infix to Postfix Conversion" << endl;
		cout << "Press 2 ->Infix to Prefix Conversion" << endl;
		cout << "Press 3 -> Postfix Evaluation" << endl;
		cout << "Press 4 -> Postfix to Infix Conversion" << endl;
		cout << "Press 5 -> Prefix to Infix Conversion" << endl;
		cout << "Press anyother button to terminate the program" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		cout << "enter the equation: " << endl;
		cin.getline(str, 99);
		

		if (choice == 1) {
			infixToPostfix(str);
		}
		else if (choice == 2) {
			infixToPrefix(str);
		}
		else if (choice == 3) {
			PostfixEvaluation(str);
		}
		else if (choice == 4) {
			postfixToInfix(str);
		}
		else if (choice == 5) {
			prefixToInfix(str);
		}
		else {
			break;
		}

		cout << endl << endl << endl << endl;
		loopback();
	}
	

	infixToPostfix("A*(B+C)/D");
	infixToPrefix("A*(B+C)/D");
	PostfixEvaluation("753*51^/+32-+");
	postfixToInfix("ab+ef/*");
	prefixToInfix("*+ab/ef");

	system("pause");
	return 0;
}