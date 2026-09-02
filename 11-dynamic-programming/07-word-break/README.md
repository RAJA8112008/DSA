# Word Break

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/word-break/)
- [GFG](https://www.geeksforgeeks.org/problems/word-break-2/1)

## Problem

You are given a string s and a list of words. Return true if s can be split into a sequence of those words. Words may be reused. Order in the dictionary does not matter.

Tiny example: s = "applepenapple", wordDict = ["apple", "pen"]. apple + pen + apple works. Answer true. "catsandog" with ["cats","dog","sand","and","cat"] cannot finish. Answer false.

A state is the start index i. If any dictionary word matches s starting at i and the rest also breaks, i is good. The boolean row can[i] means s[0..i) can be segmented.

Open the Brute, Optimal, and More optimal tabs for prefix recursion, memo on the start index, and the boolean DP row.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

Every start tries every word. Failed prefixes are retried from overlapping indexes. Worst case is exponential in n. Stack is O(n).

### 2. Optimal

- **Time:** O(n * m * L)
- **Space:** O(n)

Each start index i is solved once. Per index you try m words, each startsWith costs up to L. Memo of n booleans. n is s.length, m is dict size, L is max word length.

### 3. More optimal

- **Time:** O(n * m * L)
- **Space:** O(n + m)

Bottom-up: can[0] is true. From every true cut, stamp every word that matches. A Set makes membership obvious if you later scan splits by length. No recursion; same polynomial bound.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
