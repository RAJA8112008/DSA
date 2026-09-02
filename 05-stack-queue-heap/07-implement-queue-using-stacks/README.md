# Implement Queue using Stacks

**Topic:** Stack, Queue & Heap  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/implement-queue-using-stacks/)
- [GFG](https://www.geeksforgeeks.org/problems/queue-using-two-stacks/1)

## Problem

Build a queue (FIFO) using only stacks (LIFO). Support push, pop, peek, empty.

Example: push 1, push 2, peek is 1, pop is 1, empty is false.

Brute moves every item to a temp stack and back on each pop. Optimal uses an in-stack and an out-stack and pours only when out is empty (amortized O(1)). More optimal is the same pour, with peek reusing out-stack so you do not pour twice.

## Methods of solving

### 1. Brute

- **Time:** O(n) pop/peek
- **Space:** O(n)

On pop, pour all into temp (that reverses), pop, pour back. Every call is O(n). Easy to see FIFO, slow.

### 2. Optimal

- **Time:** O(1) amortized
- **Space:** O(n)

push always goes to inSt. pop/peek pour inSt into outSt only when outSt is empty. Each item moves at most twice.

### 3. More optimal

- **Time:** O(1) amortized
- **Space:** O(n)

Same two stacks. pop is written as peek plus a pop so pour lives in one place. Interviewers like this factoring; complexity matches Optimal.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
