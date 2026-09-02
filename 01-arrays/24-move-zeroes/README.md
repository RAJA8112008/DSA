# Move Zeroes

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Meta · Amazon · Apple · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/move-zeroes/)
- [GFG](https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1)

## Problem

Move all zeros to the end. Keep the relative order of the non-zero numbers. Modify the list in place.

Example: [0, 1, 0, 3, 12] -> [1, 3, 12, 0, 0].

Bubbling each zero right is quadratic. Building a new list of non-zeros then padding zeros is linear with extra memory. A write pointer copies non-zeros forward, then fills the tail with zeros.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

Each zero may be swapped toward the end across many cells. Worst case quadratic.
How it works: when you see a zero, swap it right until a non-zero neighbor is found or you hit the end. Slow, but in place.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Extra array holds the compacted values, then you copy back.
How it works: collect non-zeros, append zeros until length n, copy into nums.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

One write index, two linear passes, no extra list.
How it works: copy each non-zero to write and increment write. Then fill nums[write..] with 0.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
