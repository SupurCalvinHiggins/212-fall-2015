1 week -> half the problems as normal
~15 problems
12 core (10 points each)
2 extra (20 points each)
1 advanced (40 points)

objectives
Compute hash table properties (e.g. load factor, worst-case comparisons, average-case comparisons).
Apply operations (e.g. insert, resize) to linear probing, quadratic probing, double hashing, and separate chaining hash tables.
Evaluate hash functions
Analyze the time complexity of hash table operations.

TODO define real number spec (no trailing zeros, round to 4 digits)
define integer spec
define open addressing table spec
define closed addressing table spec

# Core Content

## Problem

Consider the following open addressing hash table:
```txt
[E,E,3,1,0,E,8,7,2,5]
```

What is the table's load factor? Give your answer as a real number.
[____](0.7)

## Problem

Consider the following closed addressing hash table:
```txt
[[],[0,1,5],[4,2,7,8],[]]
```

What is the table's load factor? Give your answer as a real number.
[____](1.75)

## Problem

Insert the following sequence of numbers into an empty linear probing hash table:
```txt
7,3,11,0
```
The hash function is $h(k) = k \bmod m$ where $m$ is the capacity, the maximum load factor is $0.5$, the initial capacity is $1$, and the capacity doubles when resizing.

What is the final table? Give your answer as an open addressing hash table.
[____]([0,E,E,3,11,E,E,7])

How many collisions occurred during the insertions? Give your answer as a single integer.
[____](5)

When querying the final table, what is the worst-case number of probes? Give your answer as a single integer.
[____](3)

## Problem

Insert the following sequence of numbers into an empty quadratic probing hash table:
```txt
0,8,3,12
```
The hash function is $h(k) = k \bmod m$ where $m$ is the capacity, the maximum load factor is $0.5$, the initial capacity is $1$, and the capacity doubles when resizing.

What is the final table? Give your answer as an open addressing hash table.
[____]([0,8,E,3,12,E,E,E])

How many collisions occurred during the insertions? Give your answer as a single integer.
[____](4)

When querying the final table, what is the worst-case number of probes? Give your answer as a single integer.
[____](3)

## Problem

Insert the following sequence of numbers into an empty double hashing hash table:
```txt
2,1,5,9
```
The hash functions are $h_1(k) = k \bmod m$ and $h_2(k) = 1 + (k \bmod (m - 1))$ where $m$ is the capacity, the maximum load factor is $0.5$, the initial capacity is $1$, and the capacity doubles when resizing.

What is the final table? Give your answer as an open addressing hash table.
[____]([E,1,2,E,9,5,E,E])

How many collisions occurred during the insertions? Give your answer as a single integer.
[____](1)

When querying the final table, what is the worst-case number of probes? Give your answer as a single integer.
[____](3)

## Problem

Insert the following sequence of numbers into an empty separate chaining hash table:
```txt
1,9,2,17
```
The hash function is $h(k) = k \bmod m$ where $m$ is the capacity, the maximum load factor is $0.5$, the initial capacity is $1$, the capacity doubles when resizing, and insertions occur at the back of the list.

What is the final table? Give your answer as a closed addressing hash table.
[____]([[],[1,9,17],[2],[],[],[],[],[]])

How many collisions occurred during the insertions? Give your answer as a single integer.
[____](4)

When querying the final table, what is the worst-case number of comparisons? Give your answer as a single integer.
[____](4)

## Problem

expected number of comparisons (concrete table)

Consider the following separate chaining hash table:
```txt
[[1,5,4,2], [3,6], [7], [8,9]]
```
The hash function is $h(k) = k \bmod m$ where $m$ is the capacity.

What is the expected number of comparisons when $1$ and $2$ are each queried with probability $1/2$? Give your answer as a real number.
[____](2.5)

## Problem

Suppose a hash table resizes to maintain a constant load factor of $0.5$ after every insertion:
```c++
template <typename T>
class HashTable {
    T* m_data;
    size_t m_size;
    size_t m_capacity;
    
    void resize(size_t new_capacity) {
        // ...
    }

public:
    void insert(T key) {
        // ...
        if (m_capacity != 2 * m_size) {
            resize(2 * m_size);    
        }
    }
};
```

What is the time complexity of insert?

( ) $\Theta(1)$ amortized expected
( ) $\Theta(\lg n)$
( ) $\Theta(\sqrt{n})$
(X) $\Theta(n)$

## Problem

Suppose a hash table resizes to maintain a maximum load factor of $0.5$ after every insertion:
```c++
template <typename T>
class HashTable {
    T* m_data;
    size_t m_size;
    size_t m_capacity;
    
    void resize(size_t new_capacity) {
        // ...
    }

public:
    void insert(T key) {
        // ...
        if (m_capacity < 2 * m_size) {
            resize(2 * m_size);    
        }
    }
};
``` 

What is the time complexity of insert?

(X) $\Theta(1)$ amortized expected
( ) $\Theta(\lg n)$
( ) $\Theta(\sqrt{n})$
( ) $\Theta(n)$

## Problem
 
What is the lexicographically smallest worst-case insertion sequence of $8$ distinct non-negative integers into a fixed-capacity separate chaining hash table with $16$ slots? Assume the hash function is $h(k) = k \bmod m$ where $m$ is the capacity. Give your answer as a comma-seperated list of integers.

[____](0,16,32,48,64,80,96,112)

## Problem

Suppose we want build a capacity $17$ linear probing hash table.

Is $h(k) = 34k \bmod 17$ a good hash function?
( ) Yes
(X) No

Is $h(k) = k \bmod 4$ a good hash function?
( ) Yes
(X) No

Is $h(k) = (31k \bmod 101) \bmod 17$ a good hash function?
(X) Yes
( ) No

## Problem

Suppose we want to build a capacity $17$ double hashing hash table.

Are $h_1(k) = k \bmod 17$ and $h_2(k) = 3k \bmod 17$ good hash functions?
( ) Yes
(X) No

Are $h_1(k) = k \bmod 17$ and $h_2(k) = 1 + ((31k \bmod 101) \bmod 16)$ good hash functions?
(X) Yes
( ) No

Are $h_1(k) = k \bmod 17$ and $h_2(k) = (31k \bmod 101) \bmod 17$ good hash functions?
( ) Yes
(X) No

# Extra Practice

## Problem

Consider the following fixed capacity linear probing hash table:
```txt
[27,0,9,11,3,5,13,22]
```
The hash function is $h(k) = k \bmod m$ where $m$ is the table capacity.

What order were the keys inserted in? Give your answer as a comma-separated list of integers.
[____](11,3,5,13,22,27,0,9)

## Problem
Consider the following fixed capacity quadratic probing hash table:
```txt
[5,11,1,8,10]
```
The hash function is $h(k) = k \bmod m$ where $m$ is the table capacity.

How many different insertion orders yield the table? Give your answer as a single integer.
[____](10)

# Optional Advanced Topics

## Problem

Consider a separate chaining hash table with $100$ keys and load factor $0.3$. Assume **simple uniform hashing**, that is, $P(h(k_1) = h(k_2)) = \frac{1}{m}$ for $k_1 \neq k_2$. What is the expected number of comparisons when querying a key stored in the table? Assume all keys are queried with equal probability. Give your answer as a real number.
[____](1.1485)