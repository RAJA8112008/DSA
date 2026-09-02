// Method 1: Brute
// Time: O(n) | Space: O(n)
// Push odd-position nodes, then even-position nodes, into arrays. Relink in that order. Extra arrays.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function oddEvenList(head) {
  const odds = [];
  const evens = [];
  let cur = head;
  let i = 1;
  while (cur) {
    if (i % 2 === 1) odds.push(cur);
    else evens.push(cur);
    cur = cur.next;
    i++;
  }
  const nodes = odds.concat(evens);
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
// Recursive rewire: odd.next = even.next, even.next = that node's next, then recurse. Attach evenHead when even runs out. Stack O(n).

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function oddEvenList(head) {
  if (!head || !head.next) return head;
  const evenHead = head.next;
  function go(odd, even) {
    if (!even || !even.next) {
      odd.next = evenHead;
      return;
    }
    odd.next = even.next;
    even.next = odd.next.next;
    go(odd.next, even.next);
  }
  go(head, evenHead);
  return head;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// odd and even pointers. odd.next = odd.next.next, even.next = even.next.next, until even is exhausted. odd.next = evenHead. In-place, constant extra space.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function oddEvenList(head) {
  if (!head || !head.next) return head;
  let odd = head;
  let even = head.next;
  const evenHead = even;
  while (even && even.next) {
    odd.next = even.next;
    odd = odd.next;
    even.next = odd.next;
    even = even.next;
  }
  odd.next = evenHead;
  return head;
}
