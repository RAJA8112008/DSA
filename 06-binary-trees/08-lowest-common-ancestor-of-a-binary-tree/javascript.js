// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS records the path to p and the path to q as arrays. Last common entry is the LCA. Extra path storage.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function lowestCommonAncestor(root, p, q) {
  function find(node, target, path) {
    if (!node) return false;
    path.push(node);
    if (node === target) return true;
    if (find(node.left, target, path) || find(node.right, target, path)) return true;
    path.pop();
    return false;
  }
  const a = [];
  const b = [];
  find(root, p, a);
  find(root, q, b);
  let i = 0;
  while (i < a.length && i < b.length && a[i] === b[i]) i++;
  return a[i - 1];
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// If node is null, p, or q, return node. Recurse left and right. If both sides return non-null, node is LCA. Else return the non-null side. One DFS.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function lowestCommonAncestor(root, p, q) {
  if (!root || root === p || root === q) return root;
  const left = lowestCommonAncestor(root.left, p, q);
  const right = lowestCommonAncestor(root.right, p, q);
  if (left && right) return root;
  return left || right;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative stack builds a parent map. Collect ancestors of p in a Set. Walk q's parent chain until a node is in the set. No recursion; extra map of n parents.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function lowestCommonAncestor(root, p, q) {
  const parent = new Map();
  parent.set(root, null);
  const stack = [root];
  while (!parent.has(p) || !parent.has(q)) {
    const node = stack.pop();
    if (node.left) {
      parent.set(node.left, node);
      stack.push(node.left);
    }
    if (node.right) {
      parent.set(node.right, node);
      stack.push(node.right);
    }
  }
  const seen = new Set();
  let cur = p;
  while (cur) {
    seen.add(cur);
    cur = parent.get(cur);
  }
  cur = q;
  while (!seen.has(cur)) cur = parent.get(cur);
  return cur;
}
