// binary to decimal
#include<iostream>
#include<math.h>
using namespace std;

int binaryToDecimal(int num) {
	int digit = 0;
	int decimal = 0;
	int i = 0;
	
	while (num > 0) {
		digit = num % 10; 
		decimal = (digit*pow(2,i++))+decimal;
		num /= 10;
	}
	return decimal;
}


int main() {

	int n = 0;
	cout << "enter the binary: ";
	cin >> n;
	cout << "the decimal is: " << binaryToDecimal(n) << endl;

	return 0;
}