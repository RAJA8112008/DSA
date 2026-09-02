// Method 1: Brute
// Time: O(n) | Space: O(h)
// Classic 1 + count(left) + count(right). Ignores the complete-tree promise. Fine for small n.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function countNodes(root) {
  if (!root) return 0;
  return 1 + countNodes(root.left) + countNodes(root.right);
}


// Method 2: Optimal
// Time: O(log² n) | Space: O(log n)
// Measure leftmost and rightmost depths. If equal, subtree is perfect: (1 << h) - 1. Else 1 + count(left) + count(right). Each level does O(log n) height work.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function countNodes(root) {
  if (!root) return 0;
  let lh = 0;
  let rh = 0;
  let l = root;
  let r = root;
  while (l) {
    lh++;
    l = l.left;
  }
  while (r) {
    rh++;
    r = r.right;
  }
  if (lh === rh) return (1 << lh) - 1;
  return 1 + countNodes(root.left) + countNodes(root.right);
}


// Method 3: More optimal
// Time: O(log² n) | Space: O(1)
// Height of leftmost path, then binary search the last level: exists(index) walks h-1 bits from the root. Count = full upper levels + how many last-level nodes exist. Iterative, O(1) extra besides the tree.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function countNodes(root) {
  if (!root) return 0;
  function leftHeight(node) {
    let h = 0;
    while (node) {
      h++;
      node = node.left;
    }
    return h;
  }
  function exists(index, h, node) {
    let lo = 0;
    let hi = (1 << (h - 1)) - 1;
    for (let i = 0; i < h - 1; i++) {
      const mid = Math.floor((lo + hi) / 2);
      if (index <= mid) {
        node = node.left;
        hi = mid;
      } else {
        node = node.right;
        lo = mid + 1;
      }
    }
    return !!node;
  }
  const h = leftHeight(root);
  const lastCount = 1 << (h - 1);
  let lo = 0;
  let hi = lastCount - 1;
  while (lo <= hi) {
    const mid = Math.floor((lo + hi) / 2);
    if (exists(mid, h, root)) lo = mid + 1;
    else hi = mid - 1;
  }
  return lastCount - 1 + lo;
}
