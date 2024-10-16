//#include<iostream>
//using namespace std;
//#include<vector>
//
//vector<vector<int>> TripletSum(vector<int>& a, vector<int>& b, vector<int>& c) {
//	
//	vector<vector<int>> ans;
//	for(int i = 0 ; i < a.size(); i++)
//		for (int j = 0; j < b.size(); j++) {
//			for (int k = 0; k < c.size(); k++) {
//				if (a[i] + b[i] + c[i] == 1) {
//					
//					vector<int> temp = { a[i] , b[i] , c[i] };
//					
//					if (!ans.empty()) {
//						if (ans.back() == temp)  {
//							continue;
//						}
//					}
//
//					ans.push_back(temp);
//				}
//			}
//		}
//	return ans;
//}
//
//int main() {
//
//	vector<int> a{1,2,-3};
//	vector<int> b{2,-3,1};
//	vector<int> c{-3,2,1};
//	vector<vector<int>> ans;
//	
//	ans = TripletSum(a, b, c);
//	
//	cout << "printing the ans" << endl;
//	for (int i = 0; i < ans.size(); i++) {
//		for (int j = 0; j < ans[i].size(); j++) {
//			cout << ans[i][j] << "  ";
//		}cout << endl;
//	}cout << endl;
//
//
//	return 0;
//}