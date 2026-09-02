# 3Sum

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Meta · Google · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/3sum/)
- [GFG](https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1)

## Problem

Find all unique triplets that add to 0. Order inside a triplet does not matter. Duplicate triplets must not appear twice.

Example: [-1, 0, 1, 2, -1, -4] -> [[-1, -1, 2], [-1, 0, 1]].

Three nested loops plus a uniqueness set work. Two loops plus binary search drop one n. Sort, lock the first number, then two pointers on the rest is the usual O(n²) finish.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n³)
- **Space:** O(k)

Every triple of indexes is summed. Uniqueness is handled by a sorted-key set. k is the number of triplets stored.
How it works: i < j < l. If the three numbers sum to 0, sort them and keep the key in a Set so duplicates are dropped.

### 2. Optimal

- **Time:** O(n² log n)
- **Space:** O(n)

Sort once. For each pair, binary-search the third value. Each search is log n, and there are n² pairs.
How it works: after sort, for i and j look for -(nums[i]+nums[j]) in the suffix. Skip used indexes. A set of keys still blocks duplicate triplets.

### 3. More optimal

- **Time:** O(n²)
- **Space:** O(k)

Sort plus two pointers is the standard bound. Extra memory is only the output (and the sort copy).
How it works: skip duplicate first numbers. For each i, left = i+1, right = end. Move left/right by comparing the sum to 0, and skip duplicate left/right values after a hit.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
