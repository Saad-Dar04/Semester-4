//// decimal to binary conversion.
//#include<iostream>
//#include<string>
//using namespace std;
//
//int decimalToBinary(int num) {
//	int anwser = 0;
//	int digit = 0;
//	int power = 1;
//
//	while (num != 0) {
//		digit = num % 2;
//		num /= 2;
//		anwser = (digit * power) + anwser;
//		power *= 10;
//	}
//	
//	return anwser;
//}
//
//int decimalToBinary_bitwiseOperator(int num) {
//	int power = 1;
//	int anwser = 0;
//	int bit = 0; 
//	while (num != 0) {
//		bit = num & 1;
//		anwser = (bit*power) + anwser;
//		
//		power *= 10;
//		// right shift 1 bit.
//		num = num >> 1;
//	}
//
//	return anwser;
//}
//
//int* decimalToBinary_byArray(int num , int &size) {
//	
//	int* temp = new int[1000]{};
//	while (num != 0) {
//		temp[size++] = num & 1;
//		num = num >> 1;
//	}
//	return temp; 
//}
//
//// implementing the same using strings..
//string decimalToBinary_byString(int num) {
//	
//	string anwser = "";
//	int bit = 0;
//
//	while (num != 0) {
//		bit = num & 1;
//		anwser = to_string(bit) + anwser;
//		// right shift by 1 bit.
//		num = num >> 1;
//	}
//	return anwser;
//}
//
//
//int main() {
//	
//	int size = 0;
//	int* arr  = decimalToBinary_byArray(999999999, size);
//	for (int i = size - 1; i >= 0; i--) {
//		cout << arr[i];
//	}cout << endl;
//	delete[] arr;
//
//	cout << decimalToBinary_byString(999999999)<<endl;
//	cout << "limit exceeded is liye we didnt get same anwser.. , details writtten in register that's why we made array and strings to store infinite number.." << endl;
//	cout << decimalToBinary(999999999) << endl;
//	cout << decimalToBinary_bitwiseOperator(999999999);
//	cout << endl;
//	cout << "trying out a number within their range" << endl;
//	cout << decimalToBinary(451)<<endl;
//	cout << decimalToBinary_bitwiseOperator(451)<<endl;
//
//	return 0;
//}