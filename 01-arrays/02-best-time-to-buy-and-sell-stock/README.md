# Best Time to Buy and Sell Stock

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- [GFG](https://www.geeksforgeeks.org/problems/best-time-to-buy-and-sell-stock/1)

## Problem

You may buy on one day and sell on a later day. Return the largest profit. If every sell would lose money, return 0.

Example: prices = [7, 1, 5, 3, 6, 4]. Buy at 1, sell at 6, profit 5.

The slow way tries every buy/sell pair. A prefix of the lowest price so far turns that into two linear passes. The last version keeps only the running minimum, so no extra array.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

For each buy day you scan every later sell day. That is quadratic.
How it works: i is the buy index. j is the sell index. profit is prices[j] - prices[i]. Keep the max, never go below 0.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Linear time, but it stores a min-so-far array of length n.
How it works: minLeft[i] is the cheapest price on day i or earlier. Profit if you sell on day i is prices[i] - minLeft[i]. Take the max of those profits.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Same linear scan, but only two numbers are stored: cheapest so far and best profit.
How it works: walk once. If today’s price is a new low, update cheapest. Else try selling today against that low.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
