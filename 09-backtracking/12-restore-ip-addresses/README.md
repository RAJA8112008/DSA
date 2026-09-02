# Restore IP Addresses

**Topic:** Recursion & Backtracking  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · ByteDance

## Practice

- [LeetCode](https://leetcode.com/problems/restore-ip-addresses/)

## Problem

Split string s of digits into exactly four IP parts. Each part is an integer 0..255 with no leading zero (unless the part is "0").

Tiny example: s = "25525511135". Two answers: 255.255.11.135 and 255.255.111.35.

The brute tries every way to place three dots (extra string copies) and validates after. Standard backtrack builds four parts. Prune: remaining length too small or too big, leading zeros, value > 255.

Open Brute, Optimal, and More optimal for all-dot placements, backtrack, and length prune.

## Methods of solving

### 1. Brute

- **Time:** O(n^4)
- **Space:** O(n)

Three nested cuts copy substring pieces, then a validator checks leading zeros and 0..255. n is at most 12, so this still finishes, but you build illegal IPs first.

### 2. Optimal

- **Time:** O(1)
- **Space:** O(1)

s length is at most 12, so the search is constant. Backtrack parts 0..3. From i, try length 1, 2, 3. Push the piece, recurse, pop. Copy the joined string at 4 parts.

### 3. More optimal

- **Time:** O(1)
- **Space:** O(1)

Before trying a length, prune: leftover chars must sit in [4-parts, 3*(4-parts)]. Drop leading-zero parts immediately. Cuts the tiny tree even further.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
