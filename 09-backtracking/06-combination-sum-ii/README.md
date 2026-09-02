# Combination Sum II

**Topic:** Recursion & Backtracking  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google

## Practice

- [LeetCode](https://leetcode.com/problems/combination-sum-ii/)

## Problem

Candidates may contain duplicates. Each index may be used at most once. Return unique combinations that sum to target.

Tiny example: candidates = [10, 1, 2, 7, 6, 1, 5], target = 8. One answer is [1, 1, 6]. [1, 7] appears once even though 1 appears twice in the input as a starter paired with 7.

Sort, skip duplicate values at the same start, and move to i+1 after a take. Prune when nums[i] > remain.

Open Brute, Optimal, and More optimal for generate-all-then-Set, sort-and-skip, and prune.

## Methods of solving

### 1. Brute

- **Time:** O(n * 2^n)
- **Space:** O(n * 2^n)

Every index is take or skip with extra path copies. Keep combinations whose sum is target, unique them with a sorted-tuple Set. Duplicate indexes still explore the full 2^n tree.

### 2. Optimal

- **Time:** O(n * 2^n)
- **Space:** O(n)

Sort. Skip nums[i] == nums[i-1] at the same start so identical values do not start the same role twice. Each index is used at most once (go(i+1)).

### 3. More optimal

- **Time:** O(n * 2^n)
- **Space:** O(n)

After sort, break when cands[i] > remain. Later values are larger, so they cannot help. Same unique combinations, fewer recursive calls.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
