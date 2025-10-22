#include <iostream>
#include <cmath>

bool is_prime(int n) {
    // TODO: Implement the prime number checking function here
    // A prime number is a natural number greater than 1 that is not a product of
    // two smaller natural numbers.
    // 
    // Think about it: What numbers are definitely not prime?
    // When do you know for sure that a number is prime?
    // What about the number 2? What makes it special?
    // How can you check if a number has any divisors?
    // How can you systematically check all possible divisors?
    // What's the upper limit for divisors you need to check?
    // Hint: You might want to use a helper function with a divisor parameter

    if (n == 2) return true; 
    int i = 2;
    while (i < n) {

    }
}

bool is_prime_helper(int n, int divisor) {
    // TODO: Implement the helper function for prime checking
    return 0;
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
