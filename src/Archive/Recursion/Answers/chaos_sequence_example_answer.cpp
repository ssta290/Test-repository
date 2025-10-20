#include <iostream>

int chaos(int n) {
    // Base cases
    if (n == 1 || n == 2) {
        return 1;
    }
    
    // Recursive case: Q(n) = Q(n - Q(n-1)) + Q(n - Q(n - 2)) for n > 2
    return chaos(n - chaos(n - 1)) + chaos(n - chaos(n - 2));
}

int main() {
    std::cout << "Chaos Sequence (Hofstadter Q-sequence):" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Term  Value" << std::endl;
    std::cout << "----  -----" << std::endl;
    
    for (int i = 1; i <= 20; i++) {
        std::cout << i << "     " << chaos(i) << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "Note: This is the Hofstadter Q-sequence from 'Gödel, Escher, Bach'." << std::endl;
    std::cout << "The sequence exhibits chaotic behavior and is not monotonic." << std::endl;
    
    return 0;
}
