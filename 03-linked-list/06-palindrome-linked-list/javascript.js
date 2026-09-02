// Method 1: Brute
// Time: O(n) | Space: O(n)
// Dump values into an array. Check index i against length-1-i. Extra memory is the array.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function isPalindrome(head) {
  const vals = [];
  let cur = head;
  while (cur) {
    vals.push(cur.val);
    cur = cur.next;
  }
  let i = 0;
  let j = vals.length - 1;
  while (i < j) {
    if (vals[i] !== vals[j]) return false;
    i++;
    j--;
  }
  return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse to the tail. A shared front pointer walks forward as the stack walks back. First mismatch fails. Stack is O(n).

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function isPalindrome(head) {
  const box = { front: head, ok: true };
  function go(node) {
    if (!node) return;
    go(node.next);
    if (node.val !== box.front.val) box.ok = false;
    box.front = box.front.next;
  }
  go(head);
  return box.ok;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Slow/fast to the mid, reverse the second half, compare first half with reversed half. Only a few pointers. Mutates the list; reverse again if you must restore.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function isPalindrome(head) {
  if (!head || !head.next) return true;
  let slow = head;
  let fast = head;
  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
  }
  let prev = null;
  let cur = slow;
  while (cur) {
    const next = cur.next;
    cur.next = prev;
    prev = cur;
    cur = next;
  }
  let a = head;
  let b = prev;
  while (b) {
    if (a.val !== b.val) return false;
    a = a.next;
    b = b.next;
  }
  return true;
}
