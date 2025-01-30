// class for bst
// insertion 
// search
// search iterative method
// min , max recursion + iterative method
// delete value and node containing that node
//

#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) : data(data) {
		this->left = nullptr;
		this->right = nullptr;
	}
};


class BST {
private:
	node* root;

	// helper functions
	node* insert(node* root, int x) {

		// base case , value will be inserted if this condition is met.
		if (root == nullptr) {
			return new node(x);
		}

		else if (x < root->data) {
			root->left = insert(root->left, x);
		}

		else if (x > root->data) {
			root->right = insert(root->right, x);
		}

		return root;
	}

	// inOrder Traversal
	void inOrder(node* root) {
		// base condition
		if (root == nullptr) {
			return;
		}

		// LNR
		inOrder(root->left);
		cout << root->data << endl;
		inOrder(root->right);
	}

	// function for search
	bool search(node* root, int x) {
		// base condition if found
		if (root == nullptr) {
			return false;
		}

		if (root->data == x) {
			return true;
		}


		// how to traverse in case of bst
		if (x < root->data) {
			return search(root->left, x);
		}

		else if (x > root->data) {
			return search(root->right, x);
		}

	}

	bool searchIterative(node* root, int x) {

		while (root != NULL) {

			// if found
			if (root->data == x) {
				return true; // meaning that found
			}

			else if (x < root->data) {
				root = root->left;
			}

			else if (x > root->data) {
				root = root->right;
			}

		}
		return false;
	}

	int minbst(node* root) {
		// base condition
		if (root == nullptr) {
			return NULL;
		}

		// means that left most node is found.
		if (root->left == nullptr) {
			return root->data;
		}

		// keep traversing towards left.
		int value = minbst(root->left);
		return value;
	}

	int maxbst(node* root) {
		// if no values in node.
		if (root == nullptr) {
			return NULL;
		}

		if (root->right == nullptr) {
			return root->data; // means that the 
			// maximum value has been found
		}

		int ans = maxbst(root->right);
		return ans;
	}

	int SearchMaxValue(node* root) {
		if (root->right == nullptr) {
			return root->data;
		}

		return SearchMaxValue(root->right);
	}



	node* delete_node(node* root, int x) {
		
		if (root == nullptr) {
			return nullptr;
		}

		// if found then what to do..
		if (root->data == x) {
			// 0 / leaf node
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				return nullptr;
			}


			// 1 node
			// left
			else if (root->left != nullptr && root->right == nullptr) {
				node* temp = root->left;
				delete root;
				return temp;
			}
			// right
			else if (root->left == nullptr && root->right != nullptr) {
				node* temp = root->right;
				delete root;
				return temp;
			}

			// 2 nodes
			else if (root->left != nullptr && root->right != nullptr) {
				// would be using the inOrder Successor method.
				// go to left subtree
				// find the max value
				// change it with the root->data
				// delete the maxValue wala node.
				int maxValue = SearchMaxValue(root->left);
				root->data = maxValue;
				root->left = delete_node(root->left, maxValue);
				return root;
			}
		}
		
		// search for the node
		if (x < root->data) {
			root->left = delete_node(root->left, x);
		}
		else if (x > root->data) {
			root->right = delete_node(root->right, x);
		}

		return root;
	}


public:
	BST() {
		root = nullptr;
	}

	void insert(int x) {
		this-> root = insert(root, x);
	}

	void inOrder() {
		// calling helper funciton inside
		inOrder(root);
	}

	bool search(int x) {
		bool ans = search(root, x);
		return ans;
	}

	void searchIterative(int x) {
		if (searchIterative(this->root, x))
			cout << "found";
		else 
			cout << "not found" << endl;
	}

	int minbst() {
		return minbst(this->root);
	}

	int maxbst() {
		int ans = maxbst(this->root);
		if (ans == NULL) {
			cout << "bst in empty. " << endl;
			return NULL;
		}
		else
			return ans;
	}

	/*int preOrderPredecesssor(int x) {
		return inOrderPredecessor(this->root, x).first;
	}*/
	void delete_node(int x) {
		delete_node(this->root, x);
	}


};



int main() {

	BST ptr;
	ptr.insert(10);
	ptr.insert(8);
	ptr.insert(21);
	ptr.insert(7);
	ptr.insert(27);
	ptr.insert(5);
	ptr.insert(4);
	ptr.insert(3);

	cout << "in Order traversal is: " << endl;
	ptr.inOrder();

	// search for a data in the tree
	if (ptr.search(27)) {
		cout << "found" << endl;
	}

	else
		cout << "not found" << endl;
	

	// search but with loop/iteration so that space complexity is constant
	ptr.searchIterative(100);


	// find minimum value in bst ---> left most node of bst
	cout << "The minimum value is : " << ptr.minbst() << endl;


	// find maximum value in bst ---- > right most node of bst
	cout << "The maximum value is : " << ptr.maxbst() << endl;


	// findint preorder predecessor
	//cout << "Preorder predecessor is: " << ptr.preOrderPredecesssor(8);

	//deleting a bst node
	ptr.delete_node(5);
	ptr.inOrder();

	return 0;
}