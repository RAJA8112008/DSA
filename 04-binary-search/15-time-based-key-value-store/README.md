# Time Based Key-Value Store

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Google · Amazon · Lyft · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/time-based-key-value-store/)
- [GFG](https://www.geeksforgeeks.org/problems/time-based-key-value-store/1)

## Problem

Design a map: set(key, value, timestamp) stores a value at a time. get(key, timestamp) returns the value with the largest time <= timestamp, or "" if none. Timestamps on set for one key are strictly increasing.

Tiny example: set("foo", "bar", 1), get("foo", 1) -> "bar". get("foo", 3) -> "bar". set("foo", "bar2", 4), get("foo", 4) -> "bar2". get("foo", 5) -> "bar2".

Each key holds a sorted list of (time, value). get is a last-true binary search on time.

Open Brute, Optimal, and More optimal for a linear scan, binary search on the list, and a tighter upper-bound loop.

## Methods of solving

### 1. Brute

- **Time:** set O(1), get O(n)
- **Space:** O(n)

Append every set. On get, scan the whole list for that key and keep the latest time that is still <= timestamp. Fine until a key has many versions.

### 2. Optimal

- **Time:** set O(1), get O(log n)
- **Space:** O(n)

Sets for one key arrive in increasing time, so the list is sorted. Binary search the last index whose time is <= timestamp. That is last-true on the time axis.

### 3. More optimal

- **Time:** set O(1), get O(log n)
- **Space:** O(n)

Overflow-safe mid. Half-open search for the first time > timestamp; the answer is the previous slot. No extra ans string in the loop. Same log probes, slightly cleaner bound.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
