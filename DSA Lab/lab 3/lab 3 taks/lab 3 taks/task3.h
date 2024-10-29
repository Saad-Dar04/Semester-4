#include"task2.h"


template <typename X>
class customlist :public MyList<X> {
	
	
	
	// parameterized constructor
	customlist(X* arr = nullptr, int a = 0, int b = 5) :MyList<X>(arr, a, b) {};
	

	
	// additional functionalities
	X sum_of_prime() {
		
		X sum = 0;
		
		for (int i = 0; i < MyList<X>::maxSize; i++) {
			
			for (int j = 2;; j++) {
				
				if (MyList<X>::arr[i] / j == 0)
					break;
			
			}
		
			sum += MyList<X>::arr[i];
		
		}
		
		return sum;
	}
	
	X secondmaxeven() {

		X max = MyList<X>::arr[0];
		
		X secondmax = 0;
		
		for (int j = 0; j < MyList<X>::maxSize; j++) {
		
			if (MyList<X>::arr[j] / 2 == 0) {
			
				for (int i = 0; i < j; i++) {
				
					if (max < MyList<X>::arr[j]) {
					
						secondmax = max;
						
						max = MyList<X>::arr[j];
					}
				}
			}
		}
		
		return secondmax;
	}
	
	X secondminodd() {
		
		X min = MyList<X>::arr[0];
		
		X secondmin = 0;
		
		for (int j = 0; j < MyList<X>::maxSize; j++) {
			
			if (MyList<X>::arr[j] / 2 != 0) {
				
				for (int i = 0; i < j; i++) {
					
					if (MyList<X>::arr[j] < min) {
						secondmin = min;
						min = MyList<X>::arr[j];
					}
				}
			}
		
		}
		
		return secondmin;
	
	}
	
	void printduplicates() {
		
		for (int i = 0; i < MyList<X>::maxsize; i++) {
			
			for (int j = i + 1; j < MyList<X>::maxsize; j++) {

				if (MyList<X>::arr[i] == MyList<X>::arr[j]) {

					cout << MyList<X>::arr[i] << "  ";

				}

			}
		}
	}
	
	void rotateClockwise(X arr[], X n, X r) {
	
		X mid = n / 2;

		rotatePart(arr, 0, mid - 1, r);

		// Rotate second half
		rotatePart(arr, mid, n - 1, r);
	
	}

	void rotatePart(X arr[], X start, X end, X r) {
		
		X length = end - start + 1;
		
		r = r % length; // Adjust r to avoid unnecessary rotations

		for (X i = 0; i < r; i++) {
			// Save the last element
			
			X last = arr[end];

			// Shift all elements in the range to the right
			
			for (X j = end; j > start; j--) {
			
				arr[j] = arr[j - 1];
			
			}

			
			arr[start] = last;
		
		}
	}

	void rotateantiClockwise(X arr[], X n, X r) {
	
		X mid = n / 2;

		
		rotateaPart(arr, 0, mid - 1, r);

		// Rotate second half
		
		rotateaPart(arr, mid, n - 1, r);
	
	}

	void rotateaPart(X arr[], X start, X end, X r) {
		
		X length = end - start + 1;
		
		r = r % length; // Adjust r to avoid unnecessary rotations


		
		for (X i = 0; i < r; i++) {
			// Save the last element
		
			X last = arr[end];

			// Shift all elements in the range to the left
			
			for (X j = start; j > end; j++) {
			
				arr[j] = arr[j + 1];
			}

			arr[end] = start;
		}
	}

};