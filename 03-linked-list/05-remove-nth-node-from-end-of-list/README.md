# Remove Nth Node From End of List

**Topic:** Linked List  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
- [GFG](https://www.geeksforgeeks.org/problems/remove-nth-node-from-end-of-the-list/1)

## Problem

Delete the nth node counting from the tail. Return the new head.

On 1 -> 2 -> 3 -> 4 -> 5 with n = 2, drop 4 and return 1 -> 2 -> 3 -> 5. n can delete the original head.

Copy nodes to an array and splice. Or count length, then walk length-n. The one-pass trick: dummy, send fast n+1 steps, walk both, then slow.next = slow.next.next.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Store every node in an array. Remove index length-n, then relink the remaining nodes in order. Extra array of pointers.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Recursive walk to the end, counting on the way back. When the counter hits n, skip that node from the parent. Stack is O(n).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Dummy head. Fast walks n+1 steps so the gap is n nodes. Then slow and fast move together. When fast is null, slow sits before the victim. Unlink and return dummy.next. One pass, constant extra space.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
