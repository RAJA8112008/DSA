# Cheapest Flights Within K Stops

**Topic:** Graphs  
**Level:** advanced  
**Asked at:** Amazon · Google · Bloomberg · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
- [GFG](https://www.geeksforgeeks.org/cheapest-flights-within-k-stops/)

## Problem

n cities, flights [from, to, price], src, dst, and K. Return the cheapest price from src to dst with at most K stops (so at most K+1 flights). -1 if impossible.

Example: n = 4, flights [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src 0, dst 3, K 1 answers 700 (0->1->3). With K = 2 you can take 0->1->2->3 for 400.

Stops cap the path. Brute DFS. Optimal Bellman-Ford for K+1 rounds. More optimal is a min-heap Dijkstra that tracks remaining stops.

## Methods of solving

### 1. Brute

- **Time:** O(n^K)
- **Space:** O(n + e)

DFS every path with a copied visiting array and a remaining-stop budget. Exponential in K. Easy to write, too slow when K is 20 and the graph is dense.

### 2. Optimal

- **Time:** O(K · e)
- **Space:** O(n)

Bellman-Ford: relax every flight K+1 times. Copy dist each round so you only use paths with one more flight. Classic for 'at most K edges'.

### 3. More optimal

- **Time:** O(K · e log (K n))
- **Space:** O(n · K + e)

Dijkstra on state (city, stops used). A min-heap pops cheapest cost first. best[city][stops] prunes worse repeats. Faster on sparse graphs when K is small.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
