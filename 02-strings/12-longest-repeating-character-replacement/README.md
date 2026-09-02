# Longest Repeating Character Replacement

**Topic:** Strings  
**Level:** intermediate  
**Asked at:** Google · Amazon · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/longest-repeating-character-replacement/)
- [GFG](https://www.geeksforgeeks.org/longest-repeating-character-replacement/)

## Problem

You may replace at most k characters. Return the length of the longest substring that can become all one letter after those replacements.

Example: s = "AABABBA", k = 1 -> 4 (replace the middle B in "AABA" or similar).

Trying every window and counting the mode is quadratic. A sliding window that recounts the max frequency each step is O(n*26). You can keep a running maxCount; it never needs to decrease for this length-maximizing problem.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n² · 26)
- **Space:** O(1)

Every window rebuilds 26 counts and checks whether length - maxCount <= k.
How it works: if the letters that are not the most common letter fit in k replacements, the window is valid. Keep the max valid length.

### 2. Optimal

- **Time:** O(n · 26)
- **Space:** O(1)

One window. When invalid, left moves and you recompute maxCount by scanning 26 slots.
How it works: grow right. While length - maxCount > k, decrement s[left] and recount maxCount. Then update best.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

maxCount only increases when a better majority appears. For the longest window, you never need a smaller maxCount.
How it works: grow right, update maxCount. If window is too dirty, move left once (not a while with a rescan). Window size still only grows when valid history allows it.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
