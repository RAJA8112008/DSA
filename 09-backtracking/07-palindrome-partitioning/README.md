# Palindrome Partitioning

**Topic:** Recursion & Backtracking  
**Level:** intermediate  
**Asked at:** Amazon · Google · Bloomberg

## Practice

- [LeetCode](https://leetcode.com/problems/palindrome-partitioning/)
- [GFG](https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1)

## Problem

Cut string s into pieces so every piece is a palindrome. Return every such cutting.

Tiny example: s = "aab". Two cuttings: ["a","a","b"] and ["aa","b"]. "aab" itself is not a palindrome, so it is not a one-piece answer.

The brute builds every cut of the string (extra copies of the piece list) and checks palindromes at the end. Standard backtrack only extends with a palindrome piece. Precomputing a pal[l][r] table makes each check O(1).

Open Brute, Optimal, and More optimal for all-cuts, two-pointer checks, and the DP table.

## Methods of solving

### 1. Brute

- **Time:** O(n * 2^n)
- **Space:** O(n * 2^n)

At each index you either cut or keep growing the last piece, copying the piece list every time. After a full partition you test every piece. Many illegal cuttings are built first and thrown away.

### 2. Optimal

- **Time:** O(n * 2^n)
- **Space:** O(n)

From start, try every end. If s[start..end] is a palindrome, push it, recurse end+1, pop. Illegal prefixes never grow. Copy only at the end of s.

### 3. More optimal

- **Time:** O(n * 2^n)
- **Space:** O(n^2)

pal[l][r] is true if s[l..r] is a palindrome. Fill in O(n^2). Each cut check is then O(1). Same 2^n cuttings, cheaper work per node.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
