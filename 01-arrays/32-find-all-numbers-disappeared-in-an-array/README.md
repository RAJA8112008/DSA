# Find All Numbers Disappeared in an Array

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Google · Amazon · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
- [GFG](https://www.geeksforgeeks.org/find-all-numbers-disappeared-in-an-array/)

## Problem

nums has length n. Values are in 1..n. Some numbers in 1..n never appear (replaced by duplicates). Return the missing ones. Follow-up: O(n) time, O(1) extra, you may mutate nums.

Example: [4, 3, 2, 7, 8, 2, 3, 1] answers [5, 6].

Brute checks 1..n with a scan. Optimal uses a boolean / set. More optimal negates index x-1, then collects indexes that stayed positive.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

For each candidate v in 1..n, scan the array. If it never appears, it is missing.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

A boolean array (or a set) of seen values. Then walk 1..n and collect the false slots.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1) extra

For each value x, negate nums[abs(x)-1]. Values whose slots stay positive never appeared. Same marking trick as Find All Duplicates.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
