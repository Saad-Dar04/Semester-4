#include"task1.h"

template <typename T>
class MyList : public List<T> {

protected:

public:
	// additional functionalities
	bool full() {
		// check whether we've reached the maxsize 
		if (List<T>::currentSize == List<T>::maxSize) 
			return 1;
		else
			return 0;

	}


	bool empty() {
		// checking whether the array is empty or not
		if (List<T>::currentSize == 0)
			return 1;
		else
			return 0;
	}

	int size() {
		// return the current size of the array
		return List<T>::currentSize;
	}

	bool insertAt(int index, T value) {
		// as index is mentione here , so i'm assuming this refers to the index starting from 0 and not from 1  :)
		if (index > (List<T>::maxSize - 1) || index < 0)
			return 0;
		else 
			List<T>::arr[index] = value;
			
		return 1;
	}

	T last() {
		// returns the last element of MyList
		return List<T>::arr[(List<T>::currentSize - 1)];
	}

	bool Search(T val){
		// using linear Search to transverse the entire array and find the required value
		for (int i = 0; i < List<T>::currentSize; i++) {
			if (val == List<T>::arr[i]) {
				return 1;
			}
		}
		return 0; 
	}

	// parameterized constructor with default arguments
	MyList(T* arr = nullptr, int maxSize = 0, int currentSize = 0) : List<T>(arr, maxSize, currentSize) {};
	
	// copy constructor of the above class , do we need to create the copy constructor , ye upar waley kou copy nhi kr lae ga???
	// the same one is being also used here so i guess dubara sae bananey ki zaroorat nhi hae
	// im making a copy constructor for now but would later on check if it would work w/o having this copy constructor here
	MyList(const T& obj) {
		
		List<T>::maxSize = obj.List<T>::maxSize;
		List<T>currentSize = obj.List<T>::currentSize;

		// dynamically allocating memory to the pointer of our new object
		List<T>::arr = new T[List<T>::maxSize]{};

		//copying all the elements into the new object
		for (int i = 0; i < List<T>::currentSize; i++) {
			List<T>::arr[i] = obj.List<T>::arr[i];
		}
	}

	// overriding pure virtual functions
	void addElementAtFirstIndex(T x) {
		List<T>::arr[List<T>::currentsize] = x;
		List<T>::currentsize++;
	}
	void addElementAtLastIndex(T x) {
		List<T>::arr[List<T>::maxsize-1] = x;
	}
	void removeElementFromStart() {
		List<T>::currentsize--;
	}

};