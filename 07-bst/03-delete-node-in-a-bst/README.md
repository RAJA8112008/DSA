# Delete Node in a BST

**Topic:** BST  
**Level:** intermediate  
**Asked at:** Google · Amazon · Meta · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/delete-node-in-a-bst/)
- [GFG](https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1)

## Problem

Delete the node whose value is key and return the new root. The tree must stay a BST.

Zero children: drop it. One child: splice that child in. Two children: copy the inorder successor (leftmost of the right subtree) into the node, then delete the successor.

Brute rebuilds from the remaining keys. Optimal is recursive Hibbard delete. More optimal finds the node with a parent pointer and splices in a loop.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Inorder dump every key except key, then rebuild a balanced BST from the sorted list. Simple, but you throw away the original shape.

### 2. Optimal

- **Time:** O(h)
- **Space:** O(h)

Recurse to the node. Leaf or one child: return the other child. Two children: copy leftmost of right into node.val, then delete that successor from the right subtree.

### 3. More optimal

- **Time:** O(h)
- **Space:** O(1)

Iterative search with a parent pointer. Splice zero/one-child nodes directly. For two children, copy the successor value then unlink the successor (it has no left child).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
