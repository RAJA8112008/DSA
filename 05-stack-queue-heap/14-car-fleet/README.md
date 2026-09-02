# Car Fleet

**Topic:** Stack, Queue & Heap  
**Level:** intermediate  
**Asked at:** Google · Amazon · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/car-fleet/)
- [GFG](https://www.geeksforgeeks.org/car-fleet/)

## Problem

Cars on a line drive toward target. position[i] and speed[i] describe car i. A faster car that catches a slower car ahead becomes one fleet (they cannot pass). Return how many fleets arrive.

Example: target 12, position [10,8,0,5,3], speed [2,4,1,1,3] answers 3.

Time to target is (target - pos) / speed. Brute nested checks. Optimal sorts by position and uses a stack of times. More optimal is a reverse scan tracking the current slowest fleet time.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Sort by position. For each car, scan every car closer to the target. If this car's time is <= that car's time, it joins that fleet. Extra scans that a stack would skip.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(n)

Sort cars from closest to target backward. Push time onto a stack if it is strictly slower than the fleet ahead (it cannot catch). Stack length is the fleet count. Sort dominates.

### 3. More optimal

- **Time:** O(n log n)
- **Space:** O(n)

Same sort, no stack. Walk from the target backward and count a new fleet whenever time > currentMaxTime. Extra space is the cars array only. Sort is still the bottleneck.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
