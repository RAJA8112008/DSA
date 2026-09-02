# Best Time to Buy and Sell Stock with Cooldown

**Topic:** Dynamic Programming  
**Level:** advanced  
**Asked at:** Google · Amazon · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
- [GFG](https://www.geeksforgeeks.org/buy-and-sell-stocks-with-cooldown/)

## Problem

Same as Stock II (many buys and sells, one share at a time), plus a cooldown: after you sell, you must skip the next day before buying again.

Tiny example: [1, 2, 3, 0, 2]. Buy 1, sell 2, cooldown on 3, buy 0, sell 2. Profit 3.

Three states: hold (you have a share), sold (you sold today), rest (you are free to buy, and you did not sell today). You may buy only from rest. Tomorrow’s rest may come from today’s rest or today’s sold.

Open the Brute, Optimal, and More optimal tabs for recursion with a cooldown flag, three DP arrays, and three rolling numbers.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

State is (day, holding, cooldown). Branches are buy/skip/sell. No cache. Exponential in n. Correct, too slow on long price lists.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

hold[i], sold[i], rest[i] are the three states after day i. Each is O(1) from yesterday. n days times 3 cells. This is the table that matches the cooldown rule one-to-one.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Only yesterday’s three numbers are live. Copy them into nextHold, nextSold, nextRest, then slide. Same linear scan, constant extra memory.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
