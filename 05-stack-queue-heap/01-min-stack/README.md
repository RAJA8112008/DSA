# Min Stack

**Topic:** Stack, Queue & Heap  
**Level:** beginner  
**Asked at:** Amazon · Google · Bloomberg · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/min-stack/)
- [GFG](https://www.geeksforgeeks.org/problems/get-min-at-pop/1)

## Problem

Design a stack that supports push, pop, top, and getMin in O(1) time. getMin returns the smallest value still in the stack.

Example: push 3, push 5, getMin is 3, push 2, getMin is 2, pop, getMin is 3 again.

Brute scans on every getMin. Optimal keeps a second stack of mins. More optimal stores [value, minSoFar] pairs on one stack.

## Methods of solving

### 1. Brute

- **Time:** O(n) getMin
- **Space:** O(n)

A plain array. getMin walks every item. Correct, but the interview asks for O(1) getMin.

### 2. Optimal

- **Time:** O(1)
- **Space:** O(n)

mins tracks the current minimum. Push val onto mins if it is <= current min. Pop mins when the popped value equals mins top. Duplicate mins matter: use <= so two equal mins both sit on mins.

### 3. More optimal

- **Time:** O(1)
- **Space:** O(n)

One stack of pairs [val, minSoFar]. Each node already knows the min of the prefix. Slightly more memory per item, one structure to talk through. Still O(1) everything.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
