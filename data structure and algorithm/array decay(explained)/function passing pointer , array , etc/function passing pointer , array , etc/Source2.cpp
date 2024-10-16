//#include<iostream>
//using namespace std;
//
//void func1(int* ptr, int size) {
//	cout << "now we are inside the function " << endl;
//	cout << "memory address of the pointer: " << &ptr << endl;
//	cout << "memory address of the value held by the pointer(that is of the array) :" << ptr << endl;
//	// now any manipulatin would be on the memory address that is held by the pointer and not on the pointer itself.
//	for (int i = 0; i < size; i++) {
//		*(ptr + i) = 100 + i;
//	}
//}
////int dynamicShit()
//
//void byvalueWalaPointer(int* ptr) {
//	cout << "now we are inside the function: " << endl;
//	cout << "memory address of the pointer: " << &ptr << endl;
//	cout << "memory adddress of the function that the pointer is pointing towards: " << endl;
//}
//
//void byreferencewalapointer(int*& ptr) {
//	cout << "now we are inside the function: " << endl;
//	cout << "memory address of the pointer: " << &ptr << endl;
//	cout << "memory adddress of the function that the pointer is pointing towards: "<< ptr << endl;
//	ptr = new int[10]{1,2,3,4,5,6,7,8,9};
//	cout << "memory address that it is pointing towards inside the function: " << ptr << endl;
//}
//
//int main() {
//
//	int a = 10;
//	cout << "memory address of variable a is: " << &a << endl;
//	
//	int* ptr = &a;
//	cout << "memory address of variable a is: " << ptr << endl;
//	cout << "memory address of the pointer is: " << &ptr << endl;
//	cout << "dereferencing the pointer: " << *ptr << endl;
//
//	cout << endl << endl;
//	int** storing_pointer = &ptr;
//	cout << "memory address of pointer is: " << storing_pointer << endl;
//	cout << "memory address of a is: " << *storing_pointer << endl;
//	cout << "value of a is: " << **storing_pointer << endl;
//
//
//	cout << endl << endl << endl;
//	int arr[10]{ 1,2,3,4,5,6,7,8,9 };
//	cout << "memory address of array 0th index: " << arr << endl;
//	func1(arr, sizeof(arr) / sizeof(int));
//	for (int i = 0; i < 10; i++) { cout << arr[i] << "  "; }; cout << endl;
//
//	cout << endl << endl << endl;
//	// but if we want to bring some change in the pointer itself then we would have to pass by reference..
//	// if i want k function k andar dynamic allocation krwaoun on a pointer jou k main k andar parra hoa hou tou wou kis trhan krein ge
//
//	int* referenceWalaPointer = nullptr;
//	cout << "memory address of the reference wala pointer: " << &referenceWalaPointer << endl;
//	cout << "memory address that the reference wala pointer is holding/pointing towards: " << referenceWalaPointer << endl;
//	// ab mae ye chahta houn k ye same pointer function k andar jaey aur wahan pae dynamic memory le jaey aur wou us dynamic memory ki trf point krna shur kr de
//	
//	// what if we pass the pointer by value?? phir kya msla aye ga??
//	byvalueWalaPointer(referenceWalaPointer);
//
//	cout << endl << endl << endl;
//	cout << "memory address of the reference wala pointer: " << &referenceWalaPointer << endl;
//	byreferencewalapointer(referenceWalaPointer);
//
//	cout << "memory that it is now pointing towards after the dynamic alloation: " << referenceWalaPointer<< endl;
//	for (int i = 0; i < 10; i++) {
//		cout << referenceWalaPointer[i] << endl;
//	}
//	
//
//	return 0;
//}