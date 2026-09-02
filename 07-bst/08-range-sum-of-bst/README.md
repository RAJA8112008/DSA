# Range Sum of BST

**Topic:** BST  
**Level:** beginner  
**Asked at:** Amazon · Meta · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/range-sum-of-bst/)
- [GFG](https://www.geeksforgeeks.org/count-bst-nodes-that-lie-in-a-given-range/)

## Problem

Sum every node value that sits in the closed interval [low, high].

You may visit the whole tree. A BST lets you skip a side: node.val < low means left is useless; node.val > high means right is useless.

Brute adds after visiting everyone. Optimal prunes in recursion. More optimal is an explicit stack with the same prune.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(h)

DFS every node. Add val when it is inside the interval. Correct on a plain binary tree too.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Prune: skip left when node is below low, skip right when node is above high. Best case you only walk the in-range corridor.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Explicit stack, same prune. No recursion. Push only children that can still hold in-range keys.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
