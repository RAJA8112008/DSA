# Kth Largest Element in BST

**Topic:** BST  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google · Uber

## Practice

- [GFG](https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1)
- [GFG](https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/)

## Problem

Return the k-th largest key in a BST (1-based). Inorder is sorted ascending, so reverse inorder (right, node, left) is sorted descending.

Brute stores the full inorder list and indexes from the end. Optimal reverse-inorders and stops after k visits. More optimal is Morris reverse inorder so extra memory is O(1).

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Inorder dump, then return vals[n - k]. Extra array of every key.

### 2. Optimal

- **Time:** O(h + k)
- **Space:** O(h)

Reverse inorder. Decrement k at each visit. When k hits 0, that value is the answer. Stop walking.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Morris reverse inorder: thread the successor (leftmost of the right, via left pointers of the right spine). Visit without a stack, stop at k.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
