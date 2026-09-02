# Number of Islands

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/number-of-islands/)
- [GFG](https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1)

## Problem

Count groups of land in a grid. '1' is land, '0' is water. Two land cells are the same island if they touch up, down, left, or right (not diagonal).

Example: [[1,1,0],[1,0,0],[0,0,1]] has two islands: the three 1s in the top-left, and the lone 1 at the bottom-right.

You walk each land cell and mark the whole blob so you do not count it again. Open Brute, Optimal, and More optimal for extra visited copies, in-place DFS, and Union-Find.

## Methods of solving

### 1. Brute

- **Time:** O(r²c²)
- **Space:** O(rc)

For every land cell we copy a full visited matrix and DFS that island. The extra copies are wasted work. Correct, but memory traffic is huge on a large grid.

### 2. Optimal

- **Time:** O(rc)
- **Space:** O(rc)

One DFS (or BFS) per island. Mutating land to water is the visited mark, so we never copy a matrix. Each cell is entered a constant number of times.

### 3. More optimal

- **Time:** O(rc)
- **Space:** O(rc)

Union-Find treats each land cell as a node. You only union with the right and down land neighbor, so each edge is processed once. The island count is how many land roots remain. No recursion.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
