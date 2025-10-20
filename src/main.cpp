#include <iostream>
#include <random>

#include "BST.hpp"

using namespace std;

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());  // Mersenne Twister generator
  std::uniform_int_distribution<> dis(1, 10);  // Distribution in the range [1, 10]

  BinarySearchTree<int> tree;

  cout << "Inserting Values: ";
  for (int i = 0; i < 10; i++) {
    int random_value = dis(gen);  // Generate a random number between 1 and 10
    std::cout << random_value << (i < 9 ? ", " : " ");
    tree.Insert(random_value);  // Insert into the BST
  }
  std::cout << std::endl << std::endl;

  cout << "Tree Contains: ";
  bool starting_flag = false;
  for (int i = 1; i <= 10; i++) {
    if (tree.Contains(i)) {
      if (starting_flag == false) {
        starting_flag = true;
      } else {
        std::cout << ", ";
      }

      std::cout << i;
    }
  }
  std::cout << std::endl;

  std::cout << "Minimum value: " << tree.FindMin() << std::endl;
  std::cout << "Maximum value: " << tree.FindMax() << std::endl;
}