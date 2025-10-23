#include <iostream>

#include "AVLTree.hpp"

using namespace std;

int main() {
  AVLTree tree;

  int values[] = { 5, 10, 4, 11, 12, 15, 2, 1 };

  for (auto i : values) {
    cout << "Inserting: " << i << endl;
    tree.Insert(i);
  }

  tree.Traverse();

  int values2[] = { 5, 10, 4 };

  for (auto i : values2) {
    cout << "Removing: " << i << endl;
    tree.Remove(i);
  }

  tree.Traverse();
}