//// finding out if the array is sorted using recursion
//#include<iostream>
//using namespace std;
//
//bool isSorted(int* arr, int size) {
//	if (size == 0 || size == 1) {
//		return true;
//	}
//	
//	if (arr[0] > arr[1])
//		return false;
//	else {
//		return isSorted(arr + 1, size - 1);
//	}
//}
//
//
//
//int main() {
//
//	const int size = 5;
//	int arr[size] = { 1,2,3,3,3 };
//
//	if (isSorted(arr, size)) 
//		cout << "Array is sorted in ascending order" << endl;
//	
//	else
//		cout << "Array is not sorted" << endl;
//
//
//	return 0;
//}