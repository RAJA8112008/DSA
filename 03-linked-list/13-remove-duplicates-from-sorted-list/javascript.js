// Method 1: Brute
// Time: O(n) | Space: O(n)
// Walk and push a value only when it differs from the last kept one, then rebuild. Extra array of uniques.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function deleteDuplicates(head) {
  const vals = [];
  let cur = head;
  while (cur) {
    if (vals.length === 0 || vals[vals.length - 1] !== cur.val) {
      vals.push(cur.val);
    }
    cur = cur.next;
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
// Time: O(n) | Space: O(n)
// Recurse on head.next first. If the next node has the same val, skip it. Stack is O(n).

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function deleteDuplicates(head) {
  if (!head || !head.next) return head;
  head.next = deleteDuplicates(head.next);
  if (head.next && head.next.val === head.val) return head.next;
  return head;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pointer. While the next node duplicates, skip it. Then advance. In-place, constant extra space.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function deleteDuplicates(head) {
  let cur = head;
  while (cur && cur.next) {
    if (cur.val === cur.next.val) cur.next = cur.next.next;
    else cur = cur.next;
  }
  return head;
}
