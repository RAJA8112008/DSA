# Binary Tree Zigzag Level Order Traversal

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Meta · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
- [GFG](https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1)

## Problem

Return node values by level, but alternate direction: left-to-right, then right-to-left, and so on.

Normal BFS already groups by level. Reverse every odd row, or use a deque and flip which end you pop from.

Brute is BFS then reverse odd rows. Optimal fills each row from the correct end with a deque. More optimal is DFS that inserts at depth, reversing later or inserting at index 0 on odd depths.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Level-order into lists. Reverse rows whose index is odd. Extra reverse pass per odd level.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Deque of nodes. Even levels poll from the front and offer children left-then-right at the back. Odd levels poll from the back and offer children right-then-left at the front.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

DFS with depth. Append a new list when you first reach a depth. Push on even depths, unshift on odd depths. Recursion stack only.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
