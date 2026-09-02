# Plus One

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Google · Amazon · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/plus-one/)
- [GFG](https://www.geeksforgeeks.org/plus-one/)

## Problem

digits is a non-negative integer, most significant digit first, no leading zeros. Add one and return the new digit array.

Example: [1, 2, 3] becomes [1, 2, 4]. [9, 9] becomes [1, 0, 0].

Brute joins into a big number (breaks on overflow in fixed ints). Optimal walks from the right with carry into a new array. More optimal edits in place and only allocates if every digit was 9.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Build a string / BigInt, add one, split back to digits. Fine in JS/Python, illegal in Java int, and not the interview idea.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Copy into a new array. From the last index, add 1 and propagate carry. If carry remains, allocate one extra leading 1.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1) extra if no new digit

Walk from the right on the input. A digit < 9 becomes digit+1 and you return immediately. All nines become a new array [1, 0, 0, ...].

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
