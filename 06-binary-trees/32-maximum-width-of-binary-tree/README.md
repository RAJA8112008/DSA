# Maximum Width of Binary Tree

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/maximum-width-of-binary-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/maximum-width-of-tree/1)

## Problem

Width of a level is the number of nodes between the leftmost and rightmost non-null positions on that level, counting the nulls in the middle. A complete heap-index numbering (root 0, left 2*i+1, right 2*i+2) makes width = lastIndex - firstIndex + 1.

GFG 'maximum width of tree' often means count of actual nodes on the widest level (no nulls). LeetCode counts positions. Both are shown: brute is GFG count; optimal/more optimal are the LeetCode index version.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(w)

BFS. Width of a level is the queue size (actual nodes). Max over levels. Matches GFG's non-null count.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(w)

LeetCode width: BFS with heap indices. Subtract the first index of the level so numbers stay small. Width = last - first + 1.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

DFS with (depth, normalized index). Store the first index seen at each depth. Width = idx - first[depth] + 1. Recursion only.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
