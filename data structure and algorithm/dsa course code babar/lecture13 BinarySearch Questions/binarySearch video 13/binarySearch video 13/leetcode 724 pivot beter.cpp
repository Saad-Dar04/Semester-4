#include<iostream>
#include<vector>
#include<string>
using namespace std;

int pivotIndex(vector<int>& nums) {

	int totalSum = 0;
	int rightSum = 0;
	int leftSum = 0;
	for (int i = 0; i < nums.size(); i++) {
		totalSum += nums[i];
	}cout << "total sum is: " << totalSum << endl;
	
	rightSum = totalSum;

	for (int i = 0; i < nums.size(); i++) {
		cout << "pivot is: " << i << endl;
		leftSum = totalSum - rightSum;
		cout << "left sum is: " << leftSum << endl;
		rightSum = rightSum - nums[i];
		cout << "right sum is: " << rightSum << endl;

		if (leftSum == rightSum) {
			return i;
		}
		cout << endl << endl;
	}
	return -1;
}

int main() {
	
	vector<int> num = { 1,7,3,6,5,6 };
	cout << "pivot is: " << pivotIndex(num);


	return 0;
}