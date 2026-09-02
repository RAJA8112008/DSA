# Koko Eating Bananas

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Google · Amazon · Facebook · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/koko-eating-bananas/)
- [GFG](https://www.geeksforgeeks.org/problems/koko-eating-bananas/1)

## Problem

Koko eats all piles at a fixed integer speed k bananas per hour, at most one pile per hour (ceil(pile / k) hours for that pile). Finish in h hours. Return the minimum k.

Tiny example: piles = [3, 6, 7, 11], h = 8 -> 4. Speed 3 needs 10 hours. Speed 4 needs 8.

The predicate 'can finish at speed mid' is monotone: faster never hurts. Binary search k from 1 to max(piles).

Open Brute, Optimal, and More optimal for trying every speed, binary search with integer ceil, and a long accumulator so hour sums cannot wrap.

## Methods of solving

### 1. Brute

- **Time:** O(max(piles) * n)
- **Space:** O(1)

Try k = 1, 2, ... max pile. First k that finishes in h hours is the answer. Correct, but max pile can be 10^9 so this times out.

### 2. Optimal

- **Time:** O(n log max(piles))
- **Space:** O(1)

Binary search the first speed that finishes on time. If mid works, try slower (hi = mid). If not, need faster (lo = mid + 1). Each check walks all piles.

### 3. More optimal

- **Time:** O(n log max(piles))
- **Space:** O(1)

Overflow-safe mid. Integer ceil only (no float). Early exit in the hour count when the running total already exceeds h, so a failing speed can fail before the last pile.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
