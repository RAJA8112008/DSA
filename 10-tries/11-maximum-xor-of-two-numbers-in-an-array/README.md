# Maximum XOR of Two Numbers in an Array

**Topic:** Tries  
**Level:** advanced  
**Asked at:** Google · Amazon · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)
- [GFG](https://www.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1)

## Problem

Return the largest XOR of any two numbers in the array. You may pick the same value at two indexes if it appears twice, but usually you pick two positions.

Example: [3, 10, 5, 25, 2, 8] answers 28 because 5 xor 25 is 28.

Brute tries every pair. Optimal greedily builds the answer bit by bit with a prefix set. More optimal is a 32-bit binary trie.

## Methods of solving

### 1. Brute

- **Time:** O(n^2)
- **Space:** O(1)

XOR every pair, keep the max. Correct, too slow for n = 2e5.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Build the answer from bit 31 down. Assume the next bit can be 1. If some prefix ^ candidate exists in the set of current prefixes, keep that bit. Hash set of prefixes is the usual O(n) per bit trick.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Insert every number into a binary trie (high bit first). For each number, walk the opposite bit when it exists. That walk is the max XOR against the set. Same O(32 n), clearer as a trie.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
