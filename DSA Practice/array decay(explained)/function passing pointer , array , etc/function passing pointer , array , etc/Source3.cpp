//#include <iostream>
//using namespace std;
//
//// Function that takes a pointer to a pointer and allocates memory
//void allocateMemory(int*& ptr) {
//
//    cout << "passed by reference so memory address of the ptr inside the funciton: " << &ptr << endl;
//    ptr = new int;  // Dynamically allocate memory
//    *ptr = 42;      // Assign a value to the allocated memory
//}
//
//int main() {
//    int* myPtr = nullptr;  // Declare a pointer and initialize it to nullptr
//
//    cout << "Before allocation: " << myPtr << endl; // Should output: 0 or NULL
//    cout << "memory address of the pointer: " << &myPtr << endl;
//
//    allocateMemory(myPtr);  // Pass the pointer to the function by reference
//
//    cout << "After allocation: " << myPtr << endl; // Should output the memory address
//    cout << "Value at allocated memory: " << *myPtr << endl; // Should output: 42
//
//    delete myPtr;  // Free the allocated memory
//
//    return 0;
//}
