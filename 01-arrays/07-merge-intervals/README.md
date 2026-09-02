# Merge Intervals

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Google · Meta · Amazon · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/merge-intervals/)
- [GFG](https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1)

## Problem

Given intervals [start, end], merge every overlapping pair. Touching ends merge too: [1, 2] and [2, 3] become [1, 3].

Example: [[1, 3], [2, 6], [8, 10], [15, 18]] -> [[1, 6], [8, 10], [15, 18]].

You can keep scanning the list and glue overlaps until nothing changes. Sorting by start makes overlaps neighbors, then one walk finishes the job. The last version does that walk into a result list after an in-place sort of a copy.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Each merge pass can scan all remaining pairs. Several passes still stay quadratic for typical n.
How it works: copy intervals. While any two overlap, replace them with their union and restart the pair scan.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(n)

Sort by start, then one linear merge. Sorting is the bottleneck.
How it works: after sort, only the last merged interval can overlap the next one. Stretch its end or push a new block.

### 3. More optimal

- **Time:** O(n log n)
- **Space:** O(n)

Same O(n log n) bound: you must sort unless the input is already ordered. This version sorts a copy once and writes merged ranges without extra pass flags.
How it works: identical merge walk, with an early return for an empty list and copies so caller intervals stay untouched.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
