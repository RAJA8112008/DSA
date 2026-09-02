// Method 1: Brute
// Time: O(n²) | Space: O(h)
// For each node, DFS the rest of the tree looking for k - val. Nested walks. No extra set.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function findTarget(root, k) {
  function exists(node, skip, val) {
    if (!node) return false;
    if (node !== skip && node.val === val) return true;
    return exists(node.left, skip, val) || exists(node.right, skip, val);
  }
  function go(node) {
    if (!node) return false;
    if (exists(root, node, k - node.val)) return true;
    return go(node.left) || go(node.right);
  }
  return go(root);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Hash set of visited values. DFS: if k - val is in the set, done; else add val and continue. Works on any binary tree.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function findTarget(root, k) {
  const seen = new Set();
  function go(node) {
    if (!node) return false;
    if (seen.has(k - node.val)) return true;
    seen.add(node.val);
    return go(node.left) || go(node.right);
  }
  return go(root);
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Inorder array is sorted. Two pointers from both ends. Uses the BST. Space is still linear for the array; two iterators would drop it to O(h).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function findTarget(root, k) {
  const vals = [];
  function go(node) {
    if (!node) return;
    go(node.left);
    vals.push(node.val);
    go(node.right);
  }
  go(root);
  let i = 0;
  let j = vals.length - 1;
  while (i < j) {
    const s = vals[i] + vals[j];
    if (s === k) return true;
    if (s < k) i++;
    else j--;
  }
  return false;
}
