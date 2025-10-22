#include <iostream>
#include <string>

void permute(std::string &s, int start = 0) {
    // Base case: if start >= s.length(), print the current permutation
    if (start >= s.length()) {
        std::cout << s << " ";
        return;
    }
    
    // Recursive case: for each position from start to end of string
    for (int i = start; i < s.length(); i++) {
        // Swap current character with character at position 'start'
        std::swap(s[start], s[i]);
        
        // Recursively permute the rest of the string (start+1)
        permute(s, start + 1);
        
        // Swap back to restore original order (backtracking)
        std::swap(s[start], s[i]);
    }
}

int main() {
    std::cout << "String Permutations:" << std::endl;
    std::cout << "====================" << std::endl;
    
    std::string test1 = "ABCDE";
    std::cout << "Permutations of \"" << test1 << "\":" << std::endl;
    permute(test1);
    std::cout << std::endl;
    
    return 0;
}
