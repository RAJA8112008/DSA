# Top K Frequent Elements

**Topic:** Stack, Queue & Heap  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/top-k-frequent-elements/)
- [GFG](https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1)

## Problem

Return the k numbers that appear most often in nums. Any order is fine.

Example: [1,1,1,2,2,3], k = 2 answers [1,2].

Count first. Brute then strips the current max count k times. Optimal sorts the unique numbers by count. More optimal is a bucket list indexed by count (O(n)), or a heap of size k.

## Methods of solving

### 1. Brute

- **Time:** O(n + u · k)
- **Space:** O(u)

Count in a map. Then k times scan all unique keys for the remaining max count and remove it. u is the number of unique values.

### 2. Optimal

- **Time:** O(n + u log u)
- **Space:** O(u)

Count, then sort unique keys by frequency descending, take k. Clear and fast enough for interview n.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Bucket sort: buckets[i] holds numbers that appear i times. Walk i from n down and collect k numbers. Linear because counts are at most n. A size-k min-heap is O(n log k) if they want a heap instead.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
