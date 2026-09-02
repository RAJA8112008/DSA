# Longest Common Subsequence

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/longest-common-subsequence/)
- [GFG](https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1)

## Problem

Given two strings, return the length of the longest subsequence that appears in both. Order stays; you may skip letters in either string.

Tiny example: text1 = "abcde", text2 = "ace". The letters a, c, e appear in both in that order. Answer 3.

If the current letters match, you take 1 + LCS of the rest. If they differ, you drop a letter from the first string or from the second and take the max. Empty prefix has LCS 0.

Open the Brute, Optimal, and More optimal tabs for recursion, the (m+1) by (n+1) table, and a rolling row.

## Methods of solving

### 1. Brute

- **Time:** O(2^{m+n})
- **Space:** O(m + n)

Mismatch branches into two calls. Matching still walks both strings. Overlapping (i, j) pairs are recomputed. Stack is O(m+n).

### 2. Optimal

- **Time:** O(m * n)
- **Space:** O(m * n)

One cell per prefix pair. Each cell is O(1) work from three neighbors. The full grid makes the recurrence obvious and is what you draw on a whiteboard.

### 3. More optimal

- **Time:** O(m * n)
- **Space:** O(min(m, n))

A cell only needs the previous row. Keep prev and cur. Swap the shorter string onto the row so extra memory is the smaller length. Time is still every pair of letters.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
