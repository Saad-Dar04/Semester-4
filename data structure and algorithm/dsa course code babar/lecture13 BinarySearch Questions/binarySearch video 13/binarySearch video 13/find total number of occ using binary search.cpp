////find total number of occurences in an  habing time complexity O(log n)
//#include<iostream>
//#include<vector>
//#include<utility>
//using namespace std;
//
////finding the left most occurence ka index.
//int firstOccurence(vector<int> arr, int key) {
//	//assuming the array is sorted.
//	int start = 0;
//	int end = arr.size() - 1;
//	int mid = 0;
//	int ans = -1;
//	while (start <= end) {
//
//		mid = start + (end - start) / 2;
//		
//
//		if (arr[mid] == key) {
//			ans = mid;
//			end = mid - 1;
//		}
//
//		else if (arr[mid] > key) {
//			end = mid - 1;
//		}
//
//		else if (arr[mid] < key) {
//			start = mid + 1;
//		}
//	}
//	return ans;
//}
//
//int lastOccurence(vector<int> arr, int key) {
//
//	int start = 0;
//	int end = arr.size() - 1;
//	int mid = 0;
//	int ans = -1;
//	while (start <= end) {
//
//		mid = start + (end - start) / 2;
//		cout << mid << endl;
//
//		if (arr[mid] == key) {
//			ans = mid;
//			start = mid + 1;
//		}
//
//		else if (arr[mid] > key) {
//			end = mid - 1;
//		}
//
//		else if (arr[mid] < key) {
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
//	vector<int> arr = { 0,1,1,2,2,2,2,2,2,2,2,3,3,3,3 };
//	pair<int, int> p;
//	p.first = firstOccurence(arr, 2);
//	p.second = lastOccurence(arr, 2);
//	cout << "[" << p.first << " , " << p.second << "]" << endl;
//	cout << "total number of occurences are: " << (p.second - p.first)+1 << endl;
//
//
//	return 0;
//}