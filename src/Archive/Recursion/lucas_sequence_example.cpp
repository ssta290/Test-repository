#include <iostream>

int lucas(int n) {
    if (n == 0) return 2;
    if (n == 1) return 1;
    return (lucas(n-1) + lucas(n-2));
}

int main() {
    std::cout << "Lucas Sequence:" << std::endl;
    std::cout << "===============" << std::endl;
    
    for (int i = 0; i < 10; i++) {
        std::cout << "L(" << i << ") = " << lucas(i) << std::endl;
    }
    
    return 0;
}
