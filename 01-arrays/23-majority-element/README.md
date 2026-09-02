# Majority Element

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Google · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/majority-element/)
- [GFG](https://www.geeksforgeeks.org/problems/majority-element-1587115620/1)

## Problem

The majority element appears more than n/2 times. You may assume it always exists.

Example: [3, 2, 3] -> 3. Example: [2, 2, 1, 1, 1, 2, 2] -> 2.

Count each value with a nested scan. A map counts in one pass. Boyer–Moore keeps a candidate and a vote: the majority survives because it appears more than everyone else combined.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

For each candidate you count how many times it appears. Quadratic comparisons.
How it works: if a value’s count is > n/2, return it.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

One pass over the list, extra map of distinct values.
How it works: increment counts. As soon as a count exceeds n/2, return that key.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Boyer–Moore: two integers, one pass. Because a majority exists, the last candidate is it.
How it works: vote for the current candidate. Matching values add a vote; others subtract. At 0, pick a new candidate.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
