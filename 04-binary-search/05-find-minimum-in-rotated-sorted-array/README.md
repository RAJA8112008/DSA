# Find Minimum in Rotated Sorted Array

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
- [GFG](https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1)

## Problem

nums is sorted, then rotated, with unique values. Return the smallest value (the rotation pivot).

Tiny example: [3, 4, 5, 1, 2] -> 1. [4, 5, 6, 7, 0, 1, 2] -> 0. Already sorted [1, 2, 3] -> 1.

If nums[mid] > nums[hi], the min is strictly to the right of mid. Otherwise mid is on the smaller run, so the min is at mid or left.

Open Brute, Optimal, and More optimal for a linear min, compare-with-hi binary search, and an early exit when the remaining range is already sorted.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(1)

Track the smallest value while walking. Rotation does not matter. This is the check you mention, then you switch to log n.

### 2. Optimal

- **Time:** O(log n)
- **Space:** O(1)

Compare mid with the right end. A drop after mid means the pivot is to the right. No drop means the pivot is mid or left. Unique values keep this strictly log n.

### 3. More optimal

- **Time:** O(log n)
- **Space:** O(1)

Overflow-safe mid. If nums[lo] <= nums[hi], the remaining slice is already sorted, so nums[lo] is the min and you can stop. Helps the no-rotation case in one check.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
