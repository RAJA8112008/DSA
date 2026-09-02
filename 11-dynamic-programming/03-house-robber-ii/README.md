# House Robber II

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Google · Amazon · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/house-robber-ii/)
- [GFG](https://www.geeksforgeeks.org/house-robber-ii/)

## Problem

Houses sit on a circle: the first and last houses are adjacent, so you cannot rob both. Return the maximum total.

Tiny example: [2, 3, 2]. If you take the first 2 you cannot take the last 2, so the best is 3. Answer 3.

The circle splits into two linear streets: rob houses [0 .. n-2] or rob houses [1 .. n-1]. Take the max of those two linear answers. A single house is the one extra base case.

Open the Brute, Optimal, and More optimal tabs for two exponential lines, two DP arrays, and two rolling passes.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

Each range is still a take/skip tree with no memo. Two ranges do not change the exponential shape. Stack depth is O(n).

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Each linear street is the house-robber table. Two passes, each O(n) states. You still store a best[] array per pass. Handles n = 1 before splitting.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

The same two ranges, each robbed with two rolling numbers. Extra memory no longer depends on n. Time is still two linear scans.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
