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

TODO: define classes, have to state everything required to know internal state and understand performance.
`grow_by_one_vector`
`grow_by_doubling_vector` or `vector`
`min_priority_queue`
`max_priority_queue`
`make_min_heap`
`make_max_heap`
`pop_min_heap`
`pop_max_heap`
`top_min_heap`
`top_max_heap`
`queue`
`stack`
`deque`

# Core Content (5 points)

## Problem

Consider the vector `v`'s state after the follow code executes:
```cpp
grow_by_one_vector<int> v;
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

Consider the vector `v`'s state after the follow code executes:
```cpp
vector<int> v;
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

Consider the vector `v`'s state after the following code executes:
```cpp
vector<int> v{3,6,4,5,0,2,1};
make_min_heap(v.begin(), v.end());
```

What are the contents of `v`, in order from the first element to the last? Provide your answer as a comma-delimited 
list.

[____](`0,3,1,5,6,2,4`)

## Problem

Consider the vector `v`'s state after the following code executes:
```cpp
vector<int> v{2,6,3,5,0,1,4};
make_max_heap(v.begin(), v.end());
```

What are the contents of `v`, in order from the first element to the last? Provide your answer as a comma-delimited
list.

[____](`6,5,4,2,0,1,3`)

## Problem

Consider the vector `v`'s state after the following code executes:
```cpp
vector<int> v{0,2,1,4,3,5,6};
pop_min_heap(v.begin(), v.end());
v.pop_back();
pop_min_heap(v.begin(), v.end());
v.pop_back();
pop_min_heap(v.begin(), v.end());
v.pop_back();
v.push_back(0);
push_min_heap(v.begin(), v.end());
```

What are the contents of `v`, in order from the first element to the last? Provide your answer as a comma-delimited
list.

[____](0,4,3,6,5)

## Problem

Consider the vector `v`'s state after the following code executes:
```cpp
vector<int> v{6,4,5,0,3,1,2};
pop_max_heap(v.begin(), v.end());
v.pop_back();
pop_max_heap(v.begin(), v.end());
v.pop_back();
pop_max_heap(v.begin(), v.end());
v.pop_back();
v.push_back(6);
push_max_heap(v.begin(), v.end());
```

What are the contents of `v`, in order from the first element to the last? Provide your answer as a comma-delimited
list.

[____](6,3,1,2,0)

## Problem

Consider the following class:
```cpp
class Foo {
    stack<int> s1;
    stack<int> s2;

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
    queue<int> q1;
    queue<int> q2;

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

Consider the following class:
```cpp
class Foo {
    max_priority_queue<int> pq;

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

Consider the following function:
```cpp
int foo(const vector<int>& v) {
    max_priority_queue<int> pq;
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
vector<int> foo(const vector<int>& v, int k) {
    deque<int> dq;
    vector<int> result;

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

Consider `grow_by_one_vector`.

For each operation below, give the worst-case time complexity per operation. If the best possible bound requires
amortized analysis, choose that option instead.

What is the time complexity of `push_back`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
(X) $\Theta(n)$

What is the time complexity of `push_front`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
(X) $\Theta(n)$

What is the time complexity of `pop_back`?

(X) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
( ) $\Theta(n)$

What is the time complexity of `pop_front`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
(X) $\Theta(n)$

What is the time complexity of `operator[]` (indexing)?

(X) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
( ) $\Theta(n)$

## Problem

Consider `grow_by_doubling_vector`.

For each operation below, give the worst-case time complexity per operation. If the best possible bound requires
amortized analysis, choose that option instead.

What is the time complexity of `push_back`?

( ) $\Theta(1)$
(X) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
( ) $\Theta(n)$

What is the time complexity of `push_front`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
(X) $\Theta(n)$

What is the time complexity of `pop_back`?

(X) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
( ) $\Theta(n)$

What is the time complexity of `pop_front`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
(X) $\Theta(n)$

What is the time complexity of `operator[]` (indexing)?

(X) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
( ) $\Theta(n)$

## Problem

For each operation below, give the worst-case time complexity per operation. If the best possible bound requires
amortized analysis, choose that option instead.

What is the time complexity of `make_max_heap`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
(X) $\Theta(n)$

What is the time complexity of `push_max_heap`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
(X) $\Theta(\lg n)$
( ) $\Theta(n)$

What is the time complexity of `pop_max_heap`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
(X) $\Theta(\lg n)$
( ) $\Theta(n)$

What is the time complexity of `top_max_heap`?

(X) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
( ) $\Theta(n)$

## Problem

Consider the following implementation of a stack:
```cpp
class Stack {
    max_priority_queue<std::pair<int,int>> pq;
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

For each operation below, give the worst-case time complexity per operation. If the best possible bound requires
amortized analysis, choose that option instead.

What is the time complexity of `push`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
(X) $\Theta(\lg n)$
( ) $\Theta(n)$

What is the time complexity of `pop`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
(X) $\Theta(\lg n)$
( ) $\Theta(n)$

What is the time complexity of `top`?

(X) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
( ) $\Theta(n)$

## Problem

Consider the following implementation of a queue:
```cpp
class Queue {
    max_priority_queue<std::pair<int,int>> pq;
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

For each operation below, give the worst-case time complexity per operation. If the best possible bound requires
amortized analysis, choose that option instead.

What is the time complexity of `push`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
(X) $\Theta(\lg n)$
( ) $\Theta(n)$

What is the time complexity of `pop`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
(X) $\Theta(\lg n)$
( ) $\Theta(n)$

What is the time complexity of `top`?

(X) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
( ) $\Theta(n)$

## Problem

Consider the following implementation of a min-priority queue:
```cpp
class MinPQ {
    vector<int> data;

public:
    void push(int x) {
        data.push_back(x);
    }

    void pop() {
        if (data.empty()) return;
        auto it = std::min_element(data.begin(), data.end());
        data.erase(it);
    }

    int top() {
        return *std::min_element(data.begin(), data.end());
    }

    bool empty() {
        return data.empty();
    }
};
```

For each operation below, give the worst-case time complexity per operation. If the best possible bound requires 
amortized analysis, choose that option instead.

What is the time complexity of `push`?

( ) $\Theta(1)$
(X) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
( ) $\Theta(n)$

What is the time complexity of `pop`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
(X) $\Theta(n)$

What is the time complexity of `top`?

( ) $\Theta(1)$
( ) $\Theta(1)$ amortized
( ) $\Theta(\lg n)$
(X) $\Theta(n)$

## Problem


Consider the following function:
```cpp
vector<int> next_greater_element(const vector<int>& v) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && nums[i] > nums[s.top()]) {
            int idx = s.top();
            s.pop();
            result[idx] = nums[i];
        }
        s.push(i);
    }

    return result;
}
```

What is worst-case time complexity of `next_greater_element`?

( ) $\Theta(1)$
( ) $\Theta(\lg n)$
(X) $\Theta(n)$
( ) $\Theta(n \lg n)$

## Problem

Consider the following function:
```cpp
void heapsort(vector<int>& v) {
    min_priority_queue<int> pq(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = pq.top();
        pq.pop();
    }
}
```

What is worst-case time complexity of `heapsort`?

( ) $\Theta(1)$
( ) $\Theta(\lg n)$
( ) $\Theta(n)$
(X) $\Theta(n \lg n)$

## Problem

Consider the following function:
```cpp
int max3(const vector<int>& v) {
    max_priority_queue<int> pq(v.begin(), v.end());
    pq.pop();
    pq.pop();
    return pq.top();
}
```

What is worst-case time complexity of `max3`? 

( ) $\Theta(1)$
( ) $\Theta(\lg n)$
(X) $\Theta(n)$
( ) $\Theta(n \lg n)$

## Problem

You are a software engineer working on a web browser. Web pages are written in a markup language called **HTML**, which 
describes the structure and content of a page. Before rendering a page, the browser must validate the HTML document.

In HTML, text is surrounded by **tags** that come in pairs.
* An **opening tag** looks like `<tagname>` (for example, `<p>`).
* A **closing tag** looks like `</tagname>` (for example, `</p>`).

A HTML document is **valid** if:
1. Every opening tag has a matching closing tag.
2. Tags are **properly nested**: the last tag opened must be the first one closed.

For example:
* `<a><b></b></a>` is valid.
* `<a><b></a></b>` is not valid (tags overlap incorrectly).
* `<a><b></b>` is not valid (missing </a>).

Which abstract data type best for checking whether a sequence of tags forms a valid HTML document? Here, best means an 
abstract data type that efficiently solves the problem, and provides only the operations needed.

(X) Stack
( ) Queue
( ) Priority Queue
( ) Deque

## Problem

You work for a company that manufactures networked printers. Customers send **print jobs** to the system. A print job is
a unit of work like printing one document. Jobs arrive in the order customers submit them. The system must send jobs to 
printers in that same order.

For example, suppose jobs are represented by letters and the system has two printers:
1. Jobs `A`, `B`, `C`, `D` arrive.
    - Printer 1 takes `A`.
    - Printer 2 takes `B`.
2. Both printers finish their first jobs.
    - Printer 1 takes `C`.
    - Printer 2 takes `D`.
3. Two more jobs, `E` and `F`, arrive.
    - Printer 1 takes `E`.
    - Printer 2 takes `F`.
4. Finally, job `G` arrives, and Printer 1 takes `G`.

Which abstract data type best models the system’s waiting area for jobs before they are sent to a printer? Here, best 
means an abstract data type that efficiently solves the problem, and provides only the operations needed.

( ) Stack
(X) Queue
( ) Priority Queue
( ) Deque

## Problem

You are a software engineer working on the cloud platform for a company that manufactures internet-connected 
refrigerators. Each refrigerator periodically sends log messages to the cloud. A log message records an event (e.g., 
“door opened,” “temperature adjusted,” or “power shut off”) along with a timestamp.

Recently, a serious bug was reported: many refrigerators randomly shut off within the same hour. To diagnose the 
problem, you need to merge the logs from thousands of refrigerators into a single stream that is sorted by timestamp, so
you can see the exact sequence of events across all devices.

Different refrigerators may experience network delays or temporarily go offline. This means log messages may arrive at 
the cloud out of order relative to their timestamps, even if each refrigerator sent its logs in chronological order.

Which abstract data type best allows you to select the next log entry in true chronological order? Here, best means an 
abstract data type that efficiently solves the problem, and provides only the operations needed.

( ) Stack
( ) Queue
(X) Priority Queue
( ) Deque

## Problem

You are a software engineer building a system to monitor air quality in a smart city. Sensors placed throughout the city
report PM2.5 levels (fine particulate matter) every minute. To detect dangerous spikes in pollution, your system must 
continuously report the maximum PM2.5 reading over the last $k$ minutes for each sensor.

For example, if the last 5 measurements from one sensor are `22,15,20,12,18`, the maximum in that 5-minute window is 
`22`. If the next measurement is `9`, the new maximum is `20`.

Which abstract data type best allows you to compute the maximum PM2.5 reading over the last $k$ minutes? Here, best 
means an abstract data type that efficiently solves the problem, and provides only the operations needed.

( ) Stack
( ) Queue
( ) Priority Queue
(X) Deque

## Extra Practice (10 points)

## Optional Advanced Topics (15 points)

## Optional Advanced Topics (20 points)


200 points

120 in core content - 24 problems at 5 points each (currently 25, must cut 1)

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