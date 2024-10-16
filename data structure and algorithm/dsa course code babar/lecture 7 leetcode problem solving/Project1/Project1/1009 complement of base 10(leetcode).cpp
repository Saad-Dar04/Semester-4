//#include<iostream>
//#include<cmath>
//#include<climits>
//using namespace std;
//
//// method 1
//int base_10_complement(int n) {
//	int bit = 0;
//	int anwser = 0;
//	int i = 0;
//	// because it is a positive number , we could see from the range , so right shift operator >> would do padding with zero.
//	while (n > 0) {
//		//bit = ~(n & 1); // this would store 0000000000000 or 000000000000001 but the negation would convert it into 11111111111111 lr 1111111111111111111110 that's why i was facing problems while solving this one but alas im able to do with full confidence heheeh :)
//		bit = (n & 1);
//		//cout << "the bit is: " << bit << endl;
//		if (bit == 0) {
//			anwser =  pow(2, i) + anwser;
//		}
//		i++;
//		// right shifting the operator
//		n = n >> 1;
//		//cout << n << "   iteration is: " << i <<  endl;
//	}
//	return anwser;
//}
//
//
////method 2 doing this in a single loop for better time complexity.. :p
//int base_10_complement_creatingMask(int n) {
//	//counting the number of one's
//	int mask = 0; // 0 stored in all 32 bits
//	int temp = n; // temporarily stored n ki value q k is k sath kaam honay laga hae
//	while (n != 0) {
//		
//
//		// mask = (mask << 1) | 1;  // combined both in one statement.
//		// step 02 - creating mask
//		mask = mask << 1;
//		mask = mask | 1;   // it will convert the last bit into one
//		//cout << "mask is: " << mask << endl;
//		//step 01.
//		// right shifting all the bits of n so it will run jb tk we run out of the last 1 bit
//		// us k baad sarey 0 reh jaein ge and the loop will stop
//		n = n >> 1;
//		//cout << "n is : " << n << endl;
//	}
//
//	// step 03 n k andar sae sb nikal diya hae tou it's j zero atp isliye we getting wrong anwser
//	//n = (~n) & mask; // this will give 7 anwser..
//	n = (~temp) & mask;
//	return n;
//
//}
//
//int base_10_complement_xor(int x) {
//	int bit = 0;
//	int reverse = 0;
//	int anwser = 0;
//	int  i = 0;
//	while (x != 0) {
//		// finding out the lsb by &1;
//		bit = x & 1;
//		reverse = bit ^ 1; // xor by 1 acts as a complement by reversing the bit. 
//		cout << "bit: " << bit << "       reverse:" << reverse << endl;
//		anwser = (reverse * pow(2, i++)) + anwser; // if the bit is 1 it would add up otherwise nothing would add up
//		x = x >> 1; 
//	}
//	return anwser; 
//}
//
//
//int main() {
//
//	cout << base_10_complement(5);
//	cout << endl;
//	cout << base_10_complement_creatingMask(5);
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	cout << base_10_complement_xor(5);
//
//	return 0;
//}