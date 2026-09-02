# Reverse Words in a String

**Topic:** Strings  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Apple · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/reverse-words-in-a-string/)
- [GFG](https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1)

## Problem

Reverse the order of words. Collapse any extra spaces so words are separated by a single space, with no leading or trailing space.

Example: "  hello   world  " -> "world hello".

split on spaces, drop empties, reverse, join. Doing that with a manual scan is the same idea without leaning on filter. Reverse the whole character array, then reverse each word, then trim spaces.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Library split/filter/reverse/join still copies the string.
How it works: split on " ", drop empty pieces (the extra spaces), reverse the word list, join with one space.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

One scan to collect words, then build the answer from the end. No filter callback, same linear bound.
How it works: skip spaces, slice a word, push it. Then concatenate from the last word to the first with single spaces.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Still O(n) memory because JS strings are immutable; we reverse a character array. This is the in-place pattern interviews describe.
How it works: trim extra spaces into a compact array, reverse the whole array, reverse each word between spaces.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
