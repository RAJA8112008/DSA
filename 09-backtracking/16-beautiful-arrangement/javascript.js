// Method 1: Brute
// Time: O(n * n!) | Space: O(n)
// Generate every permutation with leftover copies. After a full perm, scan all n positions. n! full arrays, most fail only at the end.

function countArrangement(n) {
  let count = 0;
  function ok(perm) {
    for (let i = 1; i <= n; i++) {
      if (perm[i - 1] % i !== 0 && i % perm[i - 1] !== 0) return false;
    }
    return true;
  }
  function go(left, perm) {
    if (left.length === 0) { if (ok(perm)) count++; return; }
    for (let i = 0; i < left.length; i++) {
      go(left.slice(0, i).concat(left.slice(i + 1)), perm.concat([left[i]]));
    }
  }
  const left = [];
  for (let x = 1; x <= n; x++) left.push(x);
  go(left, []);
  return count;
}


// Method 2: Optimal
// Time: O(n!) | Space: O(n)
// At position pos (1-based), try unused numbers that already satisfy the divisibility rule. Fail early. used[] plus undo. Count leaves that fill n.

function countArrangement(n) {
  let count = 0;
  const used = Array(n + 1).fill(false);
  function go(pos) {
    if (pos > n) { count++; return; }
    for (let num = 1; num <= n; num++) {
      if (used[num]) continue;
      if (num % pos !== 0 && pos % num !== 0) continue;
      used[num] = true;
      go(pos + 1);
      used[num] = false;
    }
  }
  go(1);
  return count;
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n * 2^n)
// n <= 15. mask bit (num-1) means num is used. pos = popcount(mask)+1. Memo[mask] caches how many ways finish from this used-set. Bitmask + prune + no leftover copies.

function countArrangement(n) {
  const memo = Array(1 << n).fill(-1);
  function go(mask) {
    let pos = 1, m = mask;
    while (m) { m &= m - 1; pos++; }
    if (pos > n) return 1;
    if (memo[mask] !== -1) return memo[mask];
    let ways = 0;
    for (let num = 1; num <= n; num++) {
      if (mask & (1 << (num - 1))) continue;
      if (num % pos !== 0 && pos % num !== 0) continue;
      ways += go(mask | (1 << (num - 1)));
    }
    memo[mask] = ways;
    return ways;
  }
  return go(0);
}
