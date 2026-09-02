// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Insert 0..n-1 in order into an empty BST. Each insert walks a growing right spine, so you get a linked list of height n.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function sortedArrayToBST(nums) {
  function insert(node, val) {
    if (!node) return new TreeNode(val);
    if (val < node.val) node.left = insert(node.left, val);
    else node.right = insert(node.right, val);
    return node;
  }
  let root = null;
  for (let i = 0; i < nums.length; i++) root = insert(root, nums[i]);
  return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Slice the array around mid each call. Balanced, but each slice copies O(n) elements across the tree of calls.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function sortedArrayToBST(nums) {
  if (!nums.length) return null;
  const mid = Math.floor(nums.length / 2);
  const node = new TreeNode(nums[mid]);
  node.left = sortedArrayToBST(nums.slice(0, mid));
  node.right = sortedArrayToBST(nums.slice(mid + 1));
  return node;
}


// Method 3: More optimal
// Time: O(n) | Space: O(log n)
// Pass inclusive indices. Each node is created once. Recursion depth is the height of the balanced tree.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function sortedArrayToBST(nums) {
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
