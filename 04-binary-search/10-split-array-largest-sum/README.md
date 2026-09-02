# Split Array Largest Sum

**Topic:** Binary Search  
**Level:** advanced  
**Asked at:** Google · Amazon · Facebook · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/split-array-largest-sum/)
- [GFG](https://www.geeksforgeeks.org/problems/split-array-largest-sum/1)

## Problem

Split nums into k non-empty contiguous subarrays. Minimize the largest subarray sum among those pieces.

Tiny example: nums = [7, 2, 5, 10, 8], k = 2. Best split is [7, 2, 5] and [10, 8], largest sum 18.

Brute tries every cut. DP stores the best largest-sum for prefixes. The interview finish line is binary search on the largest sum, same shape as ship-packages: lo = max(nums), hi = sum, and a greedy count of how many pieces a limit needs.

Open Brute, Optimal, and More optimal for recursion, the DP table, and answer-space binary search.

## Methods of solving

### 1. Brute

- **Time:** O(n^{k-1})
- **Space:** O(n)

Recurse on the start index and how many pieces are left. Try every next cut. Exponential in k. Good for explaining the search tree, not for n = 1000.

### 2. Optimal

- **Time:** O(n^2 k)
- **Space:** O(n k)

dp[i][p] = min largest-sum using the first i numbers and p subarrays. Transition: last piece is nums[j..i-1], cost = max(dp[j][p-1], prefix[i]-prefix[j]). Polynomial, still slower than binary search for interview n.

### 3. More optimal

- **Time:** O(n log sum)
- **Space:** O(1)

Binary search the largest allowed piece sum. Greedy: grow a run until the next number would exceed mid, then start a new piece. If you need more than k pieces, mid is too small. This is the usual interview solution.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
