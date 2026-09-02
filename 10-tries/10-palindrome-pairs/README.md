# Palindrome Pairs

**Topic:** Tries  
**Level:** advanced  
**Asked at:** Google · Airbnb · Amazon

## Practice

- [LeetCode](https://leetcode.com/problems/palindrome-pairs/)
- [GFG](https://www.geeksforgeeks.org/palindrome-pairs/)

## Problem

Given unique words, return every pair of indexes [i, j] (i != j) such that words[i] + words[j] is a palindrome.

Example: abcd, dcba, lls, s, sssll. Pairs include [0,1] (abcddcba), [1,0] (dcbaabcd), [3,2] (slls), [2,4] (llssssll).

Brute concatenates every pair. Optimal maps each word to its index and tries every split. More optimal inserts reversed words into a trie and checks palindrome prefixes/suffixes.

## Methods of solving

### 1. Brute

- **Time:** O(n^2 L)
- **Space:** O(1)

For every ordered pair, concatenate and test palindrome. Fine for tiny n, not for n = 5000.

### 2. Optimal

- **Time:** O(n L^2)
- **Space:** O(n L)

Map word -> index. For each word, try every split. If the left half is a palindrome, look up reverse(right). If the right half is a palindrome, look up reverse(left). Handles the empty-word case.

### 3. More optimal

- **Time:** O(n L^2)
- **Space:** O(n L)

Insert the reverse of every word into a trie, storing the index at the end. While walking a word, if the remaining suffix is a palindrome and the node is an end, you have a pair. Also collect end indexes whose leftover reverse is a palindrome. Same complexity, trie picture.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
