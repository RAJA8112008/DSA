# Group Anagrams

**Topic:** Strings  
**Level:** intermediate  
**Asked at:** Amazon · Google · Uber · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/group-anagrams/)
- [GFG](https://www.geeksforgeeks.org/problems/print-anagrams-together/1)

## Problem

Group words that are anagrams of each other. Order of groups and order inside a group do not matter.

Example: ["eat","tea","tan","ate","nat","bat"] -> [["eat","tea","ate"],["tan","nat"],["bat"]].

Comparing every pair by sorted letters is quadratic. Sorting each word as a map key is n times k log k. A count signature of 26 numbers as the key is n times k.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n² · k log k)
- **Space:** O(n·k)

Each word may be compared to every group representative. Each compare sorts a word of length k.
How it works: for each word, look for a group whose first word sorts equal to this word. If none, start a new group.

### 2. Optimal

- **Time:** O(n · k log k)
- **Space:** O(n·k)

One sort per word, then O(1) average map insert.
How it works: map sorted-word -> list of originals. Return the map values.

### 3. More optimal

- **Time:** O(n·k)
- **Space:** O(n·k)

No per-word sort. Count 26 letters and join them into a key.
How it works: count[c]++ for each character. key is the 26 numbers joined by commas so 1,11 does not collide with 11,1.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
