# Swap Nodes in Pairs

**Topic:** Linked List  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Uber · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/swap-nodes-in-pairs/)
- [GFG](https://www.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1)

## Problem

Swap every two adjacent nodes. Swap the nodes, not only their values. If a last node has no pair, leave it.

1 -> 2 -> 3 -> 4 becomes 2 -> 1 -> 4 -> 3. 1 -> 2 -> 3 becomes 2 -> 1 -> 3.

Array of nodes, swap indexes 0-1, 2-3, relink. Recursion swaps the first pair then attaches swapPairs of the rest. Iteration uses a dummy and rewires two nodes at a time.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Collect nodes, swap each pair of indexes, relink in that order. Extra array.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

If fewer than two nodes, return head. Else first = head, second = head.next, first.next = swapPairs(second.next), second.next = first, return second. Stack O(n/2).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Dummy before head. prev, a, b: prev.next = b, a.next = b.next, b.next = a, then prev = a. Iterative, constant extra space.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
