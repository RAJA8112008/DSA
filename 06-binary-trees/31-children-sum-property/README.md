# Children Sum Property

**Topic:** Binary Trees  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Apple

## Practice

- [GFG](https://www.geeksforgeeks.org/problems/children-sum-parent/1)
- [GFG](https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/)

## Problem

A tree satisfies children-sum if every node equals the sum of its children (a missing child counts as 0). Leaves are always valid.

Check bottom-up: after both children are valid, node.val must equal left.val + right.val.

Brute for each node walks the two children only (local check) after confirming subtrees. Optimal is one postorder boolean. More optimal returns the node value upward so you never read a child twice.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

For every node, sum the two children (0 if null) and compare. Recurse both sides. Extra list of all nodes first.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Postorder boolean. Null and leaves are true. Then check val == left+right and both subtrees hold.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Return a pair (ok, val) so a failed subtree aborts. Same checks, one value returned upward.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
