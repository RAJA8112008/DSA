# Maximum Subarray (Kadane)

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/maximum-subarray/)
- [GFG](https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1)

## Problem

Return the largest sum of any contiguous subarray. The subarray must be non-empty.

Example: [-2, 1, -3, 4, -1, 2, 1, -5, 4] -> 6 from [4, -1, 2, 1].

All subarrays can be summed with an inner running total. A DP array stores the best sum ending at each index. Kadane keeps only the previous ending-sum, so the extra array goes away.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

Every start index pairs with every end index. Inner additions make this quadratic.
How it works: i is the start. sum grows as j walks right. best tracks the largest sum seen, including all-negative lists.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Linear time with a DP array of length n.
How it works: dp[i] is the best sum among subarrays that end at i. It is either nums[i] alone or dp[i - 1] + nums[i]. The answer is the max of dp.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Kadane: only the previous ending-sum is needed, so extra memory is constant.
How it works: endingHere is dp[i] without the array. best is the global max. Start both from nums[0] so all-negative input still works.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
