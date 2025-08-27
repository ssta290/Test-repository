#pragma once

#include "animal.h"
#include <string>

class Cat : public Animal {
 public:
  // Cat knows it's a "cat", so callers don't need to pass the type.
  Cat(const std::string& name, int age);

  void Meow() const;

  void Introduce() const override;
};
