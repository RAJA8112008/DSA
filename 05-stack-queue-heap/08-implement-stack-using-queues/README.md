# Implement Stack using Queues

**Topic:** Stack, Queue & Heap  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/implement-stack-using-queues/)
- [GFG](https://www.geeksforgeeks.org/problems/stack-using-two-queues/1)

## Problem

Build a stack (LIFO) using only queues (FIFO). Support push, pop, top, empty.

Example: push 1, push 2, top is 2, pop is 2.

Brute uses two queues and dumps n-1 items to the other queue on pop. Optimal uses one queue and rotates on push so the front is always the top. More optimal rotates on pop instead, so push stays O(1).

## Methods of solving

### 1. Brute

- **Time:** O(n) pop
- **Space:** O(n)

Two queues. pop moves all but the last item to the other queue, then swaps names. Push is O(1). Pop is O(n).

### 2. Optimal

- **Time:** O(n) push, O(1) pop
- **Space:** O(n)

One queue. After push, rotate length-1 items so the new item sits at the front. pop/top/empty are then O(1).

### 3. More optimal

- **Time:** O(1) push, O(n) pop
- **Space:** O(n)

One queue, no rotate on push. pop rotates n-1 items then shifts. Prefer this when pushes are common and pops are rare. Same extra space.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
