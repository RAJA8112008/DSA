// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Build every subset with extra path copies, stringify, and keep a Set. Duplicate work is thrown away after you already built it. Fine for tiny n, not the interview finish.

function subsetsWithDup(nums) {
  const seen = new Set();
  const ans = [];
  function go(i, path) {
    if (i === nums.length) {
      const key = path.slice().sort(function (a, b) { return a - b; }).join(",");
      if (!seen.has(key)) {
        seen.add(key);
        ans.push(path.slice());
      }
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
// Sort, then at each start skip nums[i] when it equals nums[i-1]. Those two 2s cannot start the same role twice, so [1,2] appears once. One path, push/pop.

function subsetsWithDup(nums) {
  nums = nums.slice().sort(function (a, b) { return a - b; });
  const ans = [];
  function go(start, path) {
    ans.push(path.slice());
    for (let i = start; i < nums.length; i++) {
      if (i > start && nums[i] === nums[i - 1]) continue;
      path.push(nums[i]);
      go(i + 1, path);
      path.pop();
    }
  }
  go(0, []);
  return ans;
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// Same sort-and-skip, plus you can count how many copies of this value exist and take 0..count in one shot. That collapses a chain of duplicate-index decisions into one loop.

function subsetsWithDup(nums) {
  nums = nums.slice().sort(function (a, b) { return a - b; });
  const ans = [];
  function go(start, path) {
    ans.push(path.slice());
    let i = start;
    while (i < nums.length) {
      let j = i;
      while (j < nums.length && nums[j] === nums[i]) j++;
      const count = j - i;
      for (let take = 1; take <= count; take++) {
        path.push(nums[i]);
        go(j, path);
      }
      for (let take = 1; take <= count; take++) path.pop();
      i = j;
    }
  }
  go(0, []);
  return ans;
}
