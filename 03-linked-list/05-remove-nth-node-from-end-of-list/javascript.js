// Method 1: Brute
// Time: O(n) | Space: O(n)
// Store every node in an array. Remove index length-n, then relink the remaining nodes in order. Extra array of pointers.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function removeNthFromEnd(head, n) {
  const nodes = [];
  let cur = head;
  while (cur) {
    nodes.push(cur);
    cur = cur.next;
  }
  nodes.splice(nodes.length - n, 1);
  const dummy = new ListNode(0);
  let tail = dummy;
  for (const node of nodes) {
    tail.next = node;
    tail = tail.next;
  }
  tail.next = null;
  return dummy.next;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recursive walk to the end, counting on the way back. When the counter hits n, skip that node from the parent. Stack is O(n).

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function removeNthFromEnd(head, n) {
  function go(node) {
    if (!node) return 0;
    const fromEnd = go(node.next) + 1;
    if (fromEnd === n + 1) node.next = node.next.next;
    return fromEnd;
  }
  const dummy = new ListNode(0, head);
  go(dummy);
  return dummy.next;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy head. Fast walks n+1 steps so the gap is n nodes. Then slow and fast move together. When fast is null, slow sits before the victim. Unlink and return dummy.next. One pass, constant extra space.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function removeNthFromEnd(head, n) {
  const dummy = new ListNode(0, head);
  let fast = dummy;
  let slow = dummy;
  for (let i = 0; i < n + 1; i++) fast = fast.next;
  while (fast) {
    fast = fast.next;
    slow = slow.next;
  }
  slow.next = slow.next.next;
  return dummy.next;
}
