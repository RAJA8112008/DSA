// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full inorder into an array, return vals[k-1]. Always walks the whole tree.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function kthSmallest(root, k) {
  const vals = [];
  function inorder(node) {
    if (!node) return;
    inorder(node.left);
    vals.push(node.val);
    inorder(node.right);
  }
  inorder(root);
  return vals[k - 1];
}


// Method 2: Optimal
// Time: O(h+k) | Space: O(h)
// Recursive inorder with a counter. When count hits k, record val and stop expanding. Better when k is small.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function kthSmallest(root, k) {
  const box = { count: 0, ans: 0 };
  function go(node) {
    if (!node || box.count >= k) return;
    go(node.left);
    box.count++;
    if (box.count === k) {
      box.ans = node.val;
      return;
    }
    go(node.right);
  }
  go(root);
  return box.ans;
}


// Method 3: More optimal
// Time: O(h+k) | Space: O(h)
// Iterative inorder. Each pop is the next smallest. After k pops, return that val. Easy to stop early; no extra values array.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function kthSmallest(root, k) {
  const stack = [];
  let cur = root;
  while (true) {
    while (cur) {
      stack.push(cur);
      cur = cur.left;
    }
    cur = stack.pop();
    k--;
    if (k === 0) return cur.val;
    cur = cur.right;
  }
}
