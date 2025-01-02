//// finding the sum of an array using recursion
//#include<iostream>
//using namespace std;
//
//int findSum(int* arr, int size) {
//	// base case
//	if (size == 1) {
//		return arr[0];
//	}
//
//	int sum = arr[0] + findSum(arr + 1, size - 1);
//	return sum;
//}
//
//
//
//int main() {
//
//	const int size = 5;
//	int arr[size] = { 3,2,5,1,6 };
//	cout << "The sum of array is : " << findSum(arr, size);
//
//	return 0;
//}