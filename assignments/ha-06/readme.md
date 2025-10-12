# Overview

In this assignment, you will practice analyzing algorithms and applying asymptotic notation.

## Learning Objectives

By the end of this assignment, you should be able to:

1. Trace how common operations modify the internal state of linked lists.
2. Analyze the time complexity of common linked list operations.
3. Analyze the space complexity of linked list implementations.
4. Select between linked list implementations to solve real-world problems.
5. Trace the execution of recursive algorithms.
6. Find appropriate recursive decompositions of problems.
7. Model the work performed by recursive algorithms with recurrence relations.
8. Compute the closed form of recurrence relations via the iteration method.
9. Identify if sorting algorithms are stable, in-place, both or neither.
10. Trace the execution of mergesort and quicksort.
11. Analyze the time complexity of mergesort and quicksort.
12. Select between sorting algorithms to solve real-world problems.

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

* Avoid relying on multiple choice options to guide your answer. Instead, work out your solution first, then check
  against the choices.
* Use any resources available (including AI), but always attempt each problem on your own for 5-10 minutes before
  seeking help.

## Answer Formats

**Short answer questions are autograded. You must follow the format specified below to receive credit.**

If the problem asks for a single integer, provide your answer as a single integer without whitespace. For example, `10`.

If the problem asks for a comma-delimited list of integers, provide your answer as a comma-delimited list without
whitespace. For example, `3,1,4,0,12`.

If the problem asks for linked list format, provide your answer in the format `[a]->[b]->...`. For example, if the
linked list contains `3,1,4,2`, the linked list format is `[3]->[1]->[4]->[2]`.

## Submission

**Before you submit, attach a PDF containing your work for every question you answered:**

|files|

It doesn't need to be neat, we just want to be able to understand your process.

Note that you can submit as many times as you want before the due date!

## Confirmation

I have read and understand the above.
(X) Yes
( ) No

# Core Content (5 points)

## Problem

Consider the linked list `ll`'s state after the following code executes:

```cpp
struct Node {
   int value;
   Node* next;
   
   explicit Node(int value) : value(value), next(nullptr) { }
   Node(int value, Node* next) : value(value), next(next) { }
};

auto ll = new Node(2, new Node(3, new Node(1)));
ll->next->next = new Node(0, ll->next->next);
```

What are the contents of `ll`, in order from the head to the tail? Provide your answer in linked list format:
[____]([2]->[3]->[0]->[1])

## Problem

Consider the linked list `ll`'s state after the following code executes:

```cpp
struct Node {
   int value;
   Node* next;
   
   explicit Node(int value) : value(value), next(nullptr) { }
   Node(int value, Node* next) : value(value), next(next) { }
};

auto ll = new Node(2, new Node(3, new Node(1)));
auto tmp = ll->next;
ll->next = nullptr;
delete ll;
ll = tmp;
```

What are the contents of `ll`, in order from the head to the tail? Provide your answer in linked list format:
[____]([2]->[1])

## Problem

Consider the following function for inserting into a doubly-linked circular list:

```cpp
struct Node {
    int data;
    Node* next;
    Node* prev;

    explicit Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

Node* insert(Node* head, int value, size_t position, size_t size) {
    auto node = new Node(value);

    if (!head) {
        node->next = node;
        node->prev = node;
        return node;
    }

    Node* cur = head;
    if (position <= size / 2) {
        for (size_t i = 0; i < position; ++i)
            cur = cur->next;
    } else {
        cur = head->prev;
        for (size_t i = size; i > position; --i)
            cur = cur->prev;
    }

    node->next = cur;
    node->prev = cur->prev;
    cur->prev->next = node;
    cur->prev = node;

    return position == 0 ? node : head;
}
```

What is the worst-case time complexity of inserting into the second to last position in a list of size $$n$$ using this
function?

(X) $$\Theta(1)$$
( ) $$\Theta(\lg n)$$
( ) $$\Theta(n)$$
( ) $$\Theta(n^2)$$

## Problem

Consider the following function to delete a singly linked list:

```cpp
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void destroy(Node* head) {
    while (head) {
        if (!head->next) {
            delete head;
            break;
        }

        auto cur = head;
        while (cur->next && cur->next->next)
            cur = cur->next;

        delete cur->next;
        cur->next = nullptr;
    }
}
```

What is the worst-case time complexity of deleting a singly linked list using this function?

( ) $$\Theta(1)$$
( ) $$\Theta(\lg n)$$
( ) $$\Theta(n)$$
(X) $$\Theta(n^2)$$

## Problem

Consider the following definition of a singly linked list:

```cpp
class LinkedList {
   struct Node {
      int value;
      Node* next;
   };
   
   Node* m_head;
   Node* m_tail;
   size_t m_size;
};
```

Assume integers and pointers take $$4$$ bytes of memory. How many bytes of memory does a linked list of size $$n$$
require?

( ) $$4n + 12$$
(X) $$8n + 12$$
( ) $$8n$$
( ) $$4n$$

## Problem

Consider the following definition of a doubly-linked circular list:

```cpp
class LinkedList {
   struct Node {
      int value;
      Node* next;
      Node* prev;
   };
   
   Node* m_head;
   size_t m_size;
};
```

Assume integers and pointers take $$8$$ bytes of memory. How many bytes of memory does a linked list of size $$n$$
require?

( ) $$8n + 8$$
( ) $$8n + 12$$
(X) $$12n + 8$$
( ) $$12n + 12$$

## Problem

You work for a company that develops an operating system’s **memory allocator**, a system component that dynamically
assigns and reclaims memory for programs as they run. Whenever a memory block is requested with `new`, the allocator
finds and returns a large enough unused block. Whenever memory block is returned with `delete`, the allocator marks the
block as unused. The allocator tracks unused memory blocks using a linked list and must efficiently handle two
operations:

1. Allocate block. Given a requested block size, search the linked list for an unused block that is large enough to
   satisfy the requested allocation. If the unused block is larger than the requested size, split it into two blocks,
   one with the requested size and one with the remainder. Remove the block with the requested size from the linked
   list, and return a pointer to it.
2. Deallocate block. Given a pointer to a used block, mark it as unused and insert it into the linked list.

For example, suppose unused memory blocks are represented as `name`(`size`) and the allocator starts with one block, A(
24):

1. A block of size 8 is requested with `new`:
    * Block A(24) is split into block A(8) and block B(16).
    * Block A(8) is returned.
2. A block of size 10 is requested with `new`
    * Block B(16) is split into block B(10) and block C(6).
    * Block B(10) is returned.
3. Block A(8) is deallocated with `delete`:
    * Block A(8) is inserted before block C(6).
4. Block B(10) is deallocated with `delete`:
    * Block B(10) is inserted between block A(8) and block C(6).
5. A block of size 10 is requested with `new`:
    * Block A(8) is skipped since it is too small.
    * Block B(10) is returned.

Which linked list features best model the unused block list for the allocator? Here, “best” means a **minimal**
implementation that efficiently supports the required operations.

[X] Singly linked
[ ] Doubly linked
[ ] Circular
[X] Linear (not circular)
[X] Head pointer
[ ] Tail pointer

## Problem

You work for a company that develops an operating system’s page manager, which decides which pages to keep in memory. A
**page** is a block of data that is either stored in memory or on disk. To track pages currently in memory, the system
uses a clock algorithm.

Each page in memory is represented as a node in a linked list. Each node stores:

1. The page’s name
2. A flag (0 or 1) showing whether the page was recently used

A special pointer called the **clock hand** moves around the list, pointing to one page at a time. The system supports
these operations:

1. Add page. When a new page is loaded, add it to the list of pages. If this is the first page, the clock hand points to
   it.
2. Access page. When a page is used, its flag is set to 1 (meaning “recently used”).
3. Replace page. When memory is full and a new page must replace an old one, check the page where the clock hand points.
   If the flag is 0, replace it with the new page. Otherwise, if the flag is 1, set it to 0 and move the clock hand to
   the next page until a page where the flag is 0 is found. Then, replace it with the new page.

Which linked list features best model the page list for the page manager? Here, “best” means a **minimal**
implementation that efficiently supports the required operations.

[X] Singly linked
[ ] Doubly linked
[X] Circular
[ ] Linear (not circular)
[X] Clock hand
[ ] Head pointer
[ ] Tail pointer

## Problem

Consider the following program:

```cpp
struct Qux {
   int corge;
   Qux* waldo;
   
   explicit Qux(int corge) : corge(corge), waldo(nullptr) { }
   Qux(int corge, Qux* waldo) : corge(corge), waldo(waldo) { }
};

size_t foo(Qux* baz) {
   size_t bar = 0;
   while (baz) {
      if (baz->corge > 0)
         ++bar;
      baz = baz->waldo;
   }
   return bar;
}
```

What is the return value of `foo(new Qux(0, new Qux(2, new Qux(3))))`? Give your answer as a single integer.

[____](2)

## Problem

Consider the following program:

```cpp
int baz(int bar) {
   if (bar == 0)
      return 0;
   if (bar == 1)
      return 1;
   if (bar % 2 == 0)
      return 1 + foo(bar - 1) + foo(bar - 2);
   return 2 * foo(n / 2)
}
```

What is the return value of `baz(9)`? Give your answer as a single integer.

[____](8)

## Problem

Consider implementing `reverse(int* A, size_t n)` recursively. The function should reverse the array `A` of length `n`.

What is the correct base case?

( ) `if (n == 0) return;`
( ) `if (n == 1) return;`
(X) `if (n <= 1) return;`
( ) `if (n <= 2) return;`

What is the correct recursive step?

(X) `swap(A[0], A[n-1]); reverse(A + 1, n - 2);`
( ) `swap(A[0], A[n]); reverse(A + 1, n - 2);`
( ) `swap(A[0], A[n-1]); reverse(A, n - 2);`
( ) `swap(A[0], A[n]); reverse(A, n - 2);`

## Problem

Consider implementing `sum(Node* head)` recursively. The function should sum all the values stored in the singly linked
list with head `head`.

What is the correct base case?

(X) `if (head == nullptr) return 0;`
( ) `if (head != nullptr) return 0;`
( ) `if (head->next == nullptr) return 0;`
( ) `if (head->next != nullptr) return 0;`

What is the correct recursive step?

( ) `return sum(head);`
( ) `return sum(head->next);`
( ) `return sum(head) + sum(head->next);`
(X) `return head->value + sum(head->next);`

## Problem

Consider the following function to check if a string is a palindrome:

```cpp
bool is_palindrome(const char* s, size_t n) {
    if (n <= 1)
        return true;

    if (s[0] != s[n - 1])
        return false;

    return is_palindrome(s + 1, n - 2);
}
```

What recurrence models the number of array accesses performed by `is_palindrome` on an input of size $$n$$ in the
worst-case?

( ) $$T(n) = T(n - 1) + 2$$
(X) $$T(n) = T(n - 2) + 2$$
( ) $$T(n) = T(n - 1) + 1$$
( ) $$T(n) = T(n - 2) + 1$$

Which of these are correct base case(s) for the recurrence?

[X] $$T(0) = 0$$
[X] $$T(1) = 0$$
[ ] $$T(0) = 1$$
[ ] $$T(1) = 1$$

## Problem

Consider the following function to search a sorted array:

```cpp
size_t contains(const int* A, size_t left, size_t right, int target) {
    if (left > right)
        return -1;

    auto m1 = left + (right - left) / 3;
    auto m2 = right - (right - left) / 3;
    auto v1 = A[m1];
    auto v2 = A[m2];

    if (v1 == target)
        return m1;
    if (v2 == target)
        return m2;

    if (target < v1)
        return contains(A, left, m1 - 1, target);
    else if (target > v2)
        return contains(A, m2 + 1, right, target);
    return contains(A, m1 + 1, m2 - 1, target);
}
```

What recurrence models the number of array accesses performed by `contains` on an input array of size $$n$$ in the
worst-case? Assume $$n$$ is a power of $$3$$.

( ) $$T(n) = T(n/3) + 2$$
(X) $$T(n) = T(n/2) + 2$$
( ) $$T(n) = 2T(n/2) + 2$$
( ) $$T(n) = 3T(n/3) + 2$$

What is the correct base case for the recurrence?

(X) $$T(0) = 0$$
( ) $$T(1) = 0$$
( ) $$T(0) = 1$$
( ) $$T(1) = 1$$

## Problem

Consider the following function to search a singly linked list:

```cpp
bool contains(Node* head, int target) {
    if (head == nullptr)
        return false;

    if (head->data == target)
        return true;

    return contains(head->next, target);
}
```

What recurrence models the number of comparisons performed by `contains` on an input list of size $$n$$ in the
worst-case?

(X) $$T(n) = T(n - 1) + 2$$
( ) $$T(n) = T(n - 1) + 1$$
( ) $$T(n) = 2T(n - 1) + 2$$
( ) $$T(n) = 2T(n - 1) + 1$$

What is the correct base case for the recurrence?

( ) $$T(0) = 0$$
( ) $$T(1) = 0$$
(X) $$T(0) = 1$$
( ) $$T(1) = 1$$

## Problem

Let $$T(n) = 3 T(n - 1)$$ where $$T(1) = 1$$

Give a formula for $$T(n)$$ after expanding $$k$$ times.

(X) $$T(n) = 3^k T(n - k)$$
( ) $$T(n) = 3^{k - 1} T(n - k)$$
( ) $$T(n) = 3^{k - 1} T(n - k - 1)$$
( ) $$T(n) = 3^{k} T(n - k - 1)$$

What value of $$k$$ yields the base case?

(X) $$k = n - 1$$
( ) $$k = n$$
( ) $$k = n - 2$$
( ) $$k = n + 1$$

What is the closed form of $$T(n)$$?

( ) $$T(n) = 3^{n-1} + 1$$
( ) $$T(n) = 3^{n}$$
(X) $$T(n) = 3^{n-1}$$
( ) $$T(n) = 3^{n} + 1$$

## Problem

Let $$T(n) = T(n - 1) + n$$ where $$T(0) = 1$$.

Give a formula for $$T(n)$$ after expanding $$k$$ times.

(X) $$T(n) = T(n - k) + \sum\limits_{i=n - k + 1}^{n} i$$
( ) $$T(n) = T(n - k) + n$$
( ) $$T(n) = T(n - k) + (n - k)$$
( ) $$T(n) = T(n - k) + \sum\limits_{i=0}^{n - k - 1} i$$

What value of $$k$$ yields the base case?

( ) $$k = n - 1$$
(X) $$k = n$$
( ) $$k = n - 2$$
( ) $$k = n + 1$$

What is the closed form of $$T(n)$$?

( ) $$T(n) = n + 1$$
( ) $$T(n) = \frac{n(n+1)}{2}$$
(X) $$T(n) = \frac{n(n+1)}{2} + 1$$
( ) $$T(n) = n$$

## Problem

Let $$T(n) = T(n/2) + 1$$ where $$T(1) = 3$$. Assume $$n$$ is a power of $$2$$.

Give a formula for $$T(n)$$ after expanding $$k$$ times.

(X) $$T(n) = T(n/2^k) + \sum\limits_{i=1}^{k} 1$$
( ) $$T(n) = T(n/2^k)$$
( ) $$T(n) = T(n/2k)$$
( ) $$T(n) = T(n/2k) + \sum\limits_{i=1}^{k} 1$$

What value of $$k$$ yields the base case?

( ) $$k = 1$$
( ) $$k = n/2$$
( ) $$k = n$$
(X) $$k = \lg n$$

What is the closed form of $$T(n)$$?

(X) $$3 + \lg n$$
( ) $$\lg n$$
( ) $$3 + n / 2$$
( ) $$n / 2$$

## Problem

Consider the following sorting algorithm:

```cpp
void merge(vector<int>& A, size_t left, size_t mid, size_t right, vector<int>& aux) {
    auto i = left;
    auto j = mid;
    auto k = left;

    while (i < mid && j < right) {
        if (A[i] <= A[j]) {
            aux[k++] = A[i++];
        } else {
            aux[k++] = A[j++];
        }
    }

    while (i < mid) 
      aux[k++] = A[i++];
    
    while (j < right) 
      aux[k++] = A[j++];

    for (size_t t = left; t < right; ++t)
        A[t] = aux[t];
}

void sort(vector<int>& A, size_t left, size_t right, vector<int>& aux) {
    if (left >= right - 1) 
      return;

    auto m1 = (right - left) / 4 + left;
    auto m2 = 3 * (right - left) / 4 + left;

    sort(A, left, m1, aux);
    sort(A, m1, m2, aux);
    sort(A, m2, right, aux);

    merge(A, left, m1, m2, aux);
    merge(A, left, m2, right, aux);
}

void sort(vector<int>& A) {
    vector<int> aux(A.size());
    sort(A, 0, A.size(), aux);
}
```

Which of the following are true about `sort`?

[X] Stable
[ ] In-place

## Problem

Consider the following implementation of quicksort:

```cpp
void quicksort(vector<int>& A, size_t left, size_t right) {
    if (left >= right) return;

    auto pivot = A[left + (right - left) / 2];
    auto i = left;
    auto j = right;

    while (i <= j) {
        while (A[i] < pivot) i++;
        while (A[j] > pivot) j--;
        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }

    quicksort(A, left, j);
    quicksort(A, i, right);
}

void quicksort(vector<int>& A) {
    quicksort(A, 0, A.size() - 1);
}
```

Consider calling `quicksort({9,3,7,1,6})`.

What is the first pivot? Give your answer as a single integer

[____](7)

What are the contents of `A` after partitioning but before the recursive calls? Give your answer as a comma-seperated
list.

[____](6,3,1,7,9)

What are the contents of `A` after the first recursive call? Give your answer as a comma-seperated list.

[____](1,3,6,7,9)

What are the contents of `A` after the second recursive call? Give your answer as a comma-seperated list.

[____](1,3,6,7,9)

## Problem

Consider the following implementation of mergesort:

```cpp
void merge(vector<int>& A, size_t left, size_t mid, size_t right, vector<int>& aux) {
    auto i = left;
    auto j = mid + 1;
    auto k = left;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) {
            aux[k++] = A[i++];
        } else {
            aux[k++] = A[j++];
        }
    }

    while (i <= mid) 
      aux[k++] = A[i++];
    while (j <= right) 
      aux[k++] = A[j++];

    for (size_t t = left; t <= right; ++t)
        A[t] = aux[t];
}

void mergesort(vector<int>& A, size_t left, size_t right, vector<int>& aux) {
    if (left >= right) 
      return;

    auto mid = left + (right - left) / 2;

    mergesort(A, left, mid, aux);
    mergesort(A, mid + 1, right, aux);

    merge(A, left, mid, right, aux);
}

void mergesort(vector<int>& A) {
    vector<int> aux(A.size());
    mergesort(A, 0, A.size() - 1, aux);
}
```

Consider calling `mergesort({9,3,7,6,1})`.

What are the contents of `A` after the first recursive call? Give your answer as a comma-seperated list.

[____](3,7,9,6,1)

What are the contents of `A` after the second recursive call? Give your answer as a comma-seperated list.

[____](3,7,9,1,6)

What are the contents of `A` after the call to `merge`? Give your answer as a comma-seperated list.

[____](1,3,6,7,9)

## Problem

What recurrence $$T(n)$$ represents the worst-case complexity of mergesort? Assume $$n$$, the size of the input array,
is a power of two. If needed, refer to the implementation of mergesort given above.

( ) $$T(n) = T(n/2) + \Theta(n)$$
(X) $$T(n) = 2T(n/2) + \Theta(n)$$
( ) $$T(n) = 2T(n - 1) + \Theta(n)$$
( ) $$T(n) = 2T(n/2)$$

What is the base case for $$T(n)$$?

(X) $$T(1) = \Theta(1)$$
( ) $$T(1) = \Theta(\lg n)$$
( ) $$T(1) = \Theta(n)$$
( ) $$T(1) = \Theta(n \lg n)$$
( ) $$T(1) = \Theta(n^2)$$

What is the closed form of $$T(n)$$?

( ) $$T(n) = \Theta(1)$$
( ) $$T(n) = \Theta(\lg n)$$
( ) $$T(n) = \Theta(n)$$
(X) $$T(n) = \Theta(n \lg n)$$
( ) $$T(n) = \Theta(n^2)$$

## Problem

What recurrence $$T(n)$$ represents the worst-case complexity of quicksort? Assume $$n$$, the size of the input array,
is a power of two. If needed, refer to the implementation of quicksort given above.

(X) $$T(n) = T(n - 1) + \Theta(n)$$
( ) $$T(n) = T(n - 1) + \Theta(1)$$
( ) $$T(n) = 2T(n - 1) + \Theta(n)$$
( ) $$T(n) = 2T(n - 1)$$

What is the base case for $$T(n)$$?

(X) $$T(1) = \Theta(1)$$
( ) $$T(1) = \Theta(\lg n)$$
( ) $$T(1) = \Theta(n)$$
( ) $$T(1) = \Theta(n \lg n)$$
( ) $$T(1) = \Theta(n^2)$$

What is the closed form of $$T(n)$$?

( ) $$T(n) = \Theta(1)$$
( ) $$T(n) = \Theta(\lg n)$$
( ) $$T(n) = \Theta(n)$$
( ) $$T(n) = \Theta(n \lg n)$$
(X) $$T(n) = \Theta(n^2)$$

## Problem

You are an embedded systems engineer designing a sensor fusion module in a drone's flight control system. The system
continuously collects data from multiple sensors, such as an accelerometer, gyroscope, and magnetometer, each producing
timestamped readings.

To fuse the data correctly, the software must:

1. Merge readings from all sensors into a single vector.
2. Sort the readings by their timestamp, ensuring the most recent readings are processed together. If two readings have
   the same timestamp, their relative order does not matter.

Because stack space is limited, recursive calls can nest at most $$20$$ levels deep before causing a segmentation fault.

Which sorting algorithm is more suitable for this application?

( ) Quicksort
(X) Mergesort

# Extra Practice (10 points)

## Problem

Assume a `size_t` is $$8$$ bytes, and a pointer is $$8$$ bytes. Let $$k$$ be the size of a `T` in bytes.

Consider the following definition of a grow-by-doubling vector:

```cpp
template <typename T>
class Vector {
   T* m_data;
   size_t m_size;
};
```

What is the worst-case space complexity of a size $$n$$ vector in bytes?

( ) $$16 + k(2n - 1)$$
(X) $$16 + 2k(n - 1)$$
( ) $$16 + 2kn$$
( ) $$16 + k(2n + 1)$$

Consider the following definition of a linked list:

```cpp
template <typename T>
class List {
   struct Node {
      T data;
      Node* next;
   };

   Node* m_head;
   size_t m_size;
};
```

What is the worst-case space complexity of a size $$n$$ list in bytes?

( ) $$16 + k(n + 8)$$
( ) $$16 + 8nk$$
( ) $$16 + nk$$
(X) $$16 + n(k + 8)$$

What is the lowest value of $$k$$ such that a size $$n$$ list is strictly more space efficient than a size $$n$$ vector?
Assume $$n$$ is very large. Give your answer as a single integer.

[____](9)

## Problem

Consider implementing `size_t count_max(const int* heap, size_t t, size_t n)` recursively. The function should count the
number of occurrences of the maximum element `heap[0]` in the subtree rooted by `heap[t]` in a valid max-heap `heap`.

What is the correct base case?

( ) `if (n == 0) return 0;`
( ) `if (t < n && heap[0] == heap[t]) return 1;`
( ) `if (t < n && heap[0] != heap[t]) return 0;`
(X) `if (t >= n || heap[0] != heap[t]) return 0;`

What is the correct recursive step?

(X) `return 1 + count_max(heap, 2 * t + 1, n) + count_max(heap, 2 * t + 2, n);`
( ) `return count_max(heap, 2 * t + 1, n) + count_max(heap, 2 * t + 2, n);`
( ) `return 1 + count_max(heap, t + 1, n - 1)`
( ) `return (heap[0] == heap[t]) + count_max(heap, t + 1, n - 1);`

Assume the maximum element occurs $$k$$ times in the heap. What is the worst-case time complexity of
`count_max(heap, 0, n);`?

( ) $$\Theta(1)$$
( ) $$\Theta(\lg n)$$
(X) $$\Theta(k)$$
( ) $$\Theta(k \lg n)$$
( ) $$\Theta(n)$$

## Problem

If quicksort takes the first element as the pivot, which input(s) cause quicksort to run in $$\Theta(n^2)$$ time?

[X] Sorted (least to greatest)
[X] Reverse sorted (greatest to least)
[X] Greatest, then least, then next greatest, then next least with odd length (e.g. `[5,1,4,2,3]`)
[ ] Greatest, then least, then next greatest, then next least with even length (e.g. `[6,1,5,2,4,3]`)

If quicksort takes the last element as the pivot, which input(s) cause quicksort to run in $$\Theta(n^2)$$ time?

[X] Sorted (least to greatest)
[X] Reverse sorted (greatest to least)
[ ] Greatest, then least, then next greatest, then next least with odd length (e.g. `[5,1,4,2,3]`)
[ ] Greatest, then least, then next greatest, then next least with even length (e.g. `[6,1,5,2,4,3]`)

If quicksort takes the median of the first, middle (i.e. `A[n/2]`), and last element as the pivot, which input(s) cause
quicksort to run in $$\Theta(n^2)$$ time?

[ ] Sorted (least to greatest)
[ ] Reverse sorted (greatest to least)
[ ] Greatest, then least, then next greatest, then next least with odd length (e.g. `[5,1,4,2,3]`)
[ ] Greatest, then least, then next greatest, then next least with even length (e.g. `[6,1,5,2,4,3]`)

## Problem

Consider the following sorting algorithm:

```cpp
void sort(vector<int>& A, size_t left, size_t right) {
    if (left >= right - 1) 
      return;

    auto n = right - left;
    auto m1 = 2 * n / 3 + left;
    auto m2 = n / 3 + left;
    auto m3 = n / 6 + left;
    auto m4 = 5 * n / 6 + left;
    
    sort(A, left, m1);
    sort(A, m2, right);
    sort(A, m3, m4);
}

void sort(vector<int>& A) {
    sort(A, 0, A.size());
}
```

What recurrence models the number of operations performed by `sort` on an input array of size $$n$$ in the worst-case?
Assume $$c$$ is the amount of non-recursive work.

( ) $$T(n) = 2T(n/2) + c$$
( ) $$T(n) = 3T(n/2) + c$$
(X) $$T(n) = 3T(2n/3) + c$$
( ) $$T(n) = 2T(n/3) + c$$

What is the correct base case for the recurrence?

( ) $$T(0) = \Theta(1)$$
(X) $$T(1) = \Theta(1)$$
( ) $$T(1) = \Theta(n)$$
( ) $$T(0) = \Theta(n)$$

Give a formula for $$T(n)$$ after expanding $$k$$ times.

(X) $$T(n) = 3^k T(2^kn/3^k) + \sum\limits_{i=0}^{k-1} c 3^i$$
( ) $$T(n) = 2^k T(n/2^k) + \sum\limits_{i=0}^{k-1} c 2^i $$
( ) $$T(n) = 3^k T(n/2^k) + \sum\limits_{i=0}^{k-1} c 3^i$$
( ) $$T(n) = 2^k T(n/3^k) + \sum\limits_{i=0}^{k-1} c 2^i$$

What value of $$k$$ yields the base case?

( ) $$\frac{\lg n}{\lg(3/2)}$$
( ) $$\lg n$$
( ) $$\log_3 n$$
(X) $$\frac{\log_{3} n}{\log_{3}(3/2)}$$

What is the closed form of $$T(n)$$?

( ) $$T(n) = \Theta(n \lg n)$$
( ) $$T(n) = \Theta(n^{1.709\ldots} \lg n)$$
(X) $$T(n) = \Theta(n^{2.709\ldots})$$
( ) $$T(n) = \Theta(n^{1.709\ldots})$$

# Optional Advanced Topics (20 points)

## Problem

In this problem, you will prove the second case of the famous **master theorem**, and use it to analyze several
recurrences.

Let $$a \geq 1$$ and $$b > 1$$ be constants, let $$f(n) = \Theta(n^c)$$, and let $$T(n) = aT(n / b) + f(n)$$ where
$$T(1) = \Theta(1)$$.

What is $$T(n)$$ after expanding $$k$$ times?

( ) $$T(n) = a^k T(n/b^k) + \sum\limits_{i=0}^{k - 1} a^i n^c / b^i$$
( ) $$T(n) = a^k T(n/b^k) + \sum\limits_{i=0}^{k - 1} b^i (n / a)^{ci}$$
(X) $$T(n) = a^k T(n/b^k) + \sum\limits_{i=0}^{k - 1} a^i (n / b^i)^c$$
( ) $$T(n) = a^k T(n/b^k) + \sum\limits_{i=0}^{k - 1} n^c / b^i$$
( ) $$T(n) = a^k T(n/b^k) + \sum\limits_{i=0}^{k - 1} b^i (n / a^i)^c$$

What value of $$k$$ yields the base case?

( ) $$k = \log_a n$$
( ) $$k = \lg n$$
( ) $$k = \log_b a$$
(X) $$k = \log_b n$$
( ) $$k = \log_a b$$

The second case of the master theorem provides an asymptotic bound on $$T(n)$$ when $$c = \log_b a$$. What is that
bound?

( ) $$T(n) = \Theta(n \lg n)$$
( ) $$T(n) = \Theta(n^{\log_b a})$$
( ) $$T(n) = \Theta(n^{\log_a b} \lg n)$$
( ) $$T(n) = \Theta(n^{\log_a b})$$
(X) $$T(n) = \Theta(n^{\log_b a} \lg n)$$

Consider the recurrence for the time complexity of mergesort.

What is $$a$$? Give your answer as a single integer.

[____](2)

What is $$b$$? Give your answer as a single integer.

[____](2)

What is $$c$$? Give your answer as a single integer.

[____](1)

According to the second case of the master theorem, what is the time complexity of mergesort?

( ) $$\Theta(\lg n)$$
( ) $$\Theta(n)$$
(X) $$\Theta(n \lg n)$$
( ) $$\Theta(n^2)$$
( ) $$\Theta(n^2 \lg n$$

Which of the following recurrences can be analyzed with the second case of the master theorem (as stated above)?

[ ] $$T(n) = 3T(2n/3) + \Theta(1)$$
[ ] $$T(n) = T(n/2) + T(n/4) + \Theta(1)$$
[X] $$T(n) = 2T(n/3) + \Theta(n^{\lg 3})$$
[ ] $$T(n) = T(n - 1) + n$$
[X] $$T(n) = T(n/4) + 10$$
[x] $$T(n) = 3T(2n/5) + \Theta(n^{\log_{2.5} 3}$$

## Problem

Consider the following implementation of quicksort:

```cpp
void quicksort(vector<int>& A, size_t left, size_t right) {
    if (left >= right) return;

    auto pivot = random_pivot(left, right);
    auto i = left;
    auto j = right;

    while (i <= j) {
        while (A[i] < pivot) i++;
        while (A[j] > pivot) j--;
        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }

    quicksort(A, left, j);
    quicksort(A, i, right);
}

void quicksort(vector<int>& A) {
    quicksort(A, 0, A.size() - 1);
}
```

Assume `random_pivot` selects the pivot uniformly at random. What is the average number of recursive calls performed by
quicksort on an array of one thousand unique elements? Give your answer as a single integer (round up).

[____](1334)
