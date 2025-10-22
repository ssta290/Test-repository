#include <iostream>

#include "AVLTree.hpp"

using namespace std;

int main() {
  AVLTree tree;

  int insertions[] = { 5, 18, 19, 4, 10, 12, 20, 1, 8, 6 };

  for (auto i : insertions) {
    cout << "Inserting " << i << endl;
    tree.Insert(i);
  }
  cout << endl;

  cout << "Values successfully inserted" << endl;
}