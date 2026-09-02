# Implement Magic Dictionary

**Topic:** Tries  
**Level:** intermediate  
**Asked at:** Google · Amazon · Facebook

## Practice

- [LeetCode](https://leetcode.com/problems/implement-magic-dictionary/)
- [GFG](https://www.geeksforgeeks.org/implement-magic-dictionary/)

## Problem

Build a dict from a word list. search(query) is true if you can change exactly one letter of query and land on a stored word. Same length only. Changing zero letters does not count.

Example: dict hello, leetcode. search hhllo is true (hello with one change). search hell is false (length). search leetcode is false (zero changes).

Brute compares every word. Optimal keys wildcard patterns. More optimal DFS on a trie with one leftover mismatch.

## Methods of solving

### 1. Brute

- **Time:** O(n L)
- **Space:** O(n L)

Store the list. For each stored word of the same length, count mismatches. Return true on a count of exactly 1.

### 2. Optimal

- **Time:** O(L * 26)
- **Space:** O(n L^2)

For each word, replace each position with '*' and map that pattern to the original letters. On search, look up each starred query and see if another letter is stored. Handles duplicates carefully.

### 3. More optimal

- **Time:** O(26 L)
- **Space:** O(n L)

Trie DFS with a leftover mismatch budget of 1. At the end of the query the budget must be 0 (exactly one change). Compact and matches the 'magic' story.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
