# Course Schedule II

**Topic:** Graphs  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/course-schedule-ii/)
- [GFG](https://www.geeksforgeeks.org/problems/course-schedule/1)

## Problem

Same setup as Course Schedule, but return one valid order of courses. If a cycle makes it impossible, return [].

Example: numCourses = 4, prereqs [[1,0],[2,0],[3,1],[3,2]] can return [0,1,2,3] or [0,2,1,3].

Any topo order is accepted. Brute tries every permutation. Optimal DFS pushes a course after its neighbors. More optimal is Kahn's queue, which builds the order as it peels.

## Methods of solving

### 1. Brute

- **Time:** O(n! · e)
- **Space:** O(n)

Generate every permutation of courses and test the prereq edges. Correct for tiny n, unusable at interview sizes. Shows you know 'order' means a permutation that respects edges.

### 2. Optimal

- **Time:** O(n + e)
- **Space:** O(n + e)

DFS 3-color. After all outgoing edges are done, push the course. Reverse of that list is a topo order. Empty array if a cycle is found.

### 3. More optimal

- **Time:** O(n + e)
- **Space:** O(n + e)

Kahn's BFS builds the order directly: indegree 0 first. If the order is shorter than n, a cycle blocked some courses. No reverse step, no recursion.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
