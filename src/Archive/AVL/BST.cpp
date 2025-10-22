#include <iostream>
#include <vector>

template <typename T>
class BinarySearchTree {
 private:
  // Struct for the node
  struct Node {
    T data;
    Node* left;
    Node* right;

    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
  };

  // Root pointer
  Node* root;

  // Helper functions
  Node* FindMinimum(Node* n) {
    // Base case: a node with no left child
    if (!n->left) return n;

    // Recrusive case: minimum in the left subtree
    return FindMinimum(n->left);
  }

  Node* FindMaximum(Node* n) {
    // Base case: a node with no right child
    if (!n->right) return n;

    // Recrusive case: maximum in the right subtree
    return FindMaximum(n->right);
  }

  bool Found(Node* n, const T& v) {
    // Base case: an empty tree, v not found
    if (!n) return false;

    if (v == n->data) { // Another base case
      return true;
    } else if (v < n->data) { // Recursive case 1
      return Found(n->left, v);
    } else { // Recursive case 2
      return Found(n->right, v);
    }
  }

  // Returns the root of a tree with the value inserted
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
    if (v < n->data) {  
      n->left = InsertValue(n->left, v);  // Update left subtree
    } else {  
      n->right = InsertValue(n->right, v);  // Update right subtree
    }
    return n;
  }

  void Inorder(Node* n, std::vector<T>* values) {
    // Base case: an empty tree
    if (!n) return;

    // Recursive case: left -> current -> right
    Inorder(n->left, values);
    values->push_back(n->data);
    Inorder(n->right, values);
  }

  // Returns the root of a tree with v removed
  Node* RemoveNode(Node* n, const T& v) {
    // Base case: an empty tree - the tree already has v "deleted"
    if (!n) return n;

    // Base case: found v at n, remove n
    // Three different removal methods based on the number of child in n
    if (v == n->data) {
      // Case 1: A leave should just be deleted
      if (!n->left && !n->right) {  // A leave should just be deleted
        delete n;
        return nullptr;       // Returns an empty tree
      } 
      
      // Case 2: If has one subtree, reset root to be subtree's root
      Node* temp = (!n->left) ? n->right : (!n->right) ? n->left : nullptr;
      if (temp) {
        delete n;
        return temp;
      }
      
      // Case 3: Has two child nodes
      // Replace value of n by the minimum of the right subtree
      // Then update right subtree to remove the minimum value
      T min = FindMinimum(n->right)->data;
      n->data = min;
      n->right = RemoveNode(n->right, min);
      return n;
      }

    // Recursive case: update subtree
    if (v < n->data) n->left = RemoveNode(n->left, v);
    else n->right = RemoveNode(n->right, v);
    return n;
  }

  // Clear tree
  void Clear(Node* n) {
    // Base case: empty tree, already cleared
    if (!n) return;

    // Recursive case: delete current node and clear subtrees
    Node* left = n->left;
    Node* right = n->right;
    delete n;
    Clear(left);
    Clear(right);
  }

 public:
  // Constructor
  BinarySearchTree() : root(nullptr) {}

  // Destructor
  ~BinarySearchTree() { Clear(root); }

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
      std::cout << values[i] << ", ";
    }
    std::cout << values.back() << std::endl;
  }

  // Remove function
  void Remove(const T& value) { root = RemoveNode(root, value); }
};
