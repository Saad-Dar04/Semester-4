#include<iostream>
using namespace std;


// tale recursion to print the values in descending order.
void descending(int n) {
	// base case
	if (n == 0) {
		return;
	}

	// processing
	cout << n << " ";

	// recursive relation
	descending(n - 1);
}


void ascending(int n) {
	// base case
	if (n == 0) {
		return;
	}

	// recursive relation
	ascending(n - 1);

	//processing
	cout << n << " ";

}

int main() {

	int n = 0; 
	cout << "Enter a value :";
	cin >> n;


	descending(n);
	cout << endl;
	ascending(n);
	cout << endl;

	return 0;
}