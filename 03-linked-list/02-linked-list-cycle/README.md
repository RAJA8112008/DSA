# Linked List Cycle

**Topic:** Linked List  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Apple · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/linked-list-cycle/)
- [GFG](https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1)

## Problem

Return true if the list has a cycle, false if a walk hits null.

If pos is 1 on 3 -> 2 -> 0 -> -4, the tail points at 2 and a walk never ends. If every next is forward, you eventually reach null.

Brute stores every node you have seen and scans the list of seen nodes. A Set makes the same idea O(1) per lookup. Floyd moves slow by one and fast by two; a meeting means a loop.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Keep an array of visited nodes. For each new node, scan the array for the same object. Correct, but the scan makes it quadratic.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

A Set stores nodes you already walked. Add is O(1) on average. First repeat means a cycle. Extra memory equals the number of distinct nodes before a repeat.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Floyd: slow +1, fast +2. No set. If they meet, there is a cycle. If fast hits null, there is not. Constant extra pointers.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
