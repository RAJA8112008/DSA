# Partition Equal Subset Sum

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/partition-equal-subset-sum/)
- [GFG](https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1)

## Problem

Return true if you can split nums into two subsets with equal sum. Each number is used at most once.

Tiny example: [1, 5, 11, 5]. Total 22, so each subset needs 11. {11} and {1, 5, 5} work. Answer true. [1, 2, 3, 5] totals 11 (odd). Answer false.

If the total is odd, return false. Otherwise this is 0/1 subset sum with need = total/2. Take or skip each number.

Open the Brute, Optimal, and More optimal tabs for include/skip recursion, the 2D boolean table, and one backwards boolean row.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

Each number is included or skipped. No cache. 2^n subsets. The odd-total check is the only prune. Stack is O(n).

### 2. Optimal

- **Time:** O(n * sum)
- **Space:** O(n * sum)

can[i][s] is true if some subset of the first i numbers adds to s. Classic 0/1 knapsack boolean table. n * (sum/2) cells, each O(1).

### 3. More optimal

- **Time:** O(n * sum)
- **Space:** O(sum)

One boolean row. Walk s from need down to num so each number is used at most once. Same 0/1 rule as knapsack space cut. Extra memory is need+1 flags.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
