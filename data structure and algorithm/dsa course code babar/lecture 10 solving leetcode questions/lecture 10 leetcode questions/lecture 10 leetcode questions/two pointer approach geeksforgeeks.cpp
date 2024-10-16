//#include<iostream>
//#include<vector>
//#include<climits>
//#include<math.h>
//#include<algorithm>
//using namespace std;
//
//
//vector<int> sum(int arr[], int size) {
//	vector<int> ans;
//	// using the introspective sort to sort the array
//	sort(arr, arr+size);
//	// using two pointer approach to solve it.
//	int i = 0; 
//	int j = size - 1;
//	int key = 70;
//	while (i != j) {
//		if (arr[i] + arr[j] == key) {
//			ans.push_back(arr[i]);
//			ans.push_back(arr[j]);
//			i++; j++;
//			break;
//		}
//		else if (arr[i] + arr[j] > key) {
//			j--;
//		}
//		else if (arr[i] + arr[j] < key) {
//			i++;
//		}
//	}
//	
//	return ans;
//}
//
//
//int main() {
//
//	vector<int> ans;
//	int arr[] = { 10,20,35,50,80 , 75 };
//	ans = sum(arr, 6);
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << "  ";
//	}cout << endl;
//	return 0;
//}