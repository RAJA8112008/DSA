// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump, then return vals[n - k]. Extra array of every key.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function kthLargest(root, k) {
  const vals = [];
  function go(node) {
    if (!node) return;
    go(node.left);
    vals.push(node.val);
    go(node.right);
  }
  go(root);
  return vals[vals.length - k];
}


// Method 2: Optimal
// Time: O(h + k) | Space: O(h)
// Reverse inorder. Decrement k at each visit. When k hits 0, that value is the answer. Stop walking.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function kthLargest(root, k) {
  let ans = 0;
  function go(node) {
    if (!node || k === 0) return;
    go(node.right);
    if (k === 0) return;
    k--;
    if (k === 0) ans = node.val;
    go(node.left);
  }
  go(root);
  return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris reverse inorder: thread the successor (leftmost of the right, via left pointers of the right spine). Visit without a stack, stop at k.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function kthLargest(root, k) {
  let cur = root;
  while (cur) {
    if (!cur.right) {
      k--;
      if (k === 0) return cur.val;
      cur = cur.left;
    } else {
      let succ = cur.right;
      while (succ.left && succ.left !== cur) succ = succ.left;
      if (!succ.left) {
        succ.left = cur;
        cur = cur.right;
      } else {
        succ.left = null;
        k--;
        if (k === 0) return cur.val;
        cur = cur.left;
      }
    }
  }
  return 0;
}
