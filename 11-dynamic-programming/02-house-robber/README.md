# House Robber

**Topic:** Dynamic Programming  
**Level:** beginner  
**Asked at:** Amazon · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/house-robber/)
- [GFG](https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1)

## Problem

Houses sit in a line. nums[i] is the money in house i. You may not rob two adjacent houses. Return the maximum total.

Tiny example: [1, 2, 3, 1]. Taking 1 and 3 (indexes 0 and 2) gives 4. Taking 2 and 1 (indexes 1 and 3) gives 3. Answer 4.

At index i the choice is take nums[i] and jump to i+2, or skip and go to i+1. The answer is the max of those two.

Open the Brute, Optimal, and More optimal tabs for recursion, a 1D table, and two running totals.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

Every house branches into take or skip with no cache, so the tree is exponential. The stack is one frame per house along a path.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

best[i] is the best total using the first i houses. Each i is filled from i-1 and i-2 in constant time. n states, linear time and linear extra memory.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Only skip (best without the previous house as a take-chain) and take (best that used the previous house) are live. One pass updates both. Same linear scan, constant extra memory.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
