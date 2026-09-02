# LRU Cache

**Topic:** Linked List  
**Level:** advanced  
**Asked at:** Google · Amazon · Microsoft · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/lru-cache/)
- [GFG](https://www.geeksforgeeks.org/problems/lru-cache-page-replacement/1)

## Problem

Implement LRUCache(capacity), get(key), and put(key, value). get returns the value or -1. Both get and put count as use, so that key becomes most recently used. When capacity is full, put evicts the least recently used key. Target O(1) for get and put.

capacity 2: put(1,1), put(2,2), get(1) is 1, put(3,3) drops key 2, get(2) is -1.

An array you scan and move is O(n). A JavaScript Map is insertion-ordered: delete plus set moves a key to the newest end. The interview structure is a hashmap of key to node plus a doubly linked list of recency.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n) get/put
- **Space:** O(capacity)

Store pairs in an array. get scans, splices the hit to the end. put updates or appends, then shift if over capacity. Simple, linear per operation.

### 2. Optimal

- **Time:** O(1) get/put
- **Space:** O(capacity)

Map keeps insertion order. On get/put, delete then set so the key is newest. Evict map.keys().next().value, the oldest. O(1) amortized in modern JS engines.

### 3. More optimal

- **Time:** O(1) get/put
- **Space:** O(capacity)

Classic interview design: Map from key to node, plus sentinel doubly linked list. Most recent after head, LRU before tail. Move-to-front on get/put. Evict tail.prev. Shows O(1) without relying on Map order.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
