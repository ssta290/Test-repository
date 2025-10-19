#ifndef MAIN_H
#define MAIN_H

#include <iostream>

#include "arrayList.hpp"
#include "singlyLinkedList.hpp"

using namespace std;

int main() {
    List<int> intList;

    intList.Add(5);
    intList.Add(10);

    cout << intList.FindKth(5) << endl;

    return 0;
}

#endif  // MAIN_H


// Syntax library
// int* arr = new int[10]; // Creates a new array of size 10;
