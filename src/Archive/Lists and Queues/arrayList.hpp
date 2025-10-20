template <typename T>
class List {
 private:
  T* list_array_;
  int max_size_;
  int list_size_;

 public:
  List() : max_size_(10), list_array_(new T[max_size_]), list_size_(0) {}
  ~List() { delete[] list_array_; }
  T Head() const {
    return list_size_ == 0 ? T() : list_array_[0];
  }
  T Tail() const {
    return list_size_ == 0 ? T() : list_array_[list_size_ - 1];
  }
  T FindKth(const int k) const {
    return (k < 0 || k > list_size_ - 1) ? T() : list_array_[k];
  }
  int Add(const T var) {
    if (list_size_ == max_size_) {
      return 0;
    }

    list_array_[list_size_] = var;    
    list_size_++;
    return 1;
  }
  int Insert(const T var, const int index) { 
    if (list_size_ >= max_size_ || index < 0 || index > list_size_) {
      return 0;
    }

    // Moves every element backwards
    for (int i = list_size_; i > index; i--) {
      list_array_[i] = list_array_[i - 1];
    }

    list_array_[index] = var;
    list_size_++;
    return 1;
  }
  int Remove(const T index) {
    if (index < 0 || index >= list_size_) {
      return 0;
    }

    for (int i = index; i < list_size_ - 1; i++) {
      list_array_[i] = list_array_[i+1];
    }
    list_size_--;
    return 1;
  }
};