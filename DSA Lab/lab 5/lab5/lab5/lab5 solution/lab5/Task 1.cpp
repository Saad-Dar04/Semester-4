
//// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
////            
////	WRITTEN BY : SAAD SALMAN DAR 
////  DONOT COPY WITHOUT PRIOR AUTHORIZATION 
////  YOU COULD REACH OUT TO ME ON MY GITHUB FOR APPROVAL 
////  FOLLOW OR FACE DIRE CONSEQUENCES :  https://github.com/Saad-Dar04 
//
//// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//// <<<<<<<<<<<<<<<<<<<<<			DISCLAIMER					>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//// <<<<<<<<<<<<<<<<<<<<<			SATIRE						>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//


//// << problems still in this code that needs to be fixed >>>>>>
//// 1. if the waiting queue is empty we cannot get the test started.
//// 2. find out a way to generate a random number that greater then zero and smaller than one:)
//// 3. make the presentation on console of this code more presentable );
//// 4. code choouri mat krna mera ;0
//// 5. implement this shi using pointer , pointer kou use kr k memory allocate krou , take idea from the chatgpt ss attached with this code...
//#include "myLinearQueue.h"
//#include<string>
//#include<cstdlib>
//
//
//class Time {
//protected:
//	int minutes;
//	int hours;
//public:
//	
//	Time(int mins = 0, int hour = 0) : minutes(mins), hours(hour) {}
//	
//	~Time(){}
//	
//	void setMinutes(int minutes){
//		this->minutes = minutes;
//	}
//
//	void setHours(int hour) {
//		this->hours = hour;
//	}
//
//	void Display() {
//		cout << hours << ":" << minutes;
//	}
//};
//
//
//// forward declaration of class time
////class Time;
//
//class Student {
//protected:
//	string name;
//	int score;
//	Time time;
//
//public:
//	Student(string name = "", int score = 0, Time time = Time()) {
//		this->name = name;
//	}
//	
//	void setName(string name) {
//		this->name = name;
//	}
//
//	void setScore(int score) {
//		this->score = score;
//	}
//
//	void setTime(int hours , int mins) {
//		time.setHours(hours);
//		time.setMinutes(mins);
//	}
//
//	string getName() {
//		return this->name;
//	}
//
//	int getScore() {
//		return this->score;
//	}
//
//	Time getTime() {
//		return this->time;
//	}
//
//	//copy assignment operator
//	Student& operator=( Student& other) {
//		if (this != &other) {  // Avoid self-assignment
//			this->name = other.name;
//			this->score = other.score;
//			this->time = other.time;
//		}
//		return *this;
//	}
//
//	void Display() {
//		cout << "Student Name: " << getName();
//		cout << endl;
//		cout << " Score: " << getScore();
//		cout << endl;
//		cout << "Time taken: "; time.Display();
//		cout << endl;
//	}
//
//	~Student(){
//		// deepCopy krni parey ge because the destructor is being called mulitple times in this program
//		// use pass by referecne or deepcopy instead of pointing towards the same memory , 
//		// if specific memory has been deleted and we are still pointing towards the same memory it is called a dangling pointer. ;)
//		//cout << "destructor for student is called" << endl;
//	}
//
//};
//
//
//
//// creating a new class where all these things would be implemented at once.. :)
//class TestingSystem {
//
//protected:
//	
//	// myLinearQueue<Student> a(10);
//	// memory cannot be allcoated to the data members of a class q k it is simply a blue print
//	// constructor k andar hi jakr , when the object of testingsystem is made
//	// at that point myLinearQueue<Student> kou memory allocated ki jaey ge according to 
//	// your requirements.
//	// memory can be initialized in the constructor or we could pass a pointer to initialize that memory. :)
//	myLinearQueue<Student> waitingQueue;
//	myLinearQueue<Student> resultQueue;
//
//public:
//	TestingSystem(int QueueSize = 0) : waitingQueue(QueueSize), resultQueue(QueueSize) {
//		// we will take input from the user regarding the size of the queue and
//		// when constructor is called the size n would be sent to linearQueue k constructor and then would 
//		// be initialized by these size.. ;)
//	}
//	
//	void addStudent(string name) {
//		Student temp(name);
//		waitingQueue.enqueue(temp);
//		cout << "out of add student" << endl;
//	}
//
//	void startQuiz() {
//		// dequeue one student at a time
//		//this process will continue until the entire waiting queue is dequeued.
//		while (!waitingQueue.isEmpty()) {
//			Student temp = waitingQueue.dequeue();
//			// assign random values to score and time
//			temp.setScore(rand() % 11);
//			// assign a random value to time b/w 1 and 3 hour
//			temp.setTime((rand() % 4) , (rand() & 61) );
//			resultQueue.enqueue(temp);
//		}
//		cout << "THE QUIZ HAS ENDED." << endl;
//	}
//
//	void Display() {
//		// will start dequeing the objects from the result queue and display the info :)
//		// this loop will execute until the entire queue has dequeued.
//		Student temp;
//		while (!resultQueue.isEmpty()) {
//			temp = resultQueue.dequeue();
//			// calling the Display() funciton residing in the class Student.
//			temp.Display();
//		}
//	}
//
//};
//
//
//int main(){
//	
//	
//	// ----------->> template is working fine ;)
//	/*
//	myLinearQueue<int> a(3);
//	a.peek();
//	
//	a.enqueue(10);
//	a.display();
//	a.enqueue(20);
//	a.display();
//	a.enqueue(30);
//	a.display();
//	a.enqueue(40);
//	a.display();
//
//	cout << a.dequeue() << endl;
//	cout << a.dequeue() << endl;
//	cout << a.dequeue() << endl;
//	cout << a.dequeue() << endl;
//	a.dequeue();*/
//
//
//	// <<<< making a seperate function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
//	// the queueu will store objects of the class student
//	// should i hardcode the size of the waitingqueue
//	/*
//	myLinearQueue<Student> waitingQueue(4);
//	myLinearQueue<Student> resultQueue(10);
//*/	
//	// takin the size of the queue from the user. ;)
//	int sizeOfQueue = 0;
//	cout << "Enter the size of the queue: " ;
//	cin >> sizeOfQueue;
//	TestingSystem a(sizeOfQueue);
//
//	while (1){
//
//		cout << "/t/t/t Menu /t/t/t" << endl;
//		cout << "1.Add a student to the waiting queue" << endl;
//		cout << "2.Start the quiz and generate scores" << endl;
//		cout << "3.Display the scores , name and time taken by the students" << endl;
//		cout << "4.Exit" << endl;
//		
//		int option = 0;
//		string name = "";
//		cout << "Choose an option: ";
//		cin >> option;
//
//		if (option == 1){
//			// idhr hi check lagany laga houn queue ka :)
//			cout << "Enter the name of the Student: ";
//			cin >> name;
//			a.addStudent(name);
//		}
//
//		else if (option == 2){
//			a.startQuiz();
//		}
//
//		else if (option == 3){
//			a.Display();
//		}
//
//		else if(option==4){
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}