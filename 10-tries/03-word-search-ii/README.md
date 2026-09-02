# Word Search II

**Topic:** Tries  
**Level:** advanced  
**Asked at:** Amazon · Google · Microsoft · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/word-search-ii/)
- [GFG](https://www.geeksforgeeks.org/problems/word-boggle-1587115621/1)

## Problem

You get an m by n board of letters and a list of words. Return every word that can be formed by walking adjacent cells (up, down, left, right) without reusing a cell in the same walk.

Example: board has o,a,a,n / e,t,a,e / i,h,k,r / i,f,l,v and words eat, oath, pea, rain. Answer is eat and oath.

Brute runs Word Search I per word. Optimal walks the board once against a trie. More optimal stores the word on the end node and prunes after a find.

## Methods of solving

### 1. Brute

- **Time:** O(w m n 4^L)
- **Space:** O(L)

For each word, DFS from every cell. Mark the cell, try four neighbors, unmark. Correct, but you restart the whole board for every dictionary word.

### 2. Optimal

- **Time:** O(m n 4^L)
- **Space:** O(total chars)

Build a trie of all words, then DFS from every cell following only living children. One board walk instead of one walk per word.

### 3. More optimal

- **Time:** O(m n 4^L)
- **Space:** O(total chars)

Same trie DFS, but after you emit a word you clear that end mark (and optionally prune empty children). That stops duplicate work and extra copies of the same word.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
