/* 
   ========================================
   Hash Function Observation (C++ Version)
   ========================================
   
   Description:
   This program tests and displays the output of hash functions for integer
   and string keys using different table sizes. It utilizes the hash functions
   defined in "hash_fn.cpp".

   Development History:
    - 2025/11/18: Initial implementation
    - 2025/11/19: Finished Development
   Developer: YI-HSIANG LEE <piercelee0515@gmail.com> 
 */

#include <iostream>
#include <vector>
#include <string>
#include "hash_fn.hpp"
using namespace std;


int main() {
    // Integer keys
    vector<int> intKeys = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60};
    
    vector<int> sizes = {10, 11, 37};

    cout << "=== Hash Function Observation (C++ Version) ===\n\n";

    for (int m : sizes) {
        cout << "=== Table Size m = " << m << " ===\n";
        cout << "Key\tIndex\n";
        cout << "-----------------\n";
        for (int k : intKeys)
            cout << k << "\t" << myHashInt(k, m) << "\n";
        cout << "\n";
    }


    vector<string> strKeys = {"cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"};
    for (int m : sizes) {
        cout << "=== String Hash (m = " << m << ") ===\n";
        cout << "Key\tIndex\n";
        cout << "-----------------\n";
        for (const auto& s : strKeys)
            cout << s << "\t" << myHashString(s, m) << "\n";
        cout << "\n";
    }
}
