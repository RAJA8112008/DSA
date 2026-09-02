# Merge k Sorted Lists

**Topic:** Stack, Queue & Heap  
**Level:** advanced  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/merge-k-sorted-lists/)
- [GFG](https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1)

## Problem

lists is an array of k sorted linked lists. Merge them into one sorted list and return the head.

Example: [1->4->5, 1->3->4, 2->6] becomes 1->1->2->3->4->4->5->6.

Brute dumps every value, sorts, rebuilds. Optimal is a min-heap of the k current heads. More optimal is divide-and-conquer merge (like merge sort), no heap.

## Methods of solving

### 1. Brute

- **Time:** O(n log n)
- **Space:** O(n)

Walk every node into an array, sort, then wire a new list. Ignores that each list is already sorted. Easy to code under pressure.

### 2. Optimal

- **Time:** O(n log k)
- **Space:** O(k)

Min-heap of list heads keyed by val. Pop the smallest, push its next. n pops, heap size k. Uses the sorted property.

### 3. More optimal

- **Time:** O(n log k)
- **Space:** O(log k)

Pairwise merge like merge sort. Recursion depth log k. No heap to implement. Same n log k, often faster constants in JS, and O(1) extra besides the call stack.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
