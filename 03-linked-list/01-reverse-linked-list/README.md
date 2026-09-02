# Reverse Linked List

**Topic:** Linked List  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/reverse-linked-list/)
- [GFG](https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1)

## Problem

You get the head of a singly linked list. Return the head of the same nodes with every next pointer flipped.

1 -> 2 -> 3 -> null becomes 3 -> 2 -> 1 -> null. An empty list stays empty. A single node stays itself.

The brute path copies values, reverses the array, and builds a new list. Recursion reverses the suffix then hangs the current node on its old next. The iterative walk uses prev, cur, and next and needs only a handful of pointers.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Copy every value into an array, reverse the array, then build a brand new list. Easy to see, but it allocates n extra nodes and ignores that you can flip next in place.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Recurse to the end, then set head.next.next = head and cut head.next. The call stack holds every node, so space is O(n). Clear picture of 'suffix first'.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Iterative three-pointer reverse. Each node is visited once. Extra memory is a few names, not the stack and not a new list. This is the usual interview target.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
