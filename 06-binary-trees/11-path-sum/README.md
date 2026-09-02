# Path Sum

**Topic:** Binary Trees  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Apple · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/path-sum/)
- [GFG](https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1)

## Problem

Return true if some root-to-leaf path sums to targetSum.

Tree 5-4-11-2 with target 22 is true because 5+4+11+2 = 22. A node with one child is not a leaf.

Collect every path sum. Recursion subtracts node.val and checks 0 at a leaf. Iterative stack stores (node, remaining).

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

DFS records every root-to-leaf path as an array, sums each, compares to target. Extra storage for all paths.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Recurse with remaining. At a leaf, remaining === node.val. Else try left or right with remaining - val.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Iterative stack of node plus remaining sum. Same check at leaves. No recursion.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
