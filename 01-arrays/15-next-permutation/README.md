# Next Permutation

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Google · Meta · Amazon · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/next-permutation/)
- [GFG](https://www.geeksforgeeks.org/problems/next-permutation5226/1)

## Problem

Rearrange nums into the next larger permutation in lexicographic order. If it is already the last permutation, wrap to the smallest (sorted ascending). Modify the array in place.

Example: [1, 2, 3] -> [1, 3, 2]. Example: [3, 2, 1] -> [1, 2, 3].

Generating every permutation, sorting them, and picking the next is complete and huge. Finding the pivot then sorting the suffix is better. Finding the pivot, swapping with the next larger suffix value, and reversing the suffix is linear.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n! · n)
- **Space:** O(n! · n)

All unique permutations are generated and stored. n! grows immediately out of interview time limits.
How it works: backtracking builds every perm. Sort the bag lexicographically. Find the current sequence and copy the next one (or the first) back into nums.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(1)

One reverse scan for the pivot, then a sort of the suffix. Sort of n items is the extra log factor.
How it works: find the rightmost i with nums[i] < nums[i+1]. Find the smallest value to the right that is still larger than nums[i], swap, then sort the suffix ascending.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

The suffix is already non-increasing, so reverse is enough instead of sort.
How it works: same pivot and swap. Reverse nums[i+1 .. end] in place.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
