#include <iostream>
#include "singlyLinkedList.hpp"  // Assuming your header is named SinglyLinkedList.hpp

using namespace std;

int main() {
  SinglyLinkedList<int> list;

  for (int i = 1; i <= 4; i++) {
    list.Add(i);
  }

  list.Insert(5, 5);
  list.Insert(5, 4);
  list.Insert(5, 2);
  list.Insert(5, 0);
  list.Insert(5, 5);
  list.Insert(5, 5);
  list.Insert(5, 5);

  int k = 0;
  while (list.FindKth(k) != 0) {
    cout << list.FindKth(k) << ", ";
    k++;
  }
  cout << endl;

  for (int i = 0; i < 9; i++) {
    list.Remove(0);
  }

  k = 0;
  while (list.FindKth(k) != 0) {
    cout << list.FindKth(k) << ", ";
    k++;
  }
  cout << endl;

  list.Remove(0);
  
  return 0;
}
