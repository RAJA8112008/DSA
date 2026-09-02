# Map Sum Pairs

**Topic:** Tries  
**Level:** beginner  
**Asked at:** Amazon · Google · Bloomberg

## Practice

- [LeetCode](https://leetcode.com/problems/map-sum-pairs/)
- [GFG](https://www.geeksforgeeks.org/map-sum-pairs/)

## Problem

insert(key, val) sets the score of key (overwrite if the key already exists). sum(prefix) returns the total score of every key that starts with prefix.

Example: insert apple 3, sum ap is 3, insert app 2, sum ap is 5.

Brute stores the map and scans keys. Optimal adds the delta onto every prefix string. More optimal stores the running sum on trie nodes.

## Methods of solving

### 1. Brute

- **Time:** O(n L) sum
- **Space:** O(n L)

A plain key -> val map. sum walks every key and adds val when the key starts with the prefix.

### 2. Optimal

- **Time:** O(L) insert and sum
- **Space:** O(n L)

Keep the latest val per key. On insert, delta = newVal - oldVal. Add delta to every prefix string of the key in a second map. sum is then one lookup.

### 3. More optimal

- **Time:** O(L)
- **Space:** O(n L) shared

Trie node holds a running sum of values that pass through it. insert adds the delta along the path. sum walks the prefix and returns that node's sum.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
