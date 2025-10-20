#include <iostream>
#include <vector>

template <typename T>
struct Node {
  T data;
  Node<T>* l_child;
  Node<T>* r_child;
  Node(const T& value) : data(value), l_child(nullptr), r_child(nullptr) {}
};

template <typename T>
class BinarySearchTree {
 private:
  Node<T>* root_;
  void DeleteSubtree(Node<T>* n) {
    if (n == nullptr) return;

    if (n->l_child) {
      DeleteSubtree(n->l_child);
    }
    if (n->r_child) {
      DeleteSubtree(n->r_child);
    }

    delete n;
  }

 public:
  BinarySearchTree() : root_(nullptr) {}
  ~BinarySearchTree() { DeleteSubtree(root_); }
  T FindMin() const {
    if (!root_) return T();
    Node<T>* n = root_;
    while (n->l_child) {  // Move to the leftmost node
      n = n->l_child;
    }
    return n->data;
  }

  T FindMax() const {
    if (!root_) return T();
    Node<T>* n = root_;
    while (n->r_child) {  // Move to the leftmost node
      n = n->r_child;
    }
    return n->data;
  }

  bool Contains(const T& value) const {
    Node<T>* n = root_;
    while (n) {
      if (value < n->data) {
        n = n->l_child;
      } else if (value == n->data) {
        return true;
      } else {
        n = n->r_child;
      }
    }

    return false;
  }

  void Insert (const T& value) {
    Node<T>* newNode = new Node<T>(value);

    if (root_ == nullptr) {
      root_ = newNode;
      return;
    }
    
    Node<T>* n = root_;
    while (true) {
      if (value < n->data) {
        if (!n->l_child) {
          n->l_child = newNode;
          return;
        }

        n = n->l_child;
      } else {
        if (!n->r_child) {
          n->r_child = newNode;
          return;
        }

        n = n->r_child;
      }
    }
  }

  std::vector<T> Traverse() const { 
    std::vector<T> result;
    TraverseFromNode(root_, result);
    return result;
  }

  void TraverseFromNode(const Node<T>* n, std::vector<T>& container) const {
    if (!n) return;

    if (n->l_child) {
      TraverseFromNode(n->l_child, container);
    }

    container.push_back(n->data);

    if (n->r_child) {
      TraverseFromNode(n->r_child, container);
    }
  }

  void Remove(const T& value) {
    Node<T>* n = root_;
    Node<T>* parent = nullptr;
    
    while (n && n->data != value) {
      parent = n;

      if (value < n->data) {
        n = n->l_child;
      } else {
        n = n->r_child;
      }
    }

    if (n == nullptr) return;  // Value does not exist in tree

    if (parent == nullptr) {
      // Node is root
      RemoveHelper(root_, n);
    } else if (n == parent->l_child) {
      // Node is left child of parent
      RemoveHelper(parent->l_child, n);
    } else {
      // Node is right child of parent
      RemoveHelper(parent->r_child, n);
    }
  }

  void RemoveHelper(Node<T>*& parent_pointer, Node<T>* n) {
    // Node is root
    if (n->r_child) {
      parent_pointer = n->r_child;
      if (n->l_child) {
        // Left child has to be allocated at the far left of right child if it exists
        Node<T>* lowest_node = n->r_child;
        while (lowest_node->l_child) {
          lowest_node = lowest_node->l_child;
        }
        lowest_node->l_child = n->l_child;
      }
    } else if (n->l_child) {
      // Node only has a left child
      parent_pointer = n->l_child;
    } else {
      // Node has no children
      parent_pointer = nullptr;
    }

    delete n;
  }

  void RemoveSubtreeFromValue(const T& value) {
    Node<T>* n = root_;
    Node<T>* parent = nullptr;

    while (n != nullptr && n->data != value) {
      parent = n;
      if (value < n->data) {
        n = n->l_child;
      } else {
        n = n->r_child;
      }
    }

    if (n == nullptr) return;  // Value not found

    if (parent == nullptr) {
      root_ = nullptr;  // if n is the root
    } else if (parent->l_child == n) {
      parent->l_child = nullptr;
    } else {
      parent->r_child = nullptr;
    }

    DeleteSubtree(n);
  }
};