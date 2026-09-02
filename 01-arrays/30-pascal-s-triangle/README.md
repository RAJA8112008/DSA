# Pascal's Triangle

**Topic:** Arrays  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/pascals-triangle/)
- [GFG](https://www.geeksforgeeks.org/problems/pascal-triangle/1)

## Problem

Return the first numRows of Pascal's triangle. Row i has i numbers. Each inner value is the sum of the two values above it. Rows are 1-indexed in speech, 0-indexed in arrays.

Example: numRows = 5 yields [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]].

Brute uses nCr for every cell. Optimal builds each row from the previous. More optimal fills a row with the multiplicative formula C(r, k) = C(r, k-1) * (r-k+1)/k.

## Methods of solving

### 1. Brute

- **Time:** O(n³) with naive fact
- **Space:** O(n²)

Each cell is nCr. Computing factorials from scratch per cell is slow and overflows. Picture is right, implementation is not the interview one.

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(n²)

Row 0 is [1]. Each next row starts and ends with 1. Inner slot j is prev[j-1] + prev[j]. No overflow beyond 32-bit on the usual n <= 30 constraint.

### 3. More optimal

- **Time:** O(n²)
- **Space:** O(n²)

Each row built independently with the running product formula. Useful when you only need row r (Pascal's Triangle II) and do not want the whole triangle.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
