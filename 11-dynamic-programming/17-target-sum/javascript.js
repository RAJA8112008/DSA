// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each number branches into plus or minus. 2^n signed assignments. Stack is n. Fine as a correctness check on tiny n.

function findTargetSumWays(nums, target) {
  function go(i, sum) {
    if (i === nums.length) return sum === target ? 1 : 0;
    return go(i + 1, sum + nums[i]) + go(i + 1, sum - nums[i]);
  }
  return go(0, 0);
}


// Method 2: Optimal
// Time: O(n * sum) | Space: O(n * sum)
// Memo keys are (index, running sum). Running sum ranges about [-total, total], so unique states are O(n * total). Each state does two branches once.

function findTargetSumWays(nums, target) {
  const memo = new Map();
  function go(i, sum) {
    const key = i + ":" + sum;
    if (memo.has(key)) return memo.get(key);
    if (i === nums.length) {
      const ans = sum === target ? 1 : 0;
      memo.set(key, ans);
      return ans;
    }
    const ways = go(i + 1, sum + nums[i]) + go(i + 1, sum - nums[i]);
    memo.set(key, ways);
    return ways;
  }
  return go(0, 0);
}


// Method 3: More optimal
// Time: O(n * sum) | Space: O(sum)
// Map onto 0/1 subset-sum ways for need = (total + target) / 2. One ways[] row, inner loop backwards so each number is used once. Cleaner bottom-up, same polynomial, smaller constant memory.

function findTargetSumWays(nums, target) {
  const total = nums.reduce(function (a, b) { return a + b; }, 0);
  if (Math.abs(target) > total || (total + target) % 2 !== 0) return 0;
  const need = (total + target) / 2;
  const ways = Array(need + 1).fill(0);
  ways[0] = 1;
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    for (let s = need; s >= num; s--) {
      ways[s] += ways[s - num];
    }
  }
  return ways[need];
}
