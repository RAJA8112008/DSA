# Odd Even Linked List

**Topic:** Linked List  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Adobe · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/odd-even-linked-list/)
- [GFG](https://www.geeksforgeeks.org/odd-even-linked-list/)

## Problem

Group all odd-indexed nodes, then all even-indexed nodes. Index starts at 1 for the head. Relative order inside each group stays the same. Do it in O(1) extra space.

1 -> 2 -> 3 -> 4 -> 5 becomes 1 -> 3 -> 5 -> 2 -> 4.

Two arrays of nodes, then concat. Recursion can rewire odd/even. Iteration keeps odd and even tails and stitches evenHead at the end of odds.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Push odd-position nodes, then even-position nodes, into arrays. Relink in that order. Extra arrays.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Recursive rewire: odd.next = even.next, even.next = that node's next, then recurse. Attach evenHead when even runs out. Stack O(n).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

odd and even pointers. odd.next = odd.next.next, even.next = even.next.next, until even is exhausted. odd.next = evenHead. In-place, constant extra space.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
