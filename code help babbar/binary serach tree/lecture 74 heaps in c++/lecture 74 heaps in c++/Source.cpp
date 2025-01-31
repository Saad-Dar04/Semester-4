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

	void display() {
		for (int i = 1; i <= size; i++) {
			cout << arr[i] << " ";
		}cout << endl;
	}
};


int main() {

	heap muqaddas;
	muqaddas.insert(60);
	muqaddas.insert(50);
	muqaddas.insert(40);
	muqaddas.insert(30);
	muqaddas.insert(20);

	muqaddas.display();
	muqaddas.insert(55);
	muqaddas.display();

	muqaddas.insert(70);
	muqaddas.display();

	return 0;
}