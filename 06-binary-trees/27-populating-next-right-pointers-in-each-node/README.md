# Populating Next Right Pointers in Each Node

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Meta · Google

## Practice

- [LeetCode](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
- [GFG](https://www.geeksforgeeks.org/connect-nodes-at-same-level/)

## Problem

The tree is perfect (every level full). Each node has a next pointer. Point it at the neighbor on the right, or null at the end of a level. Return the root.

Brute is BFS: the next node in the queue on the same level is next. Optimal walks already-built next links on level i to wire level i+1, O(1) extra space. More optimal uses a leftmost pointer and a prev cursor on the child level.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Level-order queue. For each level, node.next = the next polled node, last.next = null.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(1)

On a perfect tree, left.next = right, and right.next = node.next.left. Recurse both children. Uses the next links already set on this level.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Iterative: leftmost starts at root. Walk the level via next. Wire children, then leftmost = leftmost.left. No recursion, no queue.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
