/*
   ========================================
   hash_fn.hpp — declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/18: Initial implementation
    - 2025/11/19: Finished Development
   Developer: YI-HSIANG LEE <piercelee0515@gmail.com> 
 */
#ifndef HASH_FN_HPP
#define HASH_FN_HPP

#include <string>
int myHashInt(int key, int m);
int myHashString(const std::string& str, int m);


#endif
