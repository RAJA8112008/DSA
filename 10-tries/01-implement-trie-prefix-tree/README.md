# Implement Trie (Prefix Tree)

**Topic:** Tries  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/implement-trie-prefix-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/trie-insert-and-search095/1)

## Problem

Build a trie that supports insert(word), search(word), and startsWith(prefix). search is true only for a full inserted word. startsWith is true if any inserted word begins with that prefix.

Example: insert apple, search apple is true, search app is false, startsWith app is true, then insert app and search app becomes true.

Brute stores the raw list. Optimal stores every prefix in a set. More optimal is the real 26-way trie.

## Methods of solving

### 1. Brute

- **Time:** O(n L) search
- **Space:** O(n L)

Keep every inserted string in an array. search and startsWith scan the whole list. Correct, and fine for tiny dictionaries, but not the point of the problem.

### 2. Optimal

- **Time:** O(L)
- **Space:** O(n L)

A set of full words plus a set of every prefix. Each call is a hash lookup. Extra memory stores every prefix string, which a trie shares instead.

### 3. More optimal

- **Time:** O(L)
- **Space:** O(n L) shared

Real trie. Shared prefixes share nodes. insert, search, and startsWith each walk L children. This is the expected interview finish.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
