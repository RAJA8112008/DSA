# Kth Largest Element in an Array

**Topic:** Stack, Queue & Heap  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- [GFG](https://www.geeksforgeeks.org/problems/kth-largest-element-in-an-array/1)

## Problem

Return the k-th largest value in nums (1-based: k = 1 is the maximum). The array is unsorted. You may not need a full sort.

Example: [3,2,1,5,6,4], k = 2 answers 5.

Brute repeatedly strips the max. Optimal sorts. More optimal keeps a min-heap of size k (or quickselect for expected O(n)).

## Methods of solving

### 1. Brute

- **Time:** O(n · k)
- **Space:** O(n)

Copy the array. k times, find and remove the current max. Fine for tiny k, slow for k near n.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(n)

Sort descending (or ascending and index). Honest and short. Use this first in an interview, then offer a heap.

### 3. More optimal

- **Time:** O(n log k)
- **Space:** O(k)

Min-heap of size k. If the heap is full and x is bigger than the peek, replace the peek. The peek is the k-th largest. Tiny binary heap inlined. Quickselect is expected O(n) if they want that next.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
