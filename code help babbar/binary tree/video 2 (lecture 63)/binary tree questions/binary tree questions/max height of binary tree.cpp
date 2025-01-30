#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct node {
    int val;
    node* left;
    node* right;
    node(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to insert nodes into the tree in level order
node* buildTree() {
    cout << "Enter root value (-1 for NULL): ";
    int value;
    cin >> value;

    if (value == -1) return nullptr;

    node* root = new node(value);
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        cout << "Enter left child of " << current->val << " (-1 for NULL): ";
        cin >> value;
        if (value != -1) {
            current->left = new node(value);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->val << " (-1 for NULL): ";
        cin >> value;
        if (value != -1) {
            current->right = new node(value);
            q.push(current->right);
        }
    }
    return root;
}

// Function for Level Order Traversal
void levelOrderTraversal(node* root) {
    if (!root) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        node** levelNodes = new node * [levelSize];

        for (int i = 0; i < levelSize; ++i) {
            node* current = q.front();
            q.pop();
            levelNodes[i] = current;

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        // Print the current level
        for (int i = 0; i < levelSize; ++i) {
            cout << levelNodes[i]->val << " ";
        }
        cout << endl;

        delete[] levelNodes;
    }
}





int maxHeight(node* root , int& height) {

	// base case
	if (root == nullptr) {
		return height;
	}

	if (root->left == nullptr && root->right == nullptr) {
		return ++height;
	}

	int left_height = maxHeight(root->left, height);
	int right_height = maxHeight(root->right, height);
	int maxHeight = max(left_height, right_height);
	return maxHeight;
}

int main() {
    node* root = nullptr;
    root = buildTree();
    int height = 0;
    cout << "max height is: " << maxHeight(root, height);
}