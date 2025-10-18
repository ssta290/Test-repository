#ifndef MAIN_H
#define MAIN_H

#include <complex>
#include <iostream>
#include <vector>
#include <cmath>  // Defines M_PI

void twiddle(std::vector<std::complex<double>> &input) {   // Twiddles every eleent in an array
    std::complex<double> z1 = exp(std::complex<double>(0, -M_PI/10));
    
    // Modify element directly
    for (auto &element : input) {
        element *= z1;
    }
}

std::vector<std::complex<double>> rootsOfUnity(const int n) {
    // Preallocates array
    std::vector<std::complex<double>> output(n);

    for (int i = 0; i < n; i++) {
        output[i] = exp(std::complex<double>(0, i*(2*M_PI/n)));
    }

    return output;
}

int main() {
    auto third_roots = rootsOfUnity(3);

    // Prints roots
    std::cout << "The roots of unity are as follows:" << std::endl;
    for (const auto &root : third_roots) {
        std::cout << "-" << root << std::endl;
    }
    std::cout << std::endl;

    twiddle(third_roots);

    // Prints twiddled roots
    std::cout << "The twiddled roots of unity are as follows:" << std::endl;
    for (const auto &root : third_roots) {
        std::cout << "-" << root << std::endl;
    }

    return 0;
}

#endif  // MAIN_H
