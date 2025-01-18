// merging procedure -->> merging two sorted arrays into one single sorted array
// sorted array 1 + sorted array 2 = sorted array 3.... :)
#include<iostream>
using namespace std;

int* mergingProcedure(int* arr1, int* arr2, int m, int n) {

	int i, j, k;
	i = j = k = 0;
	cout << i << " " << j << " " << k << " " << endl;
	
	// initializing new array of m+n to store both the values.
	int* mergeSorted = new int[m + n]{};

	while (i < m && j < n) {
		cout << "here" << endl;
		// you have to also include the condition k agar barabar houjati hain values
		// tou us case mae kya krna hae , isliye i included <= so it knows k agar donou ki same
		// values hain tou arr1 wali kou send kr dou , or including else in the lower condition could
		// have dealt with this problemm but now atleast i know what's wrong in it :)
		if (arr1[i] <= arr2[j]) {
			mergeSorted[k] = arr1[i];
			k++;
			i++;
			cout << "if" << endl;
		}

		else if(arr1[i] > arr2[j]){
			mergeSorted[k] = arr2[j];
			k++; j++;
			cout << "else if" << endl;
		}
	}	

	// now two cases can take place either the arr1 is completed or the arr2 is completed put into the mergeSorted array
	while (i < m) {
		mergeSorted[k] = arr1[i];
		k++; i++;
	}

	while (j < n) {
		mergeSorted[k] = arr2[j];
		k++; j++;
	}


	cout << "here" << endl;
	return mergeSorted;
}



int main() {

	// two sorted arrays , now merge them into one single array that is also sorted.
	int arr1[5] = { 7,9,18,19,22 };
	int arr2[4] = { 1,6,9,11 };
	
	int* mergeSorted = mergingProcedure(arr1, arr2, sizeof(arr1) / sizeof(int), sizeof(arr2 )/ sizeof(int));
	int size = sizeof(arr1) / sizeof(int) + sizeof(arr2) / sizeof(int);






	for (int i = 0; i < size; i++) {
		cout << mergeSorted[i] << " ";
	}cout << endl;


	return 0;
}