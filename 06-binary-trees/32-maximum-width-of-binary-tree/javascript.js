// Method 1: Brute
// Time: O(n) | Space: O(w)
// BFS. Width of a level is the queue size (actual nodes). Max over levels. Matches GFG's non-null count.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function widthOfBinaryTree(root) {
  if (!root) return 0;
  let best = 0;
  const q = [root];
  while (q.length) {
    const n = q.length;
    if (n > best) best = n;
    for (let i = 0; i < n; i++) {
      const node = q.shift();
      if (node.left) q.push(node.left);
      if (node.right) q.push(node.right);
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(w)
// LeetCode width: BFS with heap indices. Subtract the first index of the level so numbers stay small. Width = last - first + 1.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function widthOfBinaryTree(root) {
  if (!root) return 0;
  let best = 0;
  const q = [[root, 0]];
  while (q.length) {
    const n = q.length;
    const first = q[0][1];
    let last = first;
    for (let i = 0; i < n; i++) {
      const node = q[0][0];
      const idx = q[0][1] - first;
      q.shift();
      last = idx;
      if (node.left) q.push([node.left, idx * 2 + 1]);
      if (node.right) q.push([node.right, idx * 2 + 2]);
    }
    if (last + 1 > best) best = last + 1;
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS with (depth, normalized index). Store the first index seen at each depth. Width = idx - first[depth] + 1. Recursion only.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function widthOfBinaryTree(root) {
  const first = [];
  let best = 0;
  function go(node, d, idx) {
    if (!node) return;
    if (first[d] === undefined) first[d] = idx;
    const pos = idx - first[d];
    if (pos + 1 > best) best = pos + 1;
    go(node.left, d + 1, pos * 2 + 1);
    go(node.right, d + 1, pos * 2 + 2);
  }
  go(root, 0, 0);
  return best;
}
