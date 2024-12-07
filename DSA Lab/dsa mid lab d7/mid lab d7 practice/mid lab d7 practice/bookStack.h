#include<iostream>
#include<string>
using namespace std;

class Book {
protected:
	int BookID;
	string BookTitle;
public:
	Book(int BookID = int(), string BookTitle = "") : BookID(BookID), BookTitle(BookTitle) {}
	~Book(){}
	void display() {
		cout << "output: Book ID:" << BookID << " , Title: " << BookTitle;
	}
};

class BookStack {
protected:
	int currentSize;
	int maxSize;
	Book* arr;
public:
	BookStack(int maxSize) : maxSize(maxSize) {
		arr = new Book[maxSize];
		currentSize = 0;
	}

	void push(Book x) {
		arr[currentSize++] = x;
	}

	void pop() {
		if (currentSize == 0) {
			cout << "the stack is empty" << endl;
		}
		else {
			currentSize--;
			arr[currentSize].display();
		}
	}

	void peek() {
		if (currentSize == 0) {
			cout << "the stack is empty" << endl;
		}
		else {
			arr[currentSize - 1].display();
		}
	}

	void display() {
		for (int i = 0; i < currentSize; i++) {
			arr[i].display();
			cout << endl;
		}cout << endl;
	}

	int size() {
		return currentSize;
	}

};
