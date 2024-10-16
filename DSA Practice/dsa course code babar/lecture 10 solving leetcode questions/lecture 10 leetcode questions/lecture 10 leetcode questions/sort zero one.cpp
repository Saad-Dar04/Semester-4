#include<iostream>
using namespace std;

// sorting using two pointer approach , by iteration through the loop only once..
void sort_0_1_(int* arr, int size) {
	int i = 0;
	int j = size - 1;
	while (i < j) {
		cout << "looping through" << endl;
		if		(arr[i] == 0 && arr[j] == 1) { i++; j--; }
		else if (arr[i] == 1 && arr[j] == 0) { swap(arr[i], arr[j]); }
		else if (arr[i] == 0 && arr[j] == 0) { i++; }
		else if (arr[i] == 1 && arr[j] == 1) { j--; }
	}

}

int main() {
	
	
	int arr[] = { 1,1,0,0,0,0,1,0 };
	sort_0_1_(arr, sizeof(arr) / sizeof(arr[0]));
	
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << arr[i] << "  ";
	}cout << endl;

	system("pause");
	return  0;
}