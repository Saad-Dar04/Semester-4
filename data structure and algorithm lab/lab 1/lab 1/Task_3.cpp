//#include<iostream>
//using namespace std;
//
//template <typename t , int size>
//int linearSearch(t (&array)[size], t& key) {
//    
//    // loop to transverse throught the array
//    for (int i = 0; i < size; i++) {
//        if (array[i] == key) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//template < typename t >
//void printSearchResult(int index, t &key) {
//    if (index == -1) {
//        cout << "the key doesnot exist in the array." << endl;
//    }
//    else {
//        cout << "the key is : " << key << " which is at the index : " << index << endl;
//    }
//}
//
//int main() {
//  
//        // Test with an integer array of size 5
//        int intArray[5] = { 64, 25, 12, 22, 11 };
//        int intKey = 12;
//        int intIndex = linearSearch(intArray, intKey);
//        printSearchResult(intIndex, intKey);
//
//        // Test with a float array of size 4
//        float floatArray[4] = { 3.14, 2.71, 1.62, 0.57 };
//        float floatKey = 1.62;
//        int floatIndex = linearSearch(floatArray, floatKey);
//        printSearchResult(floatIndex, floatKey);
//
//        // Test with a string array of size 4
//        string stringArray[4] = { "apple", "orange", "banana", "grape" };
//        string stringKey = "banana";
//        int stringIndex = linearSearch(stringArray, stringKey);
//        printSearchResult(stringIndex, stringKey);
//
//   	return 0; 
//}
//
//// problem in my code and solution
////The return type of the linearSearch function is t,
////which in your case could be a non-integer type like float or string.
////However, the index you are returning is an integer. This can cause issues
////when dealing with types like float or string, where you expect the return 
////value to be the index.