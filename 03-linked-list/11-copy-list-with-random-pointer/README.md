# Copy List with Random Pointer

**Topic:** Linked List  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Meta · Google

## Practice

- [LeetCode](https://leetcode.com/problems/copy-list-with-random-pointer/)
- [GFG](https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1)

## Problem

Each node has val, next, and random (any node or null). Return a deep copy: new nodes, same layout of next and random.

A copy's random must point at the copied target, not the original. An empty list copies to null.

A Map from old node to new node, filled in one or two walks, is the clean extra-space answer. The weave method inserts each copy after its original, assigns random via original.random.next, then unweaves.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

First pass: clone every node into a Map, next and random left null. Second pass: wire next and random through the map. Two walks, extra map of n nodes.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

One recursive walk with a Map. If the node is already cloned, return it (handles random cycles). Otherwise clone, then fill next and random. Still O(n) extra map plus stack.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Weave: original -> copy -> original.next. Set copy.random from original.random.next. Unweave into two lists. Extra space is the copies themselves, no hash map. (O(1) auxiliary.)

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
