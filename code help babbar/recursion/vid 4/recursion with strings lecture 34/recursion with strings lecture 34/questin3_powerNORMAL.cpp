//#include<iostream>
//using namespace std;
//
//// normal approach using recursion
//int powerRecursion(int a, int b) {
//	// base case 
//	if (b == 0) {
//		return 1;
//	}
//
//	return a * powerRecursion(a, b - 1);
//}
//
//// normal apporach using loop
//int powerLoop(int a, int b) {
//	int ans = 1;
//	for (int i = 0; i < b; i++) {
//		ans *= a;
//	}
//	return ans;
//}
//
//int main() {
//	
//	int a = 3, b = 3;
//	cout << "using recursion ";
//	cout << a << "^" << b << " = " << powerRecursion(a, b);
//	cout << endl;
//	
//	cout << "using loop " << a << "^" << b << " = " << powerLoop(a, b);
//
//	return 0;
//}