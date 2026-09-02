# Design Add and Search Words Data Structure

**Topic:** Tries  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/design-add-and-search-words-data-structure/)
- [GFG](https://www.geeksforgeeks.org/add-and-search-word-data-structure-design/)

## Problem

addWord stores a word. search returns true if any stored word matches the pattern. A '.' in the pattern matches any one letter.

Example: add bad, add dad, add mad. search pad is false, search bad is true, search .ad is true, search b.. is true.

Brute scans every word. Optimal buckets by length. More optimal DFS on a trie, branching on '.' .

## Methods of solving

### 1. Brute

- **Time:** O(n L) search
- **Space:** O(n L)

Keep a list. For each stored word of the same length, compare char by char and treat '.' as a free pass. Simple and slow when the dictionary is large.

### 2. Optimal

- **Time:** O(k L)
- **Space:** O(n L)

Bucket words by length so a pattern of length L only scans that bucket. Still linear in the bucket size, but you skip obviously impossible words.

### 3. More optimal

- **Time:** O(26^d L)
- **Space:** O(n L)

Trie DFS. A letter follows one child. A '.' tries every living child. d is the number of dots. This is the expected design.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
