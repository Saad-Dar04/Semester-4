//// peak index in mountain array
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int peakIndexInMountainArray(vector<int>& arr) {
//
//	// using binary search to find out peak index
//	// array are sorted
//	int start = 0;
//	int end = arr.size() - 1;
//	int mid = 0;
//	int ans = 0;
//	while (start <= end) {
//		mid = start + (end - start) / 2;
//		if (arr[mid] > arr[mid + 1]) {
//			ans = mid;
//			end = mid - 1;
//		}
//		else if (arr[mid] < arr[mid + 1]) {
//			start = mid + 1;
//		}
//	}
//	return ans;
//}
//
//
//
//int main() {
//
//	vector<int> arr = { 0,10,5,2 };
//	cout << "peak index is: " << peakIndexInMountainArray(arr);
//
//
//	return 0;
//}