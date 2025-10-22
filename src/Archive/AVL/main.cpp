#include <iostream>

#include "AVLTree.hpp"
#include "AVLTree2.hpp"

using namespace std;

int main() {
  AVLTree tree;
  AVLTree2<int> tree2;

  int insertions[] = {15, 27, 9, 3, 18, 29, 7, 11, 6, 19, 26, 30, 4, 2, 8, 10, 20, 25, 5, 28};

  for (auto i : insertions) {
    cout << "Inserting " << i << endl;
    tree.Insert(i);
  }
  cout << endl;

  cout << "Values successfully inserted" << endl;

  for (auto i : insertions) {
    cout << "Inserting " << i << endl;
    tree2.Insert(i);
  }
  cout << endl;

  cout << "Values successfully inserted" << endl;
}