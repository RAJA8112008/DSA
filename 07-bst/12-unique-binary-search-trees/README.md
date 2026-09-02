# Unique Binary Search Trees

**Topic:** BST  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/unique-binary-search-trees/)
- [GFG](https://www.geeksforgeeks.org/problems/unique-bsts-1587115623/1)

## Problem

Given n, count how many structurally different BSTs store the keys 1..n.

If i is the root, left keys are 1..i-1 and right keys are i+1..n. The counts multiply, then you sum over every choice of root. That recurrence is the Catalan numbers: C(n) = sum C(i)*C(n-1-i).

Brute recurses with no memory. Optimal is bottom-up DP. More optimal multiplies the Catalan formula in O(n).

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(4^n / n^{3/2})
- **Space:** O(n)

Naive recursion: try each root and multiply left-count * right-count. Exponential overlapping subproblems.

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(n)

dp[k] = number of BSTs on k keys. dp[0]=1. Each k sums dp[left]*dp[k-1-left]. Standard Catalan DP.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

C(n) = C(n-1) * 2(2n-1)/(n+1). Multiply carefully with integer arithmetic. One pass, constant extra memory.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
