# Subarray Sum Equals K

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Meta · Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/subarray-sum-equals-k/)
- [GFG](https://www.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1)

## Problem

Count how many contiguous subarrays sum to k. Numbers may be negative, so a simple “shrink when too big” window is not enough.

Example: nums = [1, 1, 1], k = 2 -> 2 subarrays.

All subarrays can be summed in O(n²). A prefix array plus a map of earlier prefixes is two passes. Combining them into one pass is the usual interview code: if prefix - k was seen c times, add c.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

Every start and end pair is summed. Fine to explain, too slow for large n.
How it works: i is start, running sum grows with j. Each time the sum equals k, add 1 to the count.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Build all prefixes, then query a map. Two linear passes, O(n) extra.
How it works: prefix[i] is sum of the first i numbers. For each end i, the number of starts with prefix[i] - prefix[start] = k is how often prefix[i] - k already appeared.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Same map idea without a prefix array. One running sum.
How it works: start the map with 0 seen once (empty prefix). After adding nums[i], add the frequency of sum - k, then record this sum.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
