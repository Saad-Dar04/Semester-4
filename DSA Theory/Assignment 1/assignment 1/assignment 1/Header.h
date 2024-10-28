#include<iostream>
using namespace std;

template <typename t>
void insert(t* arr, t value, int index , int& size) {
	// checking if the index exists or not.
	if (index <= size) {
		// if index exists then update the value.
		arr[index] = value;
	}
	else {
		cout << "index doesnot exist." << endl;
	}
}

template <typename t >
void delete_index(t arr, int &size ,int index) {
	// checking if the index exists or not
	if (index <= size) {
		// we will j move all the elements in one direction and that element will be overriden
		// we will update the size of the array after deleting an element.
		for (int i = index; i <= size; i++) {
			cout << "doing" << endl;
			arr[i] = arr[i+ 1];
		}
		//this is not passed by reference so i need to send the size by reference in this case
		// is this variable passed by reference in this function?? and would updating it effect the actual variable??
		size--;
	}
	else {
		cout << "index doesnot exist" << endl;
	}
}

template<typename t>
void display(t* arr, int &size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}cout << endl;
}