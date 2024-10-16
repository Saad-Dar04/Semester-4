//// reverse an integer
//#include<cmath>
//#include<iostream>
//#include<climits>
//using namespace std;
//
//int reverse(int x) {
//   
//        int digit = 0;
//        int anwser = 0;
//        while (x != 0) {
//            digit = x % 10;
//            if (anwser >= INT_MAX / 10 || anwser < INT_MIN / 10) { return 0; }
//            anwser = (anwser * 10) + digit;
//            x /= 10;
//        }
//        return anwser;
//    
//}
//
//
//int main() {
//    int x = 0;
//    cout << "enter the number: "; 
//    cin >> x;
//    cout << "the reverse is: " << reverse(x) << endl;
//
//}