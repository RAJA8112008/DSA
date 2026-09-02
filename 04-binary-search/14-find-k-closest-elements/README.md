# Find K Closest Elements

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Google · Facebook · Amazon · LinkedIn

## Practice

- [LeetCode](https://leetcode.com/problems/find-k-closest-elements/)
- [GFG](https://www.geeksforgeeks.org/problems/find-k-closest-elements/1)

## Problem

arr is sorted. Return k values closest to x, in ascending order. Tie: pick the smaller value.

Tiny example: arr = [1, 2, 3, 4, 5], k = 4, x = 3 -> [1, 2, 3, 4]. x = -1 -> [1, 2, 3, 4].

Sorting by distance is easy but O(n log n). Sliding the window from both ends is O(n). Binary searching the left edge of a window of length k is O(log(n - k) + k).

Open Brute, Optimal, and More optimal for sort-by-distance, two pointers, and binary search on the window start.

## Methods of solving

### 1. Brute

- **Time:** O(n log n)
- **Space:** O(n)

Pair each value with its distance, sort by distance then by value, take k items, sort those k again so the answer is ascending. Heavy, but matches the tie rule clearly.

### 2. Optimal

- **Time:** O(n - k)
- **Space:** O(k)

The answer is a contiguous window of length k (the array is sorted). Shrink from both ends until the window is size k. Drop the farther end; on a tie drop the right (larger) value.

### 3. More optimal

- **Time:** O(log(n - k) + k)
- **Space:** O(k)

Binary search the left index of the k-window in [0, n-k]. If x is closer to arr[mid+k] than to arr[mid], the window should start further right. Overflow-safe mid. Copy k values at the end.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
