# Detect Cycle in a Directed Graph

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/course-schedule/)
- [GFG](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)

## Problem

A directed graph with n nodes and a list of edges [u, v] meaning u -> v. Return true if any cycle exists.

Example: 3 nodes, edges [[0,1],[1,2],[2,0]] is a cycle. Drop [2,0] and it is a DAG, so false.

Brute DFS from every node with a fresh on-path copy. Optimal 3-color DFS. More optimal Kahn: if you cannot peel all nodes, a cycle remains.

## Methods of solving

### 1. Brute

- **Time:** O(n·(n + e))
- **Space:** O(n + e)

From each start, DFS with a copied onPath array. You repeat walks that 3-color would cache as 'finished'. Extra copies are the brute cost.

### 2. Optimal

- **Time:** O(n + e)
- **Space:** O(n + e)

Colors 0/1/2. A neighbor that is still 1 is a back edge, so a cycle. Nodes marked 2 are skipped. Each edge once.

### 3. More optimal

- **Time:** O(n + e)
- **Space:** O(n + e)

Kahn's algorithm. Peel indegree 0. If the number of peeled nodes is less than n, leftover nodes sit in a cycle. Iterative, same linear time.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
