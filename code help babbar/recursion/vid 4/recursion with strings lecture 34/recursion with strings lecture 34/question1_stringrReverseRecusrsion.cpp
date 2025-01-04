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
//// same question but using only one pointer i
//void stringReverse2(string& s, int i) {
//	
//	// base case
//	if (i >= s.size() - i - 1) {
//		return;
//	}
//
//	swap(s[i], s[s.size() - i - 1]);
//	
//	stringReverse2(s, i+1);
//}
//
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
//
//	// using only one single pointer... :)
//	cout << endl << endl << endl;
//
//
//	cout << "using only one single pointer i " << endl;
//	string z = "abcd";
//	string x = "abcde";
//	cout << "before reverse: " << z << endl;
//	cout << "before reverse: " << x << endl;
//	stringReverse2(x , 0);
//	stringReverse2(z , 0);
//	cout << "after reverse: " << z << endl;
//	cout << "after reverse: " << x << endl;
//
//
//	return 0;
//}