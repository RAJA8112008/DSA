# Subsets

**Topic:** Recursion & Backtracking  
**Level:** beginner  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/subsets/)
- [GFG](https://www.geeksforgeeks.org/problems/subsets-1612087270/1)

## Problem

Given distinct integers nums, return every subset (the power set). Order of subsets and order inside a subset do not matter.

Tiny example: nums = [1, 2]. The subsets are [], [1], [2], [1,2]. That is 2^n lists.

Each index is a yes/no choice. The brute copies a new path on every call. The usual backtrack mutates one path and pops. Bitmasks walk 0 .. 2^n-1 and skip the recursion.

Open Brute, Optimal, and More optimal for extra copies, push/pop, and bitmasks.

## Methods of solving

### 1. Brute

- **Time:** O(n * 2^n)
- **Space:** O(n * 2^n)

Each call does path.concat so every node of the tree allocates a new array. Correct, but you pay extra copies on internal nodes, not only at leaves. Time is still exponential because there are 2^n subsets.

### 2. Optimal

- **Time:** O(n * 2^n)
- **Space:** O(n)

One path array is shared. Push, recurse, pop. You copy only at a leaf. Extra memory besides the output is the path plus O(n) stack.

### 3. More optimal

- **Time:** O(n * 2^n)
- **Space:** O(n)

No recursion. Each mask from 0 to 2^n-1 is one subset. Bit i on means nums[i] is in. Same output size, no call stack, tight inner loop.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
