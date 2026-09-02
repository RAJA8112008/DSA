// Method 1: Brute
// Time: O(n^{target/min}) | Space: O(target / min)
// From start you may reuse candidates[i] (call go(i, remain - value)) or move on. Order is frozen by the index, so combinations are unique. No cache; the tree size tracks how you can pile the smallest coin. Depth is about target / min(candidates).

function combinationSum(candidates, target) {
  function go(start, remain) {
    if (remain === 0) return 1;
    if (remain < 0) return 0;
    let ways = 0;
    for (let i = start; i < candidates.length; i++) {
      ways += go(i, remain - candidates[i]);
    }
    return ways;
  }
  return go(0, target);
}


// Method 2: Optimal
// Time: O(n * target) | Space: O(n * target)
// Each pair (start index, remaining target) is solved once. Work per state is a loop over the leftover candidates. Map size is O(n * target). Same combination semantics as the backtrack.

function combinationSum(candidates, target) {
  const memo = new Map();
  function go(start, remain) {
    const key = start + ":" + remain;
    if (memo.has(key)) return memo.get(key);
    if (remain === 0) {
      memo.set(key, 1);
      return 1;
    }
    if (remain < 0) return 0;
    let ways = 0;
    for (let i = start; i < candidates.length; i++) {
      ways += go(i, remain - candidates[i]);
    }
    memo.set(key, ways);
    return ways;
  }
  return go(0, target);
}


// Method 3: More optimal
// Time: O(n * target) | Space: O(target)
// Unbounded knapsack ways. Outer loop is the coin, inner loop walks sums upward so that coin may be reused. That order counts combinations, not permutations. One row of size target+1. If you swapped the loops, you would count ordered sequences instead.

function combinationSum(candidates, target) {
  const ways = Array(target + 1).fill(0);
  ways[0] = 1;
  for (let i = 0; i < candidates.length; i++) {
    const coin = candidates[i];
    for (let s = coin; s <= target; s++) {
      ways[s] += ways[s - coin];
    }
  }
  return ways[target];
}
