# Merge Two Sorted Lists

**Topic:** Linked List  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Apple · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/merge-two-sorted-lists/)
- [GFG](https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1)

## Problem

You get two lists sorted in non-decreasing order. Merge them into one sorted list by splicing the existing nodes.

1 -> 2 -> 4 and 1 -> 3 -> 4 become 1 -> 1 -> 2 -> 3 -> 4 -> 4. Either input may be null.

Dumping all values, sorting, and rebuilding works but allocates. Recursion always takes the smaller head and merges the rest. The iterative dummy picks the smaller node in a loop.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O((n+m) log(n+m))
- **Space:** O(n+m)

Collect every value, sort the array, rebuild. Simple, but sort is extra work and you throw away the original nodes.

### 2. Optimal

- **Time:** O(n+m)
- **Space:** O(n+m)

Recurse: the smaller head is the next output node, then merge the rest. Linear comparisons. Stack depth is O(n+m).

### 3. More optimal

- **Time:** O(n+m)
- **Space:** O(1)

Dummy plus a tail pointer. Each step hangs the smaller remaining node. Leftover chain attaches at the end. Constant extra space besides the output, which reuses input nodes.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
