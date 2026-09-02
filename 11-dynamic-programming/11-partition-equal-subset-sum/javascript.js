// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each number is included or skipped. No cache. 2^n subsets. The odd-total check is the only prune. Stack is O(n).

function canPartition(nums) {
  const total = nums.reduce(function (a, b) { return a + b; }, 0);
  if (total % 2 !== 0) return false;
  const need = total / 2;
  function go(i, remain) {
    if (remain === 0) return true;
    if (i === nums.length || remain < 0) return false;
    return go(i + 1, remain - nums[i]) || go(i + 1, remain);
  }
  return go(0, need);
}


// Method 2: Optimal
// Time: O(n * sum) | Space: O(n * sum)
// can[i][s] is true if some subset of the first i numbers adds to s. Classic 0/1 knapsack boolean table. n * (sum/2) cells, each O(1).

function canPartition(nums) {
  const total = nums.reduce(function (a, b) { return a + b; }, 0);
  if (total % 2 !== 0) return false;
  const need = total / 2;
  const n = nums.length;
  const can = Array.from({ length: n + 1 }, function () {
    return Array(need + 1).fill(false);
  });
  for (let i = 0; i <= n; i++) can[i][0] = true;
  for (let i = 1; i <= n; i++) {
    for (let s = 1; s <= need; s++) {
      can[i][s] = can[i - 1][s];
      if (nums[i - 1] <= s) {
        can[i][s] = can[i][s] || can[i - 1][s - nums[i - 1]];
      }
    }
  }
  return can[n][need];
}


// Method 3: More optimal
// Time: O(n * sum) | Space: O(sum)
// One boolean row. Walk s from need down to num so each number is used at most once. Same 0/1 rule as knapsack space cut. Extra memory is need+1 flags.

function canPartition(nums) {
  const total = nums.reduce(function (a, b) { return a + b; }, 0);
  if (total % 2 !== 0) return false;
  const need = total / 2;
  const can = Array(need + 1).fill(false);
  can[0] = true;
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    for (let s = need; s >= num; s--) {
      if (can[s - num]) can[s] = true;
    }
  }
  return can[need];
}
