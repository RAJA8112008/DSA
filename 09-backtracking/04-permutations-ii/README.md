# Permutations II

**Topic:** Recursion & Backtracking  
**Level:** intermediate  
**Asked at:** Amazon · LinkedIn · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/permutations-ii/)

## Problem

Permutations of nums when duplicates are allowed. Return unique orderings only.

Tiny example: nums = [1, 1, 2]. The unique permutations are [1,1,2], [1,2,1], [2,1,1]. Not six, because the two 1s are identical.

Brute builds every permutation and uniques with a Set. Optimal sorts and skips a duplicate at the same depth unless the previous copy is already used. Swaps plus a local set of values tried at this start index also unique the branches.

Open Brute, Optimal, and More optimal for the Set, sort-and-skip, and swap-with-local-set.

## Methods of solving

### 1. Brute

- **Time:** O(n * n!)
- **Space:** O(n * n!)

Generate every leftover-copy permutation, stringify, keep a Set. Duplicate 1s still walk the full n! tree. Extra copies plus the Set.

### 2. Optimal

- **Time:** O(n * n!)
- **Space:** O(n)

Sort so equal values are adjacent. Skip nums[j] when it equals nums[j-1] and used[j-1] is false. That forces a fixed order on identical numbers. One path, used[].

### 3. More optimal

- **Time:** O(n * n!)
- **Space:** O(n)

In-place swap. A tiny set of values already swapped into start this round stops identical branches. No sort required. Same unique output, less leftover copying.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
