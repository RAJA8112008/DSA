# Unique Binary Search Trees II

**Topic:** BST  
**Level:** advanced  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/unique-binary-search-trees-ii/)
- [GFG](https://www.geeksforgeeks.org/construct-all-possible-bsts-for-keys-1-to-n/)

## Problem

Return every structurally different BST that stores 1..n, not just the count.

Pick each value as root, generate all left trees on the smaller keys and all right trees on the larger keys, then attach every pair.

Brute inserts every permutation and keeps unique shapes. Optimal is divide-and-conquer on [lo, hi]. More optimal memos each [lo, hi] so shared ranges are built once.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n · n!)
- **Space:** O(n · n!)

Generate every permutation of 1..n, insert into a BST, serialize the shape, keep one copy per unique serialization. Correct but factorial.

### 2. Optimal

- **Time:** O(C(n) · n)
- **Space:** O(C(n) · n)

For each root i in [lo, hi], cartesian product of left trees and right trees. Empty range yields a single null tree so a missing child is represented once.

### 3. More optimal

- **Time:** O(C(n) · n)
- **Space:** O(C(n) · n)

Memoize [lo, hi]. Shared ranges (for example all trees on 3,4,5) are built once. Catalan many trees still must be allocated.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
