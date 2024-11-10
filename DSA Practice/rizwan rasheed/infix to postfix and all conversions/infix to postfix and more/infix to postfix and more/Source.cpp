#include "myStack.h"
#include"String"
int main() {

	//// instead of console output i could also store it inside an array aur phir end pae us array kou cout krwao dou ..

	//cout << endl << endl << endl;
	//
	//// converting a char
	//char a = '9';
	//// subtracting the ascii value of 9(57) by the ascii value of 0(48) gives us the int value 9
	//cout << a - '0' << endl;
	//cout << a - 10 << endl;

	//cout << endl << endl << endl;
	//cout << endl << endl << endl;
	

	infixToPostfix("A*(B+C)/D");
	infixToPrefix("A*(B+C)/D");
	PostfixEvaluation("753*51^/+32-+");
	postfixToInfix("ab+ef/*");
	prefixToInfix("*+ab/ef");

	system("pause");
	return 0;
}