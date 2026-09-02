# Intersection of Two Linked Lists

**Topic:** Linked List  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Apple · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/intersection-of-two-linked-lists/)
- [GFG](https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1)

## Problem

Lists A and B may share a suffix (same node objects from some point). Return the first common node, or null if they never join.

A: 4 -> 1 -> 8 -> 4 -> 5 and B: 5 -> 6 -> 1 -> 8 -> 4 -> 5 intersect at the node 8. Compare references, not values.

Nested walks check every pair. A Set of A's nodes then a walk of B is linear extra space. Two pointers that swap lists after the end equalize remaining length and meet at the join.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n·m)
- **Space:** O(1)

For each node in A, walk all of B looking for the same object. No extra set. Quadratic time.

### 2. Optimal

- **Time:** O(n+m)
- **Space:** O(n)

Put every node of A in a Set. Walk B; the first node in the set is the intersection. Linear time, extra memory for A.

### 3. More optimal

- **Time:** O(n+m)
- **Space:** O(1)

Pointer a walks A then B. Pointer b walks B then A. They travel the same total length and meet at the first shared node, or both hit null. No set.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
