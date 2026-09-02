# Rotate List

**Topic:** Linked List  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Adobe · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/rotate-list/)
- [GFG](https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1)

## Problem

Rotate the list to the right by k places. k may be larger than the length, so use k modulo n.

1 -> 2 -> 3 -> 4 -> 5 and k = 2 becomes 4 -> 5 -> 1 -> 2 -> 3. k = 0 leaves the list unchanged.

Array rotate then rebuild. Recursion is a weak fit; two-pass length plus cut is cleaner. Best: make a ring, walk n - k % n steps from the old head, break the ring.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Copy values, rotate the array with splice/concat or new indexes, rebuild. Extra array.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Recursive helper finds length and the tail, then a second walk cuts at n-k. Stack for the first walk is O(n). Same idea as counting, with recursion instead of a loop for length.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Find tail and n in one walk, close the ring, walk n - k % n steps from head, cut. Constant extra space, one extra pass after the count.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
