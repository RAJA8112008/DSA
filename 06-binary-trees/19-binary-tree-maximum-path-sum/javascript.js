// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At each node, maxDown on left and right is computed from scratch, then visit children. Nested tree walks.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function maxPathSum(root) {
  function maxDown(node) {
    if (!node) return 0;
    return node.val + Math.max(0, maxDown(node.left), maxDown(node.right));
  }
  let best = -Infinity;
  function visit(node) {
    if (!node) return;
    const left = Math.max(0, maxDown(node.left));
    const right = Math.max(0, maxDown(node.right));
    const through = node.val + left + right;
    if (through > best) best = through;
    visit(node.left);
    visit(node.right);
  }
  visit(root);
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// gain(node) = val + max(0, gain(left), gain(right)) for continuing up. Through-node sum updates a boxed best. One DFS.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function maxPathSum(root) {
  let best = -Infinity;
  function gain(node) {
    if (!node) return 0;
    const left = Math.max(0, gain(node.left));
    const right = Math.max(0, gain(node.right));
    const through = node.val + left + right;
    if (through > best) best = through;
    return node.val + Math.max(left, right);
  }
  gain(root);
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Same linear DFS, but dfs returns {gain, best} so there is no outer mutable. Parent combines through, left.best, and right.best. Cleaner to reason about.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function maxPathSum(root) {
  function dfs(node) {
    if (!node) return { gain: 0, best: -Infinity };
    const L = dfs(node.left);
    const R = dfs(node.right);
    const left = Math.max(0, L.gain);
    const right = Math.max(0, R.gain);
    const through = node.val + left + right;
    const gain = node.val + Math.max(left, right);
    const best = Math.max(through, L.best, R.best);
    return { gain: gain, best: best };
  }
  return dfs(root).best;
}
