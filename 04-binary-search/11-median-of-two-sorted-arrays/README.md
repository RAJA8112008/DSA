# Median of Two Sorted Arrays

**Topic:** Binary Search  
**Level:** advanced  
**Asked at:** Google · Amazon · Microsoft · Apple · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/median-of-two-sorted-arrays/)
- [GFG](https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1)

## Problem

Two sorted arrays a and b. Return the median of the combined sorted order. Odd total length: the middle value. Even: average of the two middle values. Required interview bound is O(log(min(m, n))).

Tiny example: [1, 3] and [2] -> 2. [1, 2] and [3, 4] -> 2.5.

Merge is O(m+n). Two pointers to the median index skip extra memory. The hard solution partitions the shorter array so the left side has (m+n+1)/2 items and every left value is <= every right value.

Open Brute, Optimal, and More optimal for merge, two-pointer kth, and the partition binary search.

## Methods of solving

### 1. Brute

- **Time:** O(m + n)
- **Space:** O(m + n)

Merge the two sorted lists into one, then pick the middle one or two values. Easy to code, extra memory, and not the log bound they asked for.

### 2. Optimal

- **Time:** O(m + n)
- **Space:** O(1)

Walk two pointers until you have seen the median index (and the one before it for even length). No merged array. Linear time, constant extra memory. Still not log.

### 3. More optimal

- **Time:** O(log(min(m, n)))
- **Space:** O(1)

Binary search a cut on the shorter array. Left parts together hold half the items. If aLeft > bRight, cut is too far right. If bLeft > aRight, cut is too far left. When both sides cross correctly, the median is max(lefts) or the average with min(rights).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
