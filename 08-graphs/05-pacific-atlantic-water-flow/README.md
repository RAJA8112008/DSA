# Pacific Atlantic Water Flow

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Google · Amazon · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/pacific-atlantic-water-flow/)
- [GFG](https://www.geeksforgeeks.org/pacific-atlantic-water-flow/)

## Problem

A heights grid. Rain at a cell can flow to a neighbor that is equal or lower. The Pacific touches the top and left borders. The Atlantic touches the bottom and right. Return every cell that can reach both oceans.

Example: a peak in the middle can flow down to both shores; a low pit in the center may reach neither.

Walking from every cell to the ocean is the slow way. Walking inland from both shores and intersecting the two reachable sets is the right way.

## Methods of solving

### 1. Brute

- **Time:** O(r²c²)
- **Space:** O(rc)

From every cell, DFS toward lower/equal neighbors with a fresh visited copy. Check if that walk hits a Pacific border and an Atlantic border. Extra copies plus a full search per cell.

### 2. Optimal

- **Time:** O(rc)
- **Space:** O(rc)

Reverse the flow: water climbs to equal or higher cells. DFS from all Pacific border cells, then from all Atlantic border cells. A cell in both visited sets is an answer. Each cell is processed a constant number of times.

### 3. More optimal

- **Time:** O(rc)
- **Space:** O(rc)

Same reverse idea with BFS from both oceans. No recursion on a huge grid. Complexity is still linear in cells. This is the interview upgrade when they worry about stack depth.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
