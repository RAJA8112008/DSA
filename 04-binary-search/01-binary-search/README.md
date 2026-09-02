# Binary Search

**Topic:** Binary Search  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/binary-search/)
- [GFG](https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1)

## Problem

nums is sorted in non-decreasing order. Return the index of target, or -1 if it is not there.

Tiny example: nums = [-1, 0, 3, 5, 9, 12], target = 9. The hit is index 4. Target 2 is missing, so -1.

A linear scan is correct and O(n). Binary search probes mid and drops half the range each time, O(log n). Use mid = lo + (hi - lo) / 2 so 32-bit indexes cannot overflow.

Open Brute, Optimal, and More optimal for the scan, the closed-range loop, and the overflow-safe version with an early endpoint check.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(1)

Walk left to right and compare every value. Correct on any array, sorted or not. Interviews want this only as the baseline before you cut the search in half.

### 2. Optimal

- **Time:** O(log n)
- **Space:** O(1)

Closed range [lo, hi]. Equal mid returns. Smaller mid throws away the left half. Larger mid throws away the right half. Each step halves the live indexes.

### 3. More optimal

- **Time:** O(log n)
- **Space:** O(1)

Same log n probes, but mid = lo + (hi - lo) / 2 never overflows a 32-bit index sum. Endpoint checks skip a loop when target is outside the remaining values.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
