/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/18: Initial implementation
    - 2025/11/19: Refactored to use hash_fn.hpp
    - 2025/11/19: Finished Development

   Developer: YI-HSIANG LEE <piercelee0515@gmail.com> 
 */
#include "hash_fn.h"
#include <math.h>

int myHashInt(int key, int m) {
    const double A = 0.6180339;  
    double value = key * A;
    double frac  = value - floor(value);
    return (int)(frac * m);
}

int myHashString(const char* str, int m) {
    unsigned long hash = 5381;
    unsigned char c;

    while ((c = (unsigned char)*str++) != '\0')
    {
        hash = (hash << 5) + hash;  
        hash += c;                  
    }

    return (int)(hash % m);
}

