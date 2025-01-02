// binary search using recursion.. 
#include<iostream>
using namespace std;

void print(int* arr, int start, int end) {
	for (int i = start; i <= end; i++) {
		cout << arr[i] << "  ";
	}
}

// size function parameter is not required in this solution , you could do the complete
// task , blky you did w/o using  the size funciton parameter it's taking up precious space 
// on our ram we dont have, hamarey kaam houjaey ga w/o this function. ;)
bool binarySearch(int* arr, int size, int key, int start, int end) {
	
	print(arr, start, end);

	// base case 
	if (start > end) {
		return false;
	}

	int mid = (start + end) / 2;
	cout << "value of arr mid is: " << arr[mid] << endl;

	if (arr[mid] == key) {
		return true;
	}

	else if (arr[mid] > key) {
		cout << "arr[mid] > key" << endl;
		bool ans = binarySearch(arr, size, key, start , mid - 1);
		return ans;
	}

	else if (arr[mid] < key) {
		cout << "arr[mid] < key" << endl;
		bool ans = binarySearch(arr, size, key, mid + 1, end);
		return ans;
	}

}

int main() {
	
	int arr[5] = { 1 , 2 , 3 , 4, 5 };
	int start = 0;
	int end = 5 - 1;
	bool ans = binarySearch(arr, 5, 2, start , end);

	if (ans)
		cout << "found" << endl;
	else
		cout << "not found" << endl;

	return 0;
}