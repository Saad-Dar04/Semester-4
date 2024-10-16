//#include<Iostream>
//using namespace std;
//
////           int* arr  both are the same over here..
//void display(int arr[], int size = 0) {
//	cout << "memory address of the array: " << arr << endl;
//	cout << "memory address of the array itself: " << &arr << endl;
//	// both have different cus of array decay this int arr[] is actually
//	// an pointer that points towards the first element of the array
//	// that is why it is having a seperate memory address location..
//}
//
//int main() {
//
//	int arr[5]{ 1,2,3,4,5 };
//	cout << "memory address of the array: " << arr << endl;
//	cout << &arr << endl;
//	display(arr, sizeof(arr) / sizeof(int));
//
//	return 0;
//}