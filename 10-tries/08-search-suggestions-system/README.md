# Search Suggestions System

**Topic:** Tries  
**Level:** intermediate  
**Asked at:** Amazon · Google · Bloomberg · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/search-suggestions-system/)
- [GFG](https://www.geeksforgeeks.org/problems/phone-directory4628/1)

## Problem

products is a list of strings. searchWord is typed one letter at a time. After each prefix, return up to 3 product names that start with that prefix, in lexicographic order.

Example: products = mobile, mouse, moneypot, monitor, mousepad and searchWord = mouse. After m, mo, mou, mous, mouse the lists grow from mobile/moneypot/monitor toward mouse/mousepad.

Brute filters after every extra letter. Optimal sorts once then binary-searches the prefix range. More optimal stores 3 suggestions on each trie node.

## Methods of solving

### 1. Brute

- **Time:** O(|s| n L)
- **Space:** O(n)

After each extra character, scan every product, keep those with the prefix, sort, take 3. Correct and slow.

### 2. Optimal

- **Time:** O(n L log n + |s| log n)
- **Space:** O(n)

Sort products once. For each growing prefix, lower-bound the first product >= prefix, then take the next three if they still share the prefix.

### 3. More optimal

- **Time:** O(total chars)
- **Space:** O(total chars)

Trie. At each node keep up to 3 lex-smallest words that pass through it (insert into a sorted short list). Typing searchWord is just walking children and reading that list.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
