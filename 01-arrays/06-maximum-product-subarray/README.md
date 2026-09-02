# Maximum Product Subarray

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/maximum-product-subarray/)
- [GFG](https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1)

## Problem

Return the largest product of any contiguous subarray. Zeros reset a product. Negatives can flip min and max.

Example: [2, 3, -2, 4] -> 6 from [2, 3]. Example: [-2, 3, -4] -> 24 from the whole list.

All subarray products work but are slow. Two DP arrays keep min and max ending at i. The last version keeps only those two running values.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(1)

Every subarray product is computed. Zeros and negatives are handled automatically, at quadratic cost.
How it works: start at i, multiply as j walks right, track the max product.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Linear time with min/max DP arrays. A negative number can turn a min into a max.
How it works: maxEnd[i] and minEnd[i] consider nums[i] alone, or times the previous max, or times the previous min. Answer is the max of maxEnd.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Same recurrence, two scalars instead of two arrays.
How it works: copy prev max/min into locals before updating, because both formulas need the old values. Then take the global max of maxEnd.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
