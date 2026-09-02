// Method 1: Brute
// Time: O(n) | Space: O(n)
// Copy values, rotate the array with splice/concat or new indexes, rebuild. Extra array.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function rotateRight(head, k) {
  if (!head) return head;
  const vals = [];
  for (let p = head; p; p = p.next) vals.push(p.val);
  k = k % vals.length;
  const rotated = vals.slice(vals.length - k).concat(vals.slice(0, vals.length - k));
  const dummy = new ListNode(0);
  let tail = dummy;
  for (const v of rotated) {
    tail.next = new ListNode(v);
    tail = tail.next;
  }
  return dummy.next;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recursive helper finds length and the tail, then a second walk cuts at n-k. Stack for the first walk is O(n). Same idea as counting, with recursion instead of a loop for length.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function rotateRight(head, k) {
  if (!head || !head.next) return head;
  const box = { n: 0, tail: null };
  function count(node) {
    if (!node) return;
    box.n++;
    box.tail = node;
    count(node.next);
  }
  count(head);
  k = k % box.n;
  if (k === 0) return head;
  let steps = box.n - k;
  let cur = head;
  for (let i = 1; i < steps; i++) cur = cur.next;
  const newHead = cur.next;
  cur.next = null;
  box.tail.next = head;
  return newHead;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Find tail and n in one walk, close the ring, walk n - k % n steps from head, cut. Constant extra space, one extra pass after the count.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function rotateRight(head, k) {
  if (!head || !head.next) return head;
  let n = 1;
  let tail = head;
  while (tail.next) {
    tail = tail.next;
    n++;
  }
  k = k % n;
  if (k === 0) return head;
  tail.next = head;
  let steps = n - k;
  let newTail = head;
  for (let i = 1; i < steps; i++) newTail = newTail.next;
  const newHead = newTail.next;
  newTail.next = null;
  return newHead;
}
