# Longest Palindromic Substring

**Topic:** Strings  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/longest-palindromic-substring/)
- [GFG](https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1)

## Problem

Return any longest palindromic substring. A palindrome reads the same forward and backward.

Example: "babad" -> "bab" or "aba". Example: "cbbd" -> "bb".

All substrings plus a palindrome check is O(n³). Expand around 2n-1 centers is O(n²). Manacher’s algorithm fills a palindrome radius array in O(n).

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n³)
- **Space:** O(1)

O(n²) slices, each palindrome test is O(n).
How it works: try longer slices first so the first hit is a longest palindrome. isPalin uses two pointers on s[left..right].

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(1)

2n-1 expansions, each O(n) in the worst case. Extra memory is a few indexes.
How it works: expand(i,i) covers odd length, expand(i,i+1) covers even. Keep the longest slice.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Manacher: a transformed string with separators, plus a radius array of length 2n+3. Each side is expanded only past the known right bound.
How it works: t = ^#s#s#$ so even and odd palindromes look the same. p[i] is the radius. Mirror across center when i is inside right. Original start is (center - radius) / 2 on the # string.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
