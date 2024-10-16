//#include<vector>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//
//int main() {
//
//    vector<int> nums1{ 54,93,21,73,84,60,18,62,59,89,83,89,25,39,41,55,78,27,65,82,94,61,12,38,76,5,35,6,51,48,61,0,47,60,84,9,13,28,38,21,55,37,4,67,64,86,45,33,41 };
//    vector<int> nums2{ 17,17,87,98,18,53,2,69,74,73,20,85,59,89,84,91,84,34,44,48,20,42,68,84,8,54,66,62,69,52,67,27,87,49,92,14,92,53,22,90,60,14,8,71,0,61,94,1,22,84,10,55,55,60,98,76,27,35,84,28,4,2,9,44,86,12,17,89,35,68,17,41,21,65,59,86,42,53,0,33,80,20 };
//
//    sort(nums1.begin(), nums1.end());
//    sort(nums2.begin(), nums2.end());
//
//    cout << "nums1 array: ";
//    for (int i = 0; i < nums1.size(); i++) {
//        cout << nums1[i] << " ";
//    }cout << endl;
//
//    cout << "nums2 array: ";
//    for (int i = 0; i < (nums2.size()); i++) {
//        cout << nums2[i] << " ";
//    }cout << endl;
//
//    int i = 0, j = 0;
//    vector<int> ans;
//
//    while (i < nums1.size() && j < nums2.size()) {
//        if (nums2[j] < nums1[i]) {
//            cout << "j++" << endl;
//            j++;
//        }
//
//        else if (nums2[j] == nums1[i]) {
//            cout << "equal too condition: " << endl;
//            // checking if array is not empty
//            if (!ans.empty()) {
//                if (nums2[j] == ans.back()) {
//                    i++; j++;
//                    continue;
//                }
//            }
//            ans.push_back(nums2[j]);
//            i++; j++;
//        }
//
//        else if (nums2[j] > nums1[i]) {
//            cout << "i++" << endl;
//            i++;
//        }
//    }
//
//    cout << "out of the loop: " << endl;
//    cout << "the anwser is: ";
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << " ";
//    }cout << endl;
//
//    return 0;
//}