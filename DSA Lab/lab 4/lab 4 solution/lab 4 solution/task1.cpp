#include "myStack.h"



int main() {
	
	myStack<int> a(5);
	a.push(10);
	stackOperations(a);
	return 0;
}