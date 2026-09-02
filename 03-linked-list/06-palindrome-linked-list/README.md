# Palindrome Linked List

**Topic:** Linked List  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Apple · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/palindrome-linked-list/)
- [GFG](https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1)

## Problem

Return true if the list reads the same forward and backward.

1 -> 2 -> 2 -> 1 is a palindrome. 1 -> 2 is not. Values compare; you may reverse half of the list in place if you restore or the caller allows mutation.

Copy values to an array and two-pointer check. Recursion compares the front on the way back. The linear extra-space-free way: find mid, reverse the second half, compare, optionally restore.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Dump values into an array. Check index i against length-1-i. Extra memory is the array.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Recurse to the tail. A shared front pointer walks forward as the stack walks back. First mismatch fails. Stack is O(n).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Slow/fast to the mid, reverse the second half, compare first half with reversed half. Only a few pointers. Mutates the list; reverse again if you must restore.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
