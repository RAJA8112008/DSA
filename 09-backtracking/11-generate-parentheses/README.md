# Generate Parentheses

**Topic:** Recursion & Backtracking  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/generate-parentheses/)
- [GFG](https://www.geeksforgeeks.org/problems/generate-all-possible-parentheses/1)

## Problem

Return every valid string of n pairs of parentheses.

Tiny example: n = 2. Answers: (()) and ()(). )( and (() are invalid.

The brute builds every length-2n string of ( and ) (2^(2n) of them) and filters with a counter. Standard backtrack adds a char with undo. The prune is: add ( only if open < n, add ) only if close < open.

Open Brute, Optimal, and More optimal for generate-all, backtrack, and the Catalan prune.

## Methods of solving

### 1. Brute

- **Time:** O(n * 2^{2n})
- **Space:** O(n * 2^{2n})

Every bit mask is a string of ( and ). You copy the string, then scan it with a balance counter. Most strings fail. Extra copies of every mask.

### 2. Optimal

- **Time:** O(4^n / sqrt(n))
- **Space:** O(n)

Backtrack with a char buffer. Try '(' and ')' at every length. Still visits some invalid prefixes unless you add the count checks (see More optimal).

### 3. More optimal

- **Time:** O(4^n / sqrt(n))
- **Space:** O(n)

Prune: add '(' only while open < n. Add ')' only while close < open. Leaves are exactly the Catalan number C_n. No invalid prefix is ever built.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
