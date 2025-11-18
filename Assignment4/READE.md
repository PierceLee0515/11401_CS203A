# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: 李奕翔
Email: piercelee0515@gmail.com  

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
```cpp
int myHashInt(int key, int m) {
    unsigned int x = static_cast<unsigned int>(key);

    x *= 2654435761u;

    unsigned int hash = x >> 16;

    return static_cast<int>(hash % m);
}


  ```
- Rationale
A direct modulo hash (`key % m`) works, but it tends to create noticeable clustering when the input keys follow simple numeric patterns.  
For example, if the keys increase in steps (10, 20, 30, ...), and the table size `m` is 10 or a multiple of it, many values collapse into the same index.  
This leads to repeated collisions and a poor overall distribution.

To avoid this issue, I chose the **Multiplication Method**, using a constant  
`A ≈ 0.618`, which comes from the inverse of the Golden Ratio.  
Because this value is irrational, multiplying a key by `A` produces fractional parts that do **not** repeat in simple cycles.  
As a result, the hash values get spread much more evenly across the interval `[0, 1)`, and after scaling by `m`, the final indices become far more uniform.  
This approach helps break the arithmetic pattern of the input keys and reduces clustering significantly.


Because `A` is an **irrational number**, the fractional part of `(key * A)` avoids repeating patterns,  
resulting in a more uniform spread of hash indices and reduced clustering compared to simple modulo hashing.


### Non-integer Keys
- Formula / pseudocode:
  ```cpp
   int myHashString(const std::string& str, int m) {
    unsigned long hash = 5381;
    for (char c : str) {
        hash = (hash << 5) + hash + static_cast<unsigned char>(tolower(c));  
    }
    return static_cast<int>(hash % m);
}


  ```
- Rationale
Although the strings may have the same length, this hashing method still produces different indices.  
This shows that the hash function accounts for the actual characters and their order, not just the length, resulting in more varied and reliable hash values.


## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Example output for integers:
  ```
   === Hash Function Observation (C Version) ===
  
  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      9
  22      5
  23      2
  24      8
  25      4
  26      0
  27      6
  28      3
  29      9
  30      5
  51      5
  52      1
  53      7
  54      3
  55      9
  56      6
  57      2
  58      8
  59      4
  60      0
  
  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      6
  23      2
  24      9
  25      4
  26      0
  27      7
  28      3
  29      10
  30      5
  51      5
  52      1
  53      8
  54      4
  55      10
  56      6
  57      2
  58      9
  59      5
  60      0
  
  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      36
  22      22
  23      7
  24      30
  25      16
  26      2
  27      25
  28      11
  29      34
  30      19
  51      19
  52      5
  53      27
  54      13
  55      36
  56      22
  57      8
  58      31
  59      17
  60      2

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      9
  22      5
  23      2
  24      8
  25      4
  26      0
  27      6
  28      3
  29      9
  30      5
  51      5
  52      1
  53      7
  54      3
  55      9
  56      6
  57      2
  58      8
  59      4
  60      0

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      6
  23      2
  24      9
  25      4
  26      0
  27      7
  28      3
  29      10
  30      5
  51      5
  52      1
  53      8
  54      4
  55      10
  56      6
  57      2
  58      9
  59      5
  60      0
  
  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      36
  22      22
  23      7
  24      30
  25      16
  26      2
  27      25
  28      11
  29      34
  30      19
  51      19
  52      5
  53      27
  54      13
  55      36
  56      22
  57      8
  58      31
  59      17
  60      2
  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations:
    * Outputs align with the analysis, showing better distribution with prime table sizes.
    * With a table size of 10, the modulo operation causes the index to be determined primarily by the key's least significant digit.
## Analysis
- When the key range is small compared to the table size, the multiplication method may not provide meaningful distribution.
- This approach successfully avoids collisions that normally occur when keys share the same last digit.
- The resulting indices do not follow any simple pattern, showing that the method breaks arithmetic structure but may also become unstable for small datasets.


## Reflection
1. Creating an effective hash function involves finding a balance between simplicity and collision reduction.
2. The multiplication method loses efficiency when the number of keys is much smaller than the chosen table size.
3. While the method helps eliminate repetitive modulo-based collisions, its randomness can make the distribution less predictable for small sets of keys.
