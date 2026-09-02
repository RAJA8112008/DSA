# Number of Connected Components in an Undirected Graph

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
- [GFG](https://www.geeksforgeeks.org/problems/number-of-provinces/1)

## Problem

n nodes, undirected edges. Return how many connected pieces the graph has.

Example: n = 5, edges [[0,1],[1,2],[3,4]] has two components: {0,1,2} and {3,4}.

Brute restarts DFS with extra visited copies. Optimal is one visited array and a DFS/BFS per unvisited node. More optimal is Union-Find: start at n, subtract one for each merge.

## Methods of solving

### 1. Brute

- **Time:** O(n·(n + e))
- **Space:** O(n + e)

For every unvisited node we DFS with a copied seen array. We still need a global mark so we do not recount. The copies add work without changing the answer.

### 2. Optimal

- **Time:** O(n + e)
- **Space:** O(n + e)

Standard connected-component walk. Each start of a DFS on an unseen node is one component. Linear in nodes and edges.

### 3. More optimal

- **Time:** O(n + e)
- **Space:** O(n)

Union-Find with no adjacency list. comps starts at n. Each successful union glues two pieces, so comps drops by 1. Path compression keeps finds cheap.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
