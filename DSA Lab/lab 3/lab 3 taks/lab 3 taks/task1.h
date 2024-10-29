#include<iostream>
using namespace std;

template <typename Type>
class List {
protected:
	Type* arr;
	int maxSize;
	int currentSize;
public:
	// pure virtual funcitons
	virtual void addElementAtFirstIndex(Type) = 0;
	virtual void addElementAtLastIndex(Type) = 0;
	virtual Type removeElementFromEnd() = 0;
	virtual void removeElementFromStart() = 0;

	// parameterized constructor with default arguments
	List(Type* arr = nullptr, int maxSize = 0, int currentSize = 0) : maxSize(maxSize), currentSize(currentSize) {
		// dynamically allocating memory to arr pointer of maxSize according to Type data type
		arr = new Type[maxSize]{};
	}

	// copy constructor
	List(const Type& obj) {

		this->maxSize = obj.maxSize;
		this->currentSize = obj.currentSize;

		// dynamically allocating memory to the new pointer
		arr = new Type[maxSize]{};

		//copying all the elements into the new object
		for (int i = 0; i < currentSize; i++) {
			this->arr[i] = obj.arr[i];
		}
	}

	// destructor for above class
	~List(){
		// destroying the dynamically allocated memory pointed by the pointer arr ;)
		delete[] arr;
	}

};