//#include<iostream>
//#include<string>
//using namespace std;
//
//bool checkPalindrome(string& str, int i, int j) {
//
//	// base case
//	if (i >= j) {
//		return true;
//	}
//	
//	// if ith element didnot match jth element
//	if (str[i] != str[j]) {
//		return false;
//	}
//
//	// recursive relation
//	bool isPalindrome = checkPalindrome(str, i + 1, j - 1);
//	return isPalindrome;
//}
//
//
//int main() {
//	
//	string str = "abbccbba";
//	bool ans = checkPalindrome(str, 0, str.size() - 1);
//
//	if (ans) {
//		cout << str << " is palindrome" << endl;
//	}
//	else
//		cout << str << " is not palindrome " << endl;
//
//	return 0;
//}
//
