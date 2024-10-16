//// finding out the unique element in the array
//#include<iostream>
//using namespace std;
//
//int uniqueNumber(int* a , int size) {
//	int ans = 0;
//	for (int i = 0; i < size; i++) {
//		ans = a[i] ^ ans;
//	}
//	return ans;
//}
//
//int main() {
//	const int size = 7;
//	int a[size] = { 1,2,3,4,1,2,3 };
//	cout << uniqueNumber(a , size);
//
//	return 0;
//}