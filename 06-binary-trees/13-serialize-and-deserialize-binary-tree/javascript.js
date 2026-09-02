// Method 1: Brute
// Time: O(n) | Space: O(n)
// JSON.stringify the nested {val,left,right} object and JSON.parse it back. Works for this node shape, hides the codec you are supposed to write, and is bulky.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function serialize(root) {
  return JSON.stringify(root);
}

function deserialize(data) {
  if (data === "null") return null;
  return JSON.parse(data);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Preorder join with commas, N for null. Deserialize consumes tokens with an index. Recursion rebuilds left then right.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function serialize(root) {
  const out = [];
  function go(node) {
    if (!node) {
      out.push("N");
      return;
    }
    out.push(String(node.val));
    go(node.left);
    go(node.right);
  }
  go(root);
  return out.join(",");
}

function deserialize(data) {
  const toks = data.split(",");
  let i = 0;
  function go() {
    const t = toks[i++];
    if (t === "N") return null;
    const node = new TreeNode(Number(t));
    node.left = go();
    node.right = go();
    return node;
  }
  return go();
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// BFS codec: queue writes val or N level by level. Deserialize uses a queue of parents and attaches children in order. Iterative, same linear cost, no recurse on serialize/deserialize.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function serialize(root) {
  if (!root) return "N";
  const out = [];
  const queue = [root];
  while (queue.length) {
    const node = queue.shift();
    if (!node) {
      out.push("N");
      continue;
    }
    out.push(String(node.val));
    queue.push(node.left);
    queue.push(node.right);
  }
  return out.join(",");
}

function deserialize(data) {
  const toks = data.split(",");
  if (toks[0] === "N") return null;
  const root = new TreeNode(Number(toks[0]));
  const queue = [root];
  let i = 1;
  while (queue.length && i < toks.length) {
    const node = queue.shift();
    if (toks[i] !== "N") {
      node.left = new TreeNode(Number(toks[i]));
      queue.push(node.left);
    }
    i++;
    if (i < toks.length && toks[i] !== "N") {
      node.right = new TreeNode(Number(toks[i]));
      queue.push(node.right);
    }
    i++;
  }
  return root;
}
