//#include<iostream>
//using namespace std;
//#include<string>
//
//void stringReverse(string& s, int i, int j) {
//	// base case
//	if (i >= j) {
//		return;
//	}
//
//	// processing
//	swap(s[i], s[j]);
//
//	// post increment would be done after  the function is called , which will
//	//  cause it to be stuck in a loop with i and j remaining the same
//	// so post increment cannot be used here we need pre increment in this case
//	//stringReverse(s, i++, j--);
//	// good ---->>>> // stringReverse(s, ++i, --j);
//	stringReverse(s, i + 1, j - 1);
//}
//
//
//int main() {
//	
//	string s = "babar";
//	
//	
//	// reverseing a string using loops
//	int i = 0;
//	int j = s.size() - 1;
//	cout << s.size() << endl;
//	cout << "before swap: " << s << endl;
//	while (i < j) {
//		swap(s[i], s[j]);
//		i++; j--;
//	}
//	cout << "after swap: " << s << endl;
//
//	cout << endl << endl << endl;
//
//	// reversing a string using recursion
//	string a = "saad";
//	cout << "before reverse: " << a << endl;
//	cout << "size of string: " << a.size() << endl;
//	stringReverse(a, 0, a.size() - 1);
//	cout << "after reverse: " << a << endl;
//	
//
//
//	return 0;
//}