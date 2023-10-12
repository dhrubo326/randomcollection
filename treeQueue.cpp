#include <bits/stdc++.h>
using namespace std;
// complete BT creation from int array
// for string + null value arry see treeArray.cpp

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

  void insert(vector<int>& nums){
    this->root = insertFromArray(nums);
  }

  void inorderTraversal(){
    inorderTraversalRecursive(root);
  }

private:
  TreeNode* insertFromArray(vector<int>& nums){
    if(nums.empty()) return nullptr;
    // create root node
    TreeNode* root = new TreeNode(nums[0]);
    // create queue for creating others node
    queue<TreeNode*>q;
    q.push(root);
    int i=1;
    while(i<nums.size()){
      TreeNode* curr = q.front();
      q.pop();
      if(i<nums.size()){
        curr->left = new TreeNode(nums[i++]);
        q.push(curr->left);
      }
      if(i<nums.size()){
        curr->right = new TreeNode(nums[i++]);
        q.push(curr->right);
      }
    }
    return root;
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

  vector<int> nums = { 1, 2, 3, 4, 5, 6, 6, 6, 8 };
	BinaryTree bt;
  bt.insert(nums);
  // Perform in-order traversal to print the elements
  cout << "In-order traversal: ";
  bt.inorderTraversal();
  cout << endl;
	
	return 0;
}