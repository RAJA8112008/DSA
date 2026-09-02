# Serialize and Deserialize Binary Tree

**Topic:** Binary Trees  
**Level:** advanced  
**Asked at:** Amazon · Google · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1)

## Problem

Write functions that turn a tree into a string and back. Null children must be recorded so the shape is unique.

A codec that round-trips 1 with left 2 and right 3 (3 has 4 and 5) must rebuild that exact tree.

JSON of nested objects is a brute that relies on the engine. Preorder with N markers is the usual DFS codec. BFS with a queue matches how some judges print trees.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

JSON.stringify the nested {val,left,right} object and JSON.parse it back. Works for this node shape, hides the codec you are supposed to write, and is bulky.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Preorder join with commas, N for null. Deserialize consumes tokens with an index. Recursion rebuilds left then right.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

BFS codec: queue writes val or N level by level. Deserialize uses a queue of parents and attaches children in order. Iterative, same linear cost, no recurse on serialize/deserialize.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
