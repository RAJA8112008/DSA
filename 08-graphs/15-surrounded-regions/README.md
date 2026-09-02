# Surrounded Regions

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/surrounded-regions/)
- [GFG](https://www.geeksforgeeks.org/problems/replace-os-with-xs/1)

## Problem

A board of 'X' and 'O'. Flip every 'O' that cannot reach the border into 'X'. An 'O' on the border, and anything connected to it, stays 'O'.

Example: a ring of X around a middle O becomes all X. An O on the edge keeps its whole blob.

Brute: for every O, DFS with a visited copy to see if the blob hits the border. Optimal: mark all border-connected O, then flip the rest. More optimal: Union-Find with a dummy 'border' node.

## Methods of solving

### 1. Brute

- **Time:** O(r²c²)
- **Space:** O(rc)

For each O, copy a visited matrix and DFS. If that blob never hits a border, flip those cells. Repeated walks over the same region.

### 2. Optimal

- **Time:** O(rc)
- **Space:** O(rc)

DFS/BFS from every border O and mark those cells (for example '#'). Then walk the board: leftover O is surrounded and becomes X; '#' is restored to O.

### 3. More optimal

- **Time:** O(rc)
- **Space:** O(rc)

Union-Find. Dummy node DUMMY represents 'touches border'. Union every O with its O neighbors, and union border O with DUMMY. Then flip O whose root is not DUMMY. No recursion.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
