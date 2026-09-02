# Product of Array Except Self

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Meta · Apple · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/product-of-array-except-self/)
- [GFG](https://www.geeksforgeeks.org/problems/product-array-puzzle170547/1)

## Problem

Build a new list answer where answer[i] is the product of every number except nums[i]. Do not use division.

Example: [1, 2, 3, 4] -> [24, 12, 8, 6].

The slow way multiplies the rest for each index. Left products and right products turn that into two extra arrays. The last version writes left products into the output, then multiplies a running right product on the way back.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

For each i you multiply n - 1 others. That is n² multiplications.
How it works: skip index i in the inner loop. Store the product in out[i].

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Three linear passes and two extra arrays of length n.
How it works: left[i] is the product of items before i. right[i] is the product after i. out[i] = left[i] * right[i].

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Still O(n) memory for the answer list, but no extra left/right arrays.
How it works: fill out with prefix products. Then walk right to left with a running suffix product and multiply it in.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
