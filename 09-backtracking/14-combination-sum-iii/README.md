# Combination Sum III

**Topic:** Recursion & Backtracking  
**Level:** intermediate  
**Asked at:** Amazon · Google

## Practice

- [LeetCode](https://leetcode.com/problems/combination-sum-iii/)

## Problem

Pick k distinct integers from 1..9 that sum to n. Return every such combination. Order does not matter.

Tiny example: k = 3, n = 7. The only answer is [1, 2, 4]. [1, 3, 3] is illegal because 3 repeats and 3 is used twice.

The brute lists every k-subset of 1..9 (extra copies) and keeps those whose sum is n. Standard backtrack walks start..9 with one path. Prune when remain is too small, too big, or not enough numbers are left.

Open Brute, Optimal, and More optimal for all k-subsets, backtrack, and prune.

## Methods of solving

### 1. Brute

- **Time:** O(C(9, k) * k)
- **Space:** O(k)

Generate every k-subset with path copies, then filter by sum. C(9,k) is tiny, but you still build losers and copy arrays on every call.

### 2. Optimal

- **Time:** O(C(9, k) * k)
- **Space:** O(k)

One path. Push x, remain -= x, recurse x+1, pop. Snapshot when k numbers are chosen and remain is 0. No extra copies on internal nodes.

### 3. More optimal

- **Time:** O(C(9, k) * k)
- **Space:** O(k)

Prune: remain < 0, or remain bigger than the largest left numbers, or remain smaller than the smallest left numbers. Stop the loop when x itself is already too big.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
