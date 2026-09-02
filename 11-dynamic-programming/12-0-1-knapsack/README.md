# 0/1 Knapsack

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [GFG](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)
- [GFG Article](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)

## Problem

Each item has values[i] and weights[i]. Take each item at most once. Capacity is the bag limit. Return the maximum total value that still fits.

Tiny example: values = [6, 10, 12], weights = [1, 2, 3], capacity = 5. Items 1 and 2 (10+12) weigh 5. Answer 22.

State (i, w) is best value from the first i items with leftover capacity w. Skip copies the previous row. Take adds this value if the weight fits.

Open the Brute, Optimal, and More optimal tabs for take/skip recursion, the 2D table, and the backwards 1D row.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

Each item is taken or skipped. No cache. Exponential in the number of items. Depth is n.

### 2. Optimal

- **Time:** O(n * W)
- **Space:** O(n * W)

Full table: n+1 rows, W+1 columns. Each cell is a max of skip and take. W is capacity. This is the picture you should be able to fill by hand.

### 3. More optimal

- **Time:** O(n * W)
- **Space:** O(W)

One row of size W+1. Inner loop walks capacity from high to low so best[w - weight] is still the previous item’s row. Forward would reuse the same item (unbounded).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
