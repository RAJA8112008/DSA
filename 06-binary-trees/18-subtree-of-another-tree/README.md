# Subtree of Another Tree

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Meta · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/subtree-of-another-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/check-if-subtree/1)

## Problem

Return true if subRoot is the same tree as some subtree of root (shape and values).

root [3,4,5,1,2] and subRoot [4,1,2] is true. An extra child on that subtree makes it false.

Collect every node and run isSameTree. DFS: isSame at this node or recurse sides. Serialize both with unique wrappers and test whether the sub string appears.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n·m)
- **Space:** O(n)

Push every node of root into an array, then isSameTree against subRoot for each. Extra array plus O(n*m) compares.

### 2. Optimal

- **Time:** O(n·m)
- **Space:** O(h)

No extra node list. If this node matches as a tree, true. Else try left or right. Worst case still O(n*m), typical interview code.

### 3. More optimal

- **Time:** O(n+m)
- **Space:** O(n+m)

Serialize with parentheses so each subtree is a unique string. Check whether ser(subRoot) is a substring of ser(root). Linear in the size of the strings (and typical includes).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
