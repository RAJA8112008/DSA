# Spiral Matrix

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/spiral-matrix/)
- [GFG](https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1)

## Problem

Walk the matrix in spiral order: right, down, left, up, and repeat. Return the values in that order.

Example: [[1, 2, 3], [4, 5, 6], [7, 8, 9]] -> [1, 2, 3, 6, 9, 8, 7, 4, 5].

A visited grid plus four direction vectors is the straightforward walk. Shrinking top/bottom/left/right bounds needs no visited flags. One loop with a direction index can turn at the edge of the remaining box.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(m·n)
- **Space:** O(m·n)

You still visit each cell once, but a boolean grid of the same size is extra memory.
How it works: start at (0,0) facing right. If the next cell is out of bounds or visited, turn right. Push each value.

### 2. Optimal

- **Time:** O(m·n)
- **Space:** O(1)

Output list is required. Extra memory is a few bound integers, treated as O(1).
How it works: peel a layer: walk top row left->right, right col top->bottom, bottom row right->left, left col bottom->top, then shrink the four bounds.

### 3. More optimal

- **Time:** O(m·n)
- **Space:** O(1)

Same bounds idea in one counted loop: visit exactly rows*cols cells, turn when the next step would leave the remaining rectangle.
How it works: after a turn, shrink the bound you just finished (top, right, bottom, or left) so the next lap is the inner layer.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
