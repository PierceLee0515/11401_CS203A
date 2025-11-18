/*
   ========================================
   hash_fn.cpp --- implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/18: Initial implementation
    - 2025/11/18: Refactored to use hash_fn.hpp
    - 2025/11/19: Finished Development
   Developer: YI-HSIANG LEE <piercelee0515@gmail.com>
 */

#include <string>
#include <cmath>
#include <cctype>

int myHashInt(int key, int m) {
    const double A = 0.6180339;  
    double value = key * A;
    double frac  = value - std::floor(value);  
    return static_cast<int>(std::floor(m * frac));
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 5381;

    for (unsigned char c : str) {
        unsigned char lc = static_cast<unsigned char>(std::tolower(c));
        hash = ((hash << 5) + hash) + lc;  
    }

    return static_cast<int>(hash % static_cast<unsigned long>(m));  
