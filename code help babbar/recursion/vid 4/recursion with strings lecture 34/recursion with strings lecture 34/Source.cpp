#include<iostream>
using namespace std;

void bubbleSort(int* arr, int size, int n) {
	
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}cout << endl;
	
	// base case
	if (n == size-1){
		return;
	}

	// one case move the element to first position
	for (int i = n+1; i < size; i++) {
		if (arr[n] > arr[i]) {
			swap(arr[n], arr[i]);
		}
	}

	bubbleSort(arr, size, n + 1);
}


void bobaSort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	} cout << endl;


	// base case
	if (size == 0 || size == 1) {
		return;
	}

	// aik case solve krein ge , pooncha jaein de elemet to the right most part
	for (int i = 0; i < size; i++) {
		if (arr[i] > arr[size - 1]) {
			swap(arr[i], arr[size - 1]);
		}
	}

	// phir recursion kou call kr dou
	bobaSort(arr, size - 1);
}


int main() {

	int a[5] = { 2,5,1,6,9 };
	bobaSort(a, 5);
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}cout << endl;



	

	return 0;
}