//#include<iostream>
//#include<vector>
//using namespace std;
//
//bool sumEqual(const vector<int>& nums, int pivot) {
//
//	int sumleft = 0;
//	int sumright = 0;
//	cout << "pivot is: " << pivot << endl;
//	//sum to the right is being calculated
//	for (int i = pivot + 1; i < nums.size() ; i++) {
//		sumright += nums[i];
//	}
//	cout << "right sum is: " << sumright << endl;
//
//	for (int i = pivot - 1; i >= 0; i--) {
//		sumleft += nums[i];
//	}
//	cout << "left sum is: " << sumleft << endl;
//
//	if (sumleft == sumright) { return 1; }
//	cout << endl << endl << endl << endl;
//	return 0;
//}
//
//int pivotIndex(vector<int>& nums) {
//	
//	for (int i = 0; i < nums.size(); i++) {
//
//		if (sumEqual(nums, i) ) {
//			return i;
//		}
//
//	}
//	return 0;
//}
//
//
//
//int main() {
//
//	vector<int> nums = { 1,2,3 };
//	cout << "the pivot index is: " << pivotIndex(nums);
//
//	return 0;
//}