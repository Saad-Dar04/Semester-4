#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	// making a constructor for this node class
	Node() :data(0), next(nullptr) {
		//cout << "node constructor has been called , and i think that both of the values have been initialized" << endl;
		//cout << "data : " << data << endl;
		//if (next == nullptr) { cout << "success" << endl; }
		//else { cout << "no success" << endl; }
	};
	~Node() {
		cout << "node destructor has been called" << endl;
	}
};