# Find Peak Element

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Google · Amazon · Facebook · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/find-peak-element/)
- [GFG](https://www.geeksforgeeks.org/problems/peak-element/1)

## Problem

A peak is an index i where nums[i] > neighbors (ends compare against the one inner neighbor). nums[-1] and nums[n] are treated as -infinity, so a peak always exists. Return any peak index.

Tiny example: [1, 2, 3, 1] -> 2 (value 3). [1, 2, 1, 3, 5, 6, 4] -> 1 or 5.

If nums[mid] < nums[mid + 1], you are climbing, so a peak is to the right. Otherwise a peak is at mid or left.

Open Brute, Optimal, and More optimal for a neighbor scan, iterative slope search, and the same idea as a recursive binary search.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(1)

Check each index against its neighbors. First (or any) success is a peak. Ends only need one comparison. Simple, not log n.

### 2. Optimal

- **Time:** O(log n)
- **Space:** O(1)

Slope test: if mid is less than mid + 1, drop the left (including mid). Else drop the right. The remaining range always contains a peak because the ends behave like -infinity.

### 3. More optimal

- **Time:** O(log n)
- **Space:** O(log n)

Same slope rule as a recursive function. Overflow-safe mid. The extra space is the call stack of log n frames. Iterative is usually preferred; this is the form you write if they ask for recursion.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
