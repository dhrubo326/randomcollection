#include <bits/stdc++.h>
using namespace std;


class Node {
public:
  int value;
  Node* left;
  Node* right;

  Node(int value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BST {
    public:
      Node* root;

      BST() {
        this->root = nullptr;
      }

      void insert(int value) {
        Node* newNode = new Node(value);

        if (this->root == nullptr) {
          this->root = newNode;
        } else {
          insertNode(this->root, newNode);
        }
      }

      void printTree(){
        inorderTraversal(root);
      }

    private:
      void insertNode(Node* root, Node* newNode) {
        if (newNode->value < root->value) {
          if (root->left == nullptr) {
            root->left = newNode;
          } else {
            insertNode(root->left, newNode);
          }
        } else {
          if (root->right == nullptr) {
            root->right = newNode;
          } else {
            insertNode(root->right, newNode);
          }
        }
      }

      void inorderTraversal(Node* root) {
      if (root == nullptr) {
        return;
      }

      inorderTraversal(root->left);
      std::cout << root->value << " ";
      inorderTraversal(root->right);
    }

};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	BST bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    // Perform in-order traversal to print the elements
    cout << "In-order traversal: ";
    bst.printTree();
    cout << endl;
	
	return 0;
}