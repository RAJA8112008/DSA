# Binary Tree Inorder Traversal

**Topic:** Binary Trees  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/binary-tree-inorder-traversal/)
- [GFG](https://www.geeksforgeeks.org/problems/inorder-traversal/1)

## Problem

Return the inorder list of node values: left subtree, then the node, then the right subtree.

Tree 1 with left 2 and right 3 yields [2, 1, 3]. An empty tree yields [].

Recursion is the definition. An explicit stack simulates the same walk. Morris traversal threads a temporary link from the predecessor so you need no stack.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Recursive inorder: walk left, push this value, walk right. Matches the definition. Extra memory is the output array plus O(h) call stack.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Iterative stack: go left until null, pop, record val, go right. Same visit order as recursion without depending on engine stack limits as much; still O(h) extra.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Morris: if there is no left, visit and go right. Else find the predecessor (rightmost in left). If pred.right is null, thread it to cur and go left. If it already points at cur, unthread, visit, go right. Auxiliary space O(1) besides the output list.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
