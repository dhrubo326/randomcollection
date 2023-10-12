#include <bits/stdc++.h>
using namespace std;
// This is testing tree class
class TreeNode {
public:
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value){
    this->data = value;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BinarySearchTree{
private:
  TreeNode* root;
public:
  BinarySearchTree(){
    this->root = nullptr;
  }

  void insert(int value){
    this->root = insertRecursive(root, value);
  }
  void inorderTraversal(){
    inorderTraversalRecursive(root);
  }
private:
  TreeNode* insertRecursive(TreeNode* node, int value){
    // base case
    if(node == nullptr){
      return new TreeNode(value);
    }
    // recursive case
    if(value < node->data){
      node->left = insertRecursive(node->left, value);
    }else{
      node->right = insertRecursive(node->right, value);
    }
    return node;
  }

  void inorderTraversalRecursive(TreeNode* node){
    if(node == nullptr) return;

    inorderTraversalRecursive(node->left);
    cout<<node->data<<" ";
    inorderTraversalRecursive(node->right);
  }

};


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(9);
    // Perform in-order traversal to print the elements
    cout << "In-order traversal: ";
    bst.inorderTraversal();
    cout << endl;
	
	return 0;
}