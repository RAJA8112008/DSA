// Method 1: Brute
// Time: O(n) | Space: O(n)
// Copy values, reverse each complete window of k in the array, rebuild a new list. Extra array and new nodes.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function reverseKGroup(head, k) {
  const vals = [];
  for (let p = head; p; p = p.next) vals.push(p.val);
  for (let i = 0; i + k <= vals.length; i += k) {
    let l = i;
    let r = i + k - 1;
    while (l < r) {
      const t = vals[l];
      vals[l] = vals[r];
      vals[r] = t;
      l++;
      r--;
    }
  }
  const dummy = new ListNode(0);
  let tail = dummy;
  for (const v of vals) {
    tail.next = new ListNode(v);
    tail = tail.next;
  }
  return dummy.next;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n/k)
// If fewer than k nodes remain, return head. Else reverse the first k, then set the old head's next to reverseKGroup of the leftover. Recursion depth is number of groups.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function reverseKGroup(head, k) {
  let n = 0;
  let p = head;
  while (p && n < k) {
    p = p.next;
    n++;
  }
  if (n < k) return head;
  let prev = null;
  let cur = head;
  for (let i = 0; i < k; i++) {
    const next = cur.next;
    cur.next = prev;
    prev = cur;
    cur = next;
  }
  head.next = reverseKGroup(cur, k);
  return prev;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy before head. For each group, reverse k nodes between groupPrev and groupNext, then slide groupPrev. No recursion. Constant extra pointers.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function reverseKGroup(head, k) {
  const dummy = new ListNode(0, head);
  let groupPrev = dummy;

  function kth(start, k) {
    let n = start;
    for (let i = 0; i < k; i++) {
      if (!n) return null;
      n = n.next;
    }
    return n;
  }

  while (true) {
    const groupLast = kth(groupPrev, k);
    if (!groupLast) break;
    const groupNext = groupLast.next;
    let prev = groupNext;
    let cur = groupPrev.next;
    while (cur !== groupNext) {
      const next = cur.next;
      cur.next = prev;
      prev = cur;
      cur = next;
    }
    const newGroupStart = groupPrev.next;
    groupPrev.next = groupLast;
    groupPrev = newGroupStart;
  }
  return dummy.next;
}
