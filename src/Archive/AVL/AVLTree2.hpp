#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class AVLTree2 {
 private:
  // Struct for the node with height field
  struct Node {
    T data;
    Node* left;
    Node* right;
    int height;

    Node(const T& value)
        : data(value), left(nullptr), right(nullptr), height(0) {}
  };

  // Root pointer
  Node* root;

  // Helper functions for AVL operations
  int GetHeight(Node* n) { return n ? n->height : -1; }

  int GetBalance(Node* n) {
    return n ? GetHeight(n->left) - GetHeight(n->right) : 0;
  }

  Node* UpdateHeight(Node* n) {
    if (n) {
      n->height = 1 + std::max(GetHeight(n->left), GetHeight(n->right));
    }
    return n;
  }

  Node* RotateLeft(Node* k1) {
    std::cout << "  LEFT rotation performed at node " << k1->data << std::endl;
    Node* k2 = k1->right;
    Node* y = k2->left;

    // Perform rotation
    k2->left = k1;
    k1->right = y;

    // Update heights
    UpdateHeight(k1);
    UpdateHeight(k2);

    return k2;
  }

  Node* RotateRight(Node* k2) {
    std::cout << "  RIGHT rotation performed at node " << k2->data << std::endl;
    Node* k1 = k2->left;
    Node* y = k1->right;

    // Perform rotation
    k1->right = k2;
    k2->left = y;

    // Update heights
    UpdateHeight(k2);
    UpdateHeight(k1);

    return k1;
  }

  Node* RotateLeftRight(Node* n) {
    std::cout << "  LEFT-RIGHT rotation performed at node " << n->data
              << std::endl;
    n->left = RotateLeft(n->left);
    return RotateRight(n);
  }

  Node* RotateRightLeft(Node* n) {
    std::cout << "  RIGHT-LEFT rotation performed at node " << n->data
              << std::endl;
    n->right = RotateRight(n->right);
    return RotateLeft(n);
  }

  Node* Rebalance(Node* n) {
    if (!n) return n;

    int balance = GetBalance(n);

    if (balance > 1) {               // Left heavy
      if (GetBalance(n->left) >= 0)  // Left-left case
        return RotateRight(n);
      else  // Left-right case
        return RotateLeftRight(n);
    } else if (balance < -1) {        // Right heavy
      if (GetBalance(n->right) <= 0)  // Right-right case
        return RotateLeft(n);
      else  // Right-left case
        return RotateRightLeft(n);
    }
    return n;
  }

  // BST helper functions
  Node* FindMinimum(Node* n) {
    // Base case: a node with no left child
    if (!n->left) return n;
    return FindMinimum(n->left);
  }

  Node* FindMaximum(Node* n) {
    // Base case: a node with no right child
    if (!n->right) return n;
    return FindMaximum(n->right);
  }

  bool Found(Node* n, const T& v) {
    // Base case: an empty tree, v not found
    if (!n) return false;

    if (v == n->data) {
      return true;  // Another base case
    } else if (v < n->data) {
      return Found(n->left, v);  // Recursive case 1
    } else {
      return Found(n->right, v);  // Recursive case 2
    }
  }

  void Inorder(Node* n, std::vector<T>* values) {
    // Base case: an empty tree
    if (!n) return;

    // Recursive case: left -> current -> right
    Inorder(n->left, values);
    values->push_back(n->data);
    Inorder(n->right, values);
  }

  // Returns the root of a tree with the value inserted
  Node* InsertValue(Node* n, const T& v) {
    // Base case: an empty tree, insert v as a new node
    if (!n) {
      return new Node(v);  // Base case: an empty tree, insert v as a new node
    }

    // Base case: found the value, return as is
    if (v == n->data) {
      return n;  // Base case: found the value, return as is
    }

    // Recursive cases: inserted v in left or right subtree
    if (v < n->data) {
      n->left = InsertValue(n->left,
                            v);  // Recursive case: inserted v in left subtree
    } else {
      n->right = InsertValue(n->right,
                             v);  // Recursive case: inserted v in right subtree
    }

    // Update height and rebalance the tree
    return Rebalance(UpdateHeight(n));
  }

  // Returns the root of a tree with v removed
  Node* RemoveNode(Node* n, const T& v) {
    // Base case: an empty tree - the tree already has v "deleted"
    if (!n) return n;

    // Base case: found v at n, remove n
    if (v == n->data) {
      // Case 1: A leaf should just be deleted
      if (!n->left && !n->right) {
        delete n;
        return nullptr;
      }

      // Case 2: If has one subtree, reset root to be subtree's root
      // No need to update height or rebalance since the subtree is unchanged
      Node* temp = (!n->left) ? n->right : (!n->right) ? n->left : nullptr;
      if (temp) {
        delete n;
        return temp;
      }

      // Case 3: Has two child nodes
      // Replace value of n by the minimum of the right subtree
      // Then update right subtree to remove the minimum value
      // Height and balance factor might be changed
      T min = FindMinimum(n->right)->data;
      n->data = min;
      n->right = RemoveNode(n->right, min);
      return Rebalance(UpdateHeight(n));
    }

    // Recursive case: update subtree
    if (v < n->data) {
      n->left = RemoveNode(n->left, v);
    } else {
      n->right = RemoveNode(n->right, v);
    }

    // Update height and rebalance the tree
    return Rebalance(UpdateHeight(n));
  }

  // Clear tree
  void Clear(Node* n) {
    // Base case: empty tree, already cleared
    if (!n) return;

    // Recursive case: delete current node and clear subtrees
    Node* left = n->left;
    Node* right = n->right;
    delete n;
    Clear(left);   // Recursive case: delete left subtree
    Clear(right);  // Recursive case: delete right subtree
  }

  // PrintTree helper functions
  void PrintTreeHelper(Node* n, int depth, std::string prefix, bool isLast) {
    // Base case: an empty tree
    if (!n) return;

    // Print current node
    std::cout << prefix;
    std::cout << (isLast ? "└── " : "├── ");
    std::cout << n->data << " (h:" << n->height << ", b:" << GetBalance(n)
              << ")" << std::endl;

    // Prepare prefix for children
    std::string newPrefix = prefix + (isLast ? "    " : "│   ");

    // Print right child first (so it appears on top)
    if (n->right) {
      PrintTreeHelper(n->right, depth + 1, newPrefix, !n->left);
    }

    // Print left child
    if (n->left) {
      PrintTreeHelper(n->left, depth + 1, newPrefix, true);
    }
  }

 public:
  // Constructor
  AVLTree2() : root(nullptr) {}

  // Destructor
  ~AVLTree2() { Clear(root); }

  // FindMin function
  T FindMin() {
    if (!root) throw std::runtime_error("Empty tree");
    return FindMinimum(root)->data;
  }

  // FindMax function
  T FindMax() {
    if (!root) throw std::runtime_error("Empty tree");
    return FindMaximum(root)->data;
  }

  // Insert function
  void Insert(const T& value) { root = InsertValue(root, value); }

  // Contains function
  bool Contains(const T& value) { return Found(root, value); }

  // Traverse function (inorder traversal)
  void Traverse() {
    if (!root) return;

    std::vector<T> values;
    Inorder(root, &values);

    for (size_t i = 0; i < values.size() - 1; ++i) {
      std::cout << values[i] << " ";
    }
    std::cout << values.back() << std::endl;
  }

  // Remove function
  void Remove(const T& value) { root = RemoveNode(root, value); }

  // GetHeight function
  int GetHeight() { return GetHeight(root); }

  // PrintTree function (ASCII art visualization)
  void PrintTree() {
    if (!root) {
      std::cout << "Tree is empty" << std::endl;
      return;
    }
    PrintTreeHelper(root, 0, "", true);
  }
};
