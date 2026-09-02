# Search in Rotated Sorted Array II

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Amazon · Facebook · Microsoft · LinkedIn

## Practice

- [LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
- [GFG](https://www.geeksforgeeks.org/problems/search-in-rotated-array-2/1)

## Problem

nums was sorted, then rotated, and it may contain duplicates. Return true if target exists.

Tiny example: [2, 5, 6, 0, 0, 1, 2], target 0 -> true. Target 3 -> false. All-equal [1, 1, 1, 1] with target 2 -> false.

One sorted half still exists around mid, except when nums[lo] == nums[mid] == nums[hi]. Then you cannot tell which half is sorted, so you shrink both ends by one.

Open Brute, Optimal, and More optimal for a scan, the rotate check plus shrink, and skipping a whole run of duplicates on each end.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(1)

Duplicates already force O(n) in the worst case, so a linear scan is honest. Still too weak as the only answer: they want the rotated-half logic.

### 2. Optimal

- **Time:** O(log n) avg, O(n) worst
- **Space:** O(1)

If lo, mid, and hi are equal, shrink both ends. Otherwise one half is sorted; keep the half that can contain target. Worst case is all duplicates, which is linear.

### 3. More optimal

- **Time:** O(log n) avg, O(n) worst
- **Space:** O(1)

Skip a whole equal-run on each end instead of one index at a time when lo/mid/hi match. Fewer iterations on long duplicate prefixes and suffixes. Worst case is still linear.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
