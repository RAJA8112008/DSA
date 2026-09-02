# Valid Palindrome II

**Topic:** Strings  
**Level:** beginner  
**Asked at:** Meta · Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/valid-palindrome-ii/)
- [GFG](https://www.geeksforgeeks.org/remove-character-string-make-palindrome/)

## Problem

Return true if s can be a palindrome after deleting at most one character.

Example: "aba" is true (already a palindrome). Example: "abca" is true (delete b or c). Example: "abc" is false.

Trying every deletion is O(n²). On the first mismatch, build two candidate strings (skip left vs skip right). Checking those ranges with two pointers and no extra strings is linear and O(1) extra memory.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

n candidate strings after deleting one index, each palindrome check is O(n).
How it works: if s is already a palindrome, true. Else for each i, check s without index i.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

One mismatch, then two extra strings of length n-1.
How it works: walk inward. On mismatch, test skip-left and skip-right by slicing. If the whole walk succeeds, no deletion was needed.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Range checks use indexes only. No sliced copies.
How it works: palin(l,r) checks a range. On the first mismatch, return palin(left+1, right) or palin(left, right-1).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
