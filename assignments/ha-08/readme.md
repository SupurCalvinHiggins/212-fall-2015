# Overview

In this assignment, you will practice with trees, search trees and balanced search trees.

## Learning Objectives

By the end of this assignment, you should be able to:

1. Compute $$k$$-ary tree properties (e.g. height, depth, perfect, complete, full).
2. Check binary search tree, red-black tree, 2-3-4 tree, and B-tree invariants.
3. Apply operations (e.g. insertion, deletion, search, rotation) to binary search trees, red-black trees, 2-3-4 trees and B-trees.
4. Convert between 2-3-4 trees and red-black trees.

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

* Avoid relying on multiple choice options to guide your answer. Instead, work out your solution first, then check against the choices.
* Use any available  resources (including AI), but always attempt each problem on your own for 5-10 minutes before seeking help.

## Answer Formats

**Short answer questions are autograded. You must follow the format specified below to receive credit.**

If the problem asks for a single integer, provide your answer as a single integer without whitespace. For example, `10`.

If the problem asks for a comma-delimited list of integers, provide your answer as a comma-delimited list without whitespace. For example, `3,1,4,0,12`.

If the problem asks for a comma-delimited list of integers with node colors, provide your answer as a comma-delimited list without whitespace, where red nodes are prefixed with `R` and black nodes are prefixed with `B`. For example, `R3,B1,B4,R0,B12`.

## Submission

**Before you submit, attach a PDF containing your work for every question you answered:**

|files|

It doesn't need to be neat, we just want to be able to understand your process.

Note that you can submit as many times as you want before the due date!

## Confirmation

I have read and understand the above.

(X) Yes
( ) No

# Core Content

## Problem

Consider the following $$4$$-ary tree:
```txt
    5
 / | | 
2  1 0  
```

What is the height of the tree? Give your answer as a single integer. [____](1)

What is the total height of all subtrees in the tree? Give your answer as a single integer. [____](1)

How many internal nodes does the tree have? Give your answer as a single integer. [____](1)

How many leaves does the tree have? Give your answer as a single integer. [____](3)

Is the tree perfect, complete and/or full?
[ ] Perfect
[X] Complete
[ ] Full

## Problem

Consider the following $$3$$-ary tree:
```txt
    0
  / | \
 1  3  2
     / | \
    5  6  7
```

What is the height of the tree? Give your answer as a single integer. [____](2)

What is the total height of all subtrees in the tree? Give your answer as a single integer. [____](3)

How many internal nodes does the tree have? Give your answer as a single integer. [____](2)

How many leaves does the tree have? Give your answer as a single integer. [____](5)

Is the tree perfect, complete and/or full?
[ ] Perfect
[ ] Complete
[X] Full

## Problem

Consider the following $$2$$-ary tree:
```txt
     8
   /   \
  9     1
 / \   / \
7   2 3   6
```

What is the height of the tree? Give your answer as a single integer. [____](2)

What is the total height of all subtrees in the tree? Give your answer as a single integer. [____](4)

How many internal nodes does the tree have? Give your answer as a single integer. [____](3)

How many leaves does the tree have? Give your answer as a single integer. [____](4)

Is the tree perfect, complete and/or full?
[X] Perfect
[X] Complete
[X] Full

## Problem

What is the minimum height of a perfect binary tree with $$65535$$ nodes? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](16)

What is the maximum height of a perfect binary tree with $$65535$$ nodes? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](16)

## Problem

What is the minimum height of a complete binary tree with $$65535$$ nodes? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](16)

What is the maximum height of a complete binary tree with $$65535$$ nodes? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](16)

## Problem

What is the minimum height of a full binary tree with $$65535$$ nodes? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](16)

What is the maximum height of a full binary tree with $$65535$$ nodes? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](32767)

## Problem

Consider the following tree:
```txt
  4
 / \
2   5
```

Does the tree obey the binary search tree property?
(X) Yes
( ) No

Consider the following tree:
```txt
7
```

Does the tree obey the binary search tree property?
(X) Yes
( ) No

Consider the following tree:
```txt
   9
  / \
 7   11
  \
   10
```

Does the tree obey the binary search tree property?
( ) Yes
(X) No

## Problem

Insert the following sequence of numbers into an empty binary search tree:
```txt
7,5,2,1,8,0,3
```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](7,5,2,1,0,3,8)

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](0,1,2,3,5,7,8)

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](0,1,3,2,5,8,7)

## Problem

Consider the following binary search tree:
```txt
   6
  / \
 3   8
/ \   \
1  5   9
 \
  2
```

What nodes are visited when searching for `6` in the tree? Give your answer as a comma-seperated list of integers. [____](6)

What nodes are visited when searching for `4` in the tree? Give your answer as a comma-seperated list of integers. [____](6,3,5)

What nodes are visited when searching for `7` in the tree? Give your answer as a comma-seperated list of integers. [____](6,8)

## Problem

Consider the following binary search tree:
```txt
   5
 /   \
2     7
 \   / \
  3 6   9
       /
      8
```

Remove the following sequence of numbers from the tree using the inorder successor strategy:
```txt
7,5,8,9
```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](3,2,6)

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](2,3,6)

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](2,6,3) 

## Problem

What binary search tree insertion orders always yield a tree with $$\Theta(n)$$ time search?

[X] Increasing order (e.g. `1,2,3,...`)
[X] Decreasing order (e.g. `-1,-2,-3,...`)
[ ] Random order (e.g. `4,1,3,...`)
[ ] Evens first, then odds (e.g. `4,2,6,...,3,5,1,...`)

## Problem

What is the minimum height of a binary search tree with $$65535$$ keys? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](16)

What is the maximum height of a binary search tree with $$65535$$ keys? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](65534)

## Problem

Nodes marked with `R` are red and nodes marked with `B` are black.

Consider the following tree:
```txt
  B5
 /  \
R3  B8
```

What red-black tree properties does the tree obey?
[X] Black root
[X] Red nodes cannot have red children
[X] Every root to leaf path contains the same number of black nodes
[X] Binary search tree property

Consider the following tree:
```txt
  B6
 /  \
R4  R8
    /
   R7
```

What red-black tree properties does the tree obey?
[X] Black root
[ ] Red nodes cannot have red children
[X] Every root to leaf path contains the same number of black nodes
[X] Binary search tree property

Consider the following tree:
```txt
  R5
 /  \
B6  B8
    /
   B7
```

What red-black tree properties does the tree obey?
[ ] Black root
[X] Red nodes cannot have red children
[ ] Every root to leaf path contains the same number of black nodes
[ ] Binary search tree property

## Problem

Rotate at the root of the following binary tree (1) right, (2) left, (3) right:
```txt
      5
     / \
    3   8
   / \   \
  2   4   9
 /
1
```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](3,2,1,5,4,8,9)

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](1,2,3,4,5,8,9)

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](1,2,4,9,8,5,3)

## Problem

Insert the following sequence of numbers into an empty red-black tree:
```txt
3,7,1,9,0,5,8
```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. Prefix integers stored in red nodes with `R`, and integers stored in black nodes iwith `B`. [____](B3,B1,R0,R7,B5,B9,R8)

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. Prefix integers stored in red nodes with `R`, and integers stored in black nodes with `B`. [____](R0,B1,B3,B5,R7,R8,B9)

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. Prefix integers stored in red nodes with `R`, and integers stored in black nodes with `B`. [____](R0,B1,B5,R8,B9,R7,B3)

## Problem

What is the minimum height of a red-black tree with $$65535$$ keys? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](16)

What is the maximum height of a red-black tree with $$65535$$ keys? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](30)

What is the minimum black height of a red-black tree with $$65535$$ keys? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](9)

What is the maximum black height of a red-black tree with $$65535$$ keys? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](16)

## Problem

Consider the following tree:
```txt
     [5]
    /   \
  [1]  [7|9]
  /
[0]
```

What 2-3-4 tree properties does the tree obey?
[X] Every node has 1, 2, or 3 keys except for possibly the root
[ ] All leaves have the same depth
[X] Multi-way search tree property

Consider the following tree:
```txt
      [4|7]
     /  |  \
[1|3] [5|6] [8|9]
```

What 2-3-4 tree properties does the tree obey?
[X] Every node has 1, 2, or 3 keys except for possibly the root
[X] All leaves have the same depth
[X] Multi-way search tree property

Consider the following tree:
```txt
      [5]
    /     \
[1|2|3|4] [4]
```

What 2-3-4 tree properties does the tree obey?
[ ] Every node has 1, 2, or 3 keys except for possibly the root
[X] All leaves have the same depth
[ ] Multi-way search tree property

## Problem

Insert the following sequence of numbers into an empty 2-3-4 tree:
```txt
2,6,9,1,4,8,3
```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](2,6,1,3,4,8,9)

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](1,2,3,4,6,8,9)

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](1,3,4,8,9,2,6)

## Problem

What is the minimum height of a 2-3-4 tree with $$65535$$ keys? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](8)

What is the maximum height of a 2-3-4 tree with $$65535$$ keys? Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](16)

## Problem

Convert the following 2-3-4 tree into an equivalent red-black tree:
```txt
        [5|8]
      /   |   \
[2|3|4] [6|7] [9]
```
For 3-nodes, use a red left child. For 4-nodes, use two red children.

What is the preorder traversal of the red-black tree? Give your answer as a comma-seperated list of integers. Prefix integers stored in red nodes with `R`, and integers stored in black nodes with `B`. [____](B8,R5,B3,R2,R4,B7,R6,B9)

What is the inorder traversal of the red-black tree? Give your answer as a comma-seperated list of integers. Prefix integers stored in red nodes with `R`, and integers stored in black nodes with `B`. [____](R2,B3,R4,R5,R6,B7,B8,B9)

What is the postorder traversal of the red-black tree? Give your answer as a comma-seperated list of integers. Prefix integers stored in red nodes with `R`, and integers stored in black nodes with `B`. [____](R2,R4,B3,R6,B7,R5,B9,B8)

## Problem

Convert the following red-black tree into an equivalent 2-3-4 tree:
```txt
     B5
   /    \
  B3    B8
 /  \     \
R1  R4    R9
```

What is the preorder traversal of the 2-3-4 tree? Give your answer as a comma-seperated list of integers. [____](5,1,3,4,8,9)

What is the inorder traversal of the 2-3-4 tree? Give your answer as a comma-seperated list of integers. [____](1,3,4,5,8,9)

What is the postorder traversal of the 2-3-4 tree? Give your answer as a comma-seperated list of integers. [____](1,3,4,8,9,5)

## Problem

Consider the following tree:
```txt
       [14|15]
      /   |   \
[5|10]  [16]   [20|25]
```

What B-tree properties does the tree obey if $$b = 5$$?
[X] Every node has between $$\lceil b / 2 \rceil - 1$$ and $$b - 1$$ keys except for possibly the root
[X] All leaves have the same depth
[ ] Multi-way search tree property

Consider the following tree:
```txt
      [15]
     /    \
[1|2|3]   [17|20]
```

What B-tree tree properties does the tree obey if $$b = 3$$?
[ ] Every node has between $$\lceil b / 2 \rceil - 1$$ and $$b - 1$$ keys except for possibly the root
[X] All leaves have the same depth
[X] Multi-way search tree property

Consider the following tree:
```txt
      [10|20]
     /   |   \
[5|7] [12|15] [22|25]
```

What B-tree properties does the tree obey if $$b = 4$$?
[X] Every node has between $$\lceil b / 2 \rceil - 1$$ and $$b - 1$$ keys except for possibly the root
[X] All leaves have the same depth
[X] Multi-way search tree property

## Problem

Insert the following sequence of numbers into an empty B-tree tree where $$b = 3$$:
```txt
0,5,2,7,1,9,4
```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](2,7,0,1,4,5,9)

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](0,1,2,4,5,7,9)

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____](0,1,4,5,9,2,7)

## Problem

What is the minimum height of a B-tree with $$65535$$ keys if $$b = 3$$? Start by finding a formula in terms of $$n$$ and $$b$$. Give your answer as a single integer. [____](10)

What is the maximum height of a B-tree with $$65535$$ keys if $$b = 3$$? Start by finding a formula in terms of $$n$$ and $$b$$. Give your answer as a single integer. [____](16)

# Extra Practice

## Problem

In a perfect BST of height $$16$$, what is the expected number of visited nodes when searching for a key chosen uniformly at random? Assume the key is in the tree with 50% probability. Give your answer as a single integer. If needed, round up to the nearest integer. [____](17)

## Problem

What is the maximum number of right rotations required to transform a BST with $$65535$$ nodes into a right chain? A right chain is a tree where nodes have only a right child, or no children. Give your answer as a single integer. [____](65534)

## Problem
A subtree property is a node property that is maintained under tree operations. For example, the binary search tree property is a subtree property. Every node in the tree obeys the binary search tree property, and this remains true after insertions, deletions and queries.

What subtree properties can be maintained in a red-black tree while retaining $$\Theta(\lg n)$$ worst-case operations? Write a modified version of insert for each such subtree property.

[X] Number of nodes in subtree
[X] Number of red nodes in subtree
[X] Maximum key in subtree
[ ] Height of subtree
[ ] Depth of node 

# Optional Advanced Topics

## Problem

How many different $$32$$ node binary trees are there? Two binary trees are different if and only if their shapes differ irrespective of the values stored in the trees. Start by finding a formula in terms of $$n$$. Give your answer as a single integer. [____](55534064877048198)

## Problem

How many nodes are in a B-tree with $$b = 4$$ after inserting `1,2,...,49163`? Start by finding a formula in terms of $$n$$ and $$b$$. Give your answer as a single integer. [____](49121)

## Problem

Consider a B-tree with $$n$$ keys.

What choices of $$b$$ yield an asymptotic slowdown of search relative to $$b = \Theta(1)$$?
[ ] $$b = \Theta(1)$$
[X] $$b = \Theta(\lg \lg n)$$
[X] $$b = \Theta(\lg n)$$
[X] $$b = \Theta(\sqrt{n})$$
[X] $$b = \Theta(n)$$

Suppose we perform a binary search of the keys in a B-tree node instead of a linear search.

What choices of $$b$$ yield an asymptotic slowdown of search relative to $$b = \Theta(1)$$?
[ ] $$b = \Theta(1)$$
[ ] $$b = \Theta(\lg \lg n)$$
[ ] $$b = \Theta(\lg n)$$
[ ] $$b = \Theta(\sqrt{n})$$
[ ] $$b = \Theta(n)$$
