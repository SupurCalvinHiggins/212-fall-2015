# Overview

## Learning Objectives

1. Model the number of basic operations performed by an algorithm with functions and summations.
2. Simplify summations of polynomials and exponential functions arising from the analysis of algorithms.
3. State asymptotic bounds on logarithmic, polynomial and exponential functions in $\Theta$, $\Omega$ and 
   $\mathcal{O}$-notation.
4. Order logarithmic, polynomial and exponential functions by growth rate.
5. Classify the growth rate of logarithmic, polynomial and exponential functions.

extra:
6. Select algorithms based on asymptotic descriptions of time and space complexity.


## Grading

TODO

# Problems

## Stating Cost Functions

### Problem

Consider the following algorithm to compute the maximum element of an array.
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

Consider the following algorithm to compute the product between an $$n \times n$$ matrix $$A$$ and a vector of $$n$$ elements $$x$$.
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

Consider the following algorithm to count the number of solutions to an instance of the 2SUM problem.
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

Consider the following algorithm to compute the sum of all positive even numbers less than $$n$$.

```cpp
int sum_even(int n) {
   int sum = 0;
   for (int i = 2; i < n; i += 2) {
      sum += i;
   }
   return sum;
}
```

Which of the following functions counts the number of assignments to `sum` performed on an input of size $$n \geq 1$$?

( ) $$T(n) = 1 + \sum\limits_{i = 2}^{n - 1} 1$$
(X) $$T(n) = \lfloor \frac{n + 1}{2} \rfloor$$
( ) $$T(n) = \lceil \frac{n + 1}{2} \rceil$$
( ) $$T(n) = 1 + \sum\limits_{i = 2}^{n - 1} \frac{1}{2}$$

### Problem

Consider the following algorithm to compute the sum of all powers of three less than or equal to $$n$$.

```cpp
int sum_pow3(int n) {
   int sum = 0;
   for (int i = 1; i <= n; i *= 3) {
      sum += i;
   }
   return sum;
}
```

Which of the following functions counts the number of assignments to `sum` performed on an input of size $$n \geq 1$$?

( ) $$T(n) = \sum\limits_{i = 1}^{n} 3^i$$
( ) $$T(n) = 1 + \lfloor \log_3 n \rfloor$$
( ) $$T(n) = 1 + \sum\limits_{i = 1}^{n} 3^i$$
(X) $$T(n) = 2 + \lfloor \log_3 n \rfloor$$

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

### Problem

Which of the following asymptotic descriptions of $$2n + 3$$ are correct?

[ ] $$\mathcal{O}(1)$$
[X] $$\mathcal{O}(n)$$
[X] $$\mathcal{O}(n^2)$$
[X] $$\Omega(1)$$
[X] $$\Omega(n)$$
[ ] $$\Omega(n^2)$$
[ ] $$\Theta(1)$$
[X] $$\Theta(n)$$
[ ] $$\Theta(n^2)$$

### Problem

Which of the following asymptotic descriptions of $$2n^2 + 3 n \lg n - 2n$$ are correct?

[ ] $$\mathcal{O}(1)$$
[ ] $$\mathcal{O}(n)$$
[X] $$\mathcal{O}(n^2)$$
[X] $$\Omega(1)$$
[X] $$\Omega(n)$$
[X] $$\Omega(n^2)$$
[ ] $$\Theta(1)$$
[ ] $$\Theta(n)$$
[X] $$\Theta(n^2)$$

### Problem

Which of the following asymptotic descriptions of $$7n^3 + 2^{16}$$ are correct?

[X] $$\mathcal{O}(n^3)$$
[X] $$\mathcal{O}(n^4)$$
[X] $$\mathcal{O}(2^n)$$
[X] $$\Omega(n^3)$$
[ ] $$\Omega(n^4)$$
[ ] $$\Omega(2^n)$$
[X] $$\Theta(n^3)$$
[ ] $$\Theta(n^4)$$
[ ] $$\Theta(2^n)$$

### Problem

Which of the following asymptotic descriptions of $$2 \cdot 3^n + 2^n + 3n^4$$ are correct?

[ ] $$\mathcal{O}(n)$$
[ ] $$\mathcal{O}(2^n)$$
[X] $$\mathcal{O}(3^n)$$
[X] $$\Omega(n)$$
[X] $$\Omega(2^n)$$
[X] $$\Omega(3^n)$$
[ ] $$\Theta(n)$$
[ ] $$\Theta(2^n)$$
[X] $$\Theta(3^n)$$

## Comparing Cost Functions

### Problem

Which of the following functions has the fastest growth rate?

( ) $$\sqrt{n} + 7$$
(X) $$n^3 + 2n$$
( ) $$5 \lg n + 100$$
( ) $$3n^{1/4} + \lg n$$

Which of the following functions has the second-fastest growth rate?

(X) $$\sqrt{n} + 7$$
( ) $$n^3 + 2n$$
( ) $$5 \lg n + 100$$
( ) $$3n^{1/4} + \lg n$$

Which of the following functions has the third-fastest growth rate?

( ) $$\sqrt{n} + 7$$
( ) $$n^3 + 2n$$
( ) $$5 \lg n + 100$$
(X) $$3n^{1/4} + \lg n$$

Which of the following functions has the slowest growth rate?

( ) $$\sqrt{n} + 7$$
( ) $$n^3 + 2n$$
(X) $$5 \lg n + 100$$
( ) $$3n^{1/4} + \lg n$$

### Problem

Which of the following functions has the fastest growth rate?

( ) $$n^3 + 2^n$$
( ) $$n^{\sqrt{3}} + 1000$$
(X) $$3^n + n$$
( ) $$50n + n^2$$

Which of the following functions has the second-fastest growth rate?

(X) $$n^3 + 2^n$$
( ) $$n^{\sqrt{3}} + 1000$$
( ) $$3^n + n$$
( ) $$50n + n^2$$

Which of the following functions has the third-fastest growth rate?

( ) $$n^3 + 2^n$$
( ) $$n^{\sqrt{3}} + 1000$$
( ) $$3^n + n$$
(X) $$50n + n^2$$

Which of the following functions has the slowest growth rate?

( ) $$n^3 + 2^n$$
(X) $$n^{\sqrt{3}} + 1000$$
( ) $$3^n + n$$
( ) $$50n + n^2$$

### Problem

Which of the following functions has the fastest growth rate?

(X) $$2^n$$
( ) $$5n \lg n + n^2$$
( ) $$7 \lg^2 n$$
( ) $$2^{\lg n}$$

Which of the following functions has the second-fastest growth rate?

( ) $$2^n$$
(X) $$5n \lg n + n^2$$
( ) $$7 \lg^2 n$$
( ) $$2^{\lg n}$$

Which of the following functions has the third-fastest growth rate?

( ) $$2^n$$
( ) $$5n \lg n + n^2$$
( ) $$7 \lg^2 n$$
(X) $$2^{\lg n}$$

Which of the following functions has the slowest growth rate?

( ) $$2^n$$
( ) $$5n \lg n + n^2$$
(X) $$7 \lg^2 n$$
( ) $$2^{\lg n}$$

### Problem

What is the growth rate of $$n \lg n + 3 n^{2 / 3}$$?

( ) Constant
( ) Logarithmic
(X) Linearithmic
( ) Quadratic
( ) Cubic
( ) Exponential

### Problem

What is the growth rate of $$n^2 + 3n + 1$$?

( ) Constant
( ) Logarithmic
( ) Linearithmic
(X) Quadratic
( ) Cubic
( ) Exponential

### Problem

What is the growth rate of $$4^{\lg n} + 2 n^3$$?

( ) Constant
( ) Logarithmic
( ) Linearithmic
( ) Quadratic
(X) Cubic
( ) Exponential

# Putting it together

### Problem

Consider the following algorithm to append to a grow-by-one dynamic array.
```cpp
int* push_back(int* A, int n, int value) {
   int* new_A = new int[n + 1];
   for (int i = 0; i < n; ++i) {
      new_A[i] = A[i];
   }
   new_A[n] = value;
   delete[] A;
   return new_A;
}
```

Which of the following functions counts the number of array accesses (reads and writes) performed on an input of size $$n$$?

( ) $$T(n) = 1 + \sum\limits_{i=0}^{n} 2$$
( ) $$T(n) = \sum\limits_{i=0}^{n} 2$$
(X) $$T(n) = 1 + \sum\limits_{i=0}^{n - 1} 2$$
( ) $$T(n) = \sum\limits_{i=0}^{n - 1} 2$$

Which of the following is the correct simplification of $$T(n)$$?

(X) $$T(n) = 2n - 1$$
( ) $$T(n) = 2n$$
( ) $$T(n) = 2n + 2$$
( ) $$T(n) = 2n + 3$$

Which of the following is a tight asymptotic bound on the time complexity?

( ) $$T(n) = \mathcal{O}(n)$$
( ) $$T(n) = \Omega(n)$$
(X) $$T(n) = \Theta(n)$$
( ) $$T(n) = \mathcal{O}(1)$$

### Problem

Consider the following algorithm to count the number of ones in an $$n \times n$$ matrix.

```cpp
int count_ones(int** M, int n) {
   int ones = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         if (M[i][j] == 1) {
            ones += 1;
         }
      }
   }
   return ones;
}
```

Which of the following functions counts the number of array accesses performed on an input of size $$n$$?

( ) $$T(n) = \sum\limits_{i=0}^{n}\sum\limits_{j=0}^{n} 1$$
( ) $$T(n) = \sum\limits_{i=0}^{n-1}\sum\limits_{j=0}^{n-1} 1$$
( ) $$T(n) = \sum\limits_{i=0}^{n}\sum\limits_{j=0}^{n} 2$$
(X) $$T(n) = \sum\limits_{i=0}^{n-1}\sum\limits_{j=0}^{n-1} 2$$

Which of the following is the correct simplification of $$T(n)$$?

( ) $$T(n) = 2(n+1)^2$$
( ) $$T(n) = (n+1)^2$$
(X) $$T(n) = 2n^2$$
( ) $$T(n) = n^2$$

Which of the following is a tight asymptotic bound on the time complexity?

(X) $$T(n) = \Theta(n^2)$$
( ) $$T(n) = \mathcal{O}(n)$$
( ) $$T(n) = \Omega(n^2)$$
( ) $$T(n) = \mathcal{O}(n^2)$$

### Problem

Consider the following algorithm to compute the cumulative sum of an array of $$n$$ integers.
```cpp
void cumsum1(int* A, int n) {
   int* B = new int[n];
   for (int i = 0; i < n; ++i) {
      int total = 0;
      for (int j = 0; j < i; ++j) {
         total += A[j];
      }
      B[i] = total;
   }
   for (int i = 0; i < n; ++i) {
      A[i] = B[i];
   }
   delete[] B;
}
```

Which of the following functions counts the number of array accesses performed on an input of size $$n$$ by `cumsum1`?

( ) $$T(n) = \sum\limits_{i = 0}^{n - 1}\sum\limits_{j = 0}^{i - 1} 1 + \sum\limits_{i=0}^{n - 1} 2$$
(X) $$T(n) = \sum\limits_{i = 0}^{n - 1}\left(1 + \sum\limits_{j = 0}^{i - 1} 1\right) + \sum\limits_{i=0}^{n - 1} 2$$
( ) $$T(n) = \sum\limits_{i = 0}^{n - 1}\sum\limits_{j = 0}^{i - 1} 2 + \sum\limits_{i=0}^{n - 1} 2$$
( ) $$T(n) = \sum\limits_{i = 0}^{n - 1}\left(1 + \sum\limits_{j = 0}^{i - 1} 2\right) + \sum\limits_{i=0}^{n - 1} 2$$

Which of the following is the correct simplification of $$T(n)$$ for `cumsum1`?

( ) $$T(n) = n^2 + 2n$$
(X) $$T(n) = n^2 + \frac{5}{2}n$$
( ) $$T(n) = n^2 + \frac{3}{2}n$$
( ) $$T(n) = n^2 + n$$

Which of the following is a tight asymptotic bound on the time complexity of `cumsum1`?

(X) $$T(n) = \Theta(n^2)$$
( ) $$T(n) = \Theta(n)$$
( ) $$T(n) = \mathcal{O}(n^2)$$
( ) $$T(n) = \mathcal{O}(n)$$

Consider the following second algorithm to compute the cumulative sum of an array of $$n$$ integers.
```cpp
void cumsum2(int* A, int n) {
   for (int i = 1; i < n; ++i) {
      A[i] += A[i - 1]
   }
}
```

Which of the following functions counts the number of array accesses performed on an input of size $$n$$ by `cumsum2`?

( ) $$T(n) = \sum\limits_{i=0}^{n - 1} 2$$
( ) $$T(n) = \sum\limits_{i=1}^{n - 1} 1$$
(X) $$T(n) = \sum\limits_{i=1}^{n - 1} 2$$
( ) $$T(n) = \sum\limits_{i=0}^{n - 1} 1$$

Which of the following is the correct simplification of $$T(n)$$ for `cumsum2`?

( ) $$T(n) = n - 1$$
( ) $$T(n) = 2n$$
( ) $$T(n) = n$$
(X) $$T(n) = 2n - 2$$

Which of the following is a tight asymptotic bound on the time complexity of `cumsum2`?

(X) $$T(n) = \Theta(n)$$
( ) $$T(n) = \mathcal{O}(n)$$
( ) $$T(n) = \mathcal{O}(n^2)$$
( ) $$T(n) = \Theta(n^2)$$

Which algorithm is likely faster?
( ) `cumsum1`
(X) `cumsum2`

# Extra Practice

TODO: amortized analysis

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

