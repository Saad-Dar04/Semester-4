#include"myStack.h"
#include<string>

int main() {
	
	myStack<string> a(5);
	a.push("ali");
	a.display();
	a.pop();
	a.display();
	a.pop();
	a.pop();

	a.push("ali");
	a.push("saad");
	a.push("smas");
	a.push("ibrahim");
	a.push("muiz");

	a.display();
	cout << a.top();

	a.pop();
	a.display();
	cout << a.top();

	a.pop();
	a.display();
	cout << a.top();

	a.pop();
	a.display();
	cout << a.top();

	a.pop();
	a.display();
	cout << a.top();

	a.pop();
	a.pop();
	a.display();
	cout << a.top();

	return 0;
}