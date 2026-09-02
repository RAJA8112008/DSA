# Two Sum II - Input Array Is Sorted

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Amazon · Google · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
- [GFG](https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/)

## Problem

A 1-indexed sorted array. Return the two indexes (1-based) whose values add to target. Exactly one solution. Do not reuse an index.

Example: numbers = [2, 7, 11, 15], target = 9. Answer [1, 2] because 2 + 7 = 9.

Brute tries every pair. Optimal binary-searches the partner of each value. More optimal is two pointers from both ends.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

Outer index i, inner j > i. First pair that sums to target is the answer. Works, ignores the sorted hint.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(1)

For each left value, binary search target - numbers[i] on the right side. Sorted order makes the search legal. Extra log n versus two pointers.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Left at start, right at end. Sum too small: left++. Sum too big: right--. Sorted order guarantees you never miss the pair. Interview finish line.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
