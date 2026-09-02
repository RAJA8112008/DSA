# Word Ladder

**Topic:** Graphs  
**Level:** advanced  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/word-ladder/)
- [GFG](https://www.geeksforgeeks.org/problems/word-ladder/1)

## Problem

beginWord, endWord, and a wordList of the same length. A step changes exactly one letter to another real word in the list. Return the length of the shortest transformation sequence, or 0 if none exists. Length counts the words, so beginWord -> hot -> dot -> dog -> cog is 5.

Example: begin hit, end cog, list [hot,dot,dog,lot,log,cog] answers 5.

This is unweighted shortest path on a huge implicit graph. Brute DFS explores every ladder. Optimal BFS. More optimal searches from both ends.

## Methods of solving

### 1. Brute

- **Time:** O(26^L · n)
- **Space:** O(n·L)

DFS with a copied remaining-word set at every step. It can walk long dead paths before it finds the short ladder. Exponential in ladder length.

### 2. Optimal

- **Time:** O(n·L·26)
- **Space:** O(n·L)

BFS from beginWord. Each word is enqueued once. Trying 26 letters at each index is the usual neighbor generator. First time you hit endWord is the shortest length.

### 3. More optimal

- **Time:** O(n·L·26)
- **Space:** O(n·L)

Bidirectional BFS. Expand the smaller frontier each round. When a candidate sits in the other set, the two searches met. Branching is cut roughly in half on typical dictionaries.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
