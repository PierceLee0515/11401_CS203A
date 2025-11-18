/*
   ========================================
   hash_fn.cpp --- implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Change integer and string hash
    - 2025/11/19: Minor refinement on hash implementations

   Developer: CHIJUILEE <ready950110@gmail.com>
 */

#include <string>
#include <cmath>
#include <cctype>

int myHashInt(int key, int m) {
    // Using a multiplication method with an irrational constant
    const double A = 0.6180339;   // closer to (sqrt(5) - 1) / 2
    double value = key * A;
    double frac  = value - std::floor(value);  // keep only fractional part
    return static_cast<int>(std::floor(m * frac));
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 5381;

    for (unsigned char c : str) {
        // normalize to lowercase to treat 'A' and 'a' as the same
        unsigned char lc = static_cast<unsigned char>(std::tolower(c));
        hash = ((hash << 5) + hash) + lc;  // hash * 33 + lc
    }

    return static_cast<int>(hash % static_cast<unsigned long>(m));  // basic division method
}
