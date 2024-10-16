#include<iostream>
#include<string>
using namespace std;

template <typename t>
void Swap(t& var1, t& var2) {
    t temp = var1;
    var1 = var2;
    var2 = temp;
}

template <typename t, int size>
void printArray(t(&var1)[size]) {
    for (int i = 0; i < size; i++) {
        cout << var1[i] << " ";
    }
}

template <typename t, int size>
void selectionSort(t(&array)[size]) {

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            t temp = t();
            if (array[i] > array[j]) {
                temp = array[i];
                Swap(array[i], array[j]);
            }
        }
    }
}

int main() {

    // Test with an integer array of size 5
    int intArray[5] = { 64, 25, 12, 22, 11 };
    cout << "Original integer array: ";
    printArray(intArray);
    selectionSort(intArray);
    cout << "Sorted integer array: ";
    printArray(intArray);

    // Test with a string array of size 4
    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    cout << "\nOriginal string array: ";
    printArray(stringArray);
    selectionSort(stringArray);
    cout << "Sorted string array: ";
    printArray(stringArray);

    return 0;
}