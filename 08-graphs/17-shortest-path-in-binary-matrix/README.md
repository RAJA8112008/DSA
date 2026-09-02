# Shortest Path in Binary Matrix

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/shortest-path-in-binary-matrix/)
- [GFG](https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/)

## Problem

An n x n grid of 0 (open) and 1 (blocked). Walk 8 directions. Return the length of the shortest path from (0,0) to (n-1,n-1), counting cells on the path. Return -1 if you cannot reach the end. Start and end must be 0.

Example: [[0,1],[1,0]] answers 2 (diagonal step).

Unweighted shortest path: BFS. DFS-all-paths is the brute. Bidirectional BFS is the upgrade on large open grids.

## Methods of solving

### 1. Brute

- **Time:** O(8^{n²})
- **Space:** O(n²)

DFS every simple path with a copied visited matrix. Keep the shortest length. Correct on a 2x2, exponential on a 20x20.

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(n²)

BFS from (0,0). First time you pop the end cell is the shortest length. Mark cells when you push so the queue stays small. 8 neighbors.

### 3. More optimal

- **Time:** O(n²)
- **Space:** O(n²)

Bidirectional BFS from start and end. When a neighbor sits in the other frontier, the two searches met. Fewer cells expanded on large open maps. Same worst-case O(n²).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
