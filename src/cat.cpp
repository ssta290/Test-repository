#include "cat.h"

#include <iostream>

Cat::Cat(const std::string& name, int age)
    : Animal(name, "cat", age) {}

void Cat::Meow() const {
  std::cout << name_ << " says: Meow!" << std::endl;
}

void Cat::Introduce() const {
    Animal::Introduce();
    std::cout << "But Cats can introduce themselves differently" << std::endl;
}