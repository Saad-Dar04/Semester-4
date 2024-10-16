//// find unique elements in an array
//// maybe just used for this specific algo , but still keep it in mind when solving further problem
//#include<iostream>
//using namespace std;
//
////o(n) time complexity , 0(1) space complexity , the obvious solution was 0(n^2) but it was taking too much time so had to see solutions for this one ;)
//void duplicate(int arr[], int size) {
//	int index = 0;
//	for (int i = 0; i < size; i++) {
//		index = abs(arr[i]) - 1;
//		// if index pae jou value this is already negative tou just print the value
//		if (arr[index] < 0) {
//			// means it has been already marked
//			cout << index+1 << endl;
//		}
//		else {
//			// if it's positive tou mark it 
//			//arr[index] = arr[index] * -1;
//			arr[index] *= -1;
//		}
//	}
//}
//
//
//int main() {
//	
//	// numbers btw the range [1,n] , n-1 elements , some exist once some twice , we have to find twice waley.
//	// it means k index b andar hi exist kr rhy houn gae tou i can mark the number against the index i encounter
//	// e.g if i encounter 2 i can mark the 2-1 index as negative and if i encounter it again i will know k i've already encourted it cus it will be marked as negative
//	// specific case scenarion k liye i could use this particular algorithm... ;)
//
//	int array[8] = {1,2,3,4,1,4,5,6};
//	duplicate(array, 8);
//
//	return 0;
//}