//time and space complexity O(n);
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

    // Function to perform an pre-order traversal of the binary tree
    void preorderTraversal() {
        preorderTraversalRecursive(root);
    }

    // Function to search in BST 
    void search(int val){
        root = searchBST(root, val);
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
    void preorderTraversalRecursive(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->data << " ";
        preorderTraversalRecursive(node->left);
        preorderTraversalRecursive(node->right);
    }

    // Recursive funtion to peform search in BST 
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        
        if(root->data == val)
            return root;
        else if(val < root->data)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
        
        return root;
    }
};



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	BinaryTree tree;

    // Insert elements into the binary tree
    tree.insert(4);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(3);

    // Perform pre-order traversal to print the elements
    cout << "Pre-order traversal: ";
    tree.preorderTraversal();
    cout << endl;
    int val = 2;
    tree.search(val);
    cout<<"Sub-rooted tree: ";
    tree.preorderTraversal();
	
	return 0;
}