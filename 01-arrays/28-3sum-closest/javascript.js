// Method 1: Brute
// Time: O(n³) | Space: O(1)
// Every triple, track the sum whose absolute gap to target is smallest.

function threeSumClosest(nums, target) {
  const n = nums.length;
  let best = nums[0] + nums[1] + nums[2];
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let k = j + 1; k < n; k++) {
        const s = nums[i] + nums[j] + nums[k];
        if (Math.abs(s - target) < Math.abs(best - target)) best = s;
      }
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n² log n) | Space: O(n)
// Sort. Fix two indexes, binary search the value closest to the leftover. Extra log n on each pair.

function threeSumClosest(nums, target) {
  const a = nums.slice().sort(function (x, y) { return x - y; });
  const n = a.length;
  let best = a[0] + a[1] + a[2];
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const need = target - a[i] - a[j];
      let lo = j + 1, hi = n - 1, pick = j + 1;
      if (lo > hi) continue;
      while (lo <= hi) {
        const mid = (lo + hi) >> 1;
        if (a[mid] === need) return target;
        if (a[mid] < need) { pick = mid; lo = mid + 1; }
        else { pick = mid; hi = mid - 1; }
      }
      const cand = [pick, pick - 1, pick + 1];
      for (let t = 0; t < cand.length; t++) {
        const k = cand[t];
        if (k <= j || k >= n) continue;
        const s = a[i] + a[j] + a[k];
        if (Math.abs(s - target) < Math.abs(best - target)) best = s;
      }
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(1) extra
// Sort. Fix i. Two pointers on the rest. Move the side that improves the sum. Track the closest. Stop early on an exact hit.

function threeSumClosest(nums, target) {
  const a = nums.slice().sort(function (x, y) { return x - y; });
  const n = a.length;
  let best = a[0] + a[1] + a[2];
  for (let i = 0; i < n; i++) {
    let L = i + 1, R = n - 1;
    while (L < R) {
      const s = a[i] + a[L] + a[R];
      if (Math.abs(s - target) < Math.abs(best - target)) best = s;
      if (s === target) return s;
      if (s < target) L++;
      else R--;
    }
  }
  return best;
}
