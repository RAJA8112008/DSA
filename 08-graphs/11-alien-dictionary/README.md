# Alien Dictionary

**Topic:** Graphs  
**Level:** advanced  
**Asked at:** Google · Amazon · Meta · Airbnb

## Practice

- [LeetCode](https://leetcode.com/problems/alien-dictionary/)
- [GFG](https://www.geeksforgeeks.org/problems/alien-dictionary/1)

## Problem

A list of words sorted in an alien alphabet. Derive a valid order of unique letters. If the order is invalid (cycle, or a longer word listed before its prefix), return "". Any valid topo order is accepted.

Example: [wrt, wrf, er, ett, rftt] can return wertf.

Compare neighbor words to build directed edges (earlier letter -> later letter). Then topo sort. Brute permutes letters. Optimal DFS. More optimal is Kahn.

## Methods of solving

### 1. Brute

- **Time:** O(k! · n · L)
- **Space:** O(k)

Collect unique letters, try every permutation, test it against consecutive word pairs. Fine for 3 letters, dead at 20. Proves you know the constraints.

### 2. Optimal

- **Time:** O(n·L + k)
- **Space:** O(k²)

Build a letter graph from the first mismatch of each consecutive pair. Reject prefix violations. DFS 3-color topo, then reverse the postorder.

### 3. More optimal

- **Time:** O(n·L + k)
- **Space:** O(k²)

Same graph, Kahn's BFS. Letters with indegree 0 come first. If you cannot emit every unique letter, there is a cycle. Iterative and easy to explain.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
