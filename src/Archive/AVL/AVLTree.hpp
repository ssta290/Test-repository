#include <algorithm>

using namespace std;

class AVLTree {
 private:
  struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
    Node(const int &value) : data(value), height(0), left(nullptr), right(nullptr) {}
  };

  Node* root;

  // Helper functions
  Node* InsertValue(const int &value, Node* n) {
    if (n == nullptr) { return new Node(value); }   // If node is empty insert a value
    if (value == n->data) { return n; }   // Don't insert a value if that value already exists

    if (value < n->data) {
      n->left = InsertValue(value, n->left);
    } else {
      n->right = InsertValue(value, n->right);
    }

    UpdateHeight(n);
    n = Rebalance(n);
    return n;
  }

  Node* Rebalance(Node* n) {
    if (!n) return n;   // Classic if n does not exist, return n

    if (GetBalance(n) > 1 ) {   // Tree is left heavy
      if (GetBalance(n->left) >= 0) {
        n = RightRotate(n);    // Left left rotation
      } else {
        n = LeftRightRotate(n);    // Left Right rotation
      }
    } else if (GetBalance(n) < - 1) {   // Tree is right heavy
      if (GetBalance(n->right) <= 0) {
        n = LeftRotate(n);   // Right Right rotation
      } else {
        n = RightLeftRotate(n); // Right Left rotation
      }
    }

    return n;
  }

  int GetHeight(Node* n) { return n ? n->height : -1; }

  void UpdateHeight(Node* n) {
    if (n) n->height = 1 + max(GetHeight(n->left), GetHeight(n->right)); 
  }

  int GetBalance(Node* n) {
    if (n) {
      return GetHeight(n->left) - GetHeight(n->right);
    } else {
      return 0;
    }
  }

  Node* RightRotate(Node* n) {
    if (!n) throw std::runtime_error("Cannot rotate right: node does not exist!");

    cout << "Rotating right..." << endl;

    if (n == root) {
      root = n->left;
    }

    Node* temp = n->left;
    n->left = n->left->right;
    temp->right = n;

    UpdateHeight(n);
    UpdateHeight(temp);
    return temp;
  }

  Node* LeftRotate(Node* n) {
    if (!n) throw std::runtime_error("Cannot rotate left: node does not exist!");

    cout << "Rotating left..." << endl;

    if (n == root) {
      root = n->right;
    }

    Node* temp = n->right;
    n->right = n->right->left;
    temp->left = n;

    UpdateHeight(n);
    UpdateHeight(temp);
    return temp;
  }

  Node* LeftRightRotate(Node* n) {
    if (!n) throw std::runtime_error("Cannot rotate left right: node does not exist!");

    n->left = LeftRotate(n->left);
    return RightRotate(n);
  }

  Node* RightLeftRotate(Node* n) {
    if (!n) throw std::runtime_error("Cannot rotate left right: node does not exist!");

    n->right = RightRotate(n->right);
    return LeftRotate(n);
  }

 public:
  AVLTree() : root(nullptr) {}
  ~AVLTree() { 
    // Delete all nodes
  }
  void Insert(const int &value) { root = InsertValue(value, root); }
};
