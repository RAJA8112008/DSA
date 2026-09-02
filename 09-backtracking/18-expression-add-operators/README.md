# Expression Add Operators

**Topic:** Recursion & Backtracking  
**Level:** advanced  
**Asked at:** Google · Meta · Amazon

## Practice

- [LeetCode](https://leetcode.com/problems/expression-add-operators/)

## Problem

Insert +, -, or * between digits of num (or concatenate digits) so the expression equals target. Return every valid expression. No leading zeros in a number (except 0 itself). * binds tighter than + and -.

Tiny example: num = "123", target = 6. Answers: "1+2+3" and "1*2*3".

The brute builds every operator placement with extra string copies and evals at the end. Standard backtrack walks an index and tries concat / + / - / *. The speed-up tracks the running value and the last operand so * can undo (cur - last + last * val) without a full eval, and prunes leading zeros.

Open Brute, Optimal, and More optimal for generate-and-eval, backtrack, and running-value prune.

## Methods of solving

### 1. Brute

- **Time:** O(4^n * n)
- **Space:** O(n)

Between digits you copy four choices: nothing (concat), +, -, *. At the end you parse and evaluate, respecting * first. Extra strings everywhere. Leading-zero expressions are built then thrown away.

### 2. Optimal

- **Time:** O(4^n)
- **Space:** O(n)

From index i, take the next operand as a long (concat digits). For the first number, just place it. Later, branch +, -, * onto one path buffer and undo. A running cur and last let you accept a leaf without a separate eval. Leading zeros are skipped.

### 3. More optimal

- **Time:** O(4^n)
- **Space:** O(n)

Track cur (value of the expression so far) and last (the last operand, signed). Concat: last = last*10+d, cur = cur - oldLast + last. Plus: cur+val, last=val. Minus: cur-val, last=-val. Times: cur-last+last*val, last=last*val. No eval. Leading zeros break. Use 64-bit to avoid overflow.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
