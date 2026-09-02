# 3Sum Closest

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Bloomberg

## Practice

- [LeetCode](https://leetcode.com/problems/3sum-closest/)
- [GFG](https://www.geeksforgeeks.org/problems/triplet-sum-closest-to-x1114/1)

## Problem

Find three numbers whose sum is as close as possible to target. Return that sum (not the triple). Exactly one best sum is guaranteed.

Example: nums = [-1, 2, 1, -4], target = 1. The sum 2 is closest ( -1 + 2 + 1 ).

Brute tries every triple. Optimal sorts then binary-searches the third value. More optimal is sort plus two pointers, tracking the closest sum.

## Methods of solving

### 1. Brute

- **Time:** O(n³)
- **Space:** O(1)

Every triple, track the sum whose absolute gap to target is smallest.

### 2. Optimal

- **Time:** O(n² log n)
- **Space:** O(n)

Sort. Fix two indexes, binary search the value closest to the leftover. Extra log n on each pair.

### 3. More optimal

- **Time:** O(n²)
- **Space:** O(1) extra

Sort. Fix i. Two pointers on the rest. Move the side that improves the sum. Track the closest. Stop early on an exact hit.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
