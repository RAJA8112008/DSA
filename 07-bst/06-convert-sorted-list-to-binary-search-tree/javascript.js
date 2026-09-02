// Method 1: Brute
// Time: O(n) | Space: O(n)
// Walk the list into an array, then build from mid indices. Extra O(n) memory for the copy.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function sortedListToBST(head) {
  const nums = [];
  while (head) {
    nums.push(head.val);
    head = head.next;
  }
  function build(lo, hi) {
    if (lo > hi) return null;
    const mid = Math.floor((lo + hi) / 2);
    const node = new TreeNode(nums[mid]);
    node.left = build(lo, mid - 1);
    node.right = build(mid + 1, hi);
    return node;
  }
  return build(0, nums.length - 1);
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(log n)
// Slow/fast finds the mid. Cut prev.next so the left half is a shorter list. Recurse on left half, mid node, and right half. No array, but each level rescans the list.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function sortedListToBST(head) {
  if (!head) return null;
  if (!head.next) return new TreeNode(head.val);
  let prev = null;
  let slow = head;
  let fast = head;
  while (fast && fast.next) {
    prev = slow;
    slow = slow.next;
    fast = fast.next.next;
  }
  prev.next = null;
  const node = new TreeNode(slow.val);
  node.left = sortedListToBST(head);
  node.right = sortedListToBST(slow.next);
  return node;
}


// Method 3: More optimal
// Time: O(n) | Space: O(log n)
// Count n. Inorder-build: recurse left of size n/2, consume the current list node as the root, then recurse right. The list pointer only moves forward. Each node is visited once.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function sortedListToBST(head) {
  let n = 0;
  let cur = head;
  while (cur) { n++; cur = cur.next; }
  cur = head;
  function build(count) {
    if (count <= 0) return null;
    const left = build(Math.floor((count - 1) / 2));
    const node = new TreeNode(cur.val);
    cur = cur.next;
    node.left = left;
    node.right = build(Math.floor(count / 2));
    return node;
  }
  return build(n);
}
