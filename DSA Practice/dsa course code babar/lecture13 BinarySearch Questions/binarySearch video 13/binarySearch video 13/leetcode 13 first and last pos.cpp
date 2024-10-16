//// first and last position of element in sorted array
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//vector<int> searchRange(vector<int>& nums, int target) {
//
//    int start = 0;
//    int end = 0;
//    if (nums.size() == 1) { end = 0; }
//    else {
//        end = nums.size() - 1;
//    }
//    int mid = 0;
//    int i = 0;
//    vector<int> ans;
//    int low = 0;
//    int high = 0;
//    while (start <= end) {
//        mid = start + ((end - start) / 2);
//        //cout << "mid is: " << mid << endl;
//        if (nums[mid] == target) {
//            low = mid;
//            high = mid;
//            cout << "mid is: " << mid;
//            while (low >= 0) {
//                cout << "here" << endl;
//                if (low != 0) {
//                    if (nums[low - 1] == target) {
//                        low--;
//                    }
//                    else {
//                        //cout << "low value submitted" << endl;
//                        ans.push_back(low);
//                        break;
//                    }
//                }
//
//                else {
//                    //cout << "low value submitted" << endl;
//                    ans.push_back(low);
//                    break;
//                }
//            }
//
//            while (high <= nums.size() - 1) {
//                if (high != nums.size() - 1) {
//                    if (nums[high + 1] == target) {
//                        high++;
//                    }
//
//                    else {
//                        // if both lie on the same indices then dont store the value
//                        //if (low == high) { break; }
//                       // cout << "high value submitted" << endl;
//                        ans.push_back(high);
//                        break;
//                    }
//
//                }
//                // if both lie on the same indices then dont store the value
//                //if (low == high) { break; }
//               // cout << "high value submitted" << endl;
//                else{
//                ans.push_back(high);
//                break;}
//
//            }
//
//            return ans;
//
//        }
//        else {
//
//            if (target > nums[mid]) {
//                start = mid + 1;
//            }
//            else {
//                end = mid - 1;
//            }
//        }
//
//    }
//
//    // returning {-1 , -1} if we are unable to find the target inside the nums array.
//    ans.push_back(-1);
//    ans.push_back(-1);
//    return ans;
//}
//
// 
//
//void display_vector(const vector<int>& nums) {
//    cout << "indicies found are: " << endl << "[  ";
//    for (int i = 0; i < nums.size(); i++) {
//        cout << nums[i] << "   ";
//    }cout << "]" << endl;
//}
//
//int main() {
//    vector<int> arr = { 1,2,3,3,3,3,4,5,9 };
//    vector<int> ans = searchRange(arr, 3);
//    display_vector(ans);
//}
