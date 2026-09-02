# Best Time to Buy and Sell Stock II

**Topic:** Dynamic Programming  
**Level:** beginner  
**Asked at:** Amazon · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
- [GFG](https://www.geeksforgeeks.org/stock-buy-sell/)

## Problem

prices[i] is the price on day i. You may buy and sell as many times as you like, but you hold at most one share. You cannot buy and sell on a timeline that overlaps. Return the maximum profit.

Tiny example: [7, 1, 5, 3, 6, 4]. Buy at 1, sell at 5 (profit 4), buy at 3, sell at 6 (profit 3). Answer 7.

DP state is (day, holding or not). Greedy is the same as summing every uphill day-to-day gain: any climb can be taken as a 1-day trade, and that matches the best multi-day hold.

Open the Brute, Optimal, and More optimal tabs for buy/skip recursion, cash/hold arrays, and the uphill sum.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

At each day you skip, buy, or sell depending on holding. Two branches most days, no cache. Exponential in the number of days.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

cash[i] is best profit ending day i with no share. hold[i] is best ending day i with a share. Transitions are skip vs sell, and skip vs buy. n days, two arrays.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Every profitable adjacent difference can be taken. That sum equals the DP. One pass, no extra arrays. Mention this is the space-cut of the two-state DP, not a different problem.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
