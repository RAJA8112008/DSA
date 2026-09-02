# Trapping Rain Water

**Topic:** Arrays  
**Level:** advanced  
**Asked at:** Amazon · Google · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/trapping-rain-water/)
- [GFG](https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1)

## Problem

Each index is a bar. Water sits on top of a bar up to the lower of the tallest bar on its left and on its right. Return total units of water.

Example: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] -> 6.

For each index you can scan left and right for the two maxes. Precomputing those max arrays is linear. Two pointers keep a running leftMax and rightMax and add water from the smaller side, using constant extra memory.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

For every index you walk the whole left side and the whole right side.
How it works: water at i is max(0, min(leftMax, rightMax) - height[i]). Sum those amounts.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Three linear passes. Two extra arrays of length n.
How it works: leftMax[i] is the tallest bar at or left of i. rightMax[i] is the tallest at or right of i. Water at i uses those two stored values.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

One pass from both ends. Only a handful of integers besides the input.
How it works: the side with the smaller max is the bottleneck. Add water there, then move that pointer and update that max. The other side is at least as tall, so it can hold this water.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
