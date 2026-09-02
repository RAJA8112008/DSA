# Longest Substring Without Repeating Characters

**Topic:** Strings  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- [GFG](https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1)

## Problem

Return the length of the longest substring that contains no repeated character.

Example: "abcabcbb" -> 3 ("abc"). Example: "bbbbb" -> 1.

Checking every substring is cubic if you rescan for uniqueness. Starting at each left and growing with a Set is quadratic. A sliding window plus last-seen index is linear.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n³)
- **Space:** O(n)

O(n²) substrings, and each uniqueness check can scan the slice again.
How it works: for every i..j, a Set of s[i..j] must have size j-i+1. Keep the max length.

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(n)

From each start, grow right until a repeat. Inner work is O(n), times n starts.
How it works: seen is a Set for the current window. On a repeat, break and try the next start.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Each index is a right endpoint once. left only moves forward. Map stores last indexes.
How it works: if this character last appeared inside the window, jump left past it. Then update last index and best length.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
