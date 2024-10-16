//#include<iostream>
//#include<vector>
//#include<math.h>
//#include<climits>
//#include<algorithm>
//using namespace std;
//
//vector<vector<int>> PairSum(int arr[], int size) {
//	// sorting the array
//	sort(arr, arr + size);
//	// using two pointer approach to solve this problem
//	int i = 0, j = size-1;
//	vector<vector<int>> ans;
//
//	while (i < j) {
//		
//		if (arr[i] + arr[j] == 0) {
//			vector<int> temp;
//			temp.push_back(max(arr[i], arr[j]));
//			temp.push_back(min(arr[i], arr[j]));
//			ans.push_back(temp);
//			for (int i = 0; i < 2; i++) {
//				cout << temp[i] << "  ";
//			}cout << endl;
//			// not the right thing to do bss aik qism ka jugaad hi lagaya hae.. :)
//			j--;
//		}
//		else if (arr[i] + arr[j] > 0) {
//			j--;
//			cout << "less than" << endl;
//		}
//		else if (arr[i] + arr[j] < 0) {
//			i++;
//			cout << "higher than" << endl;
//		}
//		
//	}
//	return ans;
//}
//
//
//int main() {
//	
//	int arr[5] = { -2,-3,3,3,2 };
//	// just like 2D array that is pointing towards other pointers.
//	// this is a vector that is pointing towards other vector<int> type that are holding values.
//	vector< vector<int> > ans;
//	ans = PairSum(arr, 5);
//	//displaying the 2D vector
//	cout << endl << endl << endl;
//	cout << "printing outside the loop: " << endl;
//	for (int i = 0; i < ans.size(); i++) {
//		for (int j = 0; j < ans[i].size(); j++) {
//			cout << ans[i][j];
//		}cout << endl;
//	}
//
//	return 0;
//}