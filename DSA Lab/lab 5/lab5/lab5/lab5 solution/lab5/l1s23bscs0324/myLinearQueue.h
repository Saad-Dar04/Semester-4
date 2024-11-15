
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//            
//	WRITTEN BY : SAAD SALMAN DAR 
//  DONOT COPY WITHOUT PRIOR AUTHORIZATION 
//  YOU COULD REACH OUT TO ME ON MY GITHUB FOR APPROVAL 
//  FOLLOW OR FACE DIRE CONSEQUENCES :  https://github.com/Saad-Dar04 

// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<			SATIRE						>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




#include "AbstractLinearQueue.h"

template <typename t>
class myLinearQueue : public AbstractLinearQueue<t> {
protected:

public:

	// constructor
	myLinearQueue(int maxQueueSize = 0) : AbstractLinearQueue<t>(maxQueueSize){
	}

	// pure virtual funciton redefinition
	bool isEmpty(){
		if (AbstractLinearQueue<t>::currentSize == 0){
			return 1;
		}
		else{
			return 0;
		}
	}

	bool isFull(){
		if (AbstractLinearQueue<t>::currentSize == AbstractLinearQueue<t>::maxSize){
			return 1;
		}
		else {
			return 0;
		}
	}

	void enqueue(t data){
		if (!isFull()){
			AbstractLinearQueue<t>::arr[AbstractLinearQueue<t>::currentSize++] = data;
			cout << "added to queue" << endl;
		}
		else{
			cout << "queue is full" << endl;
		}
	}

	t dequeue(){
		if (!isEmpty()){
			// would store the first variable in temp
			// would swap all the variables one step back
			t temp = AbstractLinearQueue<t>::arr[0];
			for (int i = 0; i < AbstractLinearQueue<t>::currentSize-1 ; i++){
				AbstractLinearQueue<t>::arr[i] = AbstractLinearQueue<t>::arr[i + 1];
			}
			
			
			/*cout << "the array after is: " << endl;
			for (int i = 0; i < AbstractLinearQueue<t>::currentSize-1; i++){
				cout << AbstractLinearQueue<t>::arr[i] << " ";
			}cout << endl;*/
			AbstractLinearQueue<t>::currentSize--;
			return temp;
		}

		else{
			cout << "Queue is Empty" << endl;
			return t();
		}

	}

	t peek(){
		if (!isEmpty()){
			return AbstractLinearQueue<t>::arr[0];
		}

		else{
			cout << "loop is empty" << endl;
			return t();
		}
	}

	int size() {
		// returns the currentsize or the number of elements currently present in the queue ;)
		return AbstractLinearQueue<t>::currentSize;
	}

	void display()const {
		for (int i = 0; i < AbstractLinearQueue<t>::currentSize; i++){
			cout << AbstractLinearQueue<t>::arr[i] << " ";
		}cout << endl;
	}


	// redefinition of destructor
	~myLinearQueue() {
		cout << "myLinearQueue destructor is called" << endl;
	}



	//// function to add studnets
	//void addStudents(const Student& obj){
	//	AbstractLinearQueue
	//}
	// or i could make a function , seperately jis k andar sarey kaam hou rhy houn rather than doing the shit over here aur function kou kharab krein.

};