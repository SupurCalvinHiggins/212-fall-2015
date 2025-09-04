# Lab 1 (01/28/2025)

# Overview

We will spend the first lab reviewing key C++ concepts from CSC 211: pointers, C-style arrays, dynamic memory allocation
and classes. We will also learn how to use the **debugger**, a powerful tool that pauses a program's execution and 
allows the programmer to inspect the values of variables.

## Learning Objectives

After completing this lab, you will be able to
1. Write C++ programs with pointers and C-style arrays
2. Write C++ programs with dynamic memory allocation
3. Write C++ programs with classes
4. Step through C++ code with a debugger

## Grading

TODO

## Setup

We assume you have an IDE with a working (1) compiler, (2) debugger and (3) formatter. If you are unsure or are missing
any of these features, please ask a group or staff member for help.

> [!WARNING]
> For this lab, we recommend against using large language models (LLMs) like Copilot and ChatGPT for the programming 
> exercises. If you have Copilot integrated with your IDE, we suggest disabling it. We believe using LLMs for 
> programming in this lab will harm your learning. However, we do recommend using LLMs to understand the debugger's
> capabilities.

### Unittests

TODO: download + explain catch.hpp

# Pointers

TODO: description and name of file.

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

TODO

# C-style Arrays

TODO

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

TODO

##  Modifying C-style Arrays

TODO:

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

TODO:

# Dynamic Memory Allocation

*Dynamic memory allocation* is a powerful feature in C++ that allows you to allocate memory at execution time.  This is useful, for example,  when you don't know the size of the data you need to store until the program is running.  A critical aspect of memory management in C++ revolves around manual memory deallocation. When a programmer allocates memory using the `new` operator, they assume direct responsibility for subsequently freeing that memory through the corresponding `delete` operator. The significance of this responsibility cannot be overstated. Failure to properly deallocate memory leads to *memory leaks*, where allocated memory remains unavailable for reuse by the program, potentially causing system performance degradation over time.

In C++, you can use the `new` operator to allocate memory for a single variable or an array of variables, and you can use the `delete` operator to free the memory when you are done with it.  The syntax is as follows:

```cpp
int *ptr = new int; // allocate memory for a single integer
int *arr = new int[10]; // allocate memory for an array of 10 integers

delete ptr; // free memory for a single integer
delete [] arr; // free memory for an array of integers
```

*Double pointers* are pointers that point to other pointers.  They are useful when you need to store the address of a pointer, or when you need to create an array of pointers.  They follow the same idea as regular pointers, i.e., they are pointer variables that store memory addresses, in this case, the memory addresses of other pointers.  The syntax is as follows:

```cpp
int value = 10; 
int *q; // declare a regular pointer to an integer
int **ptr; // declare a double pointer to an integer pointer

q = &value; // assign the address of value to q
ptr = &q; // assign the address of q to ptr
```

Now, consider the following program that uses pointers to manipulate an array of integers.  Follow the instructions in the comments to complete the program.

```cpp
void shuffler(int size) {
    // dynamically allocate memory for an array of integers
    int *numbers = new int[size];

    // create an array of pointers to integers
    int **pointers = new int *[size];

    // initialize the array of integers with values from 1 to size
    // and the array of pointers with the addresses of the integers
    for (int i = 0; i < size; i++) {
        numbers[i] = i + 1;     
        pointers[i] = &numbers[i];
    }

    // TODOs:
    // 1. randomly shuffle the array of pointers, the array of numbers
    //    should remain unchanged. you can use the std::shuffle function
    //    from the <algorithm> and <random> headers, here is an example:
    //    shuffle (p, p+n, std::default_random_engine(0))
    //    where p is a pointer to the array and n is the array's length
    // 2. print both arrays and inspect the results, memory addresses
    //    should be printed in hexadecimal format
    // 3. follow the pointers to print the values in shuffled order
    
    // clean up memory
    delete [] numbers;
    delete [] pointers;
}

int main() {
    shuffler(3);
    shuffler(5);
    shuffler(10);
}
```

Compile and run your code using `g++` on the command line.  Verify that it works as expected.  You can also trace your code using [pythontutor.com](http://pythontutor.com/cpp.html#mode=edit) to improve your understanding of pointers.

> [!IMPORTANT]
> Append your code to the `solutions-lab.txt` file

## Submission

After you have completed all the exercises, submit your `solutions-lab.txt` file to [Gradescope](https://gradescope.com).  Your code should be well-formatted and easy to read.  Make sure to test your code thoroughly before submitting it.  You must be present in the lab to receive the attendance credit.  No remote submissions will be accepted.  If you have any questions, please ask the instructor or the TA for help.