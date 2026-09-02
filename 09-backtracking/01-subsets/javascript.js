// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Each call does path.concat so every node of the tree allocates a new array. Correct, but you pay extra copies on internal nodes, not only at leaves. Time is still exponential because there are 2^n subsets.

function subsets(nums) {
  const ans = [];
  function go(i, path) {
    if (i === nums.length) {
      ans.push(path);
      return;
    }
    go(i + 1, path.slice());
    const take = path.slice();
    take.push(nums[i]);
    go(i + 1, take);
  }
  go(0, []);
  return ans;
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// One path array is shared. Push, recurse, pop. You copy only at a leaf. Extra memory besides the output is the path plus O(n) stack.

function subsets(nums) {
  const ans = [];
  function go(i, path) {
    if (i === nums.length) {
      ans.push(path.slice());
      return;
    }
    go(i + 1, path);
    path.push(nums[i]);
    go(i + 1, path);
    path.pop();
  }
  go(0, []);
  return ans;
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// No recursion. Each mask from 0 to 2^n-1 is one subset. Bit i on means nums[i] is in. Same output size, no call stack, tight inner loop.

function subsets(nums) {
  const n = nums.length;
  const ans = [];
  const total = 1 << n;
  for (let mask = 0; mask < total; mask++) {
    const cur = [];
    for (let i = 0; i < n; i++) {
      if (mask & (1 << i)) cur.push(nums[i]);
    }
    ans.push(cur);
  }
  return ans;
}
