#include "animal.h"

#include <iostream>

Animal::Animal(const std::string& name, const std::string& type, int age)
    : name_(name), type_(type), age_(age) {}

void Animal::Introduce() const {
  std::cout << "Hi, I’m " << name_ << " the " << type_
            << ". I am " << age_ << " years old." << std::endl;
}
