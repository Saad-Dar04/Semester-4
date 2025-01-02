#include<iostream>
#include<string>
using namespace std;

void sayDigit(int n, string*  alphabet) {
	
	// base case
	if (n == 0) {
		return; 
	}

	int digit = n % 10;
	// recursive relation
	sayDigit(n / 10, alphabet);


	// processing/output
	cout << alphabet[digit] << " ";
}

int main() {

	string alphabet[10] = { "zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"};
	
	int n = 0;
	cout << "Enter the digit to spell out : ";
	cin >> n;

	sayDigit(n , alphabet);

	return 0;

}