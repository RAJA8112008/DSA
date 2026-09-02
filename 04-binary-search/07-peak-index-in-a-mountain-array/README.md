# Peak Index in a Mountain Array

**Topic:** Binary Search  
**Level:** beginner  
**Asked at:** Amazon · Google · Bloomberg · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/peak-index-in-a-mountain-array/)
- [GFG](https://www.geeksforgeeks.org/problems/peak-element/1)

## Problem

arr is a mountain: it strictly increases to one peak, then strictly decreases. Return the peak index. Length is at least 3.

Tiny example: [0, 2, 1, 0] -> 1. [0, 10, 5, 2] -> 1. [3, 4, 5, 1] -> 2.

Unlike Find Peak Element, there is exactly one peak and both sides are strictly monotone. The same uphill test still works: if arr[mid] < arr[mid + 1], the peak is to the right.

Open Brute, Optimal, and More optimal for a scan, iterative binary search, and an overflow-safe loop that also compares mid - 1 when mid is not at 0.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(1)

The peak is the unique maximum. Track the index of the largest value. Fine for tiny n; they still want log n because n can be 10^5.

### 2. Optimal

- **Time:** O(log n)
- **Space:** O(1)

Uphill means lo = mid + 1. Downhill or peak means hi = mid. The two pointers meet on the unique peak. mid + 1 is in range while lo < hi.

### 3. More optimal

- **Time:** O(log n)
- **Space:** O(1)

Overflow-safe mid. Search inside (0, n-1) because ends cannot be the peak on a mountain. If both neighbors are smaller, return mid immediately.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
