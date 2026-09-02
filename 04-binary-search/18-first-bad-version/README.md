# First Bad Version

**Topic:** Binary Search  
**Level:** beginner  
**Asked at:** Google · Facebook · Amazon · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/first-bad-version/)
- [GFG](https://www.geeksforgeeks.org/problems/first-bad-version/1)

## Problem

Versions 1..n. There is a first bad version f. Every version >= f is bad. You may only call isBadVersion(v). Return f. Minimize API calls.

Tiny example: n = 5, first bad = 4. Calls on 1,2,3 are false, 4 and 5 are true, so answer 4. n = 1 is always 1 if it is bad.

Linear check from 1 is too many calls. Binary search first-true: if mid is bad, the first bad is at mid or left; if mid is good, it is strictly right.

Open Brute, Optimal, and More optimal for a scan, an ans-variable binary search, and the half-open overflow-safe loop that returns lo.

## Methods of solving

### 1. Brute

- **Time:** O(n) calls
- **Space:** O(1)

Ask isBadVersion from 1 upward. First true is the answer. Correct, burns the API on large n.

### 2. Optimal

- **Time:** O(log n) calls
- **Space:** O(1)

Classic first-true. When mid is bad, store it and search left. When mid is good, search right. About log2(n) API calls.

### 3. More optimal

- **Time:** O(log n) calls
- **Space:** O(1)

Overflow-safe mid is required in Java: (lo+hi)/2 wraps when n is 2^31-1. Half-open while (lo < hi): bad means hi = mid, good means lo = mid + 1. Return lo. Same call count, no extra ans, no overflow.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
