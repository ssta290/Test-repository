#pragma once

#include <string>

class Animal {
 protected:
  const std::string name_;
  const std::string type_;
  int age_;

 public:
  Animal(const std::string& name, const std::string& type, int age);

  virtual void Introduce() const;
  virtual void Walk() const = 0;
};
