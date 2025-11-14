# Overview

In this assignment, you will practice with graph representations and graph algorithms. 

## Learning Objectives

By the end of this assignment, you should be able to:

1. Check basic graph properties (e.g. connected, directed, acyclic, sparsity).
2. Convert between graph representations (e.g. adjacency list and matrix).
3. Trace breadth-first and depth-first search.
4. Analyze the time complexity of graph algorithms.
5. Select between breadth-first and depth-first search.

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

To prepare for the final, you should:

1. Complete at least one of each **Core Content** problem type

## Recommendations

The midterm will include many free response questions. To prepare effectively:

* Avoid relying on multiple choice options to guide your answer. Instead, work out your solution first, then check
  against the choices.
* You can use any resources available (including AI), but always attempt each problem on your own for 5-10 minutes 
  before seeking help.

## Answer Formats

**Short answer questions are autograded. You must follow the format specified below to receive credit.** 

If the problem asks for a single integer, provide your answer as a single integer without whitespace. For example, `10`.

If the problem asks for a list of integers, provide your answer as a comma-delimited list without whitespace. For example, `3,1,4,0,12`.

If the problem asks for adjacency list format, provide your answer as a nested list without whitespace. For example, `[[1],[],[0,2]]`.

If the problem asks for adjacency matrix format, provide your answer as a nested list without whitespace. For example, `[[0,0,1],[0,0,0],[1,0,1]]`.

## Confirmation

I have read and understand the above.
(X) Yes
( ) No

# Core Content (5 points)

## Problem

Convert the following adjacency matrix into an adjacency list:
```txt
[[0,1,1,0],[0,0,0,0],[1,0,0,1],[1,1,1,0]]
```

Give your answer in adjacency list format. 
[____]([[1,2],[],[0,3],[0,1,2]])

## Problem

Convert the following adjacency list into an adjacency matrix:
```txt
[[1,2],[],[0]]
```

Give your answer in adjacency matrix format. 
[____]([[0,1,1],[0,0,0],[1,0,0]])

## Problem

Consider the graph represented by the following adjacency matrix:
```txt
[[1,0,1],[0,1,0],[1,0,1]]
```

Is the graph directed?

[ ] Yes
[X] Maybe
[ ] No

Is the graph weighted?

[ ] Yes
[X] Maybe
[ ] No

Is the graph acyclic?

[ ] Yes
[ ] Maybe
[X] No

## Problem

Consider the graph represented by the following adjacency list:
```txt
[[(1,5),(2,10)],[(2,10)],[]]
```

Is the graph directed?

[X] Yes
[ ] Maybe
[ ] No

Is the graph weighted?

[X] Yes
[ ] Maybe
[ ] No

Is the graph acyclic?

[X] Yes
[ ] Maybe
[ ] No

## Problem

Consider the following adjacency matrix:
```txt
[[1,0,0,1],[0,0,0,1],[0,1,1,0],[1,1,0,0]]
```

When doing a depth-first search starting at vertex 3, what order are the vertices visited in? Give your answer as a list of integers.
[____](3,0,1,2)

## Problem

Consider the following adjacency list:
```txt
[[0,3],[3],[1,2],[0,1]]
```

When doing a breadth-first search starting at vertex 0, what order are the vertices visited in? Give your answer as a list of integers.
[____](0,1,2,3)

## Problem

What is the time complexity of adding a new vertex to an adjacency list? 

(X) $$\Theta(1)$$
( ) $$\Theta(V)$$
( ) $$\Theta(E)$$
( ) $$\Theta(V + E)$$
( ) $$\Theta(VE)$$
( ) $$\Theta(V^2)$$
( ) $$\Theta(E^2)$$

What is the time complexity of adding a new vertex to an adjacency matrix?

( ) $$\Theta(1)$$
(X) $$\Theta(V)$$
( ) $$\Theta(E)$$
( ) $$\Theta(V + E)$$
( ) $$\Theta(VE)$$
( ) $$\Theta(V^2)$$
( ) $$\Theta(E^2)$$

## Problem

What is the time complexity of adding a new edge to an adjacency list? 

(X) $$\Theta(1)$$
( ) $$\Theta(V)$$
( ) $$\Theta(E)$$
( ) $$\Theta(V + E)$$
( ) $$\Theta(VE)$$
( ) $$\Theta(V^2)$$
( ) $$\Theta(E^2)$$

What is the time complexity of adding a new edge to an adjacency matrix?

(X) $$\Theta(1)$$
( ) $$\Theta(V)$$
( ) $$\Theta(E)$$
( ) $$\Theta(V + E)$$
( ) $$\Theta(VE)$$
( ) $$\Theta(V^2)$$
( ) $$\Theta(E^2)$$

## Problem

What is the time complexity of depth-first search? Assume the best possible graph representation.

( ) $$\Theta(1)$$
( ) $$\Theta(V)$$
( ) $$\Theta(E)$$
(X) $$\Theta(V + E)$$
( ) $$\Theta(VE)$$
( ) $$\Theta(V^2)$$
( ) $$\Theta(E^2)$$

## Problem

What is the time complexity of breadth-first search? Assume the best possible graph representation.

( ) $$\Theta(1)$$
( ) $$\Theta(V)$$
( ) $$\Theta(E)$$
(X) $$\Theta(V + E)$$
( ) $$\Theta(VE)$$
( ) $$\Theta(V^2)$$
( ) $$\Theta(E^2)$$

## Problem

Suppose you wish to find the shortest possible sequence of moves to solve a Rubik cube. You will model the problem as a graph.

What are the vertices?

( ) Moves
(X) Cube states
( ) Cube tiles
( ) Colors

What are the edges?

(X) Moves
( ) Cube states
( ) Cube tiles
( ) Colors

Is the graph sparse?

(X) Yes
( ) No

Should you use depth-first or breadth-first search?

( ) Depth-first search
(X) Breadth-first search

## Problem

Suppose you wish to count the number of ways to solve a maze without ever returning to the same location. The maze is laid out on grid paper. You will model the problem as a graph.

What are the vertices?

( ) Grid lines
( ) Pathways
(X) Grid cells
( ) Maze walls

What are the edges?

( ) Connections between adjacent grid lines
(X) Connections between adjacent grid cells that are open (no wall)
( ) Connections between grid cells
( ) Connections between all grid lines

Is the graph sparse?

(X) Yes
( ) No

Should you use depth-first or breadth-first search?

(X) Depth-first search
( ) Breadth-first search

# Extra Practice

## Problem

Consider the following graph algorithm:
```cpp
constexpr int INF = 1e9;

std::vector<int> sssp(int source, const std::vector<std::vector<std::pair<int, int>>>& adj) {
    std::vector<int> dist(n, INF);
    dist[start] = 0;

    std::priority_queue<
        std::pair<int, int>, 
        std::vector<std::pair<int, int>>, 
        std::greater<std::pair<int, int>>
    > pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
```

What is the worst-case time complexity for a connected graph?

( ) $$\Theta(V)$$
( ) $$\Theta(E)$$
( ) $$\Theta(V + E)$$
( ) $$\Theta(V \lg V)$$
(X) $$\Theta(E \lg E)$$
( ) $$\Theta(V^2)$$
( ) $$\Theta(VE)$$
( ) $$\Theta(E^2)$$

## Problem

Consider the following graph algorithm:
```cpp
constexpr int INF = 1e9;

int mst(int n, const std::vector<std::vector<std::pair<int, int>>>& adj, int start = 0) {
    std::vector<bool> visited(n, false);

    std::priority_queue<
        std::pair<int, int>, 
        std::vector<std::pair<int, int>>, 
        std::greater<std::pair<int, int>>
    > pq;

    pq.push({0, start});
    int total = 0;

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        total += cost;

        for (auto [v, w] : adj[u])
            if (!visited[v])
                pq.push({w, v});
    }

    return total;
}
```

What is the worst-case time complexity for a connected graph?

( ) $$\Theta(V)$$
( ) $$\Theta(E)$$
( ) $$\Theta(V + E)$$
( ) $$\Theta(V \lg V)$$
(X) $$\Theta(E \lg E)$$
( ) $$\Theta(V^2)$$
( ) $$\Theta(VE)$$
( ) $$\Theta(E^2)$$

# Optional Advanced Topics

## Problem

A **Markov chain** is a weighted graph where the edge weights represent the probability of moving from one vertex to another. 

Consider the following Markov chain:
```txt
[[0.1,0.3,0.5,0.1],[0,0.5,0.5,0],[0.8,0.1,0,0.1],[1,0,0,0]]
```

If you start at vertex 0 and move randomly according to the edge weights, what is the average number of steps to visit vertex 3 twice? Give your answer as a single integer (round down).
[____](27)
