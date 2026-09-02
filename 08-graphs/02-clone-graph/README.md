# Clone Graph

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Meta · Google · Amazon

## Practice

- [LeetCode](https://leetcode.com/problems/clone-graph/)
- [GFG](https://www.geeksforgeeks.org/problems/clone-graph/1)

## Problem

You get one node of a connected undirected graph. Each node has a val and a neighbors array. Return a deep copy: new objects, same shape, no shared references.

Example: 1 connected to 2 and 3, 2 connected to 1 and 3. The clone has new nodes 1, 2, 3 with the same links.

A map from old node to new node is the whole trick, so you do not clone the same node twice. Brute copies extra maps; Optimal uses DFS; More optimal uses BFS.

## Methods of solving

### 1. Brute

- **Time:** O(n + e)
- **Space:** O(n)

One shared old-to-new map is required so a node is cloned once. The extra Set copy on every call is wasted; it does not change correctness. Drop the copies and you get Optimal.

### 2. Optimal

- **Time:** O(n + e)
- **Space:** O(n)

One Map from old node to new node. DFS creates the clone, then fills neighbors. Each node and edge is processed once.

### 3. More optimal

- **Time:** O(n + e)
- **Space:** O(n)

BFS with the same map avoids deep recursion on a long chain. Complexity matches DFS. Prefer this when the graph can be a long path.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
