//#include<iostream>
//using namespace std;
//
//template<typename t>
//t hammingWeight(unsigned int num) {
//	t count = 0; 
//	while (num != 0) {
//		if (num % 10) {
//			count++;
//		}
//		num /= 10; 
//	}
//	return count;
//}
//
//template <typename t>
//t rightShift(unsigned int num) {
//	t count = 0;
//	while (num != 0) {
//		if (num & 1) {
//			count++;
//		}
//		num = num >> 1;
//		cout << num << endl;
//	} 
//	return count ;
//}
//
//int main() {
//	
//	unsigned int a = 00000000000000000000000000001011;
//	cout << hammingWeight<int>(a);
//	
//	cout << a << endl;
//
//	cout << rightShift<unsigned int>(a);
//	
//	cout << a;
//
//	return 0;
//}