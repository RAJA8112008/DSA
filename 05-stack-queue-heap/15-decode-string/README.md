# Decode String

**Topic:** Stack, Queue & Heap  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Bloomberg

## Practice

- [LeetCode](https://leetcode.com/problems/decode-string/)
- [GFG](https://www.geeksforgeeks.org/problems/decode-the-string-1587115620/1)

## Problem

s encodes nested repeats: k[encoded]. Digits before [ are the repeat count. Return the decoded string. Counts fit in an int. Letters are lowercase.

Example: 3[a2[c]] becomes accaccacc. 2[abc]3[cd]ef becomes abcabccdcdcdef.

Brute recurses and copies leftover slices. Optimal one stack of [prefix, count] frames. More optimal two stacks (counts and strings) if that is easier to say out loud.

## Methods of solving

### 1. Brute

- **Time:** O(n · out)
- **Space:** O(n · out)

Recursion: parse a chunk, and when you see k[...], slice the inner substring, decode it, repeat. Extra string copies of the remaining suffix. Correct, messy bounds.

### 2. Optimal

- **Time:** O(n + out)
- **Space:** O(n + out)

One stack. Digits build k. '[' pushes the current string and k, then resets. Letters append. ']' pops and repeats. Linear in input plus output size.

### 3. More optimal

- **Time:** O(n + out)
- **Space:** O(n + out)

Two stacks: counts and strings. Same linear bound. Some interviewers prefer two named stacks over pairs. Repeat still dominates the output cost.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
