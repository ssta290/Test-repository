#include "app.h"

#include <iostream>

using namespace std;

const std::string framing = "The message is: ";

void PrintMessage(std::string message) {
    cout << framing << message << endl;
}