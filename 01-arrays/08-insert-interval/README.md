# Insert Interval

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Google · Amazon · Meta · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/insert-interval/)
- [GFG](https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1)

## Problem

intervals is already sorted and non-overlapping. Insert newInterval and merge if it overlaps anyone. Return the new sorted list.

Example: intervals = [[1, 3], [6, 9]], newInterval = [2, 5] -> [[1, 5], [6, 9]].

Appending then running a full merge works. Splitting into “before”, “overlap”, and “after” is clearer. The last version is one pass: copy the left non-overlapping pieces, merge the middle, then copy the rest.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Add the new interval, then reuse the quadratic merge-until-stable idea.
How it works: push a copy of newInterval onto a copied list, then glue overlaps with nested scans until the list is stable.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Three buckets, one scan. No sort needed because the input is already sorted.
How it works: before holds intervals fully to the left. after holds fully to the right. The middle ones stretch start/end of the new interval. Concatenate before + merged + after.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

One pass, one result list, no extra before/after arrays (the result plays that role).
How it works: copy intervals that end before the new start. Merge while the next interval starts at or before the new end. Then copy the tail.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
