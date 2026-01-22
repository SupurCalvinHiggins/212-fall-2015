# Overview

In this assignment, you will practice with hash tables.

## Learning Objectives

By the end of this assignment, you should be able to:

1. Compute common hash table properties (e.g. load factor, worst-case comparisons, expected comparisons).
2. Apply common hash table operations (e.g. insert, search, resize) to linear probing, quadratic probing double hashing and separate chaining hash tables.
3. Evaluate the suitability of hash functions for hash tables.
4. Analyze the time complexity of common hash table operations.

## Grading

This assignment is graded out of $$100$$ points. However, we provide $$200$$ points' worth of problems:

1. Only your first $$100$$ points count towards your grade.
2. The extra problems give you flexibility to:
    * Choose problems that best support your learning
    * Earn more than $$100$$ points in case of mistakes (your grade will be capped at $$100$$).
    * Practice additional problems in preparation for the midterm.

**You are not expected to complete every problem!**

## Milestones

Problems are labeled as **Core Content**, **Extra Practice** or **Optional Advanced Topics**.

To prepare for the midterm, you should:

1. Complete at least one of each **Core Content** problem type

## Recommendations

The midterm will include many free response questions. To prepare effectively:

* Avoid relying on multiple choice options to guide your answer. Instead, work out your solution first, then check against the choices.
* Use any available  resources (including AI), but always attempt each problem on your own for 5-10 minutes before seeking help.

## Answer Formats

**Short answer questions are autograded. You must follow the format specified below to receive credit.**

If the problem asks for:
1. A single integer, provide your answer as a single integer without whitespace. For example, `10`.
2. A single real number, provide your answer as a real number truncated to 4 decimal places without whitespace or trailing zeroes. For example, `1.12` 
3. A comma-delimited list of integers, provide your answer as a comma-delimited list without whitespace. For example, `3,1,4,0,12`.
4. An open addressing hash table, provide your answer as an array without whitespace where empty slots are denoted with `E`. For example, `[1,E,0,4,5,E,E,8,E]`.
5. A closed addressing hash table, provide your answer as a nested array without whitespace. For example, `[[1],[],[4,5],[2,6,7]]`.

## Submission

**Before you submit, attach a PDF containing your work for every question you answered:**

|files|

It doesn't need to be neat, we just want to be able to understand your process.

Note that you can submit as many times as you want before the due date!

## Confirmation

I have read and understand the above.

(X) Yes
( ) No

# Core Content

## Problem

Consider the following open addressing hash table:
```txt
[E,E,3,1,0,E,8,7,2,5]
```

What is the table's load factor? Give your answer as a single real number.

[____](0.7)

## Problem

Consider the following closed addressing hash table:
```txt
 [[],[0,1,5],[4,2,7,8],[]]
```

What is the table's load factor? Give your answer as a single real number.

[____](1.75)

## Problem

Insert the following sequence of numbers into an empty linear probing hash table:
```txt
7,3,11,0
```
The hash function is $$h(k) = k \bmod m$$ where $$m$$ is the capacity, the maximum load factor is $$0.5$$, the initial capacity is $$1$$, and the capacity doubles when resizing.

What is the final table? Give your answer as an open addressing hash table.

[____]([0,E,E,3,11,E,E,7])

How many collisions occurred during the insertions? Give your answer as a single integer.

[____](2)

When querying the final table, what is the worst-case number of probes? Give your answer as a single integer.

[____](3)

## Problem

Insert the following sequence of numbers into an empty quadratic probing hash table:
```txt
0,8,3,12
```
The hash function is $$h(k) = k \bmod m$$ where $$m$$ is the capacity, the maximum load factor is $$0.5$$, the initial capacity is $$1$$, and the capacity doubles when resizing.

What is the final table? Give your answer as an open addressing hash table.

[____]([0,8,E,3,12,E,E,E])

How many collisions occurred during the insertions? Give your answer as a single integer.

[____](2)

When querying the final table, what is the worst-case number of probes? Give your answer as a single integer.

[____](3)

## Problem

Insert the following sequence of numbers into an empty double hashing hash table:
```txt
2,1,5,9
```
The hash functions are $$h_1(k) = k \bmod m$$ and $$h_2(k) = 1 + (k \bmod (m - 1))$$ where $$m$$ is the capacity, the maximum load factor is $$0.5$$, the initial capacity is $$1$$, and the capacity doubles when resizing.

What is the final table? Give your answer as an open addressing hash table.

[____]([E,1,2,E,9,5,E,E])

How many collisions occurred during the insertions? Give your answer as a single integer.

[____](1)

When querying the final table, what is the worst-case number of probes? Give your answer as a single integer.

[____](4)

## Problem

Insert the following sequence of numbers into an empty separate chaining hash table:
```txt
1,9,2,17
```
The hash function is $$h(k) = k \bmod m$$ where $$m$$ is the capacity, the maximum load factor is $$0.5$$, the initial capacity is $$1$$, the capacity doubles when resizing, and insertions occur at the back of the list.

What is the final table? Give your answer as a closed addressing hash table.

[____]([[],[1,9,17],[2],[],[],[],[],[]])

How many collisions occurred during the insertions? Give your answer as a single integer.

[____](4)

When querying the final table, what is the worst-case number of comparisons? Give your answer as a single integer.

[____](3)

## Problem

Consider the following separate chaining hash table:
```txt
 [[1,5,4,2],[3,6],[7],[8,9]]
```

What is the expected number of comparisons when $$1$$ and $$2$$ are each queried with probability $$1/2$$? Give your answer as a single real number.

[____](2.5)

## Problem

Suppose a hash table resizes to maintain a constant load factor of $$0.5$$ before every insertion:
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
        if (m_capacity != 2 * (m_size + 1)) {
            resize(2 * (m_size + 1));    
        }
        // ...
    }
};
```

What is the time complexity of insert?

( ) $$\Theta(1)$$ amortized expected
( ) $$\Theta(\lg n)$$
( ) $$\Theta(\sqrt{n})$$
(X) $$\Theta(n)$$

## Problem

Suppose a hash table resizes to maintain a maximum load factor of $$0.5$$ before every insertion:
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
        if (m_capacity < 2 * (m_size + 1)) {
            resize(2 * (m_size + 1));    
        }
        // ...
    }
};
``` 

What is the time complexity of insert?

(X) $$\Theta(1)$$ amortized expected
( ) $$\Theta(\lg n)$$
( ) $$\Theta(\sqrt{n})$$
( ) $$\Theta(n)$$

## Problem
 
What is the lexicographically smallest worst-case insertion sequence of $$8$$ distinct non-negative integers into a fixed-capacity separate chaining hash table with $$16$$ slots? Assume the hash function is $$h(k) = k \bmod m$$ where $$m$$ is the capacity. Give your answer as a comma-seperated list of integers.

[____](0,16,32,48,64,80,96,112)

## Problem

Suppose we want build a capacity $$17$$ linear probing hash table.

Is $$h(k) = 34k \bmod 17$$ a good hash function?

( ) Yes
(X) No

Is $$h(k) = k \bmod 4$$ a good hash function?

( ) Yes
(X) No

Is $$h(k) = (31k \bmod 101) \bmod 17$$ a good hash function?

(X) Yes
( ) No

## Problem

Suppose we want to build a capacity $$17$$ double hashing hash table.

Are $$h_1(k) = k \bmod 17$$ and $$h_2(k) = 3k \bmod 17$$ good hash functions?

( ) Yes
(X) No

Are $$h_1(k) = k \bmod 17$$ and $$h_2(k) = 1 + ((31k \bmod 101) \bmod 16)$$ good hash functions?

(X) Yes
( ) No

Are $$h_1(k) = k \bmod 17$$ and $$h_2(k) = (31k \bmod 101) \bmod 17$$ good hash functions?

( ) Yes
(X) No

# Extra Practice

## Problem

Consider the following fixed capacity linear probing hash table:
```txt
[27,0,9,11,3,4,13,22]
```
The hash function is $$h(k) = k \bmod m$$ where $$m$$ is the table capacity.

What order were the keys inserted in? Give your answer as a comma-separated list of integers.

[____](11,3,4,13,22,27,0,9)

## Problem

Consider the following fixed capacity quadratic probing hash table:
```txt
[5,11,1,8,10]
```
The hash function is $$h(k) = k \bmod m$$ where $$m$$ is the table capacity.

How many different insertion orders yield the table? Give your answer as a single integer.

[____](25)

# Optional Advanced Topics

## Problem

Consider a separate chaining hash table with $$100$$ keys and load factor $$0.3$$. Assume **simple uniform hashing**, that is, $$P(h(k_1) = h(k_2)) = \frac{1}{m}$$ for $$k_1 \neq k_2$$. 

What is the expected number of comparisons when querying a key stored in the table? Assume all keys are queried with equal probability. Give your answer as a single real number.

[____](1.1485)