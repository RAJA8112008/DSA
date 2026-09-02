// Method 1: Brute
// Time: O(n) | Space: O(n)
// Copy every value into an array, reverse the array, then build a brand new list. Easy to see, but it allocates n extra nodes and ignores that you can flip next in place.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function reverseList(head) {
  const vals = [];
  let cur = head;
  while (cur) {
    vals.push(cur.val);
    cur = cur.next;
  }
  vals.reverse();
  const dummy = new ListNode(0);
  let tail = dummy;
  for (const v of vals) {
    tail.next = new ListNode(v);
    tail = tail.next;
  }
  return dummy.next;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse to the end, then set head.next.next = head and cut head.next. The call stack holds every node, so space is O(n). Clear picture of 'suffix first'.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function reverseList(head) {
  if (!head || !head.next) return head;
  const newHead = reverseList(head.next);
  head.next.next = head;
  head.next = null;
  return newHead;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative three-pointer reverse. Each node is visited once. Extra memory is a few names, not the stack and not a new list. This is the usual interview target.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function reverseList(head) {
  let prev = null;
  let cur = head;
  while (cur) {
    const next = cur.next;
    cur.next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}
