# Combination Sum

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Amazon · Google · Apple · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/combination-sum/)
- [GFG](https://www.geeksforgeeks.org/problems/combination-sum-1587115620/1)

## Problem

candidates holds distinct positive integers. You may reuse a number as often as you like. Return how many combinations (order does not matter) add to target. Listing the actual bags is the same backtrack with a path array; interviews that ask for the list want that brute tree. The DP counts the bags.

Tiny example: candidates = [1, 2, 3], target = 4. Combinations: [1,1,1,1], [1,1,2], [2,2], [1,3]. Answer 4. (If order counted, [1,3] and [3,1] would both score; that is Combination Sum IV, and you would loop the sum outer.)

Brute walks from a start index so [1,2] and [2,1] are the same bag. Memo caches (start, remain). The 1D row loops coins in the outer loop so each combination is counted once.

Open the Brute, Optimal, and More optimal tabs for unlimited-reuse backtracking, memoized counts, and the unbounded knapsack ways row.

## Methods of solving

### 1. Brute

- **Time:** O(n^{target/min})
- **Space:** O(target / min)

From start you may reuse candidates[i] (call go(i, remain - value)) or move on. Order is frozen by the index, so combinations are unique. No cache; the tree size tracks how you can pile the smallest coin. Depth is about target / min(candidates).

### 2. Optimal

- **Time:** O(n * target)
- **Space:** O(n * target)

Each pair (start index, remaining target) is solved once. Work per state is a loop over the leftover candidates. Map size is O(n * target). Same combination semantics as the backtrack.

### 3. More optimal

- **Time:** O(n * target)
- **Space:** O(target)

Unbounded knapsack ways. Outer loop is the coin, inner loop walks sums upward so that coin may be reused. That order counts combinations, not permutations. One row of size target+1. If you swapped the loops, you would count ordered sequences instead.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
