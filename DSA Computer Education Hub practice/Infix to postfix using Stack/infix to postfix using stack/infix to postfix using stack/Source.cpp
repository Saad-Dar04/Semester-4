#include"myStack.h"
 
int main() {

	myStack<const char*> a("((1+2)*(3-4))");
	//a.display();
	a.infix_to_postfix();
	//a.display();

	return 0;
}