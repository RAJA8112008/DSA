# Find Median from Data Stream

**Topic:** Stack, Queue & Heap  
**Level:** advanced  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/find-median-from-data-stream/)
- [GFG](https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1)

## Problem

MedianFinder: addNum inserts a number. findMedian returns the median of all numbers so far. Even count: average of the two middle values.

Example: add 1, add 2, median 1.5, add 3, median 2.

Brute stores and sorts every query. Optimal inserts into a sorted array. More optimal is two heaps: max-heap lower half, min-heap upper half.

## Methods of solving

### 1. Brute

- **Time:** O(n log n) find
- **Space:** O(n)

Keep every number. findMedian copies and sorts. addNum is O(1). Queries get slower as the stream grows.

### 2. Optimal

- **Time:** O(n) add, O(1) find
- **Space:** O(n)

Keep a sorted array. Binary search the insert index, then splice. findMedian is O(1). Better than sorting everything on each query.

### 3. More optimal

- **Time:** O(log n) add, O(1) find
- **Space:** O(n)

low is a max-heap (negated in a min-heap). high is a min-heap. Balance sizes. Median is low's top, or the average of both tops. True stream solution.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
