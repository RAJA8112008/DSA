# Magnetic Force Between Two Balls

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/magnetic-force-between-two-balls/)
- [GFG](https://www.geeksforgeeks.org/problems/aggressive-cows/1)

## Problem

Place m balls into baskets at positions (sorted after you sort them) so the minimum distance between any two balls is as large as possible. Same problem as Aggressive Cows.

Tiny example: position = [1, 2, 3, 4, 7], m = 3 -> 3. One best layout is baskets 1, 4, 7 (gaps 3 and 3).

The predicate 'can I place m balls with min gap mid?' is last-true: if mid works, a smaller gap also works, so you try a larger gap.

Open Brute, Optimal, and More optimal for trying every gap, binary search plus greedy place, and overflow-safe mid with an early count exit.

## Methods of solving

### 1. Brute

- **Time:** O((max-min) * n)
- **Space:** O(1)

Sort, then try every distance from (max-min) down to 1. First distance that can place m balls is the answer. Distance range can be 10^9, so this times out.

### 2. Optimal

- **Time:** O(n log(max-min))
- **Space:** O(1)

Sort once. Binary search the gap. Greedy: place the next ball at the first basket that is at least mid away from the last placed ball. If you place m, try a larger gap (lo = mid + 1).

### 3. More optimal

- **Time:** O(n log(max-min))
- **Space:** O(1)

Overflow-safe mid. Half-open last-true: if mid works, lo = mid + 1, else hi = mid, then return lo - 1. No separate ans. Early stop once m balls are placed.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
