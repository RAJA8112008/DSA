# Jump Game II

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/jump-game-ii/)
- [GFG](https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1)

## Problem

nums[i] is the farthest jump length from index i. You start at 0. You are promised the last index is reachable. Return the minimum number of jumps to reach the last index.

Tiny example: [2, 3, 1, 1, 4]. From 0 you can go to 1 or 2. From 1 you can reach the end in one more jump. Answer 2 (0 -> 1 -> 4).

DP: best[i] is min jumps to i. From i you update i+1 .. i+nums[i]. The linear pass treats the array as BFS layers: the current window is one jump, farthest is the next window’s end.

Open the Brute, Optimal, and More optimal tabs for min-over-jumps recursion, the O(n^2) table, and the O(n) greedy windows.

## Methods of solving

### 1. Brute

- **Time:** O(n^n)
- **Space:** O(n)

From i you try every legal step. No cache, so overlapping positions explode. Depth is at most n. Fine only as a correctness sketch.

### 2. Optimal

- **Time:** O(n^2)
- **Space:** O(n)

best[j] is min jumps to index j. From each i you relax the range i+1 .. i+nums[i]. Up to n updates per i. This is the basic DP table for min jumps.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Greedy BFS on the line. end is the close of the current jump’s window. farthest is the furthest index a jump from this window can reach. When i hits end, you spend one jump and open the next window. One pass, no array.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
