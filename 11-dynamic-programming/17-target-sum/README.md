# Target Sum

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/target-sum/)
- [GFG](https://www.geeksforgeeks.org/target-sum/)

## Problem

You have a list of non-negative integers. Place a + or a - in front of each number. Return how many ways the signed sum equals target.

Tiny example: nums = [1, 1, 1, 1, 1], target = 3. Five ways pick which one number is the minus. Answer 5.

Let P be the subset with plus and N the subset with minus. P + N = total and P - N = target, so P = (total + target) / 2. The count becomes 0/1 knapsack ways to make that subset sum. If total+target is odd or |target| > total, the answer is 0.

Open the Brute, Optimal, and More optimal tabs for +/- recursion, memo on (index, running sum), and the subset-sum ways row.

## Methods of solving

### 1. Brute

- **Time:** O(2^n)
- **Space:** O(n)

Each number branches into plus or minus. 2^n signed assignments. Stack is n. Fine as a correctness check on tiny n.

### 2. Optimal

- **Time:** O(n * sum)
- **Space:** O(n * sum)

Memo keys are (index, running sum). Running sum ranges about [-total, total], so unique states are O(n * total). Each state does two branches once.

### 3. More optimal

- **Time:** O(n * sum)
- **Space:** O(sum)

Map onto 0/1 subset-sum ways for need = (total + target) / 2. One ways[] row, inner loop backwards so each number is used once. Cleaner bottom-up, same polynomial, smaller constant memory.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
