// Reverse string function

#include <iostream>
#include <string>

using namespace std;

string ReverseString(string str) {
  // Base case is string is empty or one letter
  if (str.size() == 1 || str.size() == 0) return str;
  char s = str[str.size() - 1];
  str.pop_back();
  return s + ReverseString(str);
}

int main() {
  string str = "Hello";
  cout << ReverseString(str) << endl;
}