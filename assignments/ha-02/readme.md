# Overview

## Learning Objectives

1. Model the number of basic operations performed by an algorithm with functions and summations.
2. Simplify summations of polynomials and exponential functions arising from the analysis of algorithms.
3. State asymptotic bounds on logarithmic, polynomial and exponential functions in $\Theta$, $\Omega$ and 
   $\mathcal{O}$-notation.
4. Order logarithmic, polynomial and exponential functions by growth rate.
5. Classify the growth rate of logarithmic, polynomial and exponential functions.
6. Select algorithms based on asymptotic descriptions of time and space complexity.

## Grading

TODO

# Problems

## Stating Cost Functions

### Problem

Consider the following program to compute the maximum element of an array.
```cpp
int max_element(int* A, int n) {
    int max = A[0];
    for (int i = 1; i < n; ++i) {
        if (max < A[i]) {
            max = A[i];
        }
    }
    return max;
}
```

Which of the following functions counts the number of array accesses performed on an input of size $$n$$?

( ) $$T(n) = \sum\limits_{i=1}^{n} 2$$
( ) $$T(n) = \sum\limits_{i = 1}^{n - 1} 2$$
( ) $$T(n) = 1 + \sum\limits_{i = 1}^{n} 2$$
(X) $$T(n) = 1 + \sum\limits_{i = 1}^{n - 1} 2$$

### Problem

Consider the following program to compute the product between an $$n \times n$$ matrix $$A$$ and a vector of $$n$$ elements $$x$$.
```cpp
void matvec(double** A, double* x, double* out, int n) {
    for (int i = 0; i < n; ++i) {
        int dot = 0.0;
        for (int j = 0; j < n; ++j) {
            dot += A[i][j] * x[j];
        }
        out[i] = dot;
    }
}
```

Which of the following functions counts the number of multiplications performed on an input of size $$n$$?

( ) $$T(n) = \sum\limits_{i = 0}^{n}\sum\limits_{j = 0}^{i} 1$$
( ) $$T(n) = \sum\limits_{i = 0}^{n - 1}\sum\limits_{j = 0}^{i - 1} 1$$
(X) $$T(n) = \sum\limits_{i = 0}^{n - 1}\sum\limits_{j = 0}^{n - 1} 1$$
( ) $$T(n) = \sum\limits_{i = 0}^{n}\sum\limits_{j = 0}^{n} 1$$

### Problem

Consider the following program to count the number of solutions to an instance of the 2SUM problem.
```cpp
int count_solutions(int* A, int n, int target) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int ai = A[i];
        for (int j = 0; j < i; ++j) {
            if (ai + A[j] == target) {
                ++total;
            }
        }
    }
    return total;
}
```

Which of the following functions counts the number of array accesses performed on an input of size $$n$$?

(X) $$T(n) = \sum\limits_{i = 0}^{n - 1}\left(1 + \sum\limits_{j = 0}^{i - 1} 1 \right)$$
( ) $$T(n) = \sum\limits_{i = 0}^{n - 1}\sum\limits_{j = 0}^{i - 1} 2$$
( ) $$T(n) = \sum\limits_{i = 0}^{n - 1}\sum\limits_{j = 0}^{i - 1} 1$$
( ) $$T(n) = \sum\limits_{i = 0}^{n - 1}\left(1 + \sum\limits_{j = 0}^{n - 1} 1 \right)$$

### Problem

Consider the following algorithm to check if an element is contained in array $$A$$ of size $$n$$.
```cpp
bool contains(int* A, int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (A[i] == target) {
            return true;
        }
    }
    return false;
}
```

Which of the following functions counts the number of array accesses performed on a **best-case input** of size $$n$$?

( ) $$T(n) = \sum\limits_{i = 0}^{n - 1} 1$$
( ) $$T(n) = \sum\limits_{i = 0}^n 1$$
(X) $$T(n) = 1$$
( ) $$T(n) = \sum\limits_{i = 0}^{n-1} 2$$

### Problem

Consider the following algorithm to check if an element is contained in array $$A$$ of size $$n$$.
```cpp
bool contains(int* A, int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (A[i] == target) {
            return true;
        }
    }
    return false;
}
```

Which of the following functions counts the number of array accesses performed on a **worst-case input** of size $$n$$?

(X) $$T(n) = \sum\limits_{i = 0}^{n - 1} 1$$
( ) $$T(n) = \sum\limits_{i = 0}^n 1$$
( ) $$T(n) = 1$$
( ) $$T(n) = \sum\limits_{i = 0}^{n-2} 1$$

### Problem

Consider the following algorithm to check if an element is contained in array $$A$$ of size $$n$$.
```cpp
bool contains(int* A, int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (A[i] == target) {
            return true;
        }
    }
    return false;
}
```

Which of the following functions counts the number of array accesses performed on an **average-case input** of size $$n$$? 

Assume that the target is not in the array with probability $$\frac{1}{n + 1}$$. Also, assume that if the target is in the array, it only occurs once and each possible position is equally likely. 

( ) $$T(n) = \frac{1}{n + 1} + \sum\limits_{i = 0}^{n - 1} \frac{i + 1}{n + 1}$$
(X) $$T(n) = \frac{n}{n + 1} + \sum\limits_{i = 0}^{n - 1} \frac{i + 1}{n + 1}$$
( ) $$T(n) = \sum\limits_{i = 0}^{n} \frac{i}{n + 1}$$
( ) $$T(n) = \frac{1}{n + 1} + \sum\limits_{i = 0}^{n - 1} \frac{i}{n + 1}$$

## Simplifying Cost Functions

### Problem

Which of the following is the simplified form of $$\sum\limits_{i = 1}^{n} 2$$?

( ) $$n$$
( ) $$2n - 1$$
( ) $$2(n - 1)$$
(X) $$2n$$

### Problem

Which of the following is the simplified form of $$\sum\limits_{i = 0}^{n^2} i$$?

( ) $$\frac{n(n + 1)(2n + 1)}{6}$$
( ) $$\frac{n(n + 1)}{2}$$
(X) $$\frac{n^2(n^2 + 1)}{2}$$
( ) $$\frac{n^2(n^2 + 1)}{2} + 1$$

### Problem

Which of the following is the simplified form of $$\sum\limits_{i = 2}^{n} i^2$$?

(X) $$\frac{n(n + 1)(2n + 1)}{6} - 1$$
( ) $$\frac{n(n + 1)(2n + 1)}{6}$$
( ) $$\frac{n(n + 1)(2n + 1)}{6} + 1$$
( ) $$\frac{n(n + 1)(2n + 1)}{6} + 2$$

### Problem

Which of the following is the simplified form of $$\sum\limits_{i=0}^{n - 1} \left( n + \sum\limits_{j=0}^{i} 1 \right)$$?

(X) $$n(n + 1) + \frac{n(n-1)}{2}$$
( ) $$n^2 + \frac{n(n-1)}{2}$$
( ) $$n^2 + \frac{n(n+1)}{2}$$
( ) $$2n^2$$

### Problem

Which of the following is the simplified form of $$\sum\limits_{i=0}^{\lg n - 1} 3 \cdot 2^i$$?

( ) $$3 (\lg n - 1)$$
( ) $$3n - 1$$
( ) $$\frac{3 (\lg n) (\lg n + 1)}{2}$$
(X) $$3(n - 1)$$

## Bounding Cost Functions

multiple select:
which of the following bounds are correct?
on 2n + 3

on n^2 + 3 n \lg n - 2n

on 7n^3 + 2^16

on 2 * 3^n + 2^n + 3 * n^4

given a function is O(n^2) and Omega(n lg n) which of the following is possible?
various theta bounds


## Comparing Cost Functions

remember to shuffle the terms so it isnt always in the right order

order these
5lg n + 100, sqrt(n) + 7, 3n^{1 / 4} + lg n, n^3 + 2n
n^2 + 50n, n^sqrt(3) + 1000, 2^n + n^3, 3^n + n
7 lg^2 n, 2^{lg n}, n^2 + 5n lg n, 2^n

classify growth rate: constant, logarithmic, linear, linearithmic, quadratic, cubic,
exponential
n lg n + 3 n^{2 / 3}
n^2 + 3n + 1
4^{\lg n} + 2 n^3

TODO: 3 problems on choosing between algorithms
