# Combination Sum

**Topic:** Recursion & Backtracking  
**Level:** intermediate  
**Asked at:** Amazon · Airbnb · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/combination-sum/)
- [GFG](https://www.geeksforgeeks.org/problems/combination-sum-1587115620/1)

## Problem

Candidates are distinct positive integers. You may reuse a value. Return every combination that sums to target. Order inside a combination does not matter.

Tiny example: candidates = [2, 3, 6, 7], target = 7. Answers: [7] and [2,2,3].

The brute builds every combination of any length (extra copies) and keeps those whose sum is target. Standard backtrack tracks remain and reuses index i. After a sort, prune when candidates[i] > remain.

Open Brute, Optimal, and More optimal for generate-and-filter, reuse-index backtrack, and sorted prune.

## Methods of solving

### 1. Brute

- **Time:** O(n^{target/min})
- **Space:** O(target/min)

Every call copies path.concat. You keep going while the sum is not past target, with no sort prune. Extra arrays at every node. Correct but heavy.

### 2. Optimal

- **Time:** O(n^{target/min})
- **Space:** O(target/min)

One path, push/pop. remain shrinks. Call go(i, remain - cands[i]) to reuse this value, or move to i+1 to skip. Copy only at remain == 0.

### 3. More optimal

- **Time:** O(n^{target/min})
- **Space:** O(target/min)

Sort first. In the for-loop, break when cands[i] > remain so larger later values are never tried. Same answers, fewer dead branches.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
