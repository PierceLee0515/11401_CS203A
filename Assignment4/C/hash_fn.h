/*
   ========================================
   hash_fn.h --- declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/18: Initial implementation
    - 2025/11/19: Finished Development
   Developer:YI-HSIANG LEE <piercelee0515@gmail.com>
 */
#ifndef HASH_FN_H
#define HASH_FN_H

#include <stdio.h>
#include <string.h>

int myHashInt(int key, int m);
int myHashString(const char* str, int m);

#endif
