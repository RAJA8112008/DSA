# Linked List Cycle II

**Topic:** Linked List  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/linked-list-cycle-ii/)
- [GFG](https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170685/1)

## Problem

If the list has a cycle, return the node where the cycle begins. If not, return null.

On 3 -> 2 -> 0 -> -4 with the tail linked to 2, the start is the node holding 2. Identity matters: you return that node object, not a copy.

A Set records the first repeat. After Floyd finds a meeting point you can collect the cycle into a set and walk from head. The tight version resets one pointer to head and walks both one step; they meet at the entrance.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Walk from head. The first node already in the Set is the start of the cycle. If you reach null, there is no cycle.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Floyd finds a node inside the cycle. Walk that loop once into a Set. Then walk from head until you hit a node in the set. Extra memory is the cycle length.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

After slow and fast meet, put one pointer at head. Walk both one step at a time. They meet at the cycle start. Proof: distance from head to start equals distance from meet to start around the loop. No extra set.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
