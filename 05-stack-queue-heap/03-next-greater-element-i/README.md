# Next Greater Element I

**Topic:** Stack, Queue & Heap  
**Level:** beginner  
**Asked at:** Amazon · Google · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/next-greater-element-i/)
- [GFG](https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1)

## Problem

nums1 is a subset of nums2. For each value in nums1, find that value in nums2 and return the first greater number to its right in nums2. -1 if none.

Example: nums1 = [4,1,2], nums2 = [1,3,4,2] answers [-1,3,-1].

Brute finds then scans right. Optimal is a hash of indices plus a scan. More optimal builds a next-greater map with a monotonic stack on nums2, then maps nums1 in O(1) each.

## Methods of solving

### 1. Brute

- **Time:** O(n · m)
- **Space:** O(1)

For each nums1 value, scan nums2 to find it, then scan the suffix for a greater number. Fine when both arrays are tiny.

### 2. Optimal

- **Time:** O(n · m)
- **Space:** O(m)

Hash each nums2 value to its index so the find step is O(1). The right scan is still O(m) per query. Clearer, same worst case.

### 3. More optimal

- **Time:** O(n + m)
- **Space:** O(m)

Monotonic stack on nums2 builds next[value] = first greater to the right. Then each nums1 lookup is O(1). Linear in the two array lengths.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
