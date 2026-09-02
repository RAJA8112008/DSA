# Flood Fill

**Topic:** Graphs  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/flood-fill/)
- [GFG](https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1)

## Problem

An image grid of color numbers, a start cell (sr, sc), and a new color. Recolor the start cell and every 4-direction neighbor that had the same old color. Return the image.

Example: image [[1,1,1],[1,1,0],[1,0,1]], start (1,1), color 2 paints the connected 1s into 2s. The 1 at (2,2) stays 1 because it does not touch the blob through 4-direction edges.

This is islands on colors. If the start is already the new color, return as-is so you do not loop.

## Methods of solving

### 1. Brute

- **Time:** O(rc)
- **Space:** O(rc)

DFS with a brand-new visited matrix copy even though one matrix is enough. Extra memory, same walk. Shows the 'copy visited' habit you should drop.

### 2. Optimal

- **Time:** O(rc)
- **Space:** O(rc)

DFS from the start. Painting to the new color is the visited mark when old !== color. Each cell in the blob is painted once.

### 3. More optimal

- **Time:** O(rc)
- **Space:** O(rc)

BFS with a queue. Same linear bound, no recursive stack. Prefer this on a huge image so the call stack cannot overflow.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
