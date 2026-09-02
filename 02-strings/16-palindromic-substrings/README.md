# Palindromic Substrings

**Topic:** Strings  
**Level:** intermediate  
**Asked at:** Meta · Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/palindromic-substrings/)
- [GFG](https://www.geeksforgeeks.org/count-palindrome-sub-strings-of-a-string/)

## Problem

Count how many palindromic substrings s has. Single letters count. Different indexes count as different even if the text matches.

Example: "abc" -> 3. Example: "aaa" -> 6.

Check every substring. A boolean DP table pal[i][j] fills by length. Expanding around centers counts without the n² table.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n³)
- **Space:** O(1)

O(n²) ranges, each palindrome test O(n).
How it works: for every i..j, two-pointer check. Increment count when it is a palindrome.

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(n²)

A boolean table of n by n. Each cell is O(1) after shorter lengths are known.
How it works: pal[i][j] is true if s[i]===s[j] and the inside is a palindrome (or the length is 1 or 2). Count every true cell.

### 3. More optimal

- **Time:** O(n²)
- **Space:** O(1)

Same time, constant extra memory. Each palindrome is grown from a center.
How it works: expand(left,right) counts while the letters match. Call expand(i,i) and expand(i,i+1) for every i.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
