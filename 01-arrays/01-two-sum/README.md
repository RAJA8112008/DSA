# Two Sum

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Google · Amazon · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/two-sum/)
- [GFG](https://www.geeksforgeeks.org/problems/key-pair5616/1)

## Problem

Return the indexes of two numbers that add up to target. Each index is used at most once.

Example: nums = [2, 7, 11, 15], target = 9. Indexes 0 and 1 work because 2 + 7 = 9.

Trying every pair is correct and slow. Sorting with original indexes lets two pointers meet in the middle. A map of value -> index finds the partner while you walk once.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

Every pair is checked. For n numbers that is about n*(n-1)/2 additions.
How it works: the outer loop picks the first index. The inner loop picks a later index. The first pair whose sum equals target is returned.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(n)

Sorting is the extra cost. After that, two pointers only walk the copied list once.
How it works: store {value, index} so sorting does not lose positions. Move left up when the sum is too small, right down when it is too big.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

One pass. Each lookup in the map is average O(1), so the whole walk is O(n).
How it works: for x, look up target - x. If it was stored, return those indexes. If not, store x and its index, then continue.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
