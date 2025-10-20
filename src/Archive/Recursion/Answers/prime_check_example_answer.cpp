#include <iostream>
#include <cmath>

bool is_prime_helper(int n, int divisor) {
    // Base case: if divisor > sqrt(n), then n is prime
    if (divisor > sqrt(n)) {
        return true;
    }
    
    // If n is divisible by divisor, then n is not prime
    if (n % divisor == 0) {
        return false;
    }
    
    // Check the next divisor
    return is_prime_helper(n, divisor + 1);
}

bool is_prime(int n) {
    // Base cases
    if (n <= 1) return false;  // Numbers <= 1 are not prime
    if (n == 2) return true;   // 2 is prime
    
    // Use helper function starting with divisor 2
    return is_prime_helper(n, 2);
}

int main() {
    std::cout << "Prime Number Check:" << std::endl;
    std::cout << "===================" << std::endl;
    
    int test_numbers[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 17, 19, 23, 25, 29, 31};
    int size = sizeof(test_numbers) / sizeof(test_numbers[0]);
    
    for (int i = 0; i < size; i++) {
        int num = test_numbers[i];
        std::cout << num << " is " << (is_prime(num) ? "prime" : "not prime") << std::endl;
    }
    
    return 0;
}
