# Decode Ways

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/decode-ways/)
- [GFG](https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1)

## Problem

A mapping 1 -> A, 2 -> B, …, 26 -> Z is given. s is a digit string. Return how many ways to decode it into letters. Leading zeros are invalid. "06" is 0 ways. "10" is 1 way (J). "226" is 3 ways (BBF, VF, BZ).

At index i, if s[i] is 1..9 you may take one digit. If s[i..i+1] is 10..26 you may take two. A 0 can only finish a two-digit code 10 or 20.

Open the Brute, Optimal, and More optimal tabs for recursion from index i, a memo on i, and two rolling way-counts.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

Each position may branch into a 1-digit take and a 2-digit take. Overlapping suffixes are recomputed. Zeros prune some branches but the worst case is still exponential.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Each start index is solved once. Work per index is O(1) digit checks. Memo of n cells plus the call stack. Linear in the length of s.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

prev1 is ways for the prefix ending here, prev2 is ways for the prefix one shorter. A one-digit code adds prev1. A two-digit code adds prev2. Empty string and a leading zero are the bases. No array.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
