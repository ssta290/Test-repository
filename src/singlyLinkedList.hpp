#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;  // Must specify the time inside of the pointer
    Node(const T& value) : data(value), next(nullptr) {}  // Constructor, not strictly necessary
};

template <typename T>
class SinglyLinkedList {
 private:
    Node<T>* head_;
    Node<T>* tail_;

 public:
    SinglyLinkedList() : head_(nullptr), tail_(nullptr) {}
    ~SinglyLinkedList() {
        Node<T>* n = head_;
        while (n!= nullptr) {
            Node<T>* next_node = n->next;
            delete n;
            n = next_node;
        }
    }

    T Head() const {
        return head_ == nullptr ? T() : head_->data;
    }

    T Tail() const {
        return head_ == nullptr ? T() : tail_->data;
    }

    T FindKth(const int k) const {
        Node<T>* n = head_;
        for (int i = 0; i < k; i++) {
            n = n->next;
            if (n == nullptr) return T();
        }
        return n->data;
    }

    int Add(const T var) {
        // Reminder that 'new class_name()' creates a pointer on the heap
        Node<T>* newNode = new Node<T>(var);
        
        if (head_ == nullptr) {
            head_ = newNode;
            tail_ = newNode;
            return 1;
        }
        
        Node<T>* n = head_;
        while (n->next != nullptr) {
            n = n->next;
        }
        n->next = newNode;
        tail_ = newNode;
        return 1;
    }

    int Insert(const T var, const int index) {
        Node<T>* newNode = new Node<T>(var);

        if (head_ == nullptr) {
            head_ = newNode;
            tail_ = newNode;
            return 1;
        }

        if (index == 0) {
            newNode->next = head_;
            head_ = newNode;
            return 1;
        } 

        Node<T>* n = head_;

        // Finds the entry before index
        for (int i = 0; i < index - 1; i++) {
            n = n->next;
            if (n == nullptr) return 0;
        }
        newNode->next = n->next;
        if (newNode->next == nullptr) tail_ = newNode;
        n->next = newNode;
        return 1;
    }

    int Remove(const T index) {
        if (head_ == nullptr) return 0;
        
        Node<T>* n = head_;

        if (index == 0) {   // Edge case for removing head
            head_ = head_->next;
            delete n;
            if (head_ == nullptr) tail_ = head_;   // Edge case if only head exists
            return 1;
        }

        for (int i = 0; i < index - 1; i++) {
            n = n->next;
            if (n == nullptr) return 0; // If the index doesn't exist, return 0
        }

        if (n->next == nullptr) return 0;  // Cannot remove non-existent item
        Node<T>* temp = n->next;
        n->next = temp->next;

        if (n->next == nullptr) {
            tail_ = n;
        }

        delete temp;
        return 1;
    }
};