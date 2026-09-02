// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Every index is take or skip with extra path copies. Keep combinations whose sum is target, unique them with a sorted-tuple Set. Duplicate indexes still explore the full 2^n tree.

function combinationSum2(cands, target) {
  const seen = new Set();
  const ans = [];
  function go(i, sum, path) {
    if (sum === target) {
      const key = path.slice().sort(function (a, b) { return a - b; }).join(",");
      if (!seen.has(key)) { seen.add(key); ans.push(path.slice()); }
      return;
    }
    if (i === cands.length || sum > target) return;
    go(i + 1, sum, path.slice());
    go(i + 1, sum + cands[i], path.concat([cands[i]]));
  }
  go(0, 0, []);
  return ans;
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// Sort. Skip nums[i] == nums[i-1] at the same start so identical values do not start the same role twice. Each index is used at most once (go(i+1)).

function combinationSum2(cands, target) {
  cands = cands.slice().sort(function (a, b) { return a - b; });
  const ans = [];
  function go(start, remain, path) {
    if (remain === 0) { ans.push(path.slice()); return; }
    for (let i = start; i < cands.length; i++) {
      if (i > start && cands[i] === cands[i - 1]) continue;
      if (cands[i] > remain) continue;
      path.push(cands[i]);
      go(i + 1, remain - cands[i], path);
      path.pop();
    }
  }
  go(0, target, []);
  return ans;
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// After sort, break when cands[i] > remain. Later values are larger, so they cannot help. Same unique combinations, fewer recursive calls.

function combinationSum2(cands, target) {
  cands = cands.slice().sort(function (a, b) { return a - b; });
  const ans = [];
  function go(start, remain, path) {
    if (remain === 0) { ans.push(path.slice()); return; }
    for (let i = start; i < cands.length; i++) {
      if (cands[i] > remain) break;
      if (i > start && cands[i] === cands[i - 1]) continue;
      path.push(cands[i]);
      go(i + 1, remain - cands[i], path);
      path.pop();
    }
  }
  go(0, target, []);
  return ans;
}
