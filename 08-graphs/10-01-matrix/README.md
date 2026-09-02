# 01 Matrix

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Google · Amazon · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/01-matrix/)
- [GFG](https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1)

## Problem

A matrix of 0s and 1s. For every cell, return its distance to the nearest 0. Distance is 4-direction steps.

Example: [[0,0,0],[0,1,0],[1,1,1]] becomes [[0,0,0],[0,1,0],[1,2,1]].

Brute runs BFS from every 1. Optimal puts every 0 in one queue (multi-source BFS). More optimal is a two-pass DP: top-left then bottom-right.

## Methods of solving

### 1. Brute

- **Time:** O(r²c²)
- **Space:** O(rc)

For each 1, BFS with a fresh visited matrix until you hit a 0. You re-walk the same cells from many starts.

### 2. Optimal

- **Time:** O(rc)
- **Space:** O(rc)

Multi-source BFS from all zeros. Each 1 is reached first by its nearest 0. One visit per cell.

### 3. More optimal

- **Time:** O(rc)
- **Space:** O(1)

Two DP sweeps. First pass uses top and left (already processed). Second pass uses bottom and right. You can write into the output matrix only; extra space is O(1) besides the answer. Same linear time, no queue.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
