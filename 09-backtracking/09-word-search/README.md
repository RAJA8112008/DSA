# Word Search

**Topic:** Recursion & Backtracking  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Bloomberg · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/word-search/)
- [GFG](https://www.geeksforgeeks.org/problems/word-search/1)

## Problem

Given a board of letters and a word, return true if the word is a path of up/down/left/right cells. You may not reuse a cell on the same path.

Tiny example: board = [[A,B,C,E],[S,F,C,S],[A,D,E,E]], word = "ABCCED". Start at A, walk B, C, C, E, D. True.

The brute copies a visited matrix on every step. Standard search marks the cell, recurses, unmarks. More optimal returns as soon as one path hits the full word, and can reject early if a letter count is missing.

Open Brute, Optimal, and More optimal for extra visited copies, mark/unmark, and early stop.

## Methods of solving

### 1. Brute

- **Time:** O(r c * 4^L)
- **Space:** O(r c * L)

Every recursive step clones the whole visited grid. Correct, but memory traffic is huge. L is the word length. 4^L walks from each start.

### 2. Optimal

- **Time:** O(r c * 4^L)
- **Space:** O(L)

Mark the cell as '#' (or a visited flag), recurse four ways, restore the letter. One board, undo after each branch. Stack is O(L).

### 3. More optimal

- **Time:** O(r c * 4^L)
- **Space:** O(L)

Count letters first. If the board cannot supply a letter, return false. Search from the rarer end of the word. Return true on the first hit so you do not walk the rest of the grid.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
