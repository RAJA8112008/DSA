# Find First and Last Position of Element in Sorted Array

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Facebook · Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/find-first-and-last-position-of-element-in-a-sorted-array/)
- [GFG](https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1)

## Problem

nums is sorted in non-decreasing order and may contain duplicates. Return the first and last indexes equal to target. If target is missing, return [-1, -1].

Tiny example: [5, 7, 7, 8, 8, 10], target 8 -> [3, 4]. Target 6 -> [-1, -1].

One pass can record first and last. Two binary searches are O(log n) even when a long run of duplicates would make a linear expand O(n).

Open Brute, Optimal, and More optimal for the scan, two biased loops, and lower/upper bound packed into one helper.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(1)

One left-to-right pass. First time you see target, store i. Every time you see it, update last. Missing target leaves both at -1.

### 2. Optimal

- **Time:** O(log n)
- **Space:** O(1)

Two binary searches. When mid equals target, first-occurrence keeps searching left (hi = mid - 1) and last-occurrence keeps searching right (lo = mid + 1). Each is O(log n).

### 3. More optimal

- **Time:** O(log n)
- **Space:** O(1)

Lower bound (first >= target) and upper bound (first > target). Last index is upper - 1. Overflow-safe mid. One helper, two flags, no extra ans in the loop.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
