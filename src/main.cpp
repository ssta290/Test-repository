#include "cat.h"

#include <iostream>

void IntroduceManually(const Animal *animal) {
  animal->Introduce();
}

int main() {
  int i = 3;
  int* j = &i;

  std::cout << j << std::endl;

  std::cout << *j << std::endl;

  return 0;
}
