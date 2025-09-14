# Lab 2 - Analysis of Algorithms

# Overview

In this lab, you will design and implement several brute-force algorithms and empirically analyze their performance.

## Learning Objectives

By the end of this lab, you should be able to:

1. Design and implement brute-force algorithms.
2. Empirically analyze algorithm performance.

When trying to design an efficient algorithm to solve a challenging problem, it is often helpful to begin by designing
a brute-force algorithm.

## Grading

To receive full credit, you should:

1. Attend, participate and collaborate.
2. Make at least one submission to Gradescope.

> [!IMPORTANT] Effort is enough to receive full credit. You do not need to successfully complete any activities.

To meet the lab objectives, you should:

1. Complete all activities listed under **Core Content**.

To leave early, you should:

1. Complete all activities listed under **Core Content**.
2. Complete all activities listed under **Extra Practice**.

To maximize your learning, you should:

1. Complete all activities listed under **Core Content**.
2. Complete all activities listed under **Extra Practice**.
3. Attempt some activities listed under **Advanced Topics**.

## Submission

TODO
list the files to submit
state submission is to gradescope

# Core Content

## Project Setup

1. Create a new project called `csc212-lab-02` in your IDE.
2. Download all files from [the lab handout folder](handout) into the `csc212-lab-02` project.

## Two Sum Problem (2SUM)

In the Two Sum Problem (2SUM), you are given some integers and a target value. You must determine if there is a pair of
distinct integers that sum to the target value.

### Implementation

In this section, you will design and implement an algorithm to solve 2SUM.

1. Complete `two_sum.cpp`.
2. Build `test_two_sum` from `two_sum.cpp`, `two_sum_fast.cpp`, and `test_two_sum.cpp`.
3. Run `test_two_sum`. All tests should pass.

> [!IMPORTANT] Submit `two_sum.cpp` to Gradescope.

### Empirical Analysis

In this section, you will benchmark the performance of your 2SUM algorithm against another 2SUM algorithm.

1. Read `two_sum_fast.cpp`.
2. Predict whether your `two_sum` function or the provided `two_sum_fast` function will be faster on inputs of size `1`,
   `10`, `100`, `1000` and `10000`. Record your predictions in `two_sum_pred.md`.
3. Build `bench_two_sum` from `two_sum.cpp`, `two_sum_fast.cpp`, and `bench_two_sum.cpp`. This program takes a single
   command line argument `n`, the size of the input array, and outputs the runtime of `two_sum` and `two_sum_fast`. If
   you aren't sure how to pass command line arguments to `bench_two_sum` with your IDE, Google your IDE documentation.
4. Run `bench_two_sum` with inputs of size `1`, `10`, `100`, `1000` and `10000`. Compare the results against your
   predictions. Record your findings in `two_sum_pred.md`.

> [!IMPORTANT] Submit `two_sum_pred.md` to Gradescope.

# Extra Practice

## Three Sum Problem (3SUM)

In the Three Sum Problem (3SUM), you are given some integers and a target value. You must determine if there is a
triplet of distinct integers that sum to the target value.

### Implementation

In this section, you will design and implement an algorithm to solve 3SUM.

1. Complete `three_sum.cpp`.
2. Build `test_three_sum` from `three_sum.cpp`, `three_sum_fast.cpp`, and `test_three_sum.cpp`.
3. Run `test_three_sum`. All tests should pass.

> [!IMPORTANT] Submit `three_sum.cpp` to Gradescope.

### Empirical Analysis

In this section, you will benchmark the performance of your 3SUM algorithm against another 3SUM algorithm.

1. Read `three_sum_fast.cpp`.
2. Predict whether your `three_sum` function or the provided `three_sum_fast` function will be faster on inputs of size
   `1`, `10`, `100` and `1000`. Record your predictions in `three_sum_pred.md`.
3. Build `bench_three_sum` from `three_sum.cpp`, `three_sum_fast.cpp`, and `bench_three_sum.cpp`. This program takes a
   single command line argument `n`, the size of the input array, and outputs the runtime of `three_sum` and
   `three_sum_fast`. If you aren't sure how to pass command line arguments to `bench_three_sum` with your IDE, Google
   your IDE documentation.
4. Run `bench_three_sum` with inputs of size `1`, `10`, `100` and `1000`. Compare the results against your predictions.
   Record your findings in `three_sum_pred.md`.

> [!IMPORTANT] Submit `three_sum_pred.md` to Gradescope.

# Advanced Topics

## Subset Sum Problem (SSP)

## The Polynomial Time Hierarchy, Fine-Grained Reductions and 3SUM-Hardness

The goal of this lab is to design and implement algorithms of different complexities. You will get a hands-on look at
algorithm analysis, via benchmarking different algorithms and comparing their performance. You will also practice
modularizing your code using functions, multiple files, command line arguments, and dynamic memory allocation in C++.

> [!WARNING]
> For this lab in particular, you are NOT ALLOWED to use LLMs (large language models) such as Copilot, ChatGPT, etc.  
> You are allowed to use the internet to look up syntax and other basic information, but you should not automatically
> generate code using LLMs. If you have Copilot on your environment, please disable it for the duration of the lab.  
> Focus on understanding the concepts and writing the code yourself.

## Preliminaries

- This lab will be completed in teams of **two or three students** (you may decide your teams amongst yourselves);
- Do all your scratch work for the two algorithms on a sheet of paper or a whiteboard before you start coding. You
- should follow the same general procedure: design an algorithm to solve the problem, write the algorithm in plain
- pseudocode, test the algorithm, then implement the algorithm in C++, and test the implementation with some test cases.

## Two sum problem

The goal of this question is to implement a function that takes an array of integers and a target value, and returns 1
if there are two numbers in the array that add up to the target value, and 0 otherwise. The function takes the
following arguments: a pointer to the array, the size of the array, and the target value.

Create a file named `algorithms.cpp` include the following function declaration, and complete the body of the function:

```cpp
int two_sum(int *arr, int n, int target) {
    // TODO:
    // Complete the function
}
```

Next, we will define a separate main function just to test the `two_sum` function above. Create a file named
`two_sum_tester.cpp` and include the following code:

```cpp
#include <cassert>

// include the prototype of the function
// implemented in the algorithms.cpp file
int two_sum(int *arr, int n, int target);

// main function to test the two_sum function
int main() {
    int arr1[] = {-2, 7, 11, 0};
    int arr2[] = {3, 3};
    int arr3[] = {-10, -5, 0, 5, 10, -4, -3, -2, -1, 0};

    // assert statements to test the function,
    // if the condition is false, the program will
    // terminate with an error message       
    assert(two_sum(arr1, 4, 9) == 1);
    assert(two_sum(arr1, 4, -2) == 1);
    assert(two_sum(arr1, 4, -1) == 0);
    assert(two_sum(arr1, 4, 0) == 0);

    assert(two_sum(arr2, 2, 6) == 1);
    assert(two_sum(arr2, 2, -6) == 0);
    assert(two_sum(arr2, 2, 0) == 0);
    assert(two_sum(arr2, 2, -1) == 0);
    assert(two_sum(arr2, 2, 1) == 0);

    assert(two_sum(arr3, 10, -15) == 1);
    assert(two_sum(arr3, 10, 0) == 1);
    assert(two_sum(arr3, 10, 500) == 0);
    assert(two_sum(arr3, 10, -100) == 0);
    assert(two_sum(arr3, 10, 17) == 0);
}
```

Now compile both files together using: `g++ -std=c++11 algorithms.cpp two_sum_tester.cpp -o test2`. Run the program
using `./test2` and verify that it works as expected and all test cases are passed. If you have a particular test case
to be added, add it to the `two_sum_tester.cpp` file and recompile the program.

> [!IMPORTANT]
> At the end of the lab you will have to submit `algorithms.cpp` and `two_sum_tester.cpp` files to
> [Gradescope](https://gradescope.com).

## Three sum problem

In this question you will implement a function that takes an array of integers and a target value, and returns 1 if
there are three numbers in the array that add up to the target value, and 0 otherwise. The function takes the following
arguments: a pointer to the array, the size of the array, and the target value.

Add the following function definition to the `algorithms.cpp` file from the previous problem, and complete the body of
the function:

```cpp
int three_sum(int *arr, int n, int target) {
    // TODO:
    // Complete the function
}
```

Next, define a separate main function to test the `three_sum` function above. Create a file named `three_sum_tester.cpp`
and include multiple test cases, similarly to the tester implemented in the previous question. After completing the
code, compile and run the program using `g++ -std=c++11 algorithms.cpp three_sum_tester.cpp -o test3` and verify that it
works as expected.

> [!IMPORTANT]
> At the end of the lab you will have to submit the updated `algorithms.cpp` and `three_sum_tester.cpp`
> to [Gradescope](https://gradescope.com).

## Benchmarking algorithms

Assuming that you have implemented the `two_sum` and `three_sum` functions, and all test cases pass, we will now
benchmark the performance of these algorithms. We will use the `std::chrono` library to measure the execution time.

Create a separate file named `benchmark.cpp` and include the code below. Read the comments and complete the code as
indicated. Make sure you understand the code structure and all details related to dynamic memory allocation and command
line arguments. In particular, note that every time the program is executed, it will take a single command line
argument, which is the length of the array to be generated. The program will then **dynamycally** allocate memory,
generate an array of random integers and measure the execution time of the `two_sum` and `three_sum` functions.

```cpp
#include <iostream>
#include <string>

// include the prototype of the functions,
// implemented in the algorithms.cpp file
int two_sum(int *arr, int n, int target);
int three_sum(int *arr, int n, int target);

// define and implement a function to create 
// an array of random integers using dynamic memory allocation
int *create_random_array(int n) {
    // dynamically allocate space for an array of n integers
    int *arr = new int[n];
    // initialize the array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) - 500;
    }
    return arr;
}

// define and implement a function to benchmark the two_sum
// and three_sum functions given an array of integers and a target
void benchmark(int *arr, int n, int target) {
    // TODOs:
    // 1. measure the execution time of the two_sum function
    // 2. measure the execution time of the three_sum function
    // 3. print a line that produces the following output:
    //   the length of the array, followed by a tab character,
    //   followed by the execution time of the two_sum function,
    //   followed by a tab character, followed by the execution
    //   time of the three_sum function, and finally a newline
    //   character
    // The execution time should be in seconds with 6 decimal places
    // You can use the code provided in lectures to format the output
    // accordingly.    
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // error message indicating the correct usage of the program
        std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
        // return an error code to the operating system
        return 1;
    }
    // convert the input argument to an integer
    int length = std::stoi(argv[1]);
    // dynamically allocate memory for an array of integers
    // initialize the array with random values
    int *numbers = create_random_array(length);

    // run a function to benchmark and output the 
    // execution time of the two_sum function and
    // the three_sum function given the length
    // provided as a command line argument
    benchmark(numbers, length, 123);

    // free the memory allocated for the array
    delete [] numbers;
    // return 0 to the operating system
    return 0;
}
```

Compile and run the code using `g++ -std=c++11 algorithms.cpp benchmark.cpp -o bench`. Run the program using
`./bench 100` and verify that it works as expected. Finally lets run a more extensive experiment by generating a table
of data using `bash` commands (available in Linux, MacOS, Windows Subsystem for Linux, etc). Call the program using
doubling input sizes 1, 2, 4, ... Carefully observe the rates of growth of the execution times for the two algorithms.

```bash
$ for i in {0..13}; do ./bench $((2**$i)); done
```

> [!IMPORTANT]
> At the end of the lab you will have to submit `benchmark.cpp` to [Gradescope](https://gradescope.com). Add comments to
> the top of the file with your name and the names of your team members, and answer the following question: what is the
> purpose of `(rand() % 10000) - 5000;`? What is the exact range of values that can be generated by this expression? Are
> the running times reported in the benchmarking matching your expectations? Explain why or why not.

## Submission

After you have completed all the exercises, submit the files below to [Gradescope](https://gradescope.com). Your code
should be well-formatted and easy to read. Make sure to test your code thoroughly before submitting it. You must be
present in the lab to receive the attendance credit. No remote submissions will be accepted. If you have any questions,
please ask the instructor or the TA for help.

- `algorithms.cpp`
- `two_sum_tester.cpp`
- `three_sum_tester.cpp`
- `benchmark.cpp`