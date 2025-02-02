// max heap --> insertion done...
#include<iostream>
using namespace std;

class heap {
private:
	int* arr;
	int size;
public:
	heap() : size(0) {
		// dynamically memory allocated to array
		arr = new int[100]{};
	}

	void insert(int data) {
		// insert at last index
		
		// insert at last index
		size = size + 1;
		arr[size] = data;
		int index = size;
		
		// compare with parent until index reaches the top
		while (index > 1) {
			int parent = index / 2;
			// compare the child node with parent
			if (arr[parent] < arr[index]) {
				swap(arr[parent], arr[index]);
				// as it has swapped now we will
				index = parent;
			}
			
			// if the parent node is greater than the child node then come out of function
			else {
				return;
			}
		}
	}


	void deleteValue() {
		if (size == 0) {
			cout << "heap is empty " << endl;
			return;
		}

		// deletion would also be of the root node
		// if it is not empty
		// step 1 --> replace /swap root node with last node
		swap(arr[1], arr[size]);

		// step2 --> delete the last node , jidhr root node a chuka hae
		size--;

		// step3 --> propogate the now root node value to it's orignal position in the heap tree.
		int i = 1;
		// only continue if atleast one left node exists.. :)
		while (i*2 <= size) {
			
			int lindex = i * 2;
			int rindex = i * 2 + 1;
			int largest = i;

			// check with left
			// checking whether it is within bounds or whether this exists or not
			if (lindex <= size		&&	 arr[lindex] > arr[largest]) {
				largest = lindex;
			}

			if (rindex <= size && arr[rindex] > arr[largest]) {
				largest = rindex;
			}

			

			if (i == largest) {
				break;
			}

			swap(arr[i], arr[largest]);
			i = largest;

		}
	}	


	void display() {
		for (int i = 1; i <= size; i++) {
			cout << arr[i] << " ";
		}cout << endl;
	}
};

void maxHeapify(int* arr, int size, int i) {

	int leftIndex = i * 2;
	int rightIndex = i * 2 + 1;
	int largest = i;

	if (leftIndex <= size - 1 && arr[leftIndex] > arr[largest]) {
		largest = leftIndex;
	}

	if (rightIndex <= size - 1 && arr[rightIndex] > arr[largest]) {
		largest = rightIndex;
	}

	if (i == largest) {
		return;
	}

	swap(arr[i], arr[largest]);
	i = largest;
	maxHeapify(arr, size, i);
}

int main() {

	heap muqaddas;
	muqaddas.insert(50);
	muqaddas.insert(40);
	muqaddas.insert(30);
	muqaddas.insert(10);
	muqaddas.insert(5);

	muqaddas.display();
	muqaddas.insert(20);
	muqaddas.display();

	muqaddas.insert(15);
	muqaddas.display();

	muqaddas.deleteValue();
	muqaddas.display();

	// heapify is used to convert an array of any order into an 
	// heap either it could be of min or max order property
	// done using 1-base indexing.

	cout << endl << endl << endl;
	

	int arr[6] = {-1 , 54 , 53 , 55 , 52 , 50 };
	int size = 6;

	cout << "before heapify: " << endl;

	for (int i = 1; i <= size - 1; i++) {
		cout << arr[i] << " ";
	}cout << endl;


	for (int i = (size - 1)/2 ; i > 0; i--) {

		maxHeapify(arr, size, i);

	}

	cout << "after maxHeapify: " << endl;
	for (int i = 1; i <= size - 1; i++) {
		cout << arr[i] << " ";
	}cout << endl;

	return 0;
}