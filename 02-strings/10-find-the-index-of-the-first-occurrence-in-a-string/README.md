# Find the Index of the First Occurrence in a String

**Topic:** Strings  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)
- [GFG](https://www.geeksforgeeks.org/problems/implement-strstr/1)

## Problem

Return the first index where needle appears in haystack, or -1 if it never appears. This is strStr / indexOf.

Example: haystack = "sadbutsad", needle = "sad" -> 0. Example: "leetcode", "leeto" -> -1.

Trying needle at every start is O((n-m)*m). The same nested loops with an early break is the usual brute you then optimize. KMP builds a prefix table and searches in O(n+m).

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O((n-m)·m)
- **Space:** O(1)

Every start position compares up to m characters.
How it works: for each i, check whether haystack[i..i+m) equals needle. First hit wins.

### 2. Optimal

- **Time:** O((n-m)·m)
- **Space:** O(1)

Same worst-case bound, fewer inner steps when the first character already mismatches (slice avoided).
How it works: skip starts whose first character is wrong, then compare the rest. Empty needle returns 0.

### 3. More optimal

- **Time:** O(n + m)
- **Space:** O(m)

KMP: build lps of the needle in O(m), then scan haystack in O(n) without restarting from scratch on mismatch.
How it works: lps[i] is the longest proper prefix of needle[0..i] that is also a suffix. On mismatch, j = lps[j-1] instead of j = 0 always.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
