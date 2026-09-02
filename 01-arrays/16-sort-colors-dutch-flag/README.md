# Sort Colors (Dutch flag)

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Meta · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/sort-colors/)
- [GFG](https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1)

## Problem

nums contains only 0, 1, and 2. Sort it in place so the 0s come first, then 1s, then 2s.

Example: [2, 0, 2, 1, 1, 0] -> [0, 0, 1, 1, 2, 2].

A normal sort works and hides the structure. Counting 0/1/2 then overwriting is two passes. The Dutch-flag three pointers finish in one pass.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n log n)
- **Space:** O(n)

Generic sort does not use the fact there are only three values. Engine sort also uses extra memory.
How it works: nums.sort with a numeric comparator. Correct, but not the point of the problem.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(1)

Two linear passes and three counters. Extra memory is three integers.
How it works: count zeros, ones, and twos. Write that many 0s, then 1s, then 2s into nums.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

One pass, constant extra memory. Each index is visited a constant number of times.
How it works: low writes 0s, high writes 2s, mid walks. After a swap with high, mid stays so the swapped-in value is classified.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
