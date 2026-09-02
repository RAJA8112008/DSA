# Permutation in String

**Topic:** Strings  
**Level:** intermediate  
**Asked at:** Microsoft · Amazon · Google · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/permutation-in-string/)
- [GFG](https://www.geeksforgeeks.org/permutation-in-string/)

## Problem

Return true if s2 contains a permutation of s1 as a substring: some window of length s1.length with the same letter counts.

Example: s1 = "ab", s2 = "eidbaooo" is true ("ba"). Example: s1 = "ab", s2 = "eidboaoo" is false.

Generating all permutations of s1 is factorial. Sliding a window of width m and comparing 26 counts each step is O(n*26). A matches counter updates in O(1) per step.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(m! · n)
- **Space:** O(m! · m)

All unique perms of s1 are generated, then each is searched in s2. Factorial in m.
How it works: backtracking builds permutations. indexOf each perm in s2; any hit is true.

### 2. Optimal

- **Time:** O(n · 26)
- **Space:** O(1)

Window of size m slides across s2. Each position compares two 26-slot arrays.
How it works: need counts s1. have counts the current window. If they match, true. Slide by dropping left and adding right.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

matches tracks how many of the 26 letters currently have the right count. Each add/drop updates matches in O(1).
How it works: when have[i] hits need[i], matches++. When it leaves, matches--. matches === 26 (or the number of letters that appear in s1) means the window is a permutation. Here we compare all 26 including zeros, so 26 is the target.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
