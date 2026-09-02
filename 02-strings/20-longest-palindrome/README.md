# Longest Palindrome

**Topic:** Strings  
**Level:** beginner  
**Asked at:** Amazon · Google · Adobe · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/longest-palindrome/)
- [GFG](https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1)

## Problem

Given a string of letters, return the length of the longest palindrome you can build by rearranging (and using letters from) s. You do not have to use every character.

Example: "abccccdd" -> 7, for example "dccaccd".

You could try arrangements, which is hopeless. A count map plus “use all even parts, at most one odd center” is the idea. A fixed-size array of 128 (or 52) slots drops the hash map.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Count with nested scans: for each character type, walk the whole string. Slow counting, same final formula.
How it works: collect unique letters. For each letter, count occurrences with a full scan. Add even parts; remember if any odd exists; add 1 for a center.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(k)

One pass to count, one pass over unique keys. k is the alphabet size.
How it works: object/map frequencies. Even contribution is count - count%2. One leftover odd becomes the center.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

128 slots cover ASCII letters used in the usual prompt. Extra memory is constant.
How it works: count[charCode]++. Same even/odd rule on the 128 numbers. Equivalent: len += count[i] & ~1, then if len < s.length add 1.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
