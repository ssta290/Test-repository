#include "singlyLinkedList.hpp"

template <typename T>
class Queue {
 private:
  SinglyLinkedList<T> list_;

 public:
  Queue() : list_() {};
  ~Queue() {};
  void Enqueue(const T& value) {
    list_.Add(value);
  }
  T Dequeue() {
    T temp = list_.Head();
    list_.Remove(0);
    return temp;
  }
  T Peek() const {
    return list_.Head();
  }
};