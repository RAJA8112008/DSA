# Binary Tree Level Order Traversal

**Topic:** Binary Trees  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- [GFG](https://www.geeksforgeeks.org/problems/level-order-traversal/1)

## Problem

Return values grouped by depth, left to right in each row.

Tree 3 with left 9 and right 20 (20 has 15 and 7) yields [[3],[9,20],[15,7]]. Empty tree yields [].

DFS can drop values into buckets by depth. BFS with a queue is the natural level walk. Recording queue.length at the start of each round avoids storing depth on every node.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

DFS with a depth argument. Push val into levels[depth], creating the row if needed. Extra recursion stack plus the answer.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

BFS queue. Each node is stored with its depth. Rows grow as depth increases. Extra pair objects on the queue.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

BFS without storing depth. n = queue.length is the current row size. Process exactly those n nodes, enqueue children for the next row. Cleaner constant factors; still O(width) queue.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
