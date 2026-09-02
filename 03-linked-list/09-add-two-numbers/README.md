# Add Two Numbers

**Topic:** Linked List  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/add-two-numbers/)
- [GFG](https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1)

## Problem

Two lists store digits of two numbers in reverse order, one digit per node. Return their sum as a list in the same format. A leftover carry can create an extra node.

2 -> 4 -> 3 plus 5 -> 6 -> 4 is 342 + 465 = 807, so 7 -> 0 -> 8.

BigInt from the digits works until you remember interviews want digit-by-digit carry. Recursion adds a pair plus carry. Iteration with a dummy is the usual write-up.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n+m)
- **Space:** O(n+m)

Turn each list into a BigInt (least-significant digit first), add, then emit digits into a new list. Easy in JavaScript, hides the carry logic interviewers want.

### 2. Optimal

- **Time:** O(max(n,m))
- **Space:** O(max(n,m))

Recursive add of two nodes plus carry. Next call gets the rest of both lists. Stack depth follows the longer number.

### 3. More optimal

- **Time:** O(max(n,m))
- **Space:** O(1)

Iterative dummy. Each step sums two digits and carry, writes sum % 10, carry becomes floor(sum/10). Extra node if carry remains. Output list is required; extra pointers are constant.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
