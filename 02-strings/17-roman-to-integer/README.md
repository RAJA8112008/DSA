# Roman to Integer

**Topic:** Strings  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/roman-to-integer/)
- [GFG](https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1)

## Problem

Convert a Roman numeral to an integer. Subtractive pairs: IV=4, IX=9, XL=40, XC=90, CD=400, CM=900. Otherwise add each letter’s value.

Example: "MCMXCIV" -> 1994 (M + CM + XC + IV).

Replacing subtractive pairs first, then summing, works. Looking one character ahead in a loop is cleaner. A single rule: if the current value is less than the next, subtract it, otherwise add it.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

You copy the string and rewrite pairs, then sum. Extra string memory.
How it works: replace CM, CD, XC, XL, IX, IV with single tokens, then add a map of remaining symbols including those tokens.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(1)

One pass, a fixed map. When a subtractive pair is seen, add the pair value and skip two characters.
How it works: if val[s[i]] < val[s[i+1]], add the difference and i += 2. Else add val[s[i]] and i += 1.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Same linear scan, no skip logic: always add the current value, but subtract it instead when it is smaller than the next.
How it works: for each i, if val[s[i]] < val[s[i+1]] then sum -= val[s[i]], else sum += val[s[i]].

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
