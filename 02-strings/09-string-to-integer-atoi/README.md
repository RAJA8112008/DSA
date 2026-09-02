# String to Integer (atoi)

**Topic:** Strings  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/string-to-integer-atoi/)
- [GFG](https://www.geeksforgeeks.org/problems/implement-atoi/1)

## Problem

Parse s as a 32-bit signed integer: skip leading spaces, read an optional sign, read digits, clamp to [-2^31, 2^31 - 1]. Junk after the number is ignored. If no digits, return 0.

Example: "   -42" -> -42. Example: "4193 with words" -> 4193. Example: "91283472332" -> 2147483647.

Collecting digits into a string then Number() still needs a clamp. Multiplying a running total by 10 is the usual loop. Checking overflow before you multiply keeps you inside 32-bit limits.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

You still walk the string once, but you build a digit string and use Number, then clamp.
How it works: skip spaces, note sign, gather digits into text. Number(text) * sign, then clamp to 32-bit bounds.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(1)

No digit string. A running number. Clamp after the loop (JS Number can hold these intermediates).
How it works: same skip/sign walk. num = num * 10 + digit. Then clamp.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Overflow is stopped as soon as the next digit would leave 32-bit range, matching a language without big numbers.
How it works: before num = num*10 + d, if num > 214748364 or (num === 214748364 and d > 7), return the clamped bound for this sign.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
