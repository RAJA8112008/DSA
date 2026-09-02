# Container With Most Water

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/container-with-most-water/)
- [GFG](https://www.geeksforgeeks.org/problems/container-with-most-water0535/1)

## Problem

Bars stand at indexes 0..n-1. The water between i and j is min(height[i], height[j]) * (j - i). Return the largest area.

Example: [1, 8, 6, 2, 5, 4, 8, 3, 7] -> 49, between the 8 at index 1 and the 7 at index 8.

All pairs work. Two pointers start at the ends: the short bar cannot beat a wider pair, so you move that side. A small extra skip jumps over bars that are no taller than the current limiting height.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

Every pair of bars is an area. Quadratic checks.
How it works: i is the left wall, j the right wall. Area is min height times width. Keep the max.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(1)

Each step moves one pointer, so at most n-1 steps.
How it works: start at both ends. Record the area. Move the shorter wall inward. A taller inner wall might win; a shorter width with the same short wall cannot.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Still O(n) worst case, but bars no taller than the current min height are skipped, so fewer area multiplies on flat stretches.
How it works: after recording the area for height h, advance left while height[left] <= h and right while height[right] <= h.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
