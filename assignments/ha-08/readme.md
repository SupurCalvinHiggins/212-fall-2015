trees
    binary trees, n-ary trees, perfect, complete, full, height, depth
    inorder, postorder, preorder traversals
binary search trees
    tracing, analysis, invariants, best/worst case
red-black trees
    tracing, analysis, invariants, comparison to BSTs, rotations
2-3-4 trees:
    tracing, analysis, invariants, conversion back and forth between RB and 2-3-4 trees
B trees:
    tracing, analysis, invariants
applications
order operations
set/map

24 problems

one lecture;
    definitions: path, path length, depth (node, tree), height (node, tree)
    k-ary, perfect, complete, full
    6 problems:
        3x: height of tree, depth of tree, perfect, complete, full, arity
            complete 4-ary, height 1
            full 3-ary, height 2
            perfect 2-ary, height 2
        max/min height of perfect tree k-ary on n nodes
        max/min height of complete tree k-ary on n nodes
        max/min height of full tree k-ary on n nodes

one lecture:
    binary search trees
    tracing, analysis, invariants, best/worst case
    contains, insert, remove
    traversals: pre, post, inorder, level order
    6 problems:
        1x valid-bst or not?
        2x all traversals after insert
        2x all traversals after remove (hit all three cases)
            no children, one child, two children
        which is a worst-case insert sequence? what is complexity?
        which is a best-case insert sequence? what is complexity?

two lectures:
    red-black trees
    tracing, analysis, invariants, comparison to BSTs, rotations
    2-3-4 trees:
    tracing, analysis, invariants, conversion back and forth between RB and 2-3-4 trees
    B trees:
    tracing, analysis, invariants
    12 problems:
        valid rb or not
        valid 2-3-4 tree or not
        valid B-tree or not
        2x traversals after rb insert
        2x traversals after 2-3-4 insert
        2x traversals after B-tree insert
        conversion from rb to 2-3-4
        conversion from 2-3-4 to rb
        balanced or not



## Problem

Consider the following $4$-ary tree:
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

Consider the following $3$-ary tree:
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

Consider the following $2$-ary tree:
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

What is the minimum height of a perfect binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____](16)

What is the maximum height of a perfect binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____](16)

## Problem

What is the minimum height of a complete binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____](16)

What is the maximum height of a complete binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____](16)

## Problem

What is the minimum height of a full binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____](16)

What is the maximum height of a full binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____](32767)

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

```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

## Problem

Consider the following binary search tree:
```txt

```

What nodes are visited when searching for `` in the tree? Give your answer as a comma-seperated list of integers. [____]()

What nodes are visited when searching for `` in the tree? Give your answer as a comma-seperated list of integers. [____]()

What nodes are visited when searching for `` in the tree? Give your answer as a comma-seperated list of integers. [____]()

## Problem

Consider the following binary search tree:
```txt

```

Remove the following sequence of numbers from the tree using the inorder successor strategy:
```txt

```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

## Problem

What binary search tree insertion orders always yield a tree with $\Theta(n)$ time search?

[X] Increasing order (e.g. `1,2,3,...`)
[X] Decreasing order (e.g. `-1,-2,-3,...`)
[ ] Random order (e.g. `4,1,3,...`)
[ ] Evens first, then odds (e.g. `4,2,6,...,3,5,1,...`)

## Problem

What is the minimum height of a binary search tree with $65535$ keys? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____](16)

What is the maximum height of a binary search tree with $65535$ keys? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____](65534)

## Problem

Consider the following tree:
```txt
```

What red-black tree properties does the tree obey?
[ ] Black root
[ ] Red nodes cannot have red children
[ ] Every root to leaf path contains the same number of black nodes
[ ] Binary search tree property

Consider the following tree:
```txt
```

What red-black tree properties does the tree obey?
[ ] Black root
[ ] Red nodes cannot have red children
[ ] Every root to leaf path contains the same number of black nodes
[ ] Binary search tree property

Consider the following tree:
```txt
```

What red-black tree properties does the tree obey?
[ ] Black root
[ ] Red nodes cannot have red children
[ ] Every root to leaf path contains the same number of black nodes
[ ] Binary search tree property

## Problem

TODO: rotation

## Problem

Insert the following sequence of numbers into an empty red-black tree:
```txt

```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. Prefix integers stored in red nodes with `R`, and integers stored in black nodes iwith `B`. [____]()

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. Prefix integers stored in red nodes with `R`, and integers stored in black nodes with `B`. [____]()

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. Prefix integers stored in red nodes with `R`, and integers stored in black nodes with `B`. [____]()

## Problem

What is the minimum height of a red-black tree with $65535$ keys? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____]()

What is the maximum height of a red-black tree with $65535$ keys? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____]()

What is the minimum black height of a red-black tree with $65535$ keys? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____]()

What is the maximum black height of a red-black tree with $65535$ keys? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____]()

## Problem

Consider the following tree:
```txt
```

What 2-3-4 tree properties does the tree obey?
[ ] Every node has 1, 2, or 3 keys except for possibly the root
[ ] All leaves have the same depth
[ ] Multi-way search tree property

Consider the following tree:
```txt
```

What 2-3-4 tree properties does the tree obey?
[ ] Every node has 1, 2, or 3 keys except for possibly the root
[ ] All leaves have the same depth
[ ] Multi-way search tree property

Consider the following tree:
```txt
```

What 2-3-4 tree properties does the tree obey?
[ ] Every node has 1, 2, or 3 keys except for possibly the root
[ ] All leaves have the same depth
[ ] Multi-way search tree property

## Problem

Insert the following sequence of numbers into an empty 2-3-4 tree:
```txt

```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

## Problem

What is the minimum height of a 2-3-4 tree with $65535$ keys? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____]()

What is the maximum height of a 2-3-4 tree with $65535$ keys? Start by finding a formula in terms of $n$. Give your answer as a single integer. [____]()

## Problem

Convert the following 2-3-4 tree into the equivalent red-black tree:
```txt

```

What is the preorder traversal of the red-black tree? Give your answer as a comma-seperated list of integers. [____]()

What is the inorder traversal of the red-black tree? Give your answer as a comma-seperated list of integers. [____]()

What is the postorder traversal of the red-black tree? Give your answer as a comma-seperated list of integers. [____]()

How many red nodes are in the tree? Give your answer as a single integer. [____]()

How many black nodes are in the tree? Give your answer as a single integer. [____]()

## Problem

Convert the following red-black tree into the equivalent 2-3-4 tree:
```txt

```

What is the preorder traversal of the 2-3-4 tree? Give your answer as a comma-seperated list of integers. [____]()

What is the inorder traversal of the 2-3-4 tree? Give your answer as a comma-seperated list of integers. [____]()

What is the postorder traversal of the 2-3-4 tree? Give your answer as a comma-seperated list of integers. [____]()

How many 2-nodes are in the tree? Give your answer as a single integer. [____]()

How many 3-nodes are in the tree? Give your answer as a single integer. [____]()

How many 4-nodes are in the tree? Give your answer as a single integer. [____]()

## Problem

Consider the following tree:
```txt
```

What B-tree properties does the tree obey if $b = $?
[ ] Every node has between $\lceil b / 2 \rceil - 1$ and $b - 1$ keys except for possibly the root
[ ] All leaves have the same depth
[ ] Multi-way search tree property

Consider the following tree:
```txt
```

What B-tree tree properties does the tree obey if $b = $?
[ ] Every node has between $\lceil b / 2 \rceil - 1$ and $b - 1$ keys except for possibly the root
[ ] All leaves have the same depth
[ ] Multi-way search tree property

Consider the following tree:
```txt
```

What B-tree properties does the tree obey if $b = $?
[ ] Every node has between $\lceil b / 2 \rceil - 1$ and $b - 1$ keys except for possibly the root
[ ] All leaves have the same depth
[ ] Multi-way search tree property

## Problem

Insert the following sequence of numbers into an empty B-tree tree where $b = $:
```txt

```

What is the preorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

What is the inorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

What is the postorder traversal of the final tree? Give your answer as a comma-seperated list of integers. [____]()

## Problem

What is the minimum height of a B-tree with $65535$ keys if $b = $? Start by finding a formula in terms of $n$ and $b$. Give your answer as a single integer. [____]()

What is the maximum height of a B-tree with $65535$ keys if $b = $? Start by finding a formula in terms of $n$ and $b$. Give your answer as a single integer. [____]()

# Extra Practice

## Problem

In a perfect BST of height $16$, what is the expected number of visited nodes when searching for a key chosen uniformly at random? Assume the key is in the tree with 50% probability. Give your answer as a single integer. If needed, rounded up to the nearest integer. [____]()

## Problem

What is the maximum number of right rotations required to transform a BST with $65535$ nodes into a chain? A chain is a sequence of nodes where nodes either only have left children, or only have right children. Give your answer as a single integer. [____]()

## Problem
A subtree property is a node property that is maintained under tree operations. For example, the binary search tree property is a subtree property. Every node in the tree obeys the binary search tree property, and this remains true after insertions, deletions and queries.

What subtree properties can be maintained in a red-black tree while retaining $\Theta(\lg n)$ worst-case operations?

[X] Number of nodes in subtree
[X] Number of red nodes in subtree
[X] Maximum key in subtree
[ ] Height of subtree
[ ] Depth of node 

# Optional Advanced Topics

## Problem

How many different $32$ node binary trees are there? Two binary trees are different if and only if their shapes differ irrespective of the values stored in the trees. Start by finding a formula in terms of $n$. If you know generating functions, use them. Give your answer as a single integer. [____]()

## Problem

How many nodes are in a B-tree with $b = 4$ after inserting `0, 1, 2, ..., 65535`? Start by finding a formula in terms of $n$ and $b$. Give your answer as a single integer. [____]()

## Problem

Consider a B-tree with $n$ keys.

What choices of $b$ yield an asymptotic slowdown of search relative to $b = \Theta(1)$?
[ ] $b = \Theta(1)$
[X] $b = \Theta(\lg \lg n)$
[X] $b = \Theta(\lg n)$
[X] $b = \Theta(\sqrt{n})$
[X] $b = \Theta(n)$

Suppose we perform a binary search of the keys in a B-tree node instead of a linear search.

What choices of $b$ yield an asymptotic slowdown of search relative to $b = \Theta(1)$?
[ ] $b = \Theta(1)$
[ ] $b = \Theta(\lg \lg n)$
[ ] $b = \Theta(\lg n)$
[ ] $b = \Theta(\sqrt{n})$
[ ] $b = \Theta(n)$
