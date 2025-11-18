# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: 李奕翔 
Email: piercelee0515@gmail.com  

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  int myHashInt(int key, int m) {
    const double g = 0.618; //  1/Golden Ratio. golden ration:(sqrt(5)-1)/2
    double frac = (key * g) - floor(key * g);
    return static_cast<int>(floor(m * frac));
  }
  ```
- Rationale: Using the simple modulo operation ($key \pmod m$) for hashing can lead to poor performance, especially when the input keys exhibit an arithmetic progression (e.g., $10, 20, 30, 40, \dots$). In such cases, all keys map to the same index (zero) when the table size $m$ is $10$ or a multiple of $10$, causing clustering and increased collision rate.To mitigate this, I implemented the Multiplication Method using a constant $A$ derived from the Golden Ratio's conjugate, $\phi^{-1} \approx 0.618$ (where $\phi = (1 + \sqrt{5}) / 2$). The use of this irrational number $A$ ensures that the product of $key \times A$ results in fractional parts ($\{key \times A\}$) that are uniformly and evenly distributed across the range $[0, 1)$, regardless of any simple arithmetic patterns in the keys. This even distribution minimizes clustering and provides a more uniform spread of the resulting hash indices across the table size $m$.

### Non-integer Keys
- Formula / pseudocode:
  ```text
  int myHashString(const std::string& str, int m) {
    unsigned long hash = 5381;
    for(char c : str)
    {
        hash = ((hash << 5) + hash) + c;
    }
    return static_cast<int>(hash % m);  // basic division method
  }
  ```
- Rationale: i found that use this method although the size of string is the same the index will different.

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

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     5
  dog     3
  bat     6
  cow     0
  ant     6
  owl     1
  bee     3
  hen     6
  pig     3
  fox     8
  
  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     6
  dog     4
  bat     6
  cow     9
  ant     6
  owl     9
  bee     2
  hen     0
  pig     4
  fox     10
  
  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     29
  dog     13
  bat     13
  cow     13
  ant     19
  owl     14
  bee     19
  hen     13
  pig     7
  fox     25
  ```

- Observations: Although the index will different when the integers' unit digit are the same. the index become out of control.
- Example output for integers:
  ```
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
  ```
- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     5
  dog     3
  bat     6
  cow     0
  ant     6
  owl     1
  bee     3
  hen     6
  pig     3
  fox     8
  ```
## Analysis
- In my method when the key is small then m, it may not be useful.
- It can solution when key's unit digit are same.
- Index no rules.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. when the key's quantity is small then m, this method will not be useful.
