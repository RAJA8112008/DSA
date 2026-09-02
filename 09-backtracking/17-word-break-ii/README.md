# Word Break II

**Topic:** Recursion & Backtracking  
**Level:** advanced  
**Asked at:** Amazon · Google · Dropbox · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/word-break-ii/)

## Problem

Split s into a sequence of dictionary words. Return every sentence (words joined by spaces). A word may be reused.

Tiny example: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]. Two sentences: "cats and dog" and "cat sand dog".

The brute tries every cut with extra string copies and checks the dict at the end. Standard backtrack tries each dict word as a prefix. Memo of index -> list of tails, plus a canBreak[] prune, stops exploding on 'aaaaaaaa'.

Open Brute, Optimal, and More optimal for all cuts, prefix backtrack, and memo plus prune.

## Methods of solving

### 1. Brute

- **Time:** O(2^n * n)
- **Space:** O(2^n * n)

At each index, cut or grow the last token, copying the token list. After the string ends, every token must sit in the dict. Catastrophic on repeated letters.

### 2. Optimal

- **Time:** O(2^n * n)
- **Space:** O(2^n * n)

From i, try every dictionary word as a prefix of s[i..]. Push, recurse i+len, pop. Only legal words ever sit on the path. Still exponential in the number of sentences.

### 3. More optimal

- **Time:** O(2^n * n)
- **Space:** O(2^n * n)

can[i] is true if s[i..] can be broken at all. If !can[i], skip that index (prune). Memo[i] stores the list of sentences from i so overlapping tails are not rebuilt.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
