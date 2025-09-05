# Lab 1 (01/28/2025)

# Overview

In this lab, we will review key C++ concepts from CSC 211, including **pointers**, **C-style arrays**, **dynamic memory 
allocation** and **classes**. Additionally, we will learn to use the **debugger**, a powerful tool that allows you to 
pause a program's execution and inspect variable values. 

## Learning Objectives

By the end of this lab, you should be able to:
1. Write C++ programs using pointers and C-style arrays
2. Allocate and deallocate memory in C++
3. Model fixed length data structures (including arrays, matrices and tensors) with classes.
4. Step through C++ code using a debugger

If you are not yet confident with one or more of these skills after completing the lab, ask a staff member for help. We 
can adjust the lab to address common difficulties and help you get back on track. Your success is our top priority!

## Grading

Full credit for this lab requires **attendance**, **collaboration with your group**, and **active participation**. 
Gradescope might provide a score, but this is not your lab grade. It’s feedback for you (and for us) about your 
progress.

You may leave early once you have completed all exercises. If you need to leave early for another reason, please talk 
to a staff member.

## Setup

We assume you have an IDE with a working 
1. Compiler (ideally `g++`)
2. Debugger
3. Formatter 
If you are unsure or are missing any of these features, please ask a group or staff member for help.

> [!WARNING]
> For this lab, avoid using large language models (LLMs) like Copilot and ChatGPT when solving the programming 
> exercises. LLMs might limit your learning. If you have Copilot in your IDE, we suggest disabling it. 
> 
> However, we do recommend using LLMs to understand your IDE's and the debugger's capabilities.

### Unittests

This lab (and future labs) includes autograder test cases. You can run them locally to check your progress before 
submitting.

To compile the provided code, download `catch.hpp` from the lab folder on GitHub and include it in your project.

### Building Code with CLion

When working in CLion, create a new project for each lab or assignment.

For each project, you might need to build multiple programs. CLion uses `CMake` an industry standard tool to manage 
builds. To build and debug multiple programs in CLion, you will need to edit the `CMakeLists.txt` file. See 
[here](https://www.jetbrains.com/help/clion/quick-cmake-tutorial.html) for a tutorial.

# Debugger

If you haven't used a debugger before, please watch [this video](https://www.youtube.com/watch?v=5wGsRdumueU).

Copy the following program into a new file `step.cpp`.

```cpp
#include <iostream>

class Counter {
private:
    int total;

public:
    Counter(int start) {
        total = start                           // !!!
    }

    void add_up_to(int n) {
        for (int i = 1; i <= n; i++) {          // !!!
            total += i;                         // !!!
        }
    }

    int get_total() {
        return total;                           // !!!
    }
};

int adjust(int value) {
    if (value % 2 == 0) {                       // !!!
        return value / 2;                   
    } else {                                    // !!!
        return value * 3 + 1;                   // !!!
    }
}

int main() {
    Counter c(5);                               // !!!

    c.add_up_to(3);                             // !!!

    int result = adjust(c.get_total());         // !!!

    std::cout << "Result: " << result << "\n";  // !!!
    return 0;                                   // !!!
}
```

Set a breakpoint on `main` and step through the program. Before moving on, ensure you can reach every line of
code marked with `// !!!`. Step-over and step-into will be useful.

> [!IMPORTANT]
> You do not need to submit anything to Gradescope for this exercise.

## Debugging Unittests 

Copy the following program into a new file `debug.cpp`.

```cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int sum_of_squares(int n) {
    int total = 0;
    for (int i = 1; i < n; i++) {
        total += i * i;
    }
    return total;
}

TEST_CASE("sum_of_squares computes correctly") {
    REQUIRE(sum_of_squares(1) == 1);
    REQUIRE(sum_of_squares(2) == 5);
    REQUIRE(sum_of_squares(3) == 14);
    REQUIRE(sum_of_squares(0) == 0);
    REQUIRE(sum_of_squares(5) == 54);
}
```

This program uses the testing framework to verify the correctness of the `sum_of_squares` program. Currently, the 
program contains two bugs. Run the program with the debugger to find the two bugs, and fix them. The program should
compile and run without errors.

> [!IMPORTANT]
> You should submit `debug.cpp` to Gradescope.

# Pointers

Copy the following program into a new file `pointers.cpp`.

```cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cstdint>

int get_pointed_value(int* pointer) {
    // TODO: Return the value pointed to by `pointer`.
}

void set_pointed_value(int* pointer, int value) {
    // TODO: Set the value pointed to by `pointer` to `value`.
}

uintptr_t get_pointer_address(int* pointer) {
    // TODO: Return the memory address of the value pointed to by `pointer`.
}

TEST_CASE("get_pointed_value returns value stored at pointer") {
    int x = 99;
    int* p = &x;

    REQUIRE(get_pointed_value(p) == 99);
}

TEST_CASE("set_pointed_value modifies the value at pointer") {
    int x = 0;
    int* p = &x;

    set_pointed_value(p, 123);

    REQUIRE(x == 123);
    REQUIRE(get_pointed_value(p) == 123);
}

TEST_CASE("get_pointer_address returns correct address") {
    int x = 42;
    int* p = &x;
    
    uintptr_t addr = get_pointer_address(p);
    
    REQUIRE((int*)addr == p);
}
```

Complete the TODOs. The program should compile and run without errors.

> [!IMPORTANT]
> You should submit `pointers.cpp` to Gradescope.

# C-Style Arrays

Copy the following program into a new file `arrays.cpp`.

```cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <ostream>

void print_array(int* array, int n, std::ostream& os) {
    // TODO: Print each element of `array` to `os` separated by spaces. Do not include a trailing space.
    // NOTE: To print to `os` use the << operator. For example, `os << 5;` prints `5` to `os`. 
}

void print_string(char* string, std::ostream& os) {
    // TODO: Print each character in `string` to `os` separated by spaces. Do not include a trailing space.
    // NOTE: To print to `os` use the << operator. For example, `os << 5;` prints `5` to `os`. 
}

TEST_CASE("print_array prints integers separated by spaces") {
    int arr[] = {1, 2, 3, 4};
    std::ostringstream oss;

    print_array(arr, 4, oss);

    REQUIRE(oss.str() == "1 2 3 4");
}

TEST_CASE("print_array prints nothing for empty array") {
    int arr[] = {};
    std::ostringstream oss;

    print_array(arr, 0, oss);

    REQUIRE(oss.str().empty());
}

TEST_CASE("print_string prints characters separated by spaces") {
    char str[] = "cat";
    std::ostringstream oss;

    print_string(str, oss);

    REQUIRE(oss.str() == "c a t");
}

TEST_CASE("print_string prints nothing for empty string") {
    char str[] = "";
    std::ostringstream oss;

    print_string(str, oss);

    REQUIRE(oss.str().empty());
}
```

Complete the TODOs. The program should compile and run without errors.

> [!IMPORTANT]
> You should submit `arrays.cpp` to Gradescope.

##  Modifying C-Style Arrays

Copy the following program into a new file `reverse.cpp`.

```cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

void reverse_array(int *array, int n) {
    // TODO: Reverse the order of elements in `array`.
}

TEST_CASE("reverse_array reverses small arrays") {
    int arr[] = {1, 2, 3};
    reverse_array(arr, 3);

    REQUIRE(arr[0] == 3);
    REQUIRE(arr[1] == 2);
    REQUIRE(arr[2] == 1);
}

TEST_CASE("reverse_array works on even-length arrays") {
    int arr[] = {10, 20, 30, 40};
    reverse_array(arr, 4);

    REQUIRE(arr[0] == 40);
    REQUIRE(arr[1] == 30);
    REQUIRE(arr[2] == 20);
    REQUIRE(arr[3] == 10);
}

TEST_CASE("reverse_array leaves single-element array unchanged") {
    int arr[] = {99};
    reverse_array(arr, 1);

    REQUIRE(arr[0] == 99);
}

TEST_CASE("reverse_array leaves empty array unchanged") {
    int arr[] = {};
    reverse_array(arr, 0);

    // Nothing to check except that it compiles and runs without error
    REQUIRE(true);
}
```

Complete the TODOs. The program should compile and run without errors.

> [!IMPORTANT]
> You should submit `reverse.cpp` to Gradescope.

# Dynamic Memory Allocation

*Dynamic memory allocation* is a powerful feature in C++ that allows you to allocate memory at execution time.  This is 
useful, for example,  when you don't know the size of the data you need to store until the program is running.  A 
critical aspect of memory management in C++ revolves around manual memory deallocation. When a programmer allocates 
memory using the `new` operator, they assume direct responsibility for subsequently freeing that memory through the 
corresponding `delete` operator. The significance of this responsibility cannot be overstated. Failure to properly 
deallocate memory leads to *memory leaks*, where allocated memory remains unavailable for reuse by the program, 
potentially causing system performance degradation over time.

In C++, you can use the `new` operator to allocate memory for a single variable or an array of variables, and you can 
use the `delete` operator to free the memory when you are done with it.

Copy the following program into a new file `allocate.cpp`.

```cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int* allocate_one() {
    // TODO: Allocate a single integer with the `new` operator.
}

void deallocate_one(int* pointer) {
    // TODO: Allocate a single integer with the `delete` operator.
}

int* allocate_many(int n) {
    // TODO: Allocate an array of `n` integers with the `new[]` operator.
}

void deallocate_many(int* pointer) {
    // TODO: Deallocate an array of integers with the `delete[]` operator.
}

TEST_CASE("allocate_one allocates an integer") {
    int* p = allocate_one();

    REQUIRE(p != nullptr);

    *p = 42;
    REQUIRE(*p == 42);

    deallocate_one(p);
}

TEST_CASE("allocate_many allocates an array of n integers") {
    int n = 5;
    int* arr = allocate_many(n);

    REQUIRE(arr != nullptr);

    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }
    for (int i = 0; i < n; i++) {
        REQUIRE(arr[i] == i * 10);
    }

    deallocate_many(arr);
}
```

Complete the TODOs. The program should compile and run without errors.

> [!IMPORTANT]
> You should submit `allocate.cpp` to Gradescope.

*Double pointers* are pointers that point to other pointers.  They are useful when you need to store the address of a 
pointer, or when you need to create an array of pointers.  They follow the same idea as regular pointers, i.e., they are
pointer variables that store memory addresses, in this case, the memory addresses of other pointers.

Now, consider the following program that manipulate an array of pointers to integers. 

Copy the following program into a new file `permute.cpp`.

```cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

void permute_pointers(int** array, int* permutation, int n) {
    // TODO: Permute `array` such that `array[i] = array[permutation[i]]`.
    // NOTE: Iterating over `i` and setting `array[i] = array[permutation[i]]` will not work. Why?
}

TEST_CASE("permute_pointers rearranges according to permutation array") {
    int a = 10, b = 20, c = 30;
    int* arr[] = {&a, &b, &c};

    // New order: arr[0] <- arr[2], arr[1] <- arr[0], arr[2] <- arr[1]
    int perm[] = {2, 0, 1};

    permute_pointers(arr, perm, 3);

    REQUIRE(*arr[0] == 30); // was c
    REQUIRE(*arr[1] == 10); // was a
    REQUIRE(*arr[2] == 20); // was b
}

TEST_CASE("permute_pointers works with identity permutation") {
    int x = 1, y = 2, z = 3;
    int* arr[] = {&x, &y, &z};
    int perm[] = {0, 1, 2};

    permute_pointers(arr, perm, 3);

    REQUIRE(*arr[0] == 1);
    REQUIRE(*arr[1] == 2);
    REQUIRE(*arr[2] == 3);
}

TEST_CASE("permute_pointers works with single element") {
    int x = 42;
    int* arr[] = {&x};
    int perm[] = {0};

    permute_pointers(arr, perm, 1);

    REQUIRE(*arr[0] == 42);
}

TEST_CASE("permute_pointers on empty array does nothing") {
    int** arr = nullptr;
    int* perm = nullptr;

    permute_pointers(arr, perm, 0);

    SUCCEED("No crash on empty array");
}
```

Complete the TODOs. The program should compile and run without errors.

> [!IMPORTANT]
> You should submit `permute.cpp` to Gradescope.

# Classes

## Array

```cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stdexcept>

class Array {
private:
    int* m_data;
    int m_size;

public:
    Array(int size, int default_value) {
        // TODO: Initialize the member variables of the `Array` object. After dynamically allocating `m_data`, fill it 
        // with `default_value`.
    }
    
    ~Array() {
        // TODO: Deallocate `m_data`.
    }
    
    // C++ magic. Feel free to ignore these two lines, or ask a staff member if you are curious.
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;
    
    int get(int idx) {
        // TODO: Return the element at index `idx` in the array. If `idx` is out-of-bounds, throw an `std::out_of_range`
        // exception.
    }
    
    void set(int idx, int value) {
        // TODO: Set the element at index `idx` in the array to `value`. If `idx` is out-of-bounds, throw an 
        // `std::out_of_range` exception.
    }
    
    int size() {
        // TODO: Return the size of the array.
    }
};

TEST_CASE("Array initializes with default value") {
    Array arr(5, 42);
    REQUIRE(arr.size() == 5);

    for (int i = 0; i < arr.size(); i++) {
        REQUIRE(arr.get(i) == 42);
    }
}

TEST_CASE("Array set and get work correctly") {
    Array arr(3, 0);
    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);

    REQUIRE(arr.get(0) == 10);
    REQUIRE(arr.get(1) == 20);
    REQUIRE(arr.get(2) == 30);
}

TEST_CASE("Array overwriting values") {
    Array arr(2, 7);
    arr.set(0, 100);
    REQUIRE(arr.get(0) == 100);
}

TEST_CASE("Array throws on get out-of-bounds") {
    Array arr(3, 0);
    REQUIRE_THROWS_AS(arr.get(-1), std::out_of_range);
    REQUIRE_THROWS_AS(arr.get(3), std::out_of_range);
}

TEST_CASE("Array throws on set out-of-bounds") {
    Array arr(2, 0);
    REQUIRE_THROWS_AS(arr.set(-1, 10), std::out_of_range);
    REQUIRE_THROWS_AS(arr.set(2, 20), std::out_of_range);
}

TEST_CASE("Array size remains constant after set") {
    Array arr(4, 5);
    REQUIRE(arr.size() == 4);
    arr.set(1, 50);
    REQUIRE(arr.size() == 4);
}
```

## Matrix

```cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stdexcept>

class Matrix {
private:
    // TODO: You can use `int**`, `int*`, `Array*` or `Array` as the type of `m_data`. Use whichever option you prefer.
    // NOTE: If you use `Array*` or `Array`, note that `Array` does not support the `=` operator, so you will need to 
    // use `get` and `set` to copy elements to and from `Array`.
    int** m_data;
    int m_rows;
    int m_cols;

public:
    Matrix(int rows, int cols, int default_value) {
        // TODO: Initialize the member variables of the `Matrix` object. After dynamically allocating `m_data`, fill it 
        with `default_value`.
    }
    
    ~Matrix() {
        // TODO: Deallocate any dynamically allocated memory.
    }
    
    // C++ magic. Feel free to ignore these two lines, or ask a staff member if you are curious.
    Matrix(const Matrix&) = delete;
    Matrix& operator=(const Matrix&) = delete;
    
    int get(int row, int col) {
        // TODO: Return the element at row `row` and column `col` in the matrix. If either `row` or `col` is 
        // out-of-bounds, throw an `std::out_of_range` exception.
    }
    
    void set(int row, int col, int value) {
        // TODO: Set the element at row `row` and column `col` in the matrix to `value`. If either `row` or `col` is 
        // out-of-bounds, throw an `std::out_of_range` exception.
    }
    
    void permute_dims(int dim0, int dim1) {
        // TODO: Permute the order of the matrix dimensions. If `dim0 == 0` and `dim1 == 1`, do nothing. If `dim0 == 1`
        // and `dim1 == 0`, exchange the rows and columns of the matrix. If `B` is the matrix before the permutation and
        // `A` is the matrix after the permutation, then we should have `A[row][col] = B[col][row]`. This is the same as
        // transposing the matrix. In all other cases, throw an `std::invalid_argument` exception.
    }
    
    int rows() {
        // TODO: Return the number of rows in the matrix.
    }
    
    int cols() {
        // TODO: Return the number of columns in the matrix.
    }
};

TEST_CASE("Matrix initializes with default value") {
    Matrix mat(2, 3, 5);

    REQUIRE(mat.rows() == 2);
    REQUIRE(mat.cols() == 3);

    for (int r = 0; r < mat.rows(); ++r)
        for (int c = 0; c < mat.cols(); ++c)
            REQUIRE(mat.get(r, c) == 5);
}

TEST_CASE("Matrix set and get work correctly") {
    Matrix mat(2, 2, 0);
    mat.set(0, 0, 10);
    mat.set(1, 1, 20);

    REQUIRE(mat.get(0, 0) == 10);
    REQUIRE(mat.get(1, 1) == 20);
    REQUIRE(mat.get(0, 1) == 0);
    REQUIRE(mat.get(1, 0) == 0);
}

TEST_CASE("Matrix permute_dims swaps rows and columns") {
    Matrix mat(2, 3, 0);

    // Set values to identify positions
    int val = 1;
    for (int r = 0; r < mat.rows(); ++r)
        for (int c = 0; c < mat.cols(); ++c)
            mat.set(r, c, val++);

    mat.permute_dims(1, 0);

    REQUIRE(mat.rows() == 3);
    REQUIRE(mat.cols() == 2);

    // After transpose, mat[row][col] == original mat[col][row]
    val = 1;
    for (int r = 0; r < 2; ++r)
        for (int c = 0; c < 3; ++c)
            REQUIRE(mat.get(c, r) == val++);
}

TEST_CASE("Matrix permute_dims with identity does nothing") {
    Matrix mat(2, 2, 7);
    mat.permute_dims(0, 1);

    REQUIRE(mat.rows() == 2);
    REQUIRE(mat.cols() == 2);
    for (int r = 0; r < 2; ++r)
        for (int c = 0; c < 2; ++c)
            REQUIRE(mat.get(r, c) == 7);
}

TEST_CASE("Matrix permute_dims invalid arguments throw") {
    Matrix mat(2, 2, 0);
    REQUIRE_THROWS_AS(mat.permute_dims(0, 0), std::invalid_argument);
    REQUIRE_THROWS_AS(mat.permute_dims(1, 1), std::invalid_argument);
    REQUIRE_THROWS_AS(mat.permute_dims(0, 2), std::invalid_argument);
    REQUIRE_THROWS_AS(mat.permute_dims(2, 1), std::invalid_argument);
}

TEST_CASE("Matrix throws on get/set out-of-bounds") {
    Matrix mat(2, 3, 0);
    REQUIRE_THROWS_AS(mat.get(-1, 0), std::out_of_range);
    REQUIRE_THROWS_AS(mat.get(0, -1), std::out_of_range);
    REQUIRE_THROWS_AS(mat.get(2, 0), std::out_of_range);
    REQUIRE_THROWS_AS(mat.get(0, 3), std::out_of_range);

    REQUIRE_THROWS_AS(mat.set(-1, 0, 1), std::out_of_range);
    REQUIRE_THROWS_AS(mat.set(0, -1, 1), std::out_of_range);
    REQUIRE_THROWS_AS(mat.set(2, 0, 1), std::out_of_range);
    REQUIRE_THROWS_AS(mat.set(0, 3, 1), std::out_of_range);
}
```

## Tensor

```cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stdexcept>

class Tensor {
private:
    // TODO: You can use `int*`, `void*` or `Tensor*` as the type of `m_data`. Use whichever option you prefer.
    int* m_data;
    Array m_shape;

public:
    Tensor(Array shape, int default_value) {
        // TODO: Initialize the member variables of the `Tensor` object. After dynamically allocating `m_data`, fill it 
        // with `default_value`.
    }
    
    ~Tensor() {
        // TODO: Deallocate any dynamically allocated memory.
    }
    
    // C++ magic. Feel free to ignore these two lines, or ask a staff member if you are curious.
    Tensor(const Tensor&) = delete;
    Tensor& operator=(const Tensor&) = delete;
    
    int get(Array idx) {
        // TODO: Return the element at index `(idx[0], idx[1], ...)` in the tensor. If any component of `idx` is 
        // out-of-bounds, throw an `std::out_of_range` exception.
    }
    
    void set(Array idx, int value) {
        // TODO: Set the element at index `(idx[0], idx[1], ...)` in the tensor to `value`. If any component of `idx` is 
        // out-of-bounds, throw an `std::out_of_range` exception.
    }
    
    void permute_dims(Array dims) {
        // TODO: Permute the order of the tensor dimensions. If `B` is the matrix before the permutation and `A` is the 
        // matrix after the permutation, then we should have 
        // `A[idx[0], idx[1], ...] = B[idx[dims[0]], idx[dims[1]], ...]`. This is the same as transposing the matrix. In
        // all other cases, throw an `std::invalid_argument` exception.
    }
};

TEST_CASE("Tensor initializes with default value") {
    Array shape({2, 3}); // shape = [2,3]
    Tensor t(shape, 7);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            Array idx({i,j});
            REQUIRE(t.get(idx) == 7);
        }
    }
}

TEST_CASE("Tensor set and get work correctly") {
    Array shape({2,2});
    Tensor t(shape, 0);

    t.set(Array({0,0}), 10);
    t.set(Array({1,1}), 20);

    REQUIRE(t.get(Array({0,0})) == 10);
    REQUIRE(t.get(Array({1,1})) == 20);
    REQUIRE(t.get(Array({0,1})) == 0);
    REQUIRE(t.get(Array({1,0})) == 0);
}

TEST_CASE("Tensor throws on get out-of-bounds") {
    Array shape({2,2});
    Tensor t(shape, 0);

    REQUIRE_THROWS_AS(t.get(Array({-1,0})), std::out_of_range);
    REQUIRE_THROWS_AS(t.get(Array({0,-1})), std::out_of_range);
    REQUIRE_THROWS_AS(t.get(Array({2,0})), std::out_of_range);
    REQUIRE_THROWS_AS(t.get(Array({0,2})), std::out_of_range);
}

TEST_CASE("Tensor throws on set out-of-bounds") {
    Array shape({2,2});
    Tensor t(shape, 0);

    REQUIRE_THROWS_AS(t.set(Array({-1,0}), 1), std::out_of_range);
    REQUIRE_THROWS_AS(t.set(Array({0,-1}), 1), std::out_of_range);
    REQUIRE_THROWS_AS(t.set(Array({2,0}), 1), std::out_of_range);
    REQUIRE_THROWS_AS(t.set(Array({0,2}), 1), std::out_of_range);
}

TEST_CASE("Tensor permute_dims swaps 2D matrix") {
    Array shape({2,3});
    Tensor t(shape, 0);

    int val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            t.set(Array({i,j}), val++);

    t.permute_dims(Array({1,0})); // transpose

    REQUIRE(t.shape().get(0) == 3);
    REQUIRE(t.shape().get(1) == 2);

    val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            REQUIRE(t.get(Array({j,i})) == val++);
}

TEST_CASE("Tensor permute_dims invalid permutation throws") {
    Array shape({2,2});
    Tensor t(shape, 0);

    REQUIRE_THROWS_AS(t.permute_dims(Array({0,0})), std::invalid_argument);
    REQUIRE_THROWS_AS(t.permute_dims(Array({1,1})), std::invalid_argument);
    REQUIRE_THROWS_AS(t.permute_dims(Array({0,1,2})), std::invalid_argument);
}

TEST_CASE("Tensor 3D get/set works correctly") {
    Array shape({2, 3, 4});
    Tensor t(shape, 0);

    int val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 4; k++)
                t.set(Array({i,j,k}), val++);

    val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 4; k++)
                REQUIRE(t.get(Array({i,j,k})) == val++);
}

TEST_CASE("Tensor 3D permute_dims") {
    Array shape({2,3,4});
    Tensor t(shape, 0);

    int val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 4; k++)
                t.set(Array({i,j,k}), val++);

    t.permute_dims(Array({2,0,1})); // new shape should be {4,2,3}
    Array s = t.shape();
    REQUIRE(s.get(0) == 4);
    REQUIRE(s.get(1) == 2);
    REQUIRE(s.get(2) == 3);

    val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 4; k++)
                REQUIRE(t.get(Array({k,i,j})) == val++);
}

TEST_CASE("Tensor 4D get/set works correctly") {
    Array shape({2, 2, 3, 2});
    Tensor t(shape, 0);

    int val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 2; l++)
                    t.set(Array({i,j,k,l}), val++);

    val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 2; l++)
                    REQUIRE(t.get(Array({i,j,k,l})) == val++);
}

TEST_CASE("Tensor 4D permute_dims") {
    Array shape({2, 2, 3, 2});
    Tensor t(shape, 0);

    int val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 2; l++)
                    t.set(Array({i,j,k,l}), val++);

    t.permute_dims(Array({3,2,0,1})); // new shape should be {2,3,2,2}
    Array s = t.shape();
    REQUIRE(s.get(0) == 2);
    REQUIRE(s.get(1) == 3);
    REQUIRE(s.get(2) == 2);
    REQUIRE(s.get(3) == 2);

    val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 2; l++)
                    REQUIRE(t.get(Array({l,k,i,j})) == val++);
}
```

# Submission

After you have completed all the exercises, submit your `solutions-lab.txt` file to [Gradescope](https://gradescope.com).  Your code should be well-formatted and easy to read.  Make sure to test your code thoroughly before submitting it.  You must be present in the lab to receive the attendance credit.  No remote submissions will be accepted.  If you have any questions, please ask the instructor or the TA for help.