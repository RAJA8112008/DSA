# Reverse Nodes in k-Group

**Topic:** Linked List  
**Level:** advanced  
**Asked at:** Amazon · Microsoft · Google · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/reverse-nodes-in-k-group/)
- [GFG](https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1)

## Problem

Reverse nodes in groups of k. If the last chunk has fewer than k nodes, leave it as is. Reverse the nodes themselves, not only the values.

1 -> 2 -> 3 -> 4 -> 5 with k = 2 becomes 2 -> 1 -> 4 -> 3 -> 5. With k = 3 it becomes 3 -> 2 -> 1 -> 4 -> 5.

Array reverse of each full window is the brute. Recursion reverses the first k then attaches reverseKGroup of the rest. Iteration walks group by group with a dummy.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Copy values, reverse each complete window of k in the array, rebuild a new list. Extra array and new nodes.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n/k)

If fewer than k nodes remain, return head. Else reverse the first k, then set the old head's next to reverseKGroup of the leftover. Recursion depth is number of groups.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Dummy before head. For each group, reverse k nodes between groupPrev and groupNext, then slide groupPrev. No recursion. Constant extra pointers.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
