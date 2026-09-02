# Contains Duplicate

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Amazon · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/contains-duplicate/)
- [GFG](https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/)

## Problem

Return true if any value appears at least twice, otherwise false.

Example: [1, 2, 3, 1] is true. [1, 2, 3, 4] is false.

Nested loops compare every pair. Sorting puts equals next to each other. A Set tells you in one pass whether a value was already seen.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

Each pair is compared. Fine for tiny lists, too slow for large n.
How it works: if nums[i] equals nums[j] for j > i, a duplicate exists.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(n)

Copy then sort, then a linear neighbor check. Sorting dominates.
How it works: equals become neighbors after sort. If two neighbors match, return true.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

One pass. Set.has is average O(1).
How it works: if the set already has the number, it is a duplicate. Otherwise add it.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
