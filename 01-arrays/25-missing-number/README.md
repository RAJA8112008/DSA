# Missing Number

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Google · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/missing-number/)
- [GFG](https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1)

## Problem

nums holds n distinct numbers from the range 0..n, except one missing value. Return the missing number.

Example: [3, 0, 1] -> 2.

For each candidate 0..n you can scan the array. Sorting then looking for a gap is faster. Gauss’s sum (or XOR of indexes and values) is one pass and constant extra memory.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

For each candidate you scan the whole list. n+1 candidates times n looks.
How it works: if value x is never found in nums, x is missing.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(n)

Copy and sort, then a linear gap check. Sorting dominates.
How it works: after sort, index i should hold i. The first mismatch is the missing number. If the list is 0..n-1, n is missing.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

XOR cancels pairs. Indexes 0..n XOR all values leaves the missing one. No overflow the way a large sum might in other languages (JS numbers are fine here too).
How it works: start missing = n. XOR i and nums[i] for every i. The leftover is the missing number.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
