# Letter Combinations of a Phone Number

**Topic:** Recursion & Backtracking  
**Level:** beginner  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

## Problem

Each digit 2-9 maps to letters like a phone keypad. Return every string you can build by picking one letter per digit.

Tiny example: digits = "23". 2 is abc, 3 is def. Answers: ad, ae, af, bd, be, bf, cd, ce, cf.

The brute copies a new string on every pick. Standard backtrack pushes a char, recurses to the next digit, pops. Iterative BFS grows a queue of prefixes and avoids recursion.

Open Brute, Optimal, and More optimal for extra string copies, push/pop, and the queue.

## Methods of solving

### 1. Brute

- **Time:** O(4^n * n)
- **Space:** O(4^n * n)

Each digit branches up to 4 ways. path + letter allocates a new string every time. n is the number of digits. Fine for n <= 4, wasteful copies.

### 2. Optimal

- **Time:** O(4^n * n)
- **Space:** O(n)

One char buffer. Push a letter, recurse, pop. Copy to the answer only at the last digit. Extra space is O(n) besides the output.

### 3. More optimal

- **Time:** O(4^n * n)
- **Space:** O(4^n * n)

Iterative: start with [""]. For each digit, replace every prefix with prefix+letter. No recursion. Empty digits return [] immediately (early stop).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
