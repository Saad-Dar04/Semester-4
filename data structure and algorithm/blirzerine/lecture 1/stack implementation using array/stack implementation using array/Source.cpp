//implementation of stack using array.\
// learn implementation of array in sir ki slides , do that slide throughly.. to see k array kou oop k andar kaisay lae kr chalna hae
// i am well wersed with pointer , but i need to be learning more about how the arrays work.
// this can be used as an palindrone because jis trhan values andar jaati uski reverse bahir atti hain..
#include<iostream>
using namespace std;

// we can make global variable or use #define Size 3 to make the size of an array
#define SIZE 3
// const int SIZE = 3;

class Stack {
private:
	int pointer;
	// this will reserve an array of size which wil contain garbage values cus we didnt initliaze it
	int stack[SIZE]{};

public:
	// default parameterized constructor.
	Stack() : pointer(-1) {};

	bool isFull(){
		return pointer >= SIZE - 1; // 2 >= 3-1
	}
	
	bool isEmpty() {
		return pointer <= -1; // -1 <= -1
	}

	void push(int num) {
		if (!isFull()) {
			stack[++pointer] = num;
			cout << "you have pushed the value " << num << " at the index: " << pointer << endl;
		}
		else {
			cout << "the stack is full" << endl;
		}
	}

	int pop() {
		if (!isEmpty()) {
			// i am returning the value that is being popped , and post decrementing it so that it gets overridden.
			return stack[pointer--];
		}
		else {
			cout << "cannot pop because no elements inside the array" << endl;
			return 0;
		}
	}

	// the function of peek is to show the top most value inside the stack.
	int peek() {
		// we will only be able to peek agar stack is not empty otherwise there would be no elements and we will be trying to access memory that is not ours..
		if (!isEmpty()) {
			return stack[pointer];
		}
		else {
			cout << "no elements inside the array cannot peek" << endl;
			return 0;
		}
	}

};

//int main() {
//
//	Stack array;
//	// trying to peek when their are no elements in the array
//	array.pop();
//	array.peek();
//
//	// using push to push till the brim
//	int f = 1;
//	while (!array.isFull()) {
//		array.push(f++);
//		array.peek();
//	}
//
//	array.push(4);
//
//	int x = 0; 
//	while (!array.isEmpty()) {
//		x = array.pop();
//		cout << x << " has been popped from the stack" << endl;
//	}
//
//	array.pop();
//
//	return 0; 
//}
int main()
{
	Stack obj;
	obj.peek();
	obj.pop();

	int y = 1;
	while (!obj.isFull())
	{
		obj.push(y++);
	}

	int x = 0;
	while (!obj.isEmpty())
	{
		x = obj.pop();
		cout << x << endl;
	}

	system("pause");
	return 0;
}