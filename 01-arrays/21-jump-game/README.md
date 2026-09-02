# Jump Game

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/jump-game/)
- [GFG](https://www.geeksforgeeks.org/problems/jump-game/1)

## Problem

Each nums[i] is the max jump length from index i. Return true if you can reach the last index.

Example: [2, 3, 1, 1, 4] is true. Example: [3, 2, 1, 0, 4] is false because you land on 0 and cannot pass.

Trying every jump recursively is exponential. A boolean DP array records whether each index is reachable. The greedy farthest-reach walk is one pass: if an index is beyond farthest, you fail; if farthest covers the end, you succeed.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(2ⁿ)
- **Space:** O(n)

From each index you may try every jump length. Overlapping paths are recomputed, so the tree is exponential. Stack depth is O(n).
How it works: dfs(i) is true if i is the last index, or any i + step can reach the end.

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(n)

For each index you may look at every previous index. Worst case quadratic. Extra array of n booleans.
How it works: ok[0] is true. ok[j] becomes true if some earlier ok[i] can jump to j. Return ok[n-1].

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

One left-to-right pass. farthest is the rightmost index you can reach so far.
How it works: if i > farthest you cannot even stand here. Update farthest with i + nums[i]. If farthest covers the last index, return true.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
