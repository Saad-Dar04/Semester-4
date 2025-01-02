//// linear search using recursion.
//#include<iostream>
//using namespace std;
//
//void print(int arr[], int size) {
//    cout << "Size of the Array is: " << size << endl;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    } cout << endl;
//}
//
//bool linearSearch(int arr[], int size, int key) {
//    
//    print(arr, size);
//
//    // check if found
//    if (arr[0] == key) {
//        return true;
//    }
//    
//    // base condition
//    if (size ==1 ) {
//        // traversed throught the entire array but could not find the key
//        return false;
//    }
//
//    bool remainingPart = linearSearch(arr + 1, size-1, key);
//    return remainingPart;
//}
//                                                                
//int main() {
//
//    int arr[5] = { 1,2,3,4,5 };
//   // cout << sizeof(arr) / sizeof(int);
//    if (linearSearch(arr, sizeof(arr) / sizeof(int), 0)) {
//        cout << "found" << endl;
//    }
//    else
//        cout << "not found" << endl;
//
//}