#include<iostream>
#include<vector>
using namespace std;

int upperPivot(const vector<int>& nums) {
	cout << "upper pivot" << endl;
	int start = 0; 
	int end = nums.size() - 1;
	int mid = start + (end - start) / 2;
	cout << "start is: " << start << endl;
	cout << "end is: " << end << endl;
	cout << "mid is: " << mid << endl;


	while (start < end) {
		
		mid = start + (end - start) / 2;
		if (nums[mid] > nums[nums.size()-1]) {
			end = mid - 1;
		}

		else if (nums[mid] < nums[nums.size() - 1]) {
			start = mid;
		}

	}

	cout << "mid is : " << endl;
	return mid;
}

int lowerPivot(const vector<int>& nums) {
	cout << "lower pivot" << endl;
	int start = 0;
	int end = nums.size() - 1;
	int mid = start + (end - start) / 2;

	while (start < end) {
		// mid falls in upper half
		if (nums[mid] >= nums[0]) {
			start = mid +1;
		}

		else if (nums[mid] < nums[0]) {
			end = mid;
		}

		mid = start + (end - start) / 2;
	}

	cout << "returning mid" << endl;
	return mid;


}

bool isPivoted(const vector<int>& nums) {
	
	// all the numbers are distinct.
	if (nums[0] > nums[nums.size() - 1]) {
		return 1;
	}
	
	

	return 0;
}

// binary search karey ga and if it find the value it returns the index otherwise it returns -1.
int BinarySearch(const vector<int>& nums, int& target , int start , int end) {
	
	cout << "went inside the binary search" << endl;
	cout << "start is" << start << endl;
	cout << "end is" << end  << endl;
	int mid = start + (end - start) / 2;
	cout << "mid is" << mid << endl;
	cout << "target is: " << target << endl;
	while (start <= end) {
		
		if (nums[mid] == target) {
			return mid;
		}

		if (nums[mid] > target) {
			end = mid - 1;
		}

		else if (nums[mid] < target) {
			start = mid + 1; 
		}

		mid = start + (end - start) / 2;
	}
	// if not found.
	return -1;
}


int search(vector<int>& nums, int target) {
	// jb andar wali condition ki value tab houge tb hi wou statement k andar jaey ga.
	int ans = 0;

	if (isPivoted(nums)) {
		cout << "array is pivoted" << endl;
		// if it lies in the upper half/first function / upper pivot find out krou
		if (target >= nums[0]) {
			// end wali value will be updated
			cout << "going in upper pivot" << endl;
			int end = upperPivot(nums);
			ans = BinarySearch(nums, target, 0, end);
			return ans;
		}

		else if (target < nums[0]) {
			// start wali value will be updated
			cout << "going in lower pivot" << endl;
			cout << "target is smaller than nums[0]" << endl;
			int start = lowerPivot(nums);
			cout << "start has been returned and it is: " << start << endl;
			ans = BinarySearch(nums, target, start, (nums.size() - 1));
			return ans;
		}

	}

	else  {
		cout << "the array is not pivoted" << endl;
		ans = BinarySearch(nums, target, 0, (nums.size() - 1));
		return ans;
	}

	
}

int main() {

	vector<int> arr = { 3,1 };
	cout << "the target is located at the index: " << search(arr, 1);

	return 0;
}