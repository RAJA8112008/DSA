# Longest Consecutive Sequence

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Google · Amazon · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/longest-consecutive-sequence/)
- [GFG](https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence-1587115621/1)

## Problem

Return the length of the longest run of consecutive integers. Order in the array does not matter. Numbers may repeat.

Example: [100, 4, 200, 1, 3, 2] -> 4 because 1,2,3,4.

From each value you can walk upward until the chain breaks. Sorting unique values makes the chain a neighbor scan. A Set lets you start a chain only at numbers that have no predecessor, so each number is visited a constant number of times.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

From each unique start you may scan the set repeatedly. In the worst case this is quadratic.
How it works: put numbers in a Set. For each start, count start, start+1, start+2 while those values exist. Keep the longest streak.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(n)

Unique copy plus sort, then a linear neighbor walk. Sorting is the bottleneck.
How it works: skip duplicates while scanning the sorted unique list. A gap of 1 grows the streak; a larger gap resets it.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Each number is inserted once and then used in at most one forward walk.
How it works: only start a streak when x-1 is missing. Then count x, x+1, ... while present. That visits each run from its true beginning.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
