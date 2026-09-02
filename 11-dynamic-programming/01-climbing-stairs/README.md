# Climbing Stairs

**Topic:** Dynamic Programming  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/climbing-stairs/)
- [GFG](https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1)

## Problem

You start on stair 0. From any stair you may climb 1 step or 2 steps. Return how many distinct ordered paths reach stair n.

Tiny example: n = 3. The paths are 1+1+1, 1+2, and 2+1. Answer 3. (2+1 and 1+2 are different orders, so both count.)

The last move is a 1 from n-1 or a 2 from n-2, so ways(n) = ways(n-1) + ways(n-2), with ways(1) = 1 and ways(2) = 2. That is Fibonacci shifted by one.

Open the Brute, Optimal, and More optimal tabs for the raw recursion tree, a memo notebook, and two rolling numbers.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

Each stair branches into two calls. The same k is solved again and again, so the tree is exponential. Space is the recursion depth n.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Memo stores each k once. After the first fill, go(k) is a lookup. You still use O(n) stack plus O(n) memo cells. Same recurrence, no repeated subtrees.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Only the previous two answers are live. a is ways(i-2), b is ways(i-1). Slide them forward n-2 times. Time stays linear; extra memory is two numbers.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
