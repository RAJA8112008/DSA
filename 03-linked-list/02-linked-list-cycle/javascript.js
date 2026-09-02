// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Keep an array of visited nodes. For each new node, scan the array for the same object. Correct, but the scan makes it quadratic.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function hasCycle(head) {
  const seen = [];
  let cur = head;
  while (cur) {
    for (let i = 0; i < seen.length; i++) {
      if (seen[i] === cur) return true;
    }
    seen.push(cur);
    cur = cur.next;
  }
  return false;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A Set stores nodes you already walked. Add is O(1) on average. First repeat means a cycle. Extra memory equals the number of distinct nodes before a repeat.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function hasCycle(head) {
  const seen = new Set();
  let cur = head;
  while (cur) {
    if (seen.has(cur)) return true;
    seen.add(cur);
    cur = cur.next;
  }
  return false;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Floyd: slow +1, fast +2. No set. If they meet, there is a cycle. If fast hits null, there is not. Constant extra pointers.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function hasCycle(head) {
  let slow = head;
  let fast = head;
  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
    if (slow === fast) return true;
  }
  return false;
}
