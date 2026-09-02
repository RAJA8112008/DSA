// Method 1: Brute
// Time: O(C(9, k) * k) | Space: O(k)
// Generate every k-subset with path copies, then filter by sum. C(9,k) is tiny, but you still build losers and copy arrays on every call.

function combinationSum3(k, n) {
  const ans = [];
  function go(start, path) {
    if (path.length === k) {
      let sum = 0;
      for (let i = 0; i < path.length; i++) sum += path[i];
      if (sum === n) ans.push(path);
      return;
    }
    for (let x = start; x <= 9; x++) go(x + 1, path.concat([x]));
  }
  go(1, []);
  return ans;
}


// Method 2: Optimal
// Time: O(C(9, k) * k) | Space: O(k)
// One path. Push x, remain -= x, recurse x+1, pop. Snapshot when k numbers are chosen and remain is 0. No extra copies on internal nodes.

function combinationSum3(k, n) {
  const ans = [];
  function go(start, left, remain, path) {
    if (left === 0) { if (remain === 0) ans.push(path.slice()); return; }
    for (let x = start; x <= 9; x++) {
      path.push(x);
      go(x + 1, left - 1, remain - x, path);
      path.pop();
    }
  }
  go(1, k, n, []);
  return ans;
}


// Method 3: More optimal
// Time: O(C(9, k) * k) | Space: O(k)
// Prune: remain < 0, or remain bigger than the largest left numbers, or remain smaller than the smallest left numbers. Stop the loop when x itself is already too big.

function combinationSum3(k, n) {
  const ans = [];
  function go(start, left, remain, path) {
    if (left === 0) { if (remain === 0) ans.push(path.slice()); return; }
    const minSum = (left * (2 * start + left - 1)) / 2;
    const maxSum = (left * (2 * 9 - left + 1)) / 2;
    if (remain < minSum || remain > maxSum) return;
    for (let x = start; x <= 9; x++) {
      if (x > remain) break;
      path.push(x);
      go(x + 1, left - 1, remain - x, path);
      path.pop();
    }
  }
  go(1, k, n, []);
  return ans;
}
