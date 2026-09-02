// Method 1: Brute
// Time: O(n · n!) | Space: O(n · n!)
// Generate every permutation of 1..n, insert into a BST, serialize the shape, keep one copy per unique serialization. Correct but factorial.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function generateTrees(n) {
  function insert(node, val) {
    if (!node) return new TreeNode(val);
    if (val < node.val) node.left = insert(node.left, val);
    else node.right = insert(node.right, val);
    return node;
  }
  function clone(node) {
    if (!node) return null;
    const c = new TreeNode(node.val);
    c.left = clone(node.left);
    c.right = clone(node.right);
    return c;
  }
  function serial(node) {
    if (!node) return "#";
    return node.val + "," + serial(node.left) + "," + serial(node.right);
  }
  const nums = [];
  for (let i = 1; i <= n; i++) nums.push(i);
  const seen = {};
  const out = [];
  function perm(i) {
    if (i === nums.length) {
      let root = null;
      for (let k = 0; k < nums.length; k++) root = insert(root, nums[k]);
      const s = serial(root);
      if (!seen[s]) { seen[s] = true; out.push(clone(root)); }
      return;
    }
    for (let j = i; j < nums.length; j++) {
      const tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
      perm(i + 1);
      const tmp2 = nums[i]; nums[i] = nums[j]; nums[j] = tmp2;
    }
  }
  perm(0);
  return out;
}


// Method 2: Optimal
// Time: O(C(n) · n) | Space: O(C(n) · n)
// For each root i in [lo, hi], cartesian product of left trees and right trees. Empty range yields a single null tree so a missing child is represented once.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function generateTrees(n) {
  function build(lo, hi) {
    if (lo > hi) return [null];
    const out = [];
    for (let i = lo; i <= hi; i++) {
      const lefts = build(lo, i - 1);
      const rights = build(i + 1, hi);
      for (let L = 0; L < lefts.length; L++) {
        for (let R = 0; R < rights.length; R++) {
          const node = new TreeNode(i);
          node.left = lefts[L];
          node.right = rights[R];
          out.push(node);
        }
      }
    }
    return out;
  }
  if (n === 0) return [];
  return build(1, n);
}


// Method 3: More optimal
// Time: O(C(n) · n) | Space: O(C(n) · n)
// Memoize [lo, hi]. Shared ranges (for example all trees on 3,4,5) are built once. Catalan many trees still must be allocated.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function generateTrees(n) {
  const memo = {};
  function build(lo, hi) {
    const key = lo + "," + hi;
    if (memo[key]) return memo[key];
    if (lo > hi) return (memo[key] = [null]);
    const out = [];
    for (let i = lo; i <= hi; i++) {
      const lefts = build(lo, i - 1);
      const rights = build(i + 1, hi);
      for (let L = 0; L < lefts.length; L++) {
        for (let R = 0; R < rights.length; R++) {
          const node = new TreeNode(i);
          node.left = lefts[L];
          node.right = rights[R];
          out.push(node);
        }
      }
    }
    return (memo[key] = out);
  }
  if (n === 0) return [];
  return build(1, n);
}
