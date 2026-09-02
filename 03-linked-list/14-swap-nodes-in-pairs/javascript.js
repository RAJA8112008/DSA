// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect nodes, swap each pair of indexes, relink in that order. Extra array.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function swapPairs(head) {
  const nodes = [];
  let cur = head;
  while (cur) {
    nodes.push(cur);
    cur = cur.next;
  }
  for (let i = 0; i + 1 < nodes.length; i += 2) {
    const t = nodes[i];
    nodes[i] = nodes[i + 1];
    nodes[i + 1] = t;
  }
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
// If fewer than two nodes, return head. Else first = head, second = head.next, first.next = swapPairs(second.next), second.next = first, return second. Stack O(n/2).

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function swapPairs(head) {
  if (!head || !head.next) return head;
  const first = head;
  const second = head.next;
  first.next = swapPairs(second.next);
  second.next = first;
  return second;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy before head. prev, a, b: prev.next = b, a.next = b.next, b.next = a, then prev = a. Iterative, constant extra space.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function swapPairs(head) {
  const dummy = new ListNode(0, head);
  let prev = dummy;
  while (prev.next && prev.next.next) {
    const a = prev.next;
    const b = a.next;
    prev.next = b;
    a.next = b.next;
    b.next = a;
    prev = a;
  }
  return dummy.next;
}
