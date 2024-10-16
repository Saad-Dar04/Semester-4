//#include<iostream>
//#include<string>
//using namespace std;
//// by default we have to send the size of the array
//// but using template non type parameter we could add non typeparameter size
//// sending the array by reference would make sure that the size of the 
//// array is not lost.
//
////function template
//template <typename t , int size>
//void swapAlternate( t (&a)[size]) {  // this is the syntax for sending an array by reference.
//	// t() is calling constructor of the respective data type that stores it's default value 0 in case of int , "" in case of string , "" in case of const char* and 0.0 incase of double/float.
//	t temp = t();
//	for (int i = 0; i < size ; i+=2) {
//		if (i + 1 < size) {
//			/*temp = a[i];
//			a[i] = a[i + 1];
//			a[i + 1] = temp;*/
//			swap(a[i], a[i + 1]);
//		}
//	}
//}
//
//template <typename t, int size>
//void displayArray(const t(&a)[size]) {
//	for (int i = 0; i < size; i++) {
//		cout << a[i] << " ";
//	}cout << endl;
//}
//
//int main() {
//	
//	int a[] = { 1,2,3,4,5 };
//	swapAlternate<int>(a);
//	displayArray<int>(a);
//
//	string b[] = { "one" , "two" , "three" , "four"};
//	swapAlternate<string>(b);
//	displayArray<string>(b);
//
//	return 0;
//}