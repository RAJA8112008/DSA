# Find the Duplicate Number

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google

## Practice

- [LeetCode](https://leetcode.com/problems/find-the-duplicate-number/)
- [GFG](https://www.geeksforgeeks.org/problems/find-duplicates-in-an-array/1)

## Problem

nums has n + 1 integers, each between 1 and n. Exactly one number is repeated (it may appear more than twice). Return that number. Do not change the input in the interview-strict version.

Example: [1, 3, 4, 2, 2] -> 2.

Nested search finds a value that appears twice. A sorted copy makes duplicates neighbors. Treating indexes as a linked list (value as next pointer) and using Floyd’s cycle meeting point finds the duplicate in linear time and constant extra space.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

For each index you scan the rest of the list looking for the same value.
How it works: if nums[j] === nums[i] for j > i, that value is the duplicate.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(n)

Copy and sort, then scan neighbors. Sorting dominates. Extra memory is the copy (input stays unchanged).
How it works: after sort, the repeated number sits next to itself.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Floyd cycle detection. Values in 1..n act as next pointers, so a duplicate creates a cycle. No extra array, input not written.
How it works: slow moves one hop, fast moves two, until they meet. Reset slow to the start; the next meeting is the cycle entrance, which is the duplicate.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
