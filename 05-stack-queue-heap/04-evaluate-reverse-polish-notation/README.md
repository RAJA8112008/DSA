# Evaluate Reverse Polish Notation

**Topic:** Stack, Queue & Heap  
**Level:** beginner  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
- [GFG](https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1)

## Problem

tokens is a Reverse Polish list: numbers and + - * /. An operator uses the two previous values. Return the integer result. Division truncates toward zero.

Example: [2,1,+,3,*] is (2+1)*3 = 9. [4,13,5,/,+] is 4+(13/5) = 6.

Brute repeatedly finds the first operator and splices. Optimal is a stack: push numbers, on an operator pop two, push the result.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Copy the list. Each round find the first operator, replace the triple with one number. Splice is O(n), and you do it O(n) times.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

One stack. Numbers go on. An operator pops b then a (order matters for - and /), pushes the result. One pass.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Same stack, but a small apply helper and bitwise trunc for JS integers (or Math.trunc). Cleaner talk track. Complexity unchanged.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
