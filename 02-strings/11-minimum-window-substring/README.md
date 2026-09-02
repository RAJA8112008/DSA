# Minimum Window Substring

**Topic:** Strings  
**Level:** advanced  
**Asked at:** Meta · Amazon · Google · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/minimum-window-substring/)
- [GFG](https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1)

## Problem

Return the shortest substring of s that covers every character in t (including duplicates). If none exists, return "".

Example: s = "ADOBECODEBANC", t = "ABC" -> "BANC".

Checking every window for coverage is cubic/quadratic. Expanding from each left with a need map is still quadratic. Two pointers with a formed counter find every valid window as right grows and left shrinks, in linear time.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n² · k)
- **Space:** O(k)

Every i..j window rebuilds counts against t. k is the alphabet / unique letters in t.
How it works: covers() copies t’s need map and decrements for each character of the slice. Keep the shortest slice that covers.

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(k)

From each left, grow right until t is covered, then record and try the next left. Still quadratic starts.
How it works: missing starts as t.length. A need map counts t. As right adds characters, missing drops. First time missing hits 0, that window is a candidate.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(k)

right walks n times, left walks n times. formed tracks how many unique t-characters are satisfied.
How it works: grow right, update have. While the window is complete, record if smaller, drop s[left], move left. needCount is the number of unique keys in t.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
