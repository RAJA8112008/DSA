// Method 1: Brute
// Time: O(n^4) | Space: O(1) extra
// Four nested indexes. Sort each hit so a set of strings can drop duplicates. Correct and too slow.

function fourSum(nums, target) {
  const n = nums.length;
  const seen = Object.create(null);
  const out = [];
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let k = j + 1; k < n; k++) {
        for (let p = k + 1; p < n; p++) {
          if (nums[i] + nums[j] + nums[k] + nums[p] !== target) continue;
          const quad = [nums[i], nums[j], nums[k], nums[p]].sort(function (a, b) { return a - b; });
          const key = quad.join(",");
          if (seen[key]) continue;
          seen[key] = true;
          out.push(quad);
        }
      }
    }
  }
  return out;
}


// Method 2: Optimal
// Time: O(n^3) | Space: O(n)
// Fix i, j, k. Look up target - (a+b+c) in a set of values after k. Still cubic, extra set, duplicates need care. A stepping stone to two pointers.

function fourSum(nums, target) {
  const n = nums.length;
  const seenQ = Object.create(null);
  const out = [];
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const seen = Object.create(null);
      for (let k = j + 1; k < n; k++) {
        const need = target - nums[i] - nums[j] - nums[k];
        if (seen[need] !== undefined) {
          const quad = [nums[i], nums[j], nums[k], need].sort(function (a, b) { return a - b; });
          const key = quad.join(",");
          if (!seenQ[key]) { seenQ[key] = true; out.push(quad); }
        }
        seen[nums[k]] = k;
      }
    }
  }
  return out;
}


// Method 3: More optimal
// Time: O(n^3) | Space: O(1) extra
// Sort. Fix i and j. Two pointers on the rest. Skip duplicate i, j, left, and right. Use 64-bit sums if the language overflows. This is the expected answer.

function fourSum(nums, target) {
  nums = nums.slice().sort(function (a, b) { return a - b; });
  const n = nums.length;
  const out = [];
  for (let i = 0; i < n; i++) {
    if (i > 0 && nums[i] === nums[i - 1]) continue;
    for (let j = i + 1; j < n; j++) {
      if (j > i + 1 && nums[j] === nums[j - 1]) continue;
      let L = j + 1, R = n - 1;
      while (L < R) {
        const sum = nums[i] + nums[j] + nums[L] + nums[R];
        if (sum === target) {
          out.push([nums[i], nums[j], nums[L], nums[R]]);
          L++;
          R--;
          while (L < R && nums[L] === nums[L - 1]) L++;
          while (L < R && nums[R] === nums[R + 1]) R--;
        } else if (sum < target) L++;
        else R--;
      }
    }
  }
  return out;
}
