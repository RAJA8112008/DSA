# Daily Temperatures

**Topic:** Stack, Queue & Heap  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/daily-temperatures/)
- [GFG](https://www.geeksforgeeks.org/daily-temperatures/)

## Problem

temperatures[i] is the degree that day. For each day, return how many days you wait until a warmer day. 0 if none exists.

Example: [73,74,75,71,69,72,76,73] answers [1,1,4,2,1,1,0,0].

Brute looks right from each day. Optimal is a decreasing monotonic stack of indices. More optimal walks right to left and jumps using answers already filled.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

For each day i, scan j > i until temperatures[j] > temperatures[i]. Worst case a falling array, so n² compares.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Stack of indices with decreasing temps. When a warmer day arrives, pop until the stack is cooler again. Each index is pushed and popped at most once.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Right-to-left jump: if day j is not warmer, skip ahead by ans[j] days (those days are also not warmer than j, hence not warmer than i if temps[j] <= temps[i]). Extra space is only the output. Still linear.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
