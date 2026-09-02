# Network Delay Time

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Google · Amazon · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/network-delay-time/)
- [GFG](https://www.geeksforgeeks.org/network-delay-time/)

## Problem

A directed weighted graph: times[i] = [u, v, w] means a signal takes w to go from u to v. Send from node k. Return how long until every node gets the signal, or -1 if some node is unreachable.

Example: times [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2 answers 2.

Brute DFS all paths with extra visiting copies. Optimal Dijkstra with a linear scan for the next closest node. More optimal Dijkstra with a min-heap.

## Methods of solving

### 1. Brute

- **Time:** O(n^e)
- **Space:** O(n + e)

DFS every simple path, copying the visiting array so cycles stop. Keep the best arrival time per node. Exponential on dense graphs.

### 2. Optimal

- **Time:** O(n² + e)
- **Space:** O(n + e)

Dijkstra without a heap: each round scan all nodes for the unvisited one with smallest dist. Fine when n is a few hundred. Classic O(n²) Dijkstra.

### 3. More optimal

- **Time:** O((n + e) log n)
- **Space:** O(n + e)

Dijkstra with a binary min-heap of [distance, node]. Skip stale pops. This is the usual interview solution for sparse graphs.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
