# Valid Anagram

**Topic:** Strings  
**Level:** beginner  
**Asked at:** Amazon · Google · Meta · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/valid-anagram/)
- [GFG](https://www.geeksforgeeks.org/problems/anagram-1587115620/1)

## Problem

Return true if t is an anagram of s: same letters with the same counts, order does not matter.

Example: s = "anagram", t = "nagaram" is true. s = "rat", t = "car" is false.

You can delete matching letters one by one. Sorting both strings and comparing is cleaner. One 26-slot count array increments for s and decrements for t.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

For each letter in s you search t and splice it out. Each splice is O(n), so quadratic.
How it works: copy t into an array. For every character of s, indexOf that character in the copy; if missing, false; else splice it out. Empty copy at the end means success.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(n)

Sorting both strings dominates. Extra arrays hold the split characters.
How it works: sort the character lists and compare them index by index.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

One pass over both strings and 26 integers. For lowercase a-z the extra space is constant.
How it works: count[s[i]]++, count[t[i]]--. If every slot is 0, the bags of letters matched.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
