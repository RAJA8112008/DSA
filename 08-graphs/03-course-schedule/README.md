# Course Schedule

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/course-schedule/)
- [GFG](https://www.geeksforgeeks.org/problems/prerequisite-tasks/1)

## Problem

There are numCourses labeled 0 to n-1. prerequisites[i] = [a, b] means you must take b before a. Return true if you can finish all courses.

Example: 2 courses, [[1,0]] is true (take 0 then 1). [[1,0],[0,1]] is false (a 2-cycle).

This is 'does this directed graph have a cycle?' Brute DFS from every node with a fresh path copy. Optimal is 3-color DFS. More optimal is Kahn's indegree queue.

## Methods of solving

### 1. Brute

- **Time:** O(n·(n + e))
- **Space:** O(n + e)

From every course we DFS with a brand-new onPath array. We redo walks that a single 3-color pass would cache. Fine on tiny n, wasteful on large n.

### 2. Optimal

- **Time:** O(n + e)
- **Space:** O(n + e)

Three colors: 0 unseen, 1 on the current path, 2 done. Hitting a 1 is a cycle. Finished nodes are skipped, so each edge is walked once.

### 3. More optimal

- **Time:** O(n + e)
- **Space:** O(n + e)

Kahn's algorithm: peel indegree-0 courses. If you cannot peel all n courses, a cycle remains. Iterative, no recursion, same linear bound.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
