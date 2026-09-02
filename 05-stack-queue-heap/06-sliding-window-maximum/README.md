# Sliding Window Maximum

**Topic:** Stack, Queue & Heap  
**Level:** advanced  
**Asked at:** Amazon · Google · Uber · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/sliding-window-maximum/)
- [GFG](https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1)

## Problem

nums and a window size k. Return the maximum of every contiguous window of length k.

Example: [1,3,-1,-3,5,3,6,7], k = 3 answers [3,3,5,5,6,7].

Brute maxes each window. Optimal is a size-k heap with lazy deletes. More optimal is a decreasing deque of indices: O(n).

## Methods of solving

### 1. Brute

- **Time:** O(n · k)
- **Space:** O(1)

For each window start, scan k items for the max. Simple and too slow when k is n/2.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(n)

Max-heap of [value, index] (store negated value in a min-heap). Pop the top while its index left the window. Lazy delete keeps the heap honest. Better than n*k, worse than a deque.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(k)

Decreasing deque of indices. Pop back while nums[i] is larger. Pop front if it left the window. Front is the max. Each index enters and leaves once.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
