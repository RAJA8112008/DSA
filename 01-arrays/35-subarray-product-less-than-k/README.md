# Subarray Product Less Than K

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Google · Bloomberg

## Practice

- [LeetCode](https://leetcode.com/problems/subarray-product-less-than-k/)
- [GFG](https://www.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1)

## Problem

Count contiguous subarrays whose product is strictly less than k. nums[i] >= 1.

Example: nums = [10, 5, 2, 6], k = 100. Answer 8: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6].

Brute multiplies every subarray. Optimal nested loops that break when the running product hits k. More optimal is a sliding window: all-positive so you only shrink from the left.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

For each L, grow R, multiply. Count when prod < k. Watch overflow in fixed-width ints; JS numbers are fine for the usual constraints.

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(1)

Same nested loops, but this is already the best brute because products only grow (nums >= 1) so you can break. Still quadratic worst case when k is huge.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Window [left, right]. Multiply nums[right]. While product >= k, divide nums[left] and left++. Every new right adds (right-left+1) subarrays that end at right. If k <= 1 the answer is 0.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
