# Task Scheduler

**Topic:** Stack, Queue & Heap  
**Level:** intermediate  
**Asked at:** Amazon · Google · Uber · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/task-scheduler/)
- [GFG](https://www.geeksforgeeks.org/task-scheduler/)

## Problem

tasks is a list of CPU tasks (letters). The same letter needs n idle slots between runs. Return the least time units to finish every task. One task or one idle per unit.

Example: tasks [A,A,A,B,B,B], n = 2 answers 8: A B idle A B idle A B.

Brute backtracks every choice. Optimal simulates with a max-heap plus a cooldown queue. More optimal is the formula (maxFreq-1)*(n+1) + howManyHaveMaxFreq, then max with tasks.length.

## Methods of solving

### 1. Brute

- **Time:** O(k^t)
- **Space:** O(k)

At each time slot, try every task type that still has remaining count and is off cooldown. Exponential in the number of tasks. Only for teaching.

### 2. Optimal

- **Time:** O(t log k)
- **Space:** O(k)

Max-heap of remaining counts (26 letters). Each round pop one, then park it in a cooldown queue for n+1 time. Idle when the heap is empty but cooldown is not. k is at most 26.

### 3. More optimal

- **Time:** O(t)
- **Space:** O(1)

The busy skeleton is (maxFreq-1) groups of (n+1) slots, plus the tasks that share maxFreq. If that is shorter than tasks.length, there is no idle and the answer is tasks.length. O(t) count, O(1) extra.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
