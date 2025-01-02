//#include<iostream>
//using namespace std;
//
//int pow(int number) {
//	
//	// base case --- >> 2^0 = 1;
//	if (number == 0) {
//		return 1;
//	}
//	
//	/*int smallerProb = pow(number - 1);
//	int biggerProb = 2 * smallerProb;
//	return biggerProb;*/
//
//	return 2 * pow(number - 1);
//}
//
//
//int main() {
//
//	int number = 0;
//	
//	cout << "FINDING OUT THE POWER OF 2" << endl;
//	cout << "Enter number : ";
//	cin >> number;
//	cout << "2^" << number << " = " << pow(number) << endl;
//
//	return 0;
//}