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


## Problem

Consider the following $4$-ary tree:
```txt
    5
 / | | 
2  1 0  
```

What is the height of the tree? [____](1)

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

What is the height of the tree? [____](2)

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

What is the height of the tree? [____](2)

Is the tree perfect, complete and/or full?
[X] Perfect
[X] Complete
[X] Full

## Problem

What is the minimum height of a perfect binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. [____](16)

What is the maximum height of a perfect binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. [____](16)

## Problem

What is the minimum height of a complete binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. [____](16)

What is the maximum height of a complete binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. [____](16)

## Problem

What is the minimum height of a full binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. [____](16)

What is the maximum height of a full binary tree with $65535$ nodes? Start by finding a formula in terms of $n$. [____](32767)

## Problem

Consider the following tree:
```txt
  4
 / \
2   5
```

Is the tree a valid binary search tree?
(X) Yes
( ) No

Consider the following tree:
```txt
7
```

Is the tree a valid binary search tree?
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

Is the tree a valid binary search tree?
( ) Yes
(X) No


        1x valid-bst or not?
        2x all traversals after insert
        2x all traversals after remove (hit all three cases)
            no children, one child, two children
        which is a worst-case insert sequence? what is complexity?
