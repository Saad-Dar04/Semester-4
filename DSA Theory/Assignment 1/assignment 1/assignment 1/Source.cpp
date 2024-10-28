#include"Header.h"


int main() {
	
	int size = 9;
	int* arr = new int[size] {1, 4, 3, 8, 4, 9, 2, 5, 6};

	display(arr , size);

	//function to insert
	insert(arr, 10, 0, size);
	display(arr, size);

	cout << endl << endl << endl;
	//function to delete
	cout << size << endl;
	display(arr, size);
	delete_index(arr, size, 3);
	cout << size << endl;
	display(arr, size);
}