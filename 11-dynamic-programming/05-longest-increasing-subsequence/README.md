# Longest Increasing Subsequence

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Google · Amazon · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/longest-increasing-subsequence/)
- [GFG](https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1)

## Problem

A subsequence keeps order but may skip indexes. Strictly increasing means each chosen number is larger than the last. Return the length of the longest increasing subsequence.

Tiny example: [10, 9, 2, 5, 3, 7, 101, 18]. One LIS is 2, 5, 7, 101 (length 4). 2, 3, 7, 18 is another length 4.

The O(n^2) state is “LIS ending at i.” You extend any earlier j with nums[j] < nums[i]. The O(n log n) idea keeps the smallest tail for every length and binary-searches the first tail that is not smaller than the new number.

Open the Brute, Optimal, and More optimal tabs for take/skip recursion, the n^2 table, and the tails binary search.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

At each index you take (if it is larger than prev) or skip. No cache, so every subset of positions is explored. Depth is n.

### 2. Optimal

- **Time:** O(n^2)
- **Space:** O(n)

len[i] is the longest increasing subsequence that ends at i. Each pair (j, i) with j < i is checked once. n^2 states of work, one array of n cells. Standard interview DP.

### 3. More optimal

- **Time:** O(n log n)
- **Space:** O(n)

tails[k] is the smallest tail of all increasing subsequences of length k+1. For each number, binary search the first tail that is >= num and replace it (or append). Length of tails is the LIS length. Tails is not the LIS itself.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
