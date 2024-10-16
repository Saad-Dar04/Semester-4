//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//vector<vector<int>> threeSum(vector<int> nums) {
//
//	vector<vector<int>> ans;
//	bool flag = 0;
//	sort(nums.begin(), nums.end());
//
//	for (int i = 0; i < nums.size(); i++) {
//		for (int j = i + 1; j < nums.size(); j++) {
//			for (int k = j + 1; k < nums.size(); k++) {
//				flag = 0 ;
//				vector<int> temp = { nums[i] , nums[j] , nums[k] };
//				
//				if (!ans.empty()) {
//					// instead of this i should make it go through the whole loop
//					/*if (ans.back()==temp) {
//						continue;
//					}*/
//					for (int i = 0; i < ans.size(); i++) {
//						if (ans[i] == temp) {
//							flag = 1;
//							break;
//						}
//					}
//
//				}
//
//				if (nums[i] + nums[j] + nums[k] == 0 && flag==0) {
//					ans.push_back(temp);
//				}
//			}
//		}
//	}
//	return ans;
//}
//
//
//int main() {
//	
//	vector<int> a{ -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
//	vector<vector<int>> ans = threeSum(a);
//
//	// displaying the double pointer
//	for (int i = 0; i < ans.size(); i++) {
//
//		for (int j = 0; j < ans[i].size(); j++) {
//
//			cout << ans[i][j] << "  ";
//		}cout << endl;
//	}
//
//
//	return 0;
//}