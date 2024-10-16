//// intersection of two arrays using two pointer approach
//#include<iostream>
//#include<climits>
//#include<math.h>
//#include<vector>
//using namespace std;
//
//vector<int> intersection(int a[], int b[], int size1, int size2) {
//	vector<int> ans;
//	int i = 0; 
//	int j = 0; 
//	while (i < size1 && j < size2) {
//		if (a[i] == b[j]) {
//			ans.push_back(a[i]);
//			i++; 
//			j++;
//		}
//		else if (a[i] > b[j]) {
//			j++;
//		}
//		else if (a[i] < b[j]) {
//			i++;
//		}
//	}
//	return ans;
//}
//
//int main() {
//	vector<int> ans;
//	int a[6] = { 1,2,2,2,3,4 };
//	int b[4] = { 2,2,3,3 };
//	ans = intersection(a, b, 6, 4);
//	cout << "the common values are: " << endl;
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << " ";
//	} cout << endl;
//	return 0; 
//}