# Replace Words

**Topic:** Tries  
**Level:** beginner  
**Asked at:** Amazon · Google · Bloomberg

## Practice

- [LeetCode](https://leetcode.com/problems/replace-words/)
- [GFG](https://www.geeksforgeeks.org/replace-words/)

## Problem

A root is a prefix that can replace a successor word. Given a dictionary of roots and a sentence, replace every word with the shortest root that is a prefix of it. If no root matches, leave the word.

Example: dictionary = cat, bat, rat and sentence = the cattle was rattled by the battery becomes the cat was rat by the bat.

Brute tries every root on every word. Optimal sorts roots by length. More optimal walks a trie of roots until an end flag.

## Methods of solving

### 1. Brute

- **Time:** O(words * roots * L)
- **Space:** O(1) extra

For each sentence word, scan every root and keep the shortest one that is a prefix. Easy to write, quadratic in dictionary size.

### 2. Optimal

- **Time:** O(total chars)
- **Space:** O(roots)

Put roots in a set. For each word, try prefixes from length 1 up and take the first hit. That is the shortest root. Faster when few prefixes match.

### 3. More optimal

- **Time:** O(total chars)
- **Space:** O(roots)

Trie of roots. Walk each sentence word until you hit an end flag, then stop. Shared prefixes make this the usual interview answer.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
