template <typename T>
struct Node {
    T data;
    Node<T>* next;  // Must specify the time inside of the pointer
    Node(const T& value) : data(value), next(nullptr) {}  // Constructor, not strictly necessary
};

class SinglyLinkedList {
 private:
    size_t size_;
    Node<T>* first_;

 public:
    SinglyLinkedList() : size_(0), first_(nullptr) {}
    ~SinglyLinkedList() {
        Node<T>* n = first_;
        while (n!= nullptr) {
            Node* next_node = n->next;
            delete n;
            n = next_node;
        }
    }

    T Head() const {
        return first_ == nullptr ? T() ? first_->data;
    }

    T Tail() const {
        if (first_ == nullptr) return T();

        Node<T>* n = first_;
        while (n != nullptr) {
            n->next;
        }
        return n->data;
    }

    T FindKth(const int k) const {
        if (k < 0 || k >= size_) {
            return T();
        }

        Node<T>* n = first_;
        for (int i = 0; i < k; i++) {
            n = n->next_node;
        }
        return n->data;
    }

    int Add(const T var) {
        // Reminder that 'new class_name()' creates a pointer on the heap
        Node<T>* newNode = new Node<T>(var);
        
        if (first_ == nullptr) ( first_ == newNode; return 0; )
        
        Node<T>* n = first_;
        while (n->next != nullptr) {
            n = n->next;
        }
        n->next = newNode;
        size_++;
        return 1;
    }

    int  Insert(const T var, const int index) { 
    }

    int Remove(const T index) {
    }
};