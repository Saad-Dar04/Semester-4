// creation of binary tree through recursion.. :)
#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	
	// constructor
	node(int data) : data(data) {
		this->left = nullptr;
		this->right = nullptr;
	}
	
};


node* buildTree(node* root) {
	cout << "Enter the data: " << endl;
	int data = 0;
	cin >> data;
	// base case , if user enters -1 , it means that user does not wants to have further nodes.
	if (data == -1) {
		return nullptr;
	}
	cout << "root before : " << &root << endl;
	root = new node(data);
	cout << "root after memory allocation : " << &root <<  endl;

	cout << "Enter the data for inserting in left of: " << data << endl;
	root->left = buildTree(root->left);

	cout << "Enter the data for inserting into right of: " << data << endl;
	root->right = buildTree(root->right);
	
	return root;
}


void inOrder(node* root) {
	
	
	
	if (root == nullptr) {
		
		return;
	}

	// LNR
	inOrder(&*root->left);
	cout << (*root).data << " " << endl;
	inOrder(root->right);

}


void preOrder(node* root) {
	if (root == nullptr) {
		return;
	}

	// NLR
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}


void postOrder(node* root) {
	if (root == nullptr) {
		return;
	}

	//LRN
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";

}

void countLeafNodes(node* root, int& count) {
	
	// if we encounter an node pointer where both the left and right are pointing towards null this means
	// that we have encountered an leaf node and in that case we would increase the count by 1.
	// it is dereferencing is liye msla a rha hae :)

	// base case
	if (root == nullptr) {
		return;
	}

	if (root->left == nullptr && root->right == nullptr) {
		count++;
	}

	countLeafNodes(root->left , count);
	countLeafNodes(root->right , count);
}


int main() {

	node* root = nullptr;
	root = buildTree(root);
	// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

	//cout << endl << endl << endl;
	////cout << "root node is: " << &(*root) << endl;

	//
	//cout << "inOrder traversal is: ";
	//cout << endl;
	//inOrder(root);


	//cout << "postOrder traversal is: ";
	//postOrder(root);
	//cout << endl;

	//cout << "preOrder traversal is: ";
	//preOrder(root);
	//cout << endl;

	int count = 0;
	countLeafNodes(root, count);
	cout << "Count of leaf nodes is: " << count << endl;

	return 0;
}

