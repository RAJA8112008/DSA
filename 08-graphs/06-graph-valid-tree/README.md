# Graph Valid Tree

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Google · Amazon · Meta · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/graph-valid-tree/)
- [GFG](https://www.geeksforgeeks.org/graph-valid-tree/)
- [LintCode](https://www.lintcode.com/problem/178/)

## Problem

n nodes labeled 0 to n-1, and a list of undirected edges. Return true if these edges form a single tree: connected, and no cycle.

Example: n = 5, edges [[0,1],[0,2],[0,3],[1,4]] is a tree. Add [1,2] and you get a cycle, so false.

A tree on n nodes has exactly n-1 edges and is connected. Brute DFS with extra path copies. Optimal BFS connected-plus-n-1. More optimal Union-Find: a union that is already in the same set is a cycle.

## Methods of solving

### 1. Brute

- **Time:** O(n + e)
- **Space:** O(n + e)

Build the list, then from node 0 DFS with a fresh onPath copy at each step to catch a cycle. Count how many nodes were seen. Extra copies are the brute part; the idea (connected + acyclic) is right.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

A tree must have n-1 edges. Then one BFS/DFS from 0 must reach every node. If it does, there is no extra edge and no missing node, so no cycle.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Union-Find. If two ends already share a parent, that edge is a cycle. After n-1 successful unions you have one component. No adjacency list needed.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
