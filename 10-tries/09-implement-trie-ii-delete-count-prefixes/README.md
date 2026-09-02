# Implement Trie II / delete (count prefixes)

**Topic:** Tries  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/implement-trie-ii-prefix-tree/)
- [GFG](https://www.geeksforgeeks.org/trie-delete/)

## Problem

A trie that can insert a word, erase one copy, countWordsEqualTo(word), and countWordsStartingWith(prefix). Duplicate inserts count. erase of a missing word is a no-op.

Example: insert apple twice, countWordsEqualTo apple is 2, countWordsStartingWith app is 2, erase apple once, equal becomes 1.

Brute stores a list. Optimal uses two hash maps. More optimal is a trie with word and prefix counters, unlinking empty children.

## Methods of solving

### 1. Brute

- **Time:** O(n L)
- **Space:** O(n L)

An array of words. equalTo counts exact matches. startingWith counts prefix matches. erase removes the first copy.

### 2. Optimal

- **Time:** O(L)
- **Space:** O(n L)

wordCount map and prefixCount map. insert / erase add or subtract 1 along every prefix. Queries are hash lookups. Watch erase: never go below zero.

### 3. More optimal

- **Time:** O(L)
- **Space:** O(total chars) shared

Trie node has words (how many end here) and pref (how many pass through). insert increments. erase decrements and unlinks a child whose pref hits 0.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
