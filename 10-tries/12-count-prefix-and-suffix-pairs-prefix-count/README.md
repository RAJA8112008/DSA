# Count Prefix and Suffix Pairs / Prefix Count

**Topic:** Tries  
**Level:** beginner  
**Asked at:** Amazon · Google · Bloomberg

## Practice

- [LeetCode](https://leetcode.com/problems/counting-words-with-a-given-prefix/)
- [GFG](https://www.geeksforgeeks.org/count-the-number-of-words-with-given-prefix/)

## Problem

Prefix Count (LC counting-words-with-a-given-prefix): count how many words start with pref.

Related: Count Prefix and Suffix Pairs asks how many index pairs (i, j) with i < j have words[i] as both a prefix and a suffix of words[j].

Example (prefix count): words = pay, attention, practice, attend, pref = at. Answer 2 (attention, attend).

Brute uses startsWith. Optimal still scans but bails early. More optimal inserts into a trie and reads the prefix counter.

## Methods of solving

### 1. Brute

- **Time:** O(n L)
- **Space:** O(1)

For each word, compare pref character by character. Count a hit when the whole pref matches.

### 2. Optimal

- **Time:** O(n^2 L)
- **Space:** O(1)

For the related prefix-and-suffix-pairs problem: try every i < j and test both prefix and suffix. Still brute pairs, but the check is the right idea before a trie of (char, char) pairs.

### 3. More optimal

- **Time:** O(total chars)
- **Space:** O(total chars)

Prefix count: insert every word into a trie, increment pref on each node, then walk pref once. For prefix-and-suffix pairs, a twin trie on (first char, last char) pairs is the upgrade when n is large.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
