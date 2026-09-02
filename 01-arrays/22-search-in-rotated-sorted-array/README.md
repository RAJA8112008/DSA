# Search in Rotated Sorted Array

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array/)
- [GFG](https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1)

## Problem

nums was sorted ascending, then rotated. Values are unique. Return the index of target, or -1.

Example: [4, 5, 6, 7, 0, 1, 2], target 0 -> 4.

A linear scan always works. Finding the pivot (the smallest value) then binary-searching the correct sorted half is two binary searches. One binary search that asks “which half is sorted?” and whether target sits there is the usual finish.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(1)

Ignore rotation and scan. Correct, misses the log n goal.
How it works: return the first index whose value equals target.

### 2. Optimal

- **Time:** O(log n)
- **Space:** O(1)

Two binary searches: one finds the rotation pivot, one searches a normal sorted range.
How it works: pivot is the index of the smallest value. If target is in the left sorted run, search [0, pivot). Else search [pivot, n).

### 3. More optimal

- **Time:** O(log n)
- **Space:** O(1)

A single loop. Still log n, but one search instead of pivot-then-search.
How it works: if the left side is sorted and target is in that range, shrink right; otherwise go left. Symmetric for a sorted right side.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
