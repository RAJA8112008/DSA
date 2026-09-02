# Beautiful Arrangement

**Topic:** Recursion & Backtracking  
**Level:** intermediate  
**Asked at:** Google · Amazon

## Practice

- [LeetCode](https://leetcode.com/problems/beautiful-arrangement/)

## Problem

Count permutations perm of 1..n where for every position i (1-based), perm[i] % i == 0 or i % perm[i] == 0.

Tiny example: n = 2. [1,2] works. [2,1] also works because position 1 holds 2 and 2 % 1 == 0, and position 2 holds 1 and 2 % 1 == 0. Answer 2.

The brute builds every permutation with leftover copies and tests the rule at the end. Standard backtrack checks the rule as you place a number. A bitmask of used numbers (n <= 15) plus optional memo is the usual speed-up.

Open Brute, Optimal, and More optimal for all perms, place-and-check, and bitmasks.

## Methods of solving

### 1. Brute

- **Time:** O(n * n!)
- **Space:** O(n)

Generate every permutation with leftover copies. After a full perm, scan all n positions. n! full arrays, most fail only at the end.

### 2. Optimal

- **Time:** O(n!)
- **Space:** O(n)

At position pos (1-based), try unused numbers that already satisfy the divisibility rule. Fail early. used[] plus undo. Count leaves that fill n.

### 3. More optimal

- **Time:** O(n * 2^n)
- **Space:** O(n * 2^n)

n <= 15. mask bit (num-1) means num is used. pos = popcount(mask)+1. Memo[mask] caches how many ways finish from this used-set. Bitmask + prune + no leftover copies.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
