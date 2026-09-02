// Method 1: Brute
// Time: O(n³) | Space: O(k)
// Every triple of indexes is summed. Uniqueness is handled by a sorted-key set. k is the number of triplets stored.
// How it works: i < j < l. If the three numbers sum to 0, sort them and keep the key in a Set so duplicates are dropped.

function threeSum(nums) {
  const n = nums.length;
  const seen = new Set();
  const out = [];
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let l = j + 1; l < n; l++) {
        if (nums[i] + nums[j] + nums[l] === 0) {
          const trip = [nums[i], nums[j], nums[l]].sort(function (a, b) { return a - b; });
          const key = trip[0] + "," + trip[1] + "," + trip[2];
          if (!seen.has(key)) {
            seen.add(key);
            out.push(trip);
          }
        }
      }
    }
  }
  return out;
}


// Method 2: Optimal
// Time: O(n² log n) | Space: O(n)
// Sort once. For each pair, binary-search the third value. Each search is log n, and there are n² pairs.
// How it works: after sort, for i and j look for -(nums[i]+nums[j]) in the suffix. Skip used indexes. A set of keys still blocks duplicate triplets.

function threeSum(nums) {
  const n = nums.length;
  const list = nums.slice().sort(function (a, b) { return a - b; });
  const seen = new Set();
  const out = [];

  function find(from, target) {
    let lo = from;
    let hi = n - 1;
    while (lo <= hi) {
      const mid = Math.floor((lo + hi) / 2);
      if (list[mid] === target) return mid;
      if (list[mid] < target) lo = mid + 1;
      else hi = mid - 1;
    }
    return -1;
  }

  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const need = -(list[i] + list[j]);
      const k = find(j + 1, need);
      if (k !== -1) {
        const trip = [list[i], list[j], list[k]];
        const key = trip[0] + "," + trip[1] + "," + trip[2];
        if (!seen.has(key)) {
          seen.add(key);
          out.push(trip);
        }
      }
    }
  }
  return out;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(k)
// Sort plus two pointers is the standard bound. Extra memory is only the output (and the sort copy).
// How it works: skip duplicate first numbers. For each i, left = i+1, right = end. Move left/right by comparing the sum to 0, and skip duplicate left/right values after a hit.

function threeSum(nums) {
  const list = nums.slice().sort(function (a, b) { return a - b; });
  const n = list.length;
  const out = [];
  for (let i = 0; i < n; i++) {
    if (i > 0 && list[i] === list[i - 1]) continue;
    let left = i + 1;
    let right = n - 1;
    while (left < right) {
      const sum = list[i] + list[left] + list[right];
      if (sum === 0) {
        out.push([list[i], list[left], list[right]]);
        left++;
        right--;
        while (left < right && list[left] === list[left - 1]) left++;
        while (left < right && list[right] === list[right + 1]) right--;
      } else if (sum < 0) {
        left++;
      } else {
        right--;
      }
    }
  }
  return out;
}
