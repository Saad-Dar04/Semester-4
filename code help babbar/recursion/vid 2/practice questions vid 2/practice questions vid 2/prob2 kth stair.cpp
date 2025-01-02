//// problem 2 - number of ways to reach the kth stair...
//// see chatgpt for detailed solution anwser and understanding of how it works , notes attached.
//#include<iostream>
//using namespace std;
//
//int kthStair(int n) {
//	if (n < 0) {
//		return 0;
//	}
//	if (n == 0 || n == 1) {
//		return 1;
//	}
//	int ans = kthStair(n - 1) + kthStair(n - 2);
//	return ans;
//}
//
//int main() {
//	int n = 0;
//	cout << "Enter the Stair" << endl;
//	cin >> n;
//
//	cout << kthStair(n) << endl;
//
//
//	return 0;
//}