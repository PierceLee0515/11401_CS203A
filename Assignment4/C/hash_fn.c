#include "hash_fn.h"
#include <math.h>

int myHashInt(int key, int m) {
    const double A = 0.6180339;   // slightly more precise constant
    double value = key * A;
    double frac  = value - floor(value);
    return (int)(frac * m);
}

int myHashString(const char* str, int m) {
    unsigned long hash = 5381;
    unsigned char c;

    while ((c = (unsigned char)*str++) != '\0')
    {
        hash = (hash << 5) + hash;  // hash * 32 + hash
        hash += c;                  // += character
    }

    return (int)(hash % m);
}

