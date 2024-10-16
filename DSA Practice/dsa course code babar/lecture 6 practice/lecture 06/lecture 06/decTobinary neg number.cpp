//#include<iostream>
//#include<string>
//using namespace std;
//// this is not possible by normal int cus usky andr we cannot store 32 digits
//// it has a limit max bss 10 digits or 2^31-1 store kr skty hain usky andar ;(
//
//// one sae padding hou rhi hae isliye hum nae jugaad lagaya hae..
//// could i solve it by converting it into positive or wou 
//// sarey steps jou copy mae likhy hain wou run karoun??
//string decimalToBinary_negativeNumber(int num) {
//	// already stored in memory as the negative number.
//	string anwser = "";
//	int bit = 0;
//	int i = 0;
//	while (i++<32) {
//		bit = num & 1;
//		anwser = to_string(bit) + anwser;
//		//cout << anwser << endl;
//		num = num >> 1;
//		// padding by zero houni chahiyae thi
//		// but instead padding by 1 hou rhi hae.. :(
//	}
//	return anwser; 
//}
//
//// yeah faced with the same problem as before ,
//// tou jugaaar laga kr theek kr skty anwser but no 
//// there should be a better way to counter this.
//string decimalToBinary_neg_Number(int num) {
//	string anwser = "";
//	int bit = 0;
//	int i = 0;
//	num = -1 * num;
//	num = ~num; // taking 1's complement
//	num = num | 1; // taking 2's complement
//	// it's know a negative number tou same msla ageya padding by one wala :(
//	while (num!=0) {
//		bit = num & 1;
//		anwser = to_string(bit) + anwser;
//		num = num >> 1; 
//		//cout << anwser;
//		//cout << "looping " << endl;
//	}
//	
//	return anwser;
//}
//
//string decimalToBinary_negNumber_butwithUnsigned(unsigned int num) {
//	string anwser = "";
//	int bit = 0;
//	// it is unsigned but as we are including it as a negative number
//	// tou ye memory k andar jis trhan negative store houta hae waisay
//	// hi store houga. only difference is ye print karwaty waqt 2's complement nhi laita.
//	while (num != 0) {
//		bit = num & 1; 
//		anwser = to_string(bit) + anwser;
//		num = num >> 1;
//		cout << anwser << endl;
//		cout << "looping" << endl;
//	}
//	return anwser;
//}
//
//int main() {
//
//	cout << decimalToBinary_negativeNumber(-5);
//	cout << endl;
//	//cout << decimalToBinary_neg_Number(-5);
//
//	/*unsigned int num = -5;
//	cout << num << endl;*/
//
//	cout << decimalToBinary_negNumber_butwithUnsigned(-5);
//
//	return 0;
//
//}