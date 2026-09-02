# Gas Station

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Bloomberg

## Practice

- [LeetCode](https://leetcode.com/problems/gas-station/)
- [GFG](https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1)

## Problem

n stations on a circle. gas[i] is fuel you get, cost[i] is fuel to reach i+1. Start with an empty tank. Return the unique start index that lets you complete one loop, or -1.

Example: gas = [1, 2, 3, 4, 5], cost = [3, 4, 5, 1, 2]. Start at index 3.

Brute tries every start and walks the circle. Optimal first checks total gas >= total cost, then still tries starts. More optimal is one pass: if the tank goes negative, the next start is i+1.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

From each start, simulate the circle. Fail when the tank goes negative. Return the first start that finishes n steps.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(1)

If the total of gas[i]-cost[i] is negative, no start works. Otherwise try starts in order but skip a failed prefix using a leftover tank. Still a linear check plus a second idea.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

One pass. tank is the fuel since the current start. If tank drops below 0, no start in [oldStart, i] works, so start = i+1 and tank = 0. If the total is negative, return -1. Unique start is guaranteed.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
