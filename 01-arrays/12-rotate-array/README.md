# Rotate Array

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/rotate-array/)
- [GFG](https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1)

## Problem

Rotate nums to the right by k steps. k can be larger than n; use k % n.

Example: [1, 2, 3, 4, 5, 6, 7], k = 3 -> [5, 6, 7, 1, 2, 3, 4].

Rotating by one, k times, is easy and slow. An extra array placed at (i + k) % n is linear. Three reverses (whole list, then each half) do it in place.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n·k)
- **Space:** O(1)

Each single rotate copies n items. Doing that k times (after k %= n, still up to n-1 times) is O(n²) in the worst case.
How it works: save the last item, shift everyone right by one, put the saved item at index 0. Repeat k times.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

One extra array of length n, two linear copies.
How it works: extra[(i + k) % n] = nums[i], then copy extra back into nums.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Each item is swapped a constant number of times. No extra list.
How it works: reverse the whole array, reverse the first k items, reverse the rest. That is the right rotation.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
