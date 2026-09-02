# 4Sum

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/4sum/)
- [GFG](https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers/1)

## Problem

Return all unique quadruplets [a, b, c, d] such that they add to target. Indexes must be distinct. Order inside a quadruplet does not matter; do not emit duplicates.

Example: nums = [1, 0, -1, 0, -2, 2], target = 0. One answer is [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]].

Brute is four loops. Optimal is three loops plus a hash set. More optimal sorts, then two loops plus two pointers, skipping clones.

## Methods of solving

### 1. Brute

- **Time:** O(n^4)
- **Space:** O(1) extra

Four nested indexes. Sort each hit so a set of strings can drop duplicates. Correct and too slow.

### 2. Optimal

- **Time:** O(n^3)
- **Space:** O(n)

Fix i, j, k. Look up target - (a+b+c) in a set of values after k. Still cubic, extra set, duplicates need care. A stepping stone to two pointers.

### 3. More optimal

- **Time:** O(n^3)
- **Space:** O(1) extra

Sort. Fix i and j. Two pointers on the rest. Skip duplicate i, j, left, and right. Use 64-bit sums if the language overflows. This is the expected answer.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
