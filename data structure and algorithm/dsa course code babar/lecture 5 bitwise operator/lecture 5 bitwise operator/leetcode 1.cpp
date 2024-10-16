//#include<iostream>
//using namespace std;
//
//template <typename t>
//t func1(t num) {
//	t product = 1;
//	t sum = 0;
//	t difference = 0;
//	t remainder = 0;
//
//	while (num>0) {
//		remainder = num % 10;
//		product *= remainder;
//		sum += remainder;
//		num /= 10;
//	}
//	cout << product << endl;
//	cout << difference << endl;
//
//	difference = product - sum;
//
//	return difference;
//}
//
//int main() {
//
//	int a = 4421;
//	cout << func1<int>(a);
//
//	cout << endl;
//	cout << func1(705);
//
//
//	return 0;
//}