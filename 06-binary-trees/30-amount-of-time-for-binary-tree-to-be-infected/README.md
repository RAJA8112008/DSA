# Amount of Time for Binary Tree to Be Infected

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/)
- [GFG](https://www.geeksforgeeks.org/burn-the-binary-tree-starting-from-the-target-node/)

## Problem

At minute 0 the node with value start is infected. Each minute infection spreads to adjacent nodes (parent or child). Return how many minutes until every node is infected.

This is the max distance from start in the undirected tree. Parent map + BFS, or one DFS that returns height-below-start and distance-up.

Brute adjacency list BFS. Optimal parent map BFS max dist. More optimal single DFS tracking the answer.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Build undirected graph on values (unique). BFS from start. Answer is the max distance.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Parent pointers, BFS from the start node (find it first). Minutes = max distance.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

DFS returns height of the subtree. When the start node is found, ans is max(height below, distance going up through the parent). One traversal, no graph.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
