// implementing binary search using templates
#include<iostream>
using namespace std;

template <typename t , int size>
int binarySearch(t(&array)[size], t &key) {
    int start = 0;
    int mid = 0; 
    int end = size-1;
    while (start <= end) {
        mid = (start + end) / 2;
        
        if (key > array[mid]) {
            
            start = mid+1;
        }
        
        else if (key < array[mid]) {
            end = mid-1;
        }

        else if (key == array[mid]) {
            return mid;
        }
    }
    return -1;
}

template < typename t>
void printSearchResult(int &index , t &key) {
    if (index == -1) {
        cout << "the key doesnot exist in the array." << endl;
    }
    else {
        cout << "the key: " << key << " is situated at the index : " << index << endl;
    }
}

int main() {

    // Test with an integer array (sorted) of size 5
    int intArray[5] = { 11, 12, 22, 25, 64 };
    int intKey = 22;
    int intIndex = binarySearch(intArray, intKey);
    printSearchResult(intIndex, intKey);

    // Test with a float array (sorted) of size 4
    float floatArray[4] = { 0.57, 1.62, 2.71, 3.14 };
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray, floatKey);
    printSearchResult(floatIndex, floatKey);

    // Test with a string array (sorted) of size 4
    string stringArray[4] = { "apple", "banana", "grape", "orange" };
    string stringKey = "grape";
    int stringIndex = binarySearch(stringArray, stringKey);
    printSearchResult(stringIndex, stringKey);

    return 0;
}