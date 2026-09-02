// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Push values, sort the array, write them back onto the existing nodes. Extra array. Does not show list merge sort.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function sortList(head) {
  const vals = [];
  let cur = head;
  while (cur) {
    vals.push(cur.val);
    cur = cur.next;
  }
  vals.sort((a, b) => a - b);
  cur = head;
  let i = 0;
  while (cur) {
    cur.val = vals[i++];
    cur = cur.next;
  }
  return head;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(log n)
// Top-down merge sort. Slow/fast splits the list, recurse both halves, merge sorted chains. Stack is O(log n) for balanced splits.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function sortList(head) {
  if (!head || !head.next) return head;
  let slow = head;
  let fast = head.next;
  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
  }
  const mid = slow.next;
  slow.next = null;
  return merge(sortList(head), sortList(mid));
}

function merge(a, b) {
  const dummy = new ListNode(0);
  let tail = dummy;
  while (a && b) {
    if (a.val < b.val) {
      tail.next = a;
      a = a.next;
    } else {
      tail.next = b;
      b = b.next;
    }
    tail = tail.next;
  }
  tail.next = a || b;
  return dummy.next;
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(1)
// Bottom-up merge sort. Count n, then merge adjacent runs of size step, doubling step. split cuts a run. merge hangs the merged pair after prev. No recursion stack.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function sortList(head) {
  if (!head || !head.next) return head;
  let n = 0;
  for (let p = head; p; p = p.next) n++;
  const dummy = new ListNode(0, head);

  function split(start, len) {
    let p = start;
    for (let i = 1; p && i < len; i++) p = p.next;
    if (!p) return null;
    const rest = p.next;
    p.next = null;
    return rest;
  }

  function merge(prev, a, b) {
    let tail = prev;
    while (a && b) {
      if (a.val < b.val) {
        tail.next = a;
        a = a.next;
      } else {
        tail.next = b;
        b = b.next;
      }
      tail = tail.next;
    }
    tail.next = a || b;
    while (tail.next) tail = tail.next;
    return tail;
  }

  for (let step = 1; step < n; step *= 2) {
    let prev = dummy;
    let cur = dummy.next;
    while (cur) {
      const left = cur;
      const right = split(left, step);
      cur = split(right, step);
      prev = merge(prev, left, right);
    }
  }
  return dummy.next;
}
