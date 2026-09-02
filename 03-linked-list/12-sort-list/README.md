# Sort List

**Topic:** Linked List  
**Level:** intermediate  
**Asked at:** Amazon · Meta · Microsoft · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/sort-list/)
- [GFG](https://www.geeksforgeeks.org/problems/sort-a-linked-list/1)

## Problem

Sort a linked list in O(n log n) time. Prefer constant extra space if you can.

4 -> 2 -> 1 -> 3 becomes 1 -> 2 -> 3 -> 4. Values may be negative.

Collect, sort the array, rewrite vals. Top-down merge sort splits at the middle with slow/fast. Bottom-up merge sort iterates run lengths 1, 2, 4, ... and uses O(1) extra pointers.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n log n)
- **Space:** O(n)

Push values, sort the array, write them back onto the existing nodes. Extra array. Does not show list merge sort.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(log n)

Top-down merge sort. Slow/fast splits the list, recurse both halves, merge sorted chains. Stack is O(log n) for balanced splits.

### 3. More optimal

- **Time:** O(n log n)
- **Space:** O(1)

Bottom-up merge sort. Count n, then merge adjacent runs of size step, doubling step. split cuts a run. merge hangs the merged pair after prev. No recursion stack.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
