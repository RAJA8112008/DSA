# Edit Distance

**Topic:** Dynamic Programming  
**Level:** advanced  
**Asked at:** Google · Amazon · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/edit-distance/)
- [GFG](https://www.geeksforgeeks.org/problems/edit-distance3702/1)

## Problem

Return the fewest operations to turn word1 into word2. Allowed operations: insert one letter, delete one letter, replace one letter. Each costs 1.

Tiny example: word1 = "horse", word2 = "ros". horse -> rorse (replace h), rorse -> rose (delete r), rose -> ros (delete e). Answer 3.

If the current letters match, cost is the diagonal (no op). If they differ, cost is 1 + min(insert, delete, replace). Empty prefixes cost the leftover length (all inserts or all deletes).

Open the Brute, Optimal, and More optimal tabs for 3-way recursion, the full Levenshtein table, and two rolling rows.

## Methods of solving

### 1. Brute

- **Time:** O(3^{m+n})
- **Space:** O(m + n)

Mismatch tries insert, delete, and replace. Those three-way branches overlap heavily. Depth is the remaining letters. Unusable on long strings.

### 2. Optimal

- **Time:** O(m * n)
- **Space:** O(m * n)

dp[i][j] is edit distance of the first i letters and first j letters. Borders are i and j. Each inner cell is O(1). The table is the standard Levenshtein grid.

### 3. More optimal

- **Time:** O(m * n)
- **Space:** O(n)

A cell needs the previous row (delete, replace) and the current row’s left (insert). Keep prev and cur. Extra memory is the length of word2 plus one.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
