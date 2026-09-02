# Rotting Oranges

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/rotting-oranges/)
- [GFG](https://www.geeksforgeeks.org/problems/rotten-oranges/1)

## Problem

A grid: 0 empty, 1 fresh orange, 2 rotten. Every minute, every rotten orange infects its 4-direction neighbors. Return minutes until no fresh orange remains, or -1 if some orange never rots.

Example: [[2,1,1],[1,1,0],[0,1,1]] takes 4 minutes.

Brute rescan the whole grid each minute. Optimal is multi-source BFS from every initial 2. More optimal stores the minute on the grid so you do not keep a separate time field.

## Methods of solving

### 1. Brute

- **Time:** O((rc)²)
- **Space:** O(rc)

Each minute, copy the grid and rot any fresh cell that touches a 2. Repeat until nothing changes. You scan the whole grid once per minute, up to rc minutes.

### 2. Optimal

- **Time:** O(rc)
- **Space:** O(rc)

Put every rotten orange in the queue at minute 0. BFS infects fresh neighbors. The last minute you used is the answer. If any 1 remains, return -1.

### 3. More optimal

- **Time:** O(rc)
- **Space:** O(rc)

Same multi-source BFS, but the grid itself stores time as 2 + minutes. No third tuple field. Space is still the queue. Linear in cells.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
