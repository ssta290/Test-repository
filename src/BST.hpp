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
    if (!root_) {
      return T();
    }

    Node<T>* n = root_;
    while (true) {
      if (!(n->l_child)) return n->data;

      n = n->l_child;
    }
  }
  T FindMax() const {
    if (!root_) {
      return T();
    }

    Node<T>* n = root_;
    while (true) {
      if (!(n->r_child)) return n->data;

      n = n->r_child;
    }
  }
  bool Contains(const T& value) const {
    Node<T>* n = root_;
    while (true) {
      if (!n) {
        return false;
      }

      if (value < n->data) {
        n = n->l_child;
      } else if (value == n->data) {
        return true;
      } else {
        n = n->r_child;
      }
    }
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
  std::vector<T> Traverse() const { return std::vector<T>(1, T()); }
  void Remove(const T& value) {
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