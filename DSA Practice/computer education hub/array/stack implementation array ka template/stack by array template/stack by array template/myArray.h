#include"Array.h"

template<typename t>
class myArray : public Array<t> {
	// no data members of this class all will be inherited
public:
	myArray(int);
	bool isFull();
	bool isEmpty();
	void addValue(t val);
	t removeValue();
	void display();
	t peek();
};

template<typename t>
myArray<t>::myArray(int val) : Array<t>(val) {};

template<typename t>
bool myArray<t>::isFull() {
	// because myArray is inheriting data member , tou jb templates
	// use kr rhy houtay hain tou we have to write the 
	return Array<t>::currentSize == Array<t>::maxSize;
}

template<typename t>
bool myArray<t>::isEmpty() {
	return Array<t>::currentSize == 0;
}

template<typename t>
void myArray<t>::addValue(t val) {
	if (!isFull()) {
		// post increment 0 pae add houga and then it will increment to 1 , next value will add up
		Array<t>::arr[Array<t>::currentSize++] = val;
	}
	else {
		cout << "stack is full." << endl;
	}
}

template <typename t>
t myArray<t>::removeValue() {
	if (!isEmpty()) {
		Array<t>::currentSize--;
		return Array<t>::arr[Array<t>::currentSize];
	}
	else {
		cout << "stakc is empty" << endl;
		return NULL;
	}
}

template <typename t>
void myArray<t>::display() {
	cout << "max size: " << Array<t>::maxSize << endl;
	cout << "current size: " << Array<t>::currentSize << endl;
	for (int i = 0; i < Array<t>::currentSize; i++) {
		cout << Array<t>::arr[i] << " ";
	}cout << endl;
}

template <typename t>
t myArray<t>::peek() {
	if (!isEmpty()) {
		myArray<t>::currentSize--;
		return myArray::arr[myArray<t>::currentSize++];
	}
	else {
		cout << "stack is empty" << endl;
		return NULL;
	}
}