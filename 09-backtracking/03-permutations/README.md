# Permutations

**Topic:** Recursion & Backtracking  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/permutations/)
- [GFG](https://www.geeksforgeeks.org/problems/permutations-of-a-given-string/1)

## Problem

Return every ordering of distinct nums. There are n! of them.

Tiny example: nums = [1, 2, 3]. One permutation is [1,3,2]. All six orderings are required.

The brute copies a leftover list on every pick. The standard backtrack uses a used[] flag and one path. In-place swaps avoid the used array and extra leftover copies.

Open Brute, Optimal, and More optimal for leftover copies, used[], and swaps.

## Methods of solving

### 1. Brute

- **Time:** O(n * n!)
- **Space:** O(n * n!)

At each step you copy the leftover numbers into a new array and copy the path. Extra copies on every internal node. n! leaves, each of length n.

### 2. Optimal

- **Time:** O(n * n!)
- **Space:** O(n)

used[j] marks nums[j] as taken. One path, mark/unmark. Extra space is O(n) besides the n! output lists.

### 3. More optimal

- **Time:** O(n * n!)
- **Space:** O(n)

Swap nums[start] with each later index, recurse start+1, swap back. The prefix is the path. No used[] and no leftover copies. Still n! output.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
