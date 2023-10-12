#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a new node into the binary tree
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    // Function to perform an in-order traversal of the binary tree
    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }

private:
    // Recursive function to insert a new node
    TreeNode* insertRecursive(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else {
            node->right = insertRecursive(node->right, val);
        }

        return node;
    }

    // Recursive function to perform in-order traversal
    void inorderTraversalRecursive(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderTraversalRecursive(node->left);
        cout << node->data << " ";
        inorderTraversalRecursive(node->right);
    }
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	 BinaryTree tree;

    // Insert elements into the binary tree
    tree.insert(3);
    tree.insert(1);
    tree.insert(5);
    tree.insert(2);
    tree.insert(4);

    // Perform in-order traversal to print the elements
    cout << "In-order traversal: ";
    tree.inorderTraversal();
    cout << endl;
	
	return 0;
}