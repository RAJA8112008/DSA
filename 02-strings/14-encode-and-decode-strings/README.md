# Encode and Decode Strings

**Topic:** Strings  
**Level:** intermediate  
**Asked at:** Meta · Google · Amazon · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/encode-and-decode-strings/)
- [GFG](https://www.geeksforgeeks.org/encode-and-decode-strings/)
- [LintCode](https://www.lintcode.com/problem/659/)

## Problem

Design encode(strs) -> one string, and decode(that string) -> the original list. Words may contain any characters, including the delimiter you might want to use.

Example: ["hello","world"] must round-trip. Example: ["","#","a#b"] must also round-trip.

JSON.stringify works as a blunt encoder. Escaping a delimiter also works if you are careful. Length-prefix (len#word) is the usual interview design: decode reads digits, then a slice of that length.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

JSON does the escaping for you. Fine in JS, often not what the interviewer wants to hear as the data-structure answer.
How it works: encode is JSON.stringify. decode is JSON.parse. n is total characters.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Write a header of counts and lengths, then the raw words glued together. The header cannot be confused with word contents because a single # separates header from body.
How it works: header is n, then each word length. Body is the words concatenated. Decode reads n lengths, then slices the body.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

No escaping rules to get wrong. Length is written in decimal, then "#", then raw characters. Decode cannot confuse "#" inside a word because length tells you how far to slice.
How it works: encode concatenates String(len) + "#" + word. decode finds "#", parses len, slices the next len chars.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
