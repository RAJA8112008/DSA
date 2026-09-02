# Remove Duplicates from Sorted List

**Topic:** Linked List  
**Level:** beginner  
**Asked at:** Amazon · Apple · Adobe · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
- [GFG](https://www.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1)

## Problem

The list is sorted. Delete extra nodes so each number appears once. Keep the first copy of each value.

1 -> 1 -> 2 -> 3 -> 3 becomes 1 -> 2 -> 3. An already-unique list does not change.

Collect unique values into an array and rebuild. Recursion skips a next that matches head.val. Iteration: while cur.next exists and equals cur.val, jump cur.next.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Walk and push a value only when it differs from the last kept one, then rebuild. Extra array of uniques.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Recurse on head.next first. If the next node has the same val, skip it. Stack is O(n).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

One pointer. While the next node duplicates, skip it. Then advance. In-place, constant extra space.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
