# First Missing Positive

**Topic:** Arrays  
**Level:** advanced  
**Asked at:** Amazon · Microsoft · Google · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/first-missing-positive/)
- [GFG](https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1)

## Problem

Return the smallest missing positive integer (1, 2, 3, …). The list may contain negatives, zeros, and values larger than n.

Example: [3, 4, -1, 1] -> 2. Example: [1, 2, 0] -> 3.

Sorting then scanning for 1, 2, 3, … works. A Set of positives makes the scan O(n). The in-place version puts each value v in 1..n at index v-1, then the first index whose value is not i+1 is the answer.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n log n)
- **Space:** O(n)

Copy, sort, then walk looking for the next needed positive. Sorting dominates.
How it works: ignore non-positives and duplicates. need starts at 1. When you see need, bump it. At the end, need is missing.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

One Set of the input, then at most n+1 membership tests.
How it works: the answer is in 1..n+1. Probe 1, 2, 3, … until a value is not in the set.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Index-as-hash / cyclic placement. Extra memory is a few integers. The input is overwritten.
How it works: swap nums[i] to index nums[i]-1 while that value is in 1..n and not already home. Then the first i with nums[i] !== i+1 is the missing number; else n+1.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
