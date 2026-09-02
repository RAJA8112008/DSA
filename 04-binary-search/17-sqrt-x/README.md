# Sqrt(x)

**Topic:** Binary Search  
**Level:** beginner  
**Asked at:** Amazon · Bloomberg · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/sqrtx/)
- [GFG](https://www.geeksforgeeks.org/problems/square-root/1)

## Problem

Return the integer square root of a non-negative x: the largest integer r such that r * r <= x. Do not use a library sqrt if they forbid it.

Tiny example: 4 -> 2. 8 -> 2 because 2*2 = 4 and 3*3 = 9 > 8. 0 -> 0. 1 -> 1.

Linear try of 0, 1, 2, ... works. Binary search on r in [0, x] (or [1, x/2 + 1]) is O(log x). Newton's method usually needs fewer iterations.

Open Brute, Optimal, and More optimal for incrementing r, binary search, and integer Newton.

## Methods of solving

### 1. Brute

- **Time:** O(sqrt(x))
- **Space:** O(1)

Increase r while (r+1)*(r+1) still fits in x. Use 64-bit (or a division check) so r*r does not overflow 32-bit int.

### 2. Optimal

- **Time:** O(log x)
- **Space:** O(1)

Last-true search: mid is good when mid <= x / mid (avoids mid*mid overflow). If good, try a larger r. If not, shrink high. x in {0,1} returns x.

### 3. More optimal

- **Time:** O(log x)
- **Space:** O(1)

Integer Newton: r = (r + x/r) / 2 until r <= x/r. Overflow-safe. Usually fewer loops than binary search. Still exact for the floor sqrt.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
