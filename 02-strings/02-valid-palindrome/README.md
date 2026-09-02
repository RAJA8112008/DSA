# Valid Palindrome

**Topic:** Strings  
**Level:** beginner  
**Asked at:** Meta · Amazon · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/valid-palindrome/)
- [GFG](https://www.geeksforgeeks.org/problems/palindrome-string0817/1)

## Problem

A phrase is a palindrome if, after keeping only letters and digits and ignoring case, it reads the same forward and backward.

Example: "A man, a plan, a canal: Panama" is true. "race a car" is false.

Building a cleaned string and reversing it is easy. Cleaning into an array and two-pointer checking avoids reverse. The last version never builds a cleaned copy: it skips junk in place.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Linear scan, but a full cleaned copy plus a reversed copy.
How it works: keep [a-z0-9], lowercase, then compare the string to its reverse.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Still a cleaned array, but comparison is two pointers instead of building a reversed string.
How it works: push kept characters into chars, then left/right must match.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

No extra string of length n. Two indexes on the original text.
How it works: skip non-alphanumeric on both sides, lowercase the two live characters, compare, then move in.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
