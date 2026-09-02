# Accounts Merge

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Meta · Google · Amazon · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/accounts-merge/)
- [GFG](https://www.geeksforgeeks.org/accounts-merge/)

## Problem

accounts[i] is [name, email1, email2, ...]. Two accounts belong to the same person if they share any email. Merge those accounts: one name, sorted unique emails. Different people may share a name.

Example: John with a@x and b@x, John with b@x and c@x merge into one John with a, b, c.

Emails are graph nodes. Brute DFS with extra visited copies. Optimal DFS/BFS grouping. More optimal Union-Find on emails.

## Methods of solving

### 1. Brute

- **Time:** O(n² · m)
- **Space:** O(n · m)

Build an email-to-accounts list, then from each unvisited account DFS through shared emails with a copied seen set. Extra copies plus scanning accounts repeatedly.

### 2. Optimal

- **Time:** O(n · m log m)
- **Space:** O(n · m)

Graph of emails: link every email in an account to the first email. DFS each component, sort, prepend the name. Sorting emails is the log factor.

### 3. More optimal

- **Time:** O(n · m log m)
- **Space:** O(n · m)

Union-Find on emails. Union every email in an account with the first email. Group by root, sort each group. No adjacency lists; merges are nearly O(1).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
