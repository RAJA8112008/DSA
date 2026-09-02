# All Nodes Distance K in Binary Tree

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)
- [GFG](https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/)

## Problem

Return every node value that is exactly K edges away from target. Edges go to children and to the parent, so you need parent pointers or an undirected graph.

Build parent map with a DFS/BFS, then BFS from target, stopping at distance K.

Brute converts the tree to an adjacency list. Optimal parent map + BFS. More optimal DFS that returns distance to target and explores the other side when it knows how far the target is.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Undirected graph of val->neighbors (vals are unique on LC). BFS from target.val for K steps.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Parent map from nodes (not values). BFS from the target node with a visited set of pointers. Collect at distance k.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

DFS returns distance from this subtree to target, or -1. When a child reports dist, walk the other child at k - dist - 2, and maybe record this node. Downward walk from target collects depth k.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
