#include"myStack.h"
#include<string>

int main() {
	
	myStack<string> a(5);
	a.isFull();
	a.isEmpty();
	//a.pop();
	a.push("aloo");
	a.display();
	a.pop();
	a.display();
	
	return 0;
}