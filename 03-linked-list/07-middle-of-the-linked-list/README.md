# Middle of the Linked List

**Topic:** Linked List  
**Level:** beginner  
**Asked at:** Amazon · Google · Apple · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/middle-of-the-linked-list/)
- [GFG](https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1)

## Problem

Return the middle node. If there are two middles, return the second one.

On 1 -> 2 -> 3 -> 4 -> 5 the middle is 3. On 1 -> 2 -> 3 -> 4 -> 5 -> 6 the middle is 4.

Store nodes in an array and pick index floor(length/2). Recursion can move slow and fast down the chain. Iterative slow/fast is the usual one-pass answer.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Push every node into an array, then return the node at floor(length/2). Extra array of pointers.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Recursive slow/fast: if fast cannot take two steps, slow is the middle. Stack depth is O(n).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Iterative tortoise and hare. When fast falls off, slow is the second middle on even length. Constant extra space.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
