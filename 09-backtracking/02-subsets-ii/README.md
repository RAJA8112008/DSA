# Subsets II

**Topic:** Recursion & Backtracking  
**Level:** intermediate  
**Asked at:** Amazon · Meta · Bloomberg

## Practice

- [LeetCode](https://leetcode.com/problems/subsets-ii/)

## Problem

Same power set as Subsets, but nums may contain duplicates. Return unique subsets only.

Tiny example: nums = [1, 2, 2]. Valid unique subsets include [], [1], [2], [1,2], [2,2], [1,2,2]. You must not list [1,2] twice from the two different 2s used as the only 2.

Sort first so equal values sit together. At one start index, skip a value that equals the previous value. The brute generates everything and dumps string keys into a Set.

Open Brute, Optimal, and More optimal for the Set trick, sort-and-skip, and the same skip plus an early break.

## Methods of solving

### 1. Brute

- **Time:** O(n * 2^n)
- **Space:** O(n * 2^n)

Build every subset with extra path copies, stringify, and keep a Set. Duplicate work is thrown away after you already built it. Fine for tiny n, not the interview finish.

### 2. Optimal

- **Time:** O(n * 2^n)
- **Space:** O(n)

Sort, then at each start skip nums[i] when it equals nums[i-1]. Those two 2s cannot start the same role twice, so [1,2] appears once. One path, push/pop.

### 3. More optimal

- **Time:** O(n * 2^n)
- **Space:** O(n)

Same sort-and-skip, plus you can count how many copies of this value exist and take 0..count in one shot. That collapses a chain of duplicate-index decisions into one loop.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
