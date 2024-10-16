//binary search implementation
// array should be sorted in either increasing or decreasing order in order to use the binarySearch
// 0(lon n) time complexity , space complexity O(1)
#include<iostream>
#include<climits>
using namespace std;

// non type template paramter
// when passing the arrays by reference they rembeber their size
// function template by doing this function k andar seperately size of array kou send krny ki zaroorat nhi parey ge;)
template <typename t , int size>
int BinarySearch(t (&arr)[size] , t key) {
	
	int start = 0;
	int end = size - 1;
	int mid = 0;
	cout << "start is : " << start << endl;
	cout << "end is : " << end << endl;
	cout << "mid is : " << mid<< endl;


	while (start <= end) {
		
		mid = (start + end) / 2;
		cout << "mid is : " << mid << endl;
		
		if (key == arr[mid]) { return mid; }

		else {
			// part selection

			// if key is greater than mid wali value then right waley part ki selection
			if (key > arr[mid]) {
				start = mid + 1;
				end = end;
				cout << "start is : " << start << endl;
				cout << "end is : " << end << endl;
			}

			// if key is smaller tou left part kou select krna hae.
			else if (key < arr[mid]){
				start = start;
				end = mid - 1;
				cout << "start is : " << start << endl;
				cout << "end is : " << end << endl;
			}

		}
	}
	// minimum value that an integer can store inside it for signed integers which is 2^-31.
	return INT_MIN;
}


int main() {

	int arr1[] = { 1,2,3,6,9,11 };
	int index = 0;
	index = BinarySearch(arr1, 1);
	if (index == INT_MIN) { cout << "value not found" << endl; }
	else {
		cout << "value found at index: " << index << "  , the value is: " << arr1[index] << endl;
	}

	cout << endl << endl << endl << endl;

	// trying for float type
	// the problem that i was having was that function k andar key kou int type declare kiya hoa tha isliye wou 10.11 kou as 10 store kr rha tha that's why key was'nt matching...
	double arr2[] = { 1.1 , 2.34 , 4.45 , 10.11 };
	 index = 0;
	index = BinarySearch(arr2, 10.11);
	if (index == INT_MIN) { cout << "value not found" << endl; }
	else {
		cout << "value found at index: " << index << "  , the value is: " << arr1[index] << endl;
	}


	return 0;
}