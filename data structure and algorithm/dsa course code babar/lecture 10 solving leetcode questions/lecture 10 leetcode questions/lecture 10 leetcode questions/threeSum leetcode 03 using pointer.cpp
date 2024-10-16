//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<math.h>
//#include<climits>
//using namespace std;
//
//bool goAhed(vector<vector<int>> ans, vector<int>temp) {
//	
//	for (int i = 0; i < ans.size(); i++) {
//		if (ans[i] == temp) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//vector<vector<int>> threeSum_pointer(vector<int> a) {
//	vector<vector<int>> ans;
//	// sorting the vector
//	sort(a.begin(), a.end());
//	int i = 0;
//	int j = a.size() - 1;
//	int k = j - 1;
//	bool flag = false;
//	
//	// trying to solve using three pointer apporach to counter the time limit exceeded wali khach khach.
//	while (i<j) {
//		vector<int> temp = { a[i] , a[k] , a[j] };
//		if (k > i && flag==0){
//			if (a[i] + a[k] + a[j] == 0 && goAhed(ans,temp)) {
//				ans.push_back(temp);
//			}
//			k--;
//		}
//
//		else if (k == i) {
//			i++;
//			k += 2;
//			flag = true;
//			
//		}
//
//		else if (k < j && flag == 1) {
//			vector<int> temp = { a[i] , a[k] , a[j] };
//			if (a[i] + a[k] + a[j] == 0 && goAhed(ans,temp)) {
//				ans.push_back(temp);
//			}
//			k++;
//		}
//
//		else if (k == j && flag == 1) {
//			flag = 0;
//			j--;
//			k -= 2;
//		}
//	}
//	return ans;
//}
//
//
//int main() {
//
//	vector<int> a{ -2,0,1,1,2 };
//	vector<vector<int>> ans = threeSum_pointer(a);
//
//	for (int i = 0; i < ans.size(); i++) {
//		for (int j = 0; j < ans[i].size(); j++) {
//			cout << ans[i][j] << " ";
//		}cout << endl;
//	}
//
//	return 0;
//}