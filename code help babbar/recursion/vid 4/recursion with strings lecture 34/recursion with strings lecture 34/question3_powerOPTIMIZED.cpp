//#include<iostream>
//using namespace std;
//
//int powerRecursion(int& a , int b) {
//	// base case
//	if (b == 0) {
//		return 1;
//	}
//	
//	// if even
//	if (b % 2 == 0) {
//		int ans = powerRecursion(a, b / 2) * powerRecursion(a, b / 2);
//		return ans;
//	}
//	// if odd
//	else if (b % 2 != 0) {
//		int ans = a * powerRecursion(a, b / 2) * powerRecursion(a, b / 2);
//		return ans;
//	}
//
//}
//
//// the same using loop
//int powerLoop(int a , int b) {
//
//	for (int i = 0; i < b; i++) {
//
//	}
//}
//
//int main() {
//
//	int a = 3, b = 2;
//	cout << "using recursion optimized method: " << powerRecursion(a, b);
//	cout << "using loop optimized method: " << powerLoop(a, b);
//	return 0;
//}