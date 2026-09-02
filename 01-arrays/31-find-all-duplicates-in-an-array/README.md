# Find All Duplicates in an Array

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/find-all-duplicates-in-an-array/)
- [GFG](https://www.geeksforgeeks.org/problems/find-duplicates-in-an-array/1)

## Problem

nums holds n integers, each in 1..n. Some appear twice, the rest once. Return every value that appears twice. O(n) time and O(1) extra space is the follow-up (you may mutate nums).

Example: [4, 3, 2, 7, 8, 2, 3, 1] answers [2, 3].

Brute is nested counts. Optimal sorts. More optimal marks index abs(x)-1 negative; a second negative means a duplicate.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

For each value, count how many times it appears. Push it once if the count is 2. Slow, no extra set.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(1) extra

Sort, then walk adjacent pairs. Equal neighbors are a duplicate. Simple, mutates order.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1) extra

Value x belongs at index x-1. Negate that slot when you first see x. If it is already negative, x is the duplicate. Restore signs later if you must.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
