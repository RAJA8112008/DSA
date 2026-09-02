# Longest Common Prefix

**Topic:** Strings  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/longest-common-prefix/)
- [GFG](https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1)

## Problem

Return the longest prefix shared by every string in strs. If there is none, return "".

Example: ["flower","flow","flight"] -> "fl". Example: ["dog","racecar","car"] -> "".

Shrinking a running prefix against each next word is simple. Sorting then comparing only the first and last words also works. Vertical scan stops at the first column that disagrees.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(S)
- **Space:** O(m)

S is the total number of characters. Each word is compared to the current prefix from scratch.
How it works: prefix starts as strs[0]. For each next word, cut prefix while it is not a prefix of that word.

### 2. Optimal

- **Time:** O(n log n + m)
- **Space:** O(m)

Sort the n words, then only the first and last can disagree. m is the shorter of those two.
How it works: after sort, walk columns of first vs last until they differ. That slice is the prefix of the whole set.

### 3. More optimal

- **Time:** O(S)
- **Space:** O(1)

No sort copy. Extra memory is a few indexes. Worst case still reads every character of every word until a mismatch.
How it works: for column i of strs[0], every other word must have the same character. Return the slice before the first failure.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
