#include <bits/stdc++.h>
using namespace std;
// Create BT from string array
// for int value input, see treeQueue.cpp

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

class BinaryTree{
private:
  TreeNode* root;
public:
  BinaryTree(){
    this->root = nullptr;
  }

  void createTree(vector<string>& arr){
    if(arr.size()==0) return;
    this->root = new TreeNode(stoi(arr[0]));
    createTreeRecursive(root, 0, arr);
  }

  void inorderTraversal(){
    inorderTraversalRecursive(root);
  }

private:
  // Recursive tree creation from string array
  void createTreeRecursive(TreeNode *node, int i, vector<string>&arr){
    if(node != nullptr){
      if(2*i+1 < arr.size()){
        if(arr[2*i+1] == "null"){
          node->left = nullptr;
        }else{
          node->left = new TreeNode(stoi(arr[2*i+1]));
        }
        createTreeRecursive(node->left, 2*i+1, arr);
      }

      if(2*i + 2 < arr.size()){
        if(arr[2*i+2] == "null"){
          node->right = nullptr;
        }else{
          node->right = new TreeNode(stoi(arr[2*i+2]));
        }
        createTreeRecursive(node->right, 2*i+2, arr);
      }
    }
  }
  // in-order traversal
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

  vector<string> arr = { "2","1","3","null","4","null","7" };
	BinaryTree bt;
  bt.createTree(arr);
  // Perform in-order traversal to print the elements
  cout << "In-order traversal: ";
  bt.inorderTraversal();
  cout << endl;
	
	return 0;
}