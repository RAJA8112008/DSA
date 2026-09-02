# Valid Parentheses

**Topic:** Strings  
**Level:** beginner  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/valid-parentheses/)
- [GFG](https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1)

## Problem

s contains only ()[]{}. Return true if every closer matches the most recent unmatched opener and the whole string is used up.

Example: "()[]{}" is true. "([)]" is false. "{" is false.

Repeatedly deleting "()" "[]" "{}" works and is slow. A stack of openers is the linear solution. A map from closer to opener is the same algorithm written without a chain of ifs.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Each pass scans the whole string and removes one pair. Up to n/2 passes.
How it works: while any "()", "[]", or "{}" remains, split-join it away. Success is an empty string.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

One pass. Stack holds at most n openers.
How it works: push openers. On a closer, pop and check it is the matching opener. Leftover openers fail.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Same O(n) bound. A pair map avoids three mismatch branches, and odd length fails immediately.
How it works: if the character is a key in pairs, it is a closer: pop must equal pairs[ch]. Else it is an opener: push.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
