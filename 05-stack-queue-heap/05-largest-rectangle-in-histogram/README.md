# Largest Rectangle in Histogram

**Topic:** Stack, Queue & Heap  
**Level:** advanced  
**Asked at:** Amazon · Google · Microsoft · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/largest-rectangle-in-histogram/)
- [GFG](https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115623/1)

## Problem

heights[i] is the height of bar i, width 1. Return the largest rectangle you can form using consecutive bars.

Example: [2,1,5,6,2,3] answers 10 (the 5 and 6 bars, height 5, width 2).

For each bar, you need the nearest shorter bar on the left and on the right. That width times this height is a candidate. Brute expands. Optimal two monotonic passes. More optimal one pass with a 0 sentinel.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

For each bar, walk left and right while bars are at least this tall. Width times height. n starts, each can walk n.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Two monotonic stacks: nearest smaller to the left, nearest smaller to the right. Then one pass of height * (right - left - 1). Each index processed a constant number of times.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Append a 0 sentinel so every bar gets popped. One increasing stack of indices. When you pop height h at i, the width is i - newTop - 1. Same linear bound, one pass, less arrays.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
