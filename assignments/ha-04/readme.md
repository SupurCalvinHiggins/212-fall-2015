# Overview

In this assignment, you will practice TODO.

## Learning Objectives

By the end of this assignment, you should be able to:

1. Trace how common dynamic array and min/max-heaps operations change the data structure's internal state.
2. Trace the execution of programs that use stacks, queues and min/max-priority queues.
3. Analyze the asymptotic time complexity of common dynamic array and min/max-heap operations.
4. Analyze the asymptotic time complexity of programs that use stacks, queues, and min/max-priority queues.
5. Select between stacks, queues, or min/max-priority queues to efficiently solve computational problems.

TODO: discuss answer formats here, require checking a i understand box
integer
comma-delimited list

# Core Content (5 points)

## Problem

Suppose `std::vector<int>` is implemented as a grow-by-one dynamic array with initial capacity $1$. Assume the 
underlying array never shrinks.

Consider the vector `v`'s state after the follow code executes:
```cpp
std::vector<int> v;
v.push_back(0);
v.push_front(1);
v.push_front(2);
v.push_back(3);
v.pop_front();
v.pop_back();
v.push_front(4);
```

What is `v`'s size? Provide your answer as a single integer.

[____](=3)

What is `v`'s capacity? Provide your answer as a single integer.

[____](=4)

What are the contents of `v`, in order from the first element to the last? Provide your answer as a comma-delimited 
list.

[____](4,1,0)

## Problem

Suppose `std::vector<int>` is implemented as a grow-by-doubling dynamic array with initial capacity $1$. Assume the
underlying array never shrinks.

Consider the vector `v`'s state after the follow code executes:
```cpp
std::vector<int> v;
v.push_back(0);
v.push_back(1);
v.push_back(2);
v.push_front(3);
v.push_front(4);
v.pop_back();
v.pop_back();
v.pop_front();
v.pop_front()
v.push_back(5);
```

What is `v`'s size? Provide your answer as a single integer.

[____](=2)

What is `v`'s capacity? Provide your answer as a single integer.

[____](=8)

What are the contents of `v`, in order from the first element to the last? Provide your answer as a comma-delimited
list.

[____](0,5)

## Problem

Suppose `std::make_heap` is implemented as the $\Theta(n)$ **binary min-heap** construction algorithm discussed in 
lecture.

Consider the vector `v`'s state after the following code executes:
```cpp
std::vector<int> v{3,6,4,5,0,2,1};
std::make_heap(v.begin(), v.end());
```

What are the contents of `v`, in order from the first element to the last? Provide your answer as a comma-delimited 
list.

[____](`0,3,1,5,6,2,4`)

## Problem

Suppose `std::make_heap` is implemented as the $\Theta(n)$ **binary max-heap** construction algorithm discussed in 
lecture.

Consider the vector `v`'s state after the following code executes:
```cpp
std::vector<int> v{2,6,3,5,0,1,4};
std::make_heap(v.begin(), v.end());
```

What are the contents of `v`, in order from the first element to the last? Provide your answer as a comma-delimited
list.

[____](`6,5,4,2,0,1,3`)

## Problem

Suppose `std::push_heap` and `std::pop_heap` are implemented as the $\mathcal{O}(\lg n)$ **binary min-heap** operations 
discussed in lecture.

Consider the vector `v`'s state after the following code executes:
```cpp
std::vector<int> v{0,2,1,4,3,5,6};
std::pop_heap(v.begin(), v.end());
v.pop_back();
std::pop_heap(v.begin(), v.end());
v.pop_back();
std::pop_heap(v.begin(), v.end());
v.pop_back();
v.push_back(0);
std::push_heap(v.begin(), v.end());
```

What are the contents of `v`, in order from the first element to the last? Provide your answer as a comma-delimited
list.

[____](0,4,3,6,5)

## Problem

Suppose `std::push_heap` and `std::pop_heap` are implemented as the $\mathcal{O}(\lg n)$ **binary max-heap** operations
discussed in lecture.

Consider the vector `v`'s state after the following code executes:
```cpp
std::vector<int> v{6,4,5,0,3,1,2};
std::pop_heap(v.begin(), v.end());
v.pop_back();
std::pop_heap(v.begin(), v.end());
v.pop_back();
std::pop_heap(v.begin(), v.end());
v.pop_back();
v.push_back(6);
std::push_heap(v.begin(), v.end());
```

What are the contents of `v`, in order from the first element to the last? Provide your answer as a comma-delimited
list.

[____](6,3,1,2,0)

## Problem

Consider the following class:
```cpp
class Foo {
    std::stack<int> s1;
    std::stack<int> s2;

    void baz() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void corge(int x) {
        s1.push(x);
    }

    void qux() {
        if (s2.empty()) baz();
        s2.pop();
    }

    int bar() {
        if (s2.empty()) baz();
        return s2.top();
    }
};
```

What is the output of the following program? Provide your answer as a comma-delimited list.

```cpp
Foo f;
for (int i = 0; i < 4; ++i)
    f.corge(i);

std::cout << f.bar();
f.qux();
for (int i = 1; i < 4; ++i) {
    std::cout << ',' << f.bar();
    f.qux();
}
```

[____](0,1,2,3)

## Problem

Consider the following class:
```cpp
class Foo {
    std::queue<int> q1;
    std::queue<int> q2;

    void baz() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
    }

public:
    void corge(int x) {
        q1.push(x);
    }

    void qux() {
        baz();
        q1.pop();
        std::swap(q1, q2);
    }

    int bar() {
        baz();
        int val = q1.front();
        q2.push(val);
        q1.pop();
        std::swap(q1, q2);
        return val;
    }
};
```

What is the output of the following program? Provide your answer as a comma-delimited list.

```cpp
Foo f;
for (int i = 0; i < 4; ++i)
    f.corge(i);

std::cout << f.bar();
f.qux();
for (int i = 1; i < 4; ++i) {
    std::cout << ',' << f.bar();
    f.qux();
}
```

[____](3,2,1,0)

## Problem

Assume that `std::priority_queue<int>` is a max-priority queue. Consider the following class:
```cpp
class Foo {
    std::priority_queue<int> pq;

public:
    void corge(int x) {
        pq.push(-x);
    }

    void qux() {
        pq.pop();
    }

    int bar() {
        return -pq.top();
    }
};
```

What is the output of the following program? Provide your answer as a comma-delimited list.

```cpp
Foo f;
f.corge(2);
f.corge(1);
f.corge(3);
f.corge(0);

std::cout << f.bar();
f.qux();
for (int i = 1; i < 4; ++i) {
    std::cout << ',' << f.bar();
    f.qux();
}
```

[____](0,1,2,3)

## Problem

Assume that `std::priority_queue<int>` is a max-priority queue. 

Consider the following function:
```cpp
int foo(const std::vector<int>& v) {
    std::priority_queue<int> pq;
    for (auto f : v)
        pq.push(-f);
 
    int t = 0;
    while (pq.size() > 1) {
        auto a = -pq.top(); 
        pq.pop();
        auto b = -pq.top(); 
        pq.pop();
        auto c = a + b;
        t += c;
        pq.push(-c);
    }
    return t;
}
```

What is `foo({1,1,2,3,7,13})`? Provide your answer as a single integer.

[____](=54)

## Problem

Consider the following function:
```cpp
std::vector<int> foo(const std::vector<int>& v, int k) {
    std::deque<int> dq;
    std::vector<int> result;

    for (int i = 0; i < v.size(); ++i) {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && v[dq.back()] <= v[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(v[dq.front()]);
    }

    return result;
}
```

What is `foo({1,1,2,3,7,0},3)`? Provide your answer as a comma-delimited list.

[____](2,3,7,7)

## Problem

Consider the following implementation of a stack:
```cpp
class Stack {
    std::priority_queue<std::pair<int,int>> pq;
    int counter = 0;

public:
    void push(int x) {
        pq.push({++counter, x});
    }

    void pop() {
        pq.pop();
    }

    int top() {
        return pq.top().second;
    }

    bool empty() {
        return pq.empty();
    }
};
```

What is the worst-case time complexity of `push`?

( ) $\Theta(1)$
(X) $\Theta(\lg n)$
( ) $\Theta(n)$
( ) $\Theta(n \lg n)$

What is the worst-case time complexity of `pop`?

( ) $\Theta(1)$
(X) $\Theta(\lg n)$
( ) $\Theta(n)$
( ) $\Theta(n \lg n)$

What is the worst-case time complexity of `top`?

(X) $\Theta(1)$
( ) $\Theta(\lg n)$
( ) $\Theta(n)$
( ) $\Theta(n \lg n)$

Which methods perform worse than a stack implemented with a grow-by-doubling dynamic array?

[X] `push`
[X] `pop`
[ ] `top`

## Problem

Consider the following implementation of a queue:
```cpp
class Queue {
    std::priority_queue<std::pair<int,int>> pq;
    int counter = 0;

public:
    void push(int x) {
        pq.push({counter--, x});
    }

    void pop() {
        pq.pop();
    }

    int front() {
        return pq.top().second;
    }

    bool empty() {
        return pq.empty();
    }
};
```

What is the worst-case time complexity of `push`?

( ) $\Theta(1)$
(X) $\Theta(\lg n)$
( ) $\Theta(n)$
( ) $\Theta(n \lg n)$

What is the worst-case time complexity of `pop`?

( ) $\Theta(1)$
(X) $\Theta(\lg n)$
( ) $\Theta(n)$
( ) $\Theta(n \lg n)$

What is the worst-case time complexity of `top`?

(X) $\Theta(1)$
( ) $\Theta(\lg n)$
( ) $\Theta(n)$
( ) $\Theta(n \lg n)$

Which methods perform worse than a queue implemented with a grow-by-doubling dynamic array? Assume `push` prepends to
the dynamic array, and `pop` appends.

[ ] `push`
[X] `pop`
[ ] `top`

## Problem



200 points

120 in core content - 24 problems at 5 points each (currently 25, must cut 1)


State complexity of push/pop-front/back, indexing for grow-by-one DA.
State complexity of push/pop-front/back, indexing for doubling DA.
State complexity of heapify, push, pop, top for heap.
Analysis of min priority queue implemented as a dynamic array (could include speedup against heap)

Analysis of paren matching using stacks.
Analysis of buildup and pulse every k using queues.
Analysis of heapsort using min priority queues.
Analysis of third largest using max priority queue.
TODO analysis of program using deque

Select ADT for HTML validation.
Select ADT for queueing up requests to a webserver.
Select ADT for merging logs in chronological order.
Select ADT for maintaining median in a stream.
TODO select ADT with deque

30 in extra practice - 3 problems at 10 points each
50 in advanced topics - 2 problems at 15, 1 at 20

Analysis of building min-heap via inserting increasing (or mostly increasing) sequence.
Analysis of queue where the first n integers are inserted in order, cycled to front where only the integers that are 0 under mod k are retained.
Analysis of heapsort with many duplicate elements.
Analysis of reservoir sampling with bounded heap size.
Analysis of d-ary heap with parameter optimization on d. Consider the case where each node is implemented with a heap.

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

## Confirmation

I have read and understand the above.
(X) Yes
( ) No

# Core Content (5 points)

# Extra Practice (10 points)

# Optional Advanced Topics (15 points)

# Optional Advanced Topics (20 points)