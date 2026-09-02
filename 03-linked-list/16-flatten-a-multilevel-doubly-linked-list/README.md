# Flatten a Multilevel Doubly Linked List

**Topic:** Linked List  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Meta · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)
- [GFG](https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1)

## Problem

Each node has prev, next, and child. Child is the head of another doubly list. Flatten so you get a single-level list in preorder: node, then its child list, then its old next. All child pointers become null. prev/next stay consistent.

1-2-3 with 3's child 7-8 becomes 1-2-3-7-8 with no children.

DFS into an array then relink. Recursion flattens a child and splices it. Iteration finds the child's tail and splices without a call stack.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

DFS preorder into an array (node, child, next). Then walk the array and set next/prev, clear child. Extra array of every node.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Recurse: if a node has a child, flatten the child, hang it after the node, find the child's tail, attach the old next. Stack depth follows nesting.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Walk with one pointer. On a child, find that child's current tail (no recurse), splice the whole child between cur and cur.next, clear child. Then continue. Auxiliary space O(1).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
