// Method 1: Brute
// Time: O(n^{target/min}) | Space: O(target/min)
// Every call copies path.concat. You keep going while the sum is not past target, with no sort prune. Extra arrays at every node. Correct but heavy.

function combinationSum(cands, target) {
  const ans = [];
  function go(start, sum, path) {
    if (sum === target) { ans.push(path); return; }
    if (sum > target) return;
    for (let i = start; i < cands.length; i++) {
      go(i, sum + cands[i], path.concat([cands[i]]));
    }
  }
  go(0, 0, []);
  return ans;
}


// Method 2: Optimal
// Time: O(n^{target/min}) | Space: O(target/min)
// One path, push/pop. remain shrinks. Call go(i, remain - cands[i]) to reuse this value, or move to i+1 to skip. Copy only at remain == 0.

function combinationSum(cands, target) {
  const ans = [];
  function go(i, remain, path) {
    if (remain === 0) { ans.push(path.slice()); return; }
    if (i === cands.length || remain < 0) return;
    go(i + 1, remain, path);
    path.push(cands[i]);
    go(i, remain - cands[i], path);
    path.pop();
  }
  go(0, target, []);
  return ans;
}


// Method 3: More optimal
// Time: O(n^{target/min}) | Space: O(target/min)
// Sort first. In the for-loop, break when cands[i] > remain so larger later values are never tried. Same answers, fewer dead branches.

function combinationSum(cands, target) {
  cands = cands.slice().sort(function (a, b) { return a - b; });
  const ans = [];
  function go(start, remain, path) {
    if (remain === 0) { ans.push(path.slice()); return; }
    for (let i = start; i < cands.length; i++) {
      if (cands[i] > remain) break;
      path.push(cands[i]);
      go(i, remain - cands[i], path);
      path.pop();
    }
  }
  go(0, target, []);
  return ans;
}
