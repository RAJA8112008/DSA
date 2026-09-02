// Method 1: Brute
// Time: O(h) | Space: O(h)
// Walk BST paths into two arrays of nodes, then scan from the start until they differ. Extra path arrays.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function lowestCommonAncestor(root, p, q) {
  function pathTo(node, target) {
    const path = [];
    let cur = node;
    while (cur) {
      path.push(cur);
      if (cur === target || cur.val === target.val) break;
      cur = target.val < cur.val ? cur.left : cur.right;
    }
    return path;
  }
  const a = pathTo(root, p);
  const b = pathTo(root, q);
  let i = 0;
  while (i < a.length && i < b.length && a[i] === b[i]) i++;
  return a[i - 1];
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recursive BST walk. Split point is the LCA. Stack O(h).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function lowestCommonAncestor(root, p, q) {
  if (p.val < root.val && q.val < root.val) {
    return lowestCommonAncestor(root.left, p, q);
  }
  if (p.val > root.val && q.val > root.val) {
    return lowestCommonAncestor(root.right, p, q);
  }
  return root;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Same split logic in a loop. No recursion. Constant extra space.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function lowestCommonAncestor(root, p, q) {
  let cur = root;
  while (cur) {
    if (p.val < cur.val && q.val < cur.val) cur = cur.left;
    else if (p.val > cur.val && q.val > cur.val) cur = cur.right;
    else return cur;
  }
  return null;
}
