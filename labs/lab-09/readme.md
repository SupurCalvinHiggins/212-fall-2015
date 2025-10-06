# Lab 8 - Balanced Binary Search Trees

# Overview

In this lab, you will design, implement and analyze balanced binary search trees.

## Learning Objectives

By the end of this lab, you should be able to:

1. Implement abstract data types with balanced binary search trees.
2. Evaluate the performance characteristics of balanced binary search trees.

## Grading

To receive full credit, you should:

1. Attend, participate and collaborate.
2. Make at least one submission to Gradescope.

> [!IMPORTANT]
> Effort is enough to receive full credit. You do not need to successfully complete any activities.

## Milestones

To achieve the lab objectives, you should:

1. Complete all activities listed under **Core Content**.

> [!NOTE]
> If you do not complete all activities listed under **Core Content** during the lab period, we recommend finishing them
> on your own. Subsequent labs, assignments and lectures will assume you have completed this lab's **Core Content**
> activities.

To leave early, you should:

1. Complete all activities listed under **Core Content**.
2. Complete all activities listed under **Extra Practice** or **Optional Advanced Topics**.

To maximize your learning, you should:

1. Complete all activities listed under **Core Content**.
2. Complete all activities listed under **Extra Practice**.
3. Attempt some activities listed under **Optional Advanced Topics**.

# Core Content

## Project Setup

1. Create a new project called `csc212-lab-09` in your IDE.
2. Download all files from [the lab handout folder](handout) into the `csc212-lab-09` project.

> [!NOTE]
> To download all files from the repository, navigate to the root of the repository, click on the green **Code** button
> and select **Download Zip**.`

## Pseudo-Set

Pseudo-sets provide three main operations:

1. `insert` which adds a value into the set.
2. `contains` which checks if a value is in the set.

### Implementation

In this section, you will design and implement a pseudo-set using a balanced binary search tree.

1. Complete `pseudoset.h` and `pseudoset.cpp`.
2. Build `test_pseudoset` from `pseudoset.cpp`, and `test_pseudoset.cpp`.
3. Run `test_pseudoset`. All tests should pass.

> [!IMPORTANT]
> Submit `pseudoset.h` and `pseudoset.cpp` to Gradescope.

### Theoretical Analysis

In this section, you will analyze the time complexity of your pseudo-set implementation. If you spend more than 5-10
minutes on this section, look at the solution provided below and move on.

1. Give tight bounds on the worst-case time complexity of `insert` and `contains` on a pseudo-set of size $n$. Justify
   your answer. Record your answer and justification under **Analysis** in `pseudoset.md`.

<details>
<summary>Solution</summary>

1. The pseudo-set is always represented by a valid red-black tree. Let $b$ be the black height of the tree. The
   worst-case of `insert` and `contains` always involves traversing the longest path from the root to a leaf. Since red
   nodes cannot have red children, and every path from root to leaf must contain exactly $b$ black nodes, there are at
   most $2b$ nodes on the longest path. Thus, the length of the longest path is $\Omega(b)$ and $\mathcal{O}(2b)$, so it
   is $\Theta(b)$. TODO

</details> 

> [!IMPORTANT]
> Submit `pseudoset.md` to Gradescope.

# Extra Practice

## Set

Sets provide three main operations:

1. `insert` which adds a value into the set.
2. `erase` which removes a value from the set.
3. `contains` which checks if a value is in the set.

### Implementation

In this section, you will design and implement a set using a binary search tree.

1. Complete `set.h` and `set.cpp`.
2. Build `test_set` from `set.cpp`, and `test_set.cpp`.
3. Run `test_set`. All tests should pass.

> [!IMPORTANT]
> Submit `set.h` and `set.cpp` to Gradescope.

### Theoretical Analysis

In this section, you will analyze the time complexity of your set implementation. If you spend more than 5-10 minutes on
this section, look at the solution provided below and move on.

TODO

<details>
<summary>Solution</summary>

TODO

</details>

> [!IMPORTANT]
> Submit `set.md` to Gradescope.