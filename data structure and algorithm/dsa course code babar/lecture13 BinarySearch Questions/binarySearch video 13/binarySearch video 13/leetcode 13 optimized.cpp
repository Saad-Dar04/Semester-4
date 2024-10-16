//#include<iostream>
//using namespace std;
//#include<vector>
//#include<utility>
//
////vector<int> SearchRange(const vector<int> &arr , int target) {
//pair<int,int> SearchRange(const vector<int>& arr, int target) {
//
//	int start = 0;
//	int end = arr.size() - 1;
//	int mid = 0;
//	int ans = -1;
//	//vector<int> indicies;
//	pair<int, int> index;
//	// writing code for first/lest most occurence
//	while (start <= end) {
//		
//		mid = start + (end - start) / 2;
//
//		if (arr[mid] == target) {
//			ans = mid;
//			end = mid - 1;
//		}
//
//		else if (arr[mid] > target) {
//			end = mid - 1;
//		}
//
//		else if (arr[mid] < target) {
//			start = mid + 1;
//		}
//
//	}
//
//	//indicies.push_back(ans);
//	index.first = ans;
//
//	//writing code for the second/right most occurence
//	start = 0;
//	end = arr.size() - 1;
//	mid = 0;
//	ans = -1;
//	while (start <= end) {
//
//		mid = start + (end - start) / 2;
//
//		if (arr[mid] == target) {
//			// index stored and will try to search in the right area
//			ans = mid;
//			start = mid + 1;
//		}
//		
//		else if (arr[mid] > target) {
//			end = mid - 1;
//		}
//
//		else if (arr[mid] < target) {
//			start = mid + 1;
//		}
//
//	}
//	//indicies.push_back(ans);
//	index.second = ans;
//	return index;
//}
//
//
//int main() {
//		
//	vector<int> arr = { 0,2,2,2,2,2,2,2,2,2,2,2,2,3 };
//	pair<int,int> ans = SearchRange(arr , 2);
//	cout << "[" << ans.first << " , " << ans.second << "]" << endl;
//
//	return 0;
//}