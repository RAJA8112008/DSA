# Two Sum IV - Input is a BST

**Topic:** BST  
**Level:** beginner  
**Asked at:** Amazon · Google · Meta · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
- [GFG](https://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/)

## Problem

Return true if two distinct nodes sum to k.

On any tree a hash set of seen values works: at each node ask whether k - val was already seen. On a BST you can also dump inorder (sorted) and two-pointer. Two BST iterators, one from the left and one from the right, do the same with O(h) extra memory.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(h)

For each node, DFS the rest of the tree looking for k - val. Nested walks. No extra set.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Hash set of visited values. DFS: if k - val is in the set, done; else add val and continue. Works on any binary tree.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Inorder array is sorted. Two pointers from both ends. Uses the BST. Space is still linear for the array; two iterators would drop it to O(h).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
