//#include<iostream>
//using namespace std;
//
//void func1(int arr[]) {
//	cout << "memory address inside the function: " << arr << endl;
//}
//
//void func2(int arr[]) {
//	// this tells the size of the base address only.
//	cout << "size of arr inside the function: " ;
//	int arrSize = sizeof(arr);
//	cout << arrSize << endl;
//}
//
//void mainpulateFunc(int arr[], int size) {
//	cout << "memory address inside the maniupulate function: " << arr << endl;
//	for (int i = 0; i < size; i++) {
//		*(arr + i) = 100 + i;
//	}
//	cout << "manipulated: " << endl;
//}
//
//int*  stackArray() {
//	// making an array on stack and returning it to the main function.
//	int arr[5] = { 1,2,3,4,5 };
//	 return arr;
// }
//
//int* heapArray(int &size) {
//	size = 10;
//	int* arr = new int[size]{};
//	return arr;
//}
//
//int main() {
//
//	int arr[10]{};
//	cout << "the arr is called the base address and it shows the address of the 0th index: " << arr << endl;
//	for (int i = 0; i < 10; i++) {
//		*(arr + i) = i;
//	}
//
//	// the name of the array is also called the base address..
//	func1(arr);
//
//
//	// inside the main function it tells us the size of the complete array , thats why we need to send the size along with it , cus inside the funciton
//	// the compiler doesnot know what is the size of the complete array..
//	cout << "size of arr function in the main function: ";
//	int size = sizeof(arr);
//	cout << size << endl;
//	func2(arr);
//
//	// array is passed by reference cus we are sending it's memory address aur us memory address kou lae kr manipulation hou rhi
//	// tou anything manipulated inside the function would also show up inside the main as well..
//	cout << endl << endl << endl;
//	cout << "memory address outside the manipulate func: " << arr << endl;
//	mainpulateFunc(arr, sizeof(arr) / sizeof(int));
//	cout << "loop iteration after the manipulation: " << endl;
//	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
//		cout << arr[i] << "  ";
//	}
//
//	// making an static array(on stack) inside the func and trying to access that memory location in the main() wont work cus stack scope honay k baad 
//	// khtm houjata hae where as on the other hand the heap stays forever..
//	cout << endl << endl << endl;
//	cout << "trying to access stack wali array: " << endl;
//	int* lala = stackArray();
//	for (int i = 0; i < 5; i++) {
//		cout << lala[i] << "    ";
//	}
//	cout << endl << endl << endl << endl;
//
//
//
//
//	// it's showing garbage value cus wou wali memory address pae garbage values agai hain..
//	cout << "heap wali array: " << endl;
//	int sizeoflala = 0;
//	lala = heapArray(sizeoflala);
//	cout << "size in the main function is: " << sizeoflala << endl;
//	for (int i = 0; i < sizeoflala; i++) {
//		cout << lala[i] << "   ";
//	}
//	cout << endl << endl << endl;
//
//	int dost[10]{};
//	cout << dost << endl;
//	cout << &dost << endl;
//
//	return 0;
//}