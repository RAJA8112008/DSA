# Longest Word in Dictionary

**Topic:** Tries  
**Level:** beginner  
**Asked at:** Amazon · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/longest-word-in-dictionary/)
- [GFG](https://www.geeksforgeeks.org/longest-word-in-dictionary/)

## Problem

From a list of words, return the longest word that can be built one character at a time from other words in the list. If there is a tie, return the lexicographically smallest. If none, return empty.

Example: w, wo, wor, worl, world answers world. Each prefix was itself a word.

Brute checks every prefix of every word. Optimal sorts then grows a set. More optimal DFS on a trie where every node on the path is an end.

## Methods of solving

### 1. Brute

- **Time:** O(n^2 L)
- **Space:** O(n)

Put words in a set. For each word, test that every prefix is in the set. Keep the longest, breaking ties lexicographically.

### 2. Optimal

- **Time:** O(n L log n)
- **Space:** O(n)

Sort by length then lex. A word is valid if the set already holds word without its last letter (or the word has length 1). Insert only valid words. The last survivor is the answer if you also keep the lex-smallest of that length.

### 3. More optimal

- **Time:** O(total chars)
- **Space:** O(total chars)

Insert every word into a trie with an end flag. DFS only through end nodes. The deepest (then lex-smallest) path is the answer.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
