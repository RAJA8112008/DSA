# Integer to Roman

**Topic:** Strings  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/integer-to-roman/)
- [GFG](https://www.geeksforgeeks.org/problems/convert-to-roman-no-1587115621/1)

## Problem

Convert an integer 1..3999 to Roman numerals using the standard symbols, including subtractive forms IV, IX, XL, XC, CD, CM.

Example: 1994 -> "MCMXCIV".

Nested while loops per symbol work. A parallel list of values and glyphs from 1000 down to 1 is the usual greedy table. The compact table already includes 900, 400, 90, 40, 9, 4 so you never special-case those.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(1)
- **Space:** O(1)

The input is at most 3999, so the number of appended symbols is bounded. Separate while loops per unit are verbose.
How it works: peel thousands as M, then hundreds with C/D/CM/CD, then tens, then ones, with explicit ifs for 9 and 4.

### 2. Optimal

- **Time:** O(1)
- **Space:** O(1)

Same greedy idea, data-driven: walk a values array and append the matching glyph count times.
How it works: values and glyphs are aligned. For each pair, while num >= values[i], append glyphs[i] and subtract.

### 3. More optimal

- **Time:** O(1)
- **Space:** O(1)

Use division to append a glyph in a batch instead of a per-unit inner while for large counts (e.g. 3 -> "III" in one repeat).
How it works: count = Math.floor(num / values[i]); append glyphs[i] that many times; num %= values[i].

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
