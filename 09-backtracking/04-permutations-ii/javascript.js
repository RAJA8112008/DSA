// Method 1: Brute
// Time: O(n * n!) | Space: O(n * n!)
// Generate every leftover-copy permutation, stringify, keep a Set. Duplicate 1s still walk the full n! tree. Extra copies plus the Set.

function permuteUnique(nums) {
  const seen = new Set();
  const ans = [];
  function go(left, path) {
    if (left.length === 0) {
      const key = path.join(",");
      if (!seen.has(key)) { seen.add(key); ans.push(path); }
      return;
    }
    for (let i = 0; i < left.length; i++) {
      go(left.slice(0, i).concat(left.slice(i + 1)), path.concat([left[i]]));
    }
  }
  go(nums.slice(), []);
  return ans;
}


// Method 2: Optimal
// Time: O(n * n!) | Space: O(n)
// Sort so equal values are adjacent. Skip nums[j] when it equals nums[j-1] and used[j-1] is false. That forces a fixed order on identical numbers. One path, used[].

function permuteUnique(nums) {
  nums = nums.slice().sort(function (a, b) { return a - b; });
  const ans = [];
  const used = Array(nums.length).fill(false);
  function go(path) {
    if (path.length === nums.length) { ans.push(path.slice()); return; }
    for (let j = 0; j < nums.length; j++) {
      if (used[j]) continue;
      if (j > 0 && nums[j] === nums[j - 1] && !used[j - 1]) continue;
      used[j] = true;
      path.push(nums[j]);
      go(path);
      path.pop();
      used[j] = false;
    }
  }
  go([]);
  return ans;
}


// Method 3: More optimal
// Time: O(n * n!) | Space: O(n)
// In-place swap. A tiny set of values already swapped into start this round stops identical branches. No sort required. Same unique output, less leftover copying.

function permuteUnique(nums) {
  const ans = [];
  function go(start) {
    if (start === nums.length) { ans.push(nums.slice()); return; }
    const seen = {};
    for (let i = start; i < nums.length; i++) {
      if (seen[nums[i]]) continue;
      seen[nums[i]] = 1;
      const t = nums[start]; nums[start] = nums[i]; nums[i] = t;
      go(start + 1);
      const t2 = nums[start]; nums[start] = nums[i]; nums[i] = t2;
    }
  }
  go(0);
  return ans;
}
