//// finding the pivot in an sorted and rotated array
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int findingPivot(const vector<int>& arr) {
//	int start = 0;
//	int end = arr.size() - 1;
//	int mid = start + (end-start)/2;
//	while(start<end) {
//
//		// find out kidhr fall kr rhi hae on this first function or the second one
//		//falling on the higher function
//		if (arr[mid] >= arr[0]) {
//			start = mid + 1;
//		}
//		// falling on the lower function
//		else if (arr[mid] < arr[0]) {
//			end = mid;
//		}
//
//		mid = start + (end - start) / 2;
//	} 
//
//	return mid;
//}
//
//
//int main() {
//
//	vector<int> arr = { 3,7,9,1,2};
//	cout << "pivot at: " << findingPivot(arr);
//
//	return 0;
//}