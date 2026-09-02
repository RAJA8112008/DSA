# Search Insert Position

**Topic:** Binary Search  
**Level:** beginner  
**Asked at:** Amazon · Bloomberg · Microsoft · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/search-insert-position/)
- [GFG](https://www.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1)

## Problem

nums is sorted and unique. Return the index of target, or the index where it would be inserted to keep the list sorted.

Tiny example: [1, 3, 5, 6]. Target 5 -> 2. Target 2 -> 1. Target 7 -> 4. Target 0 -> 0.

That index is the lower bound: the first position where nums[i] >= target (or n if all values are smaller).

Open Brute, Optimal, and More optimal for a left-to-right scan, closed-range binary search, and the half-open first-true loop.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(1)

The first index with nums[i] >= target is the insert slot. If none exist, insert at n. Fine for tiny n; too slow when they ask for log n.

### 2. Optimal

- **Time:** O(log n)
- **Space:** O(1)

Track the best insert index seen so far. When mid is >= target, mid is a candidate and you search left. When mid is smaller, the slot is strictly right of mid.

### 3. More optimal

- **Time:** O(log n)
- **Space:** O(1)

Half-open [lo, hi) with hi = n. No extra ans variable: when the loop ends, lo is the first index >= target. Overflow-safe mid.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
