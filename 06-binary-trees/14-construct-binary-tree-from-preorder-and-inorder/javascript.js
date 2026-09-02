// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Root is preorder[0]. Scan inorder for it, slice left/right arrays, recurse. Slicing and scanning are O(n) per node.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function buildTree(preorder, inorder) {
  if (!preorder.length) return null;
  const rootVal = preorder[0];
  const root = new TreeNode(rootVal);
  const mid = inorder.indexOf(rootVal);
  root.left = buildTree(preorder.slice(1, mid + 1), inorder.slice(0, mid));
  root.right = buildTree(preorder.slice(mid + 1), inorder.slice(mid + 1));
  return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// HashMap of inorder indexes. Recurse with (preL, preR, inL, inR) bounds. Each node created once; map lookup O(1).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function buildTree(preorder, inorder) {
  const idx = new Map();
  for (let i = 0; i < inorder.length; i++) idx.set(inorder[i], i);
  function build(preL, preR, inL, inR) {
    if (preL > preR) return null;
    const root = new TreeNode(preorder[preL]);
    const mid = idx.get(root.val);
    const leftSize = mid - inL;
    root.left = build(preL + 1, preL + leftSize, inL, mid - 1);
    root.right = build(preL + leftSize + 1, preR, mid + 1, inR);
    return root;
  }
  return build(0, preorder.length - 1, 0, inorder.length - 1);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Advance a preorder index and an inorder index. build(stop) creates a node, builds left until inorder hits this val, then right until stop. No hashmap; O(h) stack only besides the tree.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function buildTree(preorder, inorder) {
  let p = 0;
  let i = 0;
  function build(stop) {
    if (p >= preorder.length) return null;
    if (inorder[i] === stop) {
      i++;
      return null;
    }
    const root = new TreeNode(preorder[p++]);
    root.left = build(root.val);
    root.right = build(stop);
    return root;
  }
  return build();
}
