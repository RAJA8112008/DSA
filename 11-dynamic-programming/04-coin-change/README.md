# Coin Change

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/coin-change/)
- [GFG](https://www.geeksforgeeks.org/problems/number-of-coins1824/1)

## Problem

You have coin values in coins. Each coin may be used any number of times. Return the fewest coins that sum to amount, or -1 if it is impossible.

Tiny example: coins = [1, 3, 4], amount = 6. 4+1+1 is three coins, 3+3 is two. Answer 2.

This is unbounded knapsack for minimum count. A state is remaining amount (or current sum). The transition is: try each coin and add 1.

Open the Brute, Optimal, and More optimal tabs for raw recursion, a memo on remaining, and a 1D bottom-up row.

## Methods of solving

### 1. Brute

- **Time:** O(S^n)
- **Space:** O(amount)

At every remaining amount you branch on every coin. The tree is huge and repeats the same remain. Depth is at most amount (all 1s). S is amount, n is number of coins.

### 2. Optimal

- **Time:** O(n * amount)
- **Space:** O(amount)

Each remaining amount is solved once. Work per state is a loop over n coins. Memo array is size amount+1. Same recurrence as brute, overlapping calls collapsed.

### 3. More optimal

- **Time:** O(n * amount)
- **Space:** O(amount)

Bottom-up 1D unbounded knapsack. best[s] is fewest coins for sum s. Filling left to right allows reuse. No recursion. Same asymptotics as memo, cleaner order, no stack.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
