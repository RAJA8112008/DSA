# Capacity To Ship Packages Within D Days

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Amazon · Facebook · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)
- [GFG](https://www.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1)

## Problem

Packages must ship in order. Each day you load a contiguous prefix that still fits in capacity cap. Return the smallest cap that finishes in days days.

Tiny example: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5 -> 15. Cap cannot be smaller than the heaviest package.

Same monotone search as Koko: lo = max(weight), hi = sum(weights). can(cap) counts how many days that cap needs.

Open Brute, Optimal, and More optimal for trying every cap, binary search, and early fail when the day count already exceeds D.

## Methods of solving

### 1. Brute

- **Time:** O(sum * n)
- **Space:** O(1)

Try every capacity from the heaviest box up to the total sum. First success is the answer. Sum can be huge, so this is only the idea sketch.

### 2. Optimal

- **Time:** O(n log sum)
- **Space:** O(1)

Binary search capacity. Greedy load until the next package would overflow, then start a new day. If that day count is <= D, try a smaller cap.

### 3. More optimal

- **Time:** O(n log sum)
- **Space:** O(1)

Overflow-safe mid. Stop counting days as soon as d exceeds the limit. Same answer, fewer wasted additions on a capacity that is clearly too small.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
