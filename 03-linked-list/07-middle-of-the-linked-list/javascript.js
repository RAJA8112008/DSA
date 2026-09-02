// Method 1: Brute
// Time: O(n) | Space: O(n)
// Push every node into an array, then return the node at floor(length/2). Extra array of pointers.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function middleNode(head) {
  const nodes = [];
  let cur = head;
  while (cur) {
    nodes.push(cur);
    cur = cur.next;
  }
  return nodes[Math.floor(nodes.length / 2)];
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recursive slow/fast: if fast cannot take two steps, slow is the middle. Stack depth is O(n).

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function middleNode(head) {
  function walk(slow, fast) {
    if (!fast || !fast.next) return slow;
    return walk(slow.next, fast.next.next);
  }
  return walk(head, head);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative tortoise and hare. When fast falls off, slow is the second middle on even length. Constant extra space.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function middleNode(head) {
  let slow = head;
  let fast = head;
  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
  }
  return slow;
}
