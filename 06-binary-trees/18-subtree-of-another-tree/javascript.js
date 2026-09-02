// Method 1: Brute
// Time: O(n·m) | Space: O(n)
// Push every node of root into an array, then isSameTree against subRoot for each. Extra array plus O(n*m) compares.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSubtree(root, subRoot) {
  function same(a, b) {
    if (!a && !b) return true;
    if (!a || !b || a.val !== b.val) return false;
    return same(a.left, b.left) && same(a.right, b.right);
  }
  const nodes = [];
  function collect(node) {
    if (!node) return;
    nodes.push(node);
    collect(node.left);
    collect(node.right);
  }
  collect(root);
  for (const node of nodes) {
    if (same(node, subRoot)) return true;
  }
  return false;
}


// Method 2: Optimal
// Time: O(n·m) | Space: O(h)
// No extra node list. If this node matches as a tree, true. Else try left or right. Worst case still O(n*m), typical interview code.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSubtree(root, subRoot) {
  function same(a, b) {
    if (!a && !b) return true;
    if (!a || !b || a.val !== b.val) return false;
    return same(a.left, b.left) && same(a.right, b.right);
  }
  if (!root) return false;
  if (same(root, subRoot)) return true;
  return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(n+m)
// Serialize with parentheses so each subtree is a unique string. Check whether ser(subRoot) is a substring of ser(root). Linear in the size of the strings (and typical includes).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSubtree(root, subRoot) {
  function ser(node) {
    if (!node) return "N";
    return "(" + node.val + "," + ser(node.left) + "," + ser(node.right) + ")";
  }
  return ser(root).indexOf(ser(subRoot)) !== -1;
}
