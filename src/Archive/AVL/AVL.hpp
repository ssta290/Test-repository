#include <iostream>

using namespace std;

template <typename T>
class AVLTree {
 private:
  struct Node : public BinarySearchTree<T>::Node {
    T data;
    Node* left;
    Node* right;
    int height;

    Node(const T& value) : data(value), height(0) {}
  }

  Node* root;
  
  int GetHeight(Node*n) { return n ? n->height : -1 }

  int GetBalance(Node*n) { return n ? GetHeight(n->right) - GetHeight(n->left) : 0 }

  Node* UpdateHeight(Node* n) {
    if (n) {
      n->height = 1 + std::max(GetHeight(n->left), GetHeight(r->right));
    }
    return n;
  }

  void RotateLeftLeft(Node* parent) {
    child = parent->left;
    if (parent == root) root = child;

    Node* temp = child->right;
    child->right = parent;
    parent->left = temp;
    cout << "Rotating left left" << endl;
  }

  void RotateRightRight(Node* parent) {
    child = parent->right;
    if (parent == root) root = child;

    Node* temp = child->left;
    child->left = parent;
    parent->right = temp;
    cout << "Rotating right right" << endl;
  }

  void Rebalance(Node* n) {

  }
  
  Node* InsertValue(Node* n, const T& v) {
    // Base case: an empty tree, insert v as a new node
    if (!n) {
      return new Node(v);
    } 

    // Base case: found the value, return as is
    if (v == n->data) {  
      return n;
    } 

    // Recursive cases: inserted v in left or right subtree
    n->height++;
    if (v < n->data) {  
      n->left = InsertValue(n->left, v);  // Update left subtree
    } else {  
      n->right = InsertValue(n->right, v);  // Update right subtree
    }
    return n;
  }

  void Insert(const T& value) { root = InsertValue(root, value); Rebalance(root); }
}